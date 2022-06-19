#include "symbol_table.h"

#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

extern int yylineno;

struct SymbolTable *current_scope = NULL;
enum SEMANTIC_ERROR semantic_error = NO_ERROR;

size_t string_hash(char *string)
{
    assert(string != NULL);
    size_t hash = stbds_hash_string(string, HASH_SEED);
    return hash % ST_ARRAY_SIZE;
}

struct SymbolTableEntry *search_bucket(struct SymbolTableEntry *node, char *identifier)
{
    while (node != NULL && strcmp(node->name, identifier) != 0)
        node = node->next;
    return node;
}

struct SymbolTableEntry *search_tables(struct SymbolTable *table, char *identifier)
{
    unsigned int bucket = string_hash(identifier);

    while (table != NULL)
    {
        struct SymbolTableEntry *entry = search_bucket(table->buckets[bucket], identifier);
        if (entry != NULL)
            return entry;
        table = table->parent;
    }

    return NULL;
}

struct SymbolTable *create_table()
{
    struct SymbolTable *table = malloc(sizeof(*table));
    assert(table != NULL);

    table->parent = NULL;
    for (unsigned int i = 0; i < ST_ARRAY_SIZE; i++)
        table->buckets[i] = NULL;

    return table;
}

struct SymbolTableEntry *insert(char *identifier, _Bool is_const, _Bool is_init, _Bool is_func, _Bool is_param)
{
    unsigned int bucket = string_hash(identifier);
    struct SymbolTableEntry *head = current_scope->buckets[bucket];

    if (search_bucket(head, identifier) != NULL)
    {
        semantic_error = USED_IDENTIFIER;
        return NULL;
    }

    struct SymbolTableEntry *entry = malloc(sizeof(*entry));
    assert(entry != NULL);

    entry->name = identifier;
    entry->next = head;
    entry->types = NULL;
    entry->is_init = is_init;
    entry->is_used = 0;
    entry->is_func = is_func;
    entry->is_const = is_const;
    entry->is_param = is_param;
    entry->main_type = INVALID;

    current_scope->buckets[bucket] = entry;

    semantic_error = NO_ERROR;
    return entry;
}

void scope_down()
{
    struct SymbolTable *new_scope = create_table();
    new_scope->parent = current_scope;
    current_scope = new_scope;
}

void scope_up()
{
    for (unsigned int i = 0; i < ST_ARRAY_SIZE; i++)
    {
        struct SymbolTableEntry *head = current_scope->buckets[i];
        while (head != NULL)
        {
            struct SymbolTableEntry *next = head->next;
            if (!(head->is_used))
                fprintf(stderr, "Warning on line %d: Identifier '%s' declared but not used\n", yylineno, head->name);
            head = next;
        }
    }
    struct SymbolTable *old_scope = current_scope;
    current_scope = old_scope->parent;
    // destroy_table(old_scope);
}

struct SymbolTableEntry *lookup(char *identifier, _Bool func, _Bool need_init, _Bool init)
{
    struct SymbolTableEntry *found = search_tables(current_scope, identifier);
    // run checks, as parameters to lookup (const, init, func)
    // if found == NULL OR checks fail, return NULL;
    if (found == NULL)
        semantic_error = UNDECLARED_IDENTIFIER;
    else if (found->is_func == 0 && func == 1)
        semantic_error = NOT_A_FUNCTION;
    else if (found->is_func == 1 && func == 0)
        semantic_error = IS_A_FUNCTION;
    else if (found->is_init == 0 && func == 1)
        semantic_error = UNDEFINED_FUNCTION;
    else if (found->is_init == 0 && need_init && found->is_param == 0)
        semantic_error = UNINITIALIZED_IDENTIFIER;
    else if (found->is_const && init)
        semantic_error = CONSTANT_ASSIGNMENT;
    else
    {
        // printf("lookup: %s\n, need init: %d, init: %d, is_init: %d\n", identifier, need_init, init, found->is_init);
        found->is_used = 1;
        found->is_init |= init;
        // printf("lookup: %s\n, need init: %d, init: %d, is_init: %d\n", identifier, need_init, init, found->is_init);
        return found;
    }

    return NULL;
}

char *get_error_message()
{
    switch (semantic_error)
    {
    case NO_ERROR:
        return NULL;
    case USED_IDENTIFIER:
        return "Identifier already used";
    case UNDECLARED_IDENTIFIER:
        return "Identifier not declared";
    case UNINITIALIZED_IDENTIFIER:
        return "Identifier not initialized";
    case NOT_A_FUNCTION:
        return "Identifier is not a function";
    case IS_A_FUNCTION:
        return "Identifier is a function";
    case INVALID_TYPE:
        return "Invalid type modifier combination";
    case UNDEFINED_FUNCTION:
        return "Function declared but not defined";
    case INCOMPATIBLE_TYPES:
        return "Operation between incompatible types";
    case CONSTANT_ASSIGNMENT:
        return "Assignment to constant";
    default:
        return "Unknown error";
    }
}

enum TYPE verify_type(const enum TYPE *types)
{
    unsigned int size = arrlen(types);
    if (size > 4)
        return -1;

    // check they are unique and get non-const types
    int type[3] = {-1, -1, -1};
    unsigned int j = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        if (types[i] != CONST_TYPE)
            type[j++] = types[i];
        for (unsigned int k = i + 1; k < size; k++)
            if (types[i] == types[k])
                return -1;
    }

    // check not 'const'
    if (j == 0)
        return -1;

    // search for ones that may be bundled only with const: 0,3,7,8,9,10
    for (unsigned int i = 0; i < j; i++)
    {
        if (type[i] == 0 || type[i] == 7 || type[i] == 8 || type[i] == 10)
            return size == 1 ? INT_TYPE : -1;
        if (type[i] == 3)
            return (size == 1) ? FLOAT_TYPE : -1;
        if (type[i] == 9)
            return (size == 1) ? VOID_TYPE : -1;
    }

    // check if 2 exists, if so, return j == 1 or j==2 and new_list[!i] is 5
    if (type[0] == 2)
        return ((j == 1) || ((j == 2) && (type[1] == 5))) ? FLOAT_TYPE : -1;
    if (j > 1 && type[1] == 2)
        return ((j == 2) && (type[1] == 5)) ? FLOAT_TYPE : -1;

    // remaining ones can be bundled with int, so we remove it from the list
    int new_list[2] = {-1, -1};
    unsigned int k = j;
    j = 0;
    for (unsigned int i = 0; i < k; i++)
    {
        if (type[i] != 4)
            new_list[j++] = type[i];
    }
    if (j == 0)
        return INT_TYPE;

    // check if 1 exists, if so, return j == 1 or j==2 and type[!i] is 7 or 8 - same for 5 and 6
    if (new_list[0] == 1)
        return ((j == 1) || ((j == 2) && (new_list[1] == 7 || new_list[1] == 8))) ? INT_TYPE : -1;

    if (j > 1 && new_list[1] == 1)
        return ((j == 2) && (new_list[1] == 7 || new_list[1] == 8)) ? INT_TYPE : -1;

    if (new_list[0] == 5)
        return ((j == 1) || ((j == 2) && (new_list[1] == 7 || new_list[1] == 8))) ? INT_TYPE : -1;

    if (j > 1 && new_list[1] == 5)
        return ((j == 2) && (new_list[1] == 7 || new_list[1] == 8)) ? INT_TYPE : -1;

    if (new_list[0] == 6)
        return ((j == 1) || ((j == 2) && (new_list[1] == 7 || new_list[1] == 8))) ? INT_TYPE : -1;

    if (j > 1 && new_list[1] == 6)
        return ((j == 2) && (new_list[1] == 7 || new_list[1] == 8)) ? INT_TYPE : -1;

    assert(0);
    return -1;
}

void change_parameters(struct SymbolTableEntry *entry, enum TYPE *types, _Bool func, _Bool init, _Bool param, enum TYPE main_type)
{
    entry->types = types;
    entry->is_init = init;
    entry->is_param = param;
    entry->main_type = main_type;
}

struct AST_Node *change_list_params(struct AST_Node *initializer_list, enum TYPE *types, _Bool param)
{
    enum TYPE main_type = verify_type(types);
    if (main_type == -1)
    {
        semantic_error = INVALID_TYPE;
        return NULL;
    }

    struct AST_Node *node = initializer_list;
    // printf("Tag %d\n", node->tag);
    while (node != NULL)
    {
        switch (node->tag)
        {
        case NODE_TYPE_IDENTIFIER:
            change_parameters(node->identifier, types, 0, 0, param, main_type);
            return initializer_list;
        case NODE_TYPE_OPERATION:
            if (node->op == ASSIGN_OP)
            {
                assert(node->left->tag == NODE_TYPE_IDENTIFIER);
                change_parameters(node->left->identifier, types, 0, 1, param, main_type);
                return initializer_list;
            }
            else if (node->op == COMMA_OP)
            {
                if (node->right->tag == NODE_TYPE_OPERATION)
                {
                    assert(node->right->op == ASSIGN_OP);
                    assert(node->right->left->tag == NODE_TYPE_IDENTIFIER);
                    change_parameters(node->right->left->identifier, types, 0, 1, param, main_type);
                }
                else
                {
                    assert(node->right->tag == NODE_TYPE_IDENTIFIER);
                    change_parameters(node->right->identifier, types, 0, 0, param, main_type);
                }
                node = node->left;
            }
            else
                printf("IDK OP %d\n", node->op);
            break;
        default:
            printf("IDK NODE_TYPE %d\n", node->tag);
            break;
        }
    }

    return initializer_list;
}

enum TYPE *insert_into_array(enum TYPE *arr, enum TYPE type)
{
    arrput(arr, type);
    return arr;
}

void def_func(struct SymbolTableEntry *entry)
{
    entry->is_func = 1;
    entry->is_init = 1;
}

void delete_array(enum TYPE **arr)
{
    if (arr != NULL)
    {
        arrfree(*arr);
        arr = NULL;
    }
}

void destroy_table(struct SymbolTable *table)
{
    for (unsigned int i = 0; i < ST_ARRAY_SIZE; i++)
    {
        struct SymbolTableEntry *head = table->buckets[i];
        while (head != NULL)
        {
            struct SymbolTableEntry *next = head->next;
            delete_array(&head->types);
            free(head);
            head = next;
        }
    }

    free(table);
}

void destroy_global_table()
{
    destroy_table(current_scope);
}
