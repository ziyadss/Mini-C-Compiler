#include "quadruples.h"

extern struct AST_Node *program;

FILE *output_file = NULL;

char *_operation(struct AST_Node *operation, _Bool left);
void _operation_dst(char *identifier, struct AST_Node *operation);
char *_node(struct AST_Node *statement, _Bool left, _Bool ternary, int label, int label_cont);
char *_block(struct AST_Node *block, int label, int label_cont);

int label_count()
{
    static int label_count = 1;
    return label_count++;
}

char *reverse_jump(char *jmp)
{
    if (strcmp(jmp, "JE") == 0)
        return "JNE";
    else if (strcmp(jmp, "JNE") == 0)
        return "JE";
    else if (strcmp(jmp, "JLE") == 0)
        return "JG";
    else if (strcmp(jmp, "JG") == 0)
        return "JLE";
    else if (strcmp(jmp, "JL") == 0)
        return "JGE";
    else if (strcmp(jmp, "JGE") == 0)
        return "JL";

    fprintf(stderr, "Unknown jump: %s\n", jmp);
    return NULL;
}

void _parameters_pop(struct AST_Node *parameters)
{
    if (parameters == NULL)
        return;

    while (parameters->right != NULL)
    {
        assert(parameters->right->tag == NODE_TYPE_IDENTIFIER);
        fprintf(output_file, "POP %s\n", parameters->right->identifier->name);
        parameters = parameters->left;
    }

    assert(parameters->tag == NODE_TYPE_IDENTIFIER);
    fprintf(output_file, "POP %s\n", parameters->identifier->name);
}

void _parameters_push(struct AST_Node *parameters)
{
    if (parameters == NULL)
        return;

    if (parameters->tag == NODE_TYPE_OPERATION && parameters->op == COMMA_OP)
    {
        _parameters_push(parameters->left);
        _parameters_push(parameters->right);
    }
    else
        fprintf(output_file, "PUSH %s\n", _node(parameters, 1, 1, 0, 0));
}

char *_inv_cond_operation(struct AST_Node *operation, char **jmp)
{
    char *name = "temp1";
    *jmp = NULL;
    int lbl1, lbl2;
    char *left_op;
    switch (operation->op)
    {
    case CALL_OP:
        _parameters_push(operation->right);
        fprintf(output_file, "CALL %s\n", operation->left->identifier->name);
        name = "retval";
        break;
    case ADD_ASSIGN_OP:
        name = operation->left->identifier->name;
        fprintf(output_file, "ADD %s, %s, %s\n", name, name, _node(operation->right, 1, 1, 0, 0));
        break;
    case AND_ASSIGN_OP:
        name = operation->left->identifier->name;
        fprintf(output_file, "AND %s, %s, %s\n", name, name, _node(operation->right, 1, 1, 0, 0));
        break;
    case ASSIGN_OP:
        if (operation->right->tag == NODE_TYPE_OPERATION)
            _operation_dst(operation->left->identifier->name, operation->right);
        else
            fprintf(output_file, "MOV %s, %s\n", operation->left->identifier->name, _node(operation->right, 1, 1, 0, 0));
        name = operation->left->identifier->name;
        break;
    case DIV_ASSIGN_OP:
        name = operation->left->identifier->name;
        fprintf(output_file, "DIV %s, %s, %s\n", name, name, _node(operation->right, 1, 1, 0, 0));
        break;
    case MOD_ASSIGN_OP:
        name = operation->left->identifier->name;
        fprintf(output_file, "MOD %s, %s, %s\n", name, name, _node(operation->right, 1, 1, 0, 0));
        break;
    case MUL_ASSIGN_OP:
        name = operation->left->identifier->name;
        fprintf(output_file, "MUL %s, %s, %s\n", name, name, _node(operation->right, 1, 1, 0, 0));
        break;
    case OR_ASSIGN_OP:
        name = operation->left->identifier->name;
        fprintf(output_file, "OR %s, %s, %s\n", name, name, _node(operation->right, 1, 1, 0, 0));
        break;
    case SHL_ASSIGN_OP:
        name = operation->left->identifier->name;
        fprintf(output_file, "SHL %s, %s, %s\n", name, name, _node(operation->right, 1, 1, 0, 0));
        break;
    case SHR_ASSIGN_OP:
        name = operation->left->identifier->name;
        fprintf(output_file, "SHR %s, %s, %s\n", name, name, _node(operation->right, 1, 1, 0, 0));
        break;
    case SUB_ASSIGN_OP:
        name = operation->left->identifier->name;
        fprintf(output_file, "SUB %s, %s, %s\n", name, name, _node(operation->right, 1, 1, 0, 0));
        break;
    case XOR_ASSIGN_OP:
        name = operation->left->identifier->name;
        fprintf(output_file, "XOR %s, %s, %s\n", name, name, _node(operation->right, 1, 1, 0, 0));
        break;
    case ADD_OP:
        fprintf(output_file, "ADD %s, %s, %s\n", name, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case AND_OP:
        fprintf(output_file, "CMP %s, 0\n", _node(operation->left, 1, 1, 0, 0));
        lbl1 = label_count();
        fprintf(output_file, "JE L%d\nCMP %s, 0\nJE L%d\nMOV %s, 1\n", lbl1, _node(operation->right, 1, 1, 0, 0), lbl1, name);
        lbl2 = label_count();
        fprintf(output_file, "JMP L%d\n\nL%d:\nMOV %s, 0\n\nL%d:\n", lbl2, lbl1, name, lbl2);
        break;
    case BIT_AND_OP:
        fprintf(output_file, "AND %s, %s, %s\n", name, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case BIT_NOT_OP:
        fprintf(output_file, "XOR %s, %s, -1\n", name, _node(operation->left, 1, 1, 0, 0));
        break;
    case BIT_OR_OP:
        fprintf(output_file, "OR %s, %s, %s\n", name, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case DEC_OP:
        if (operation->left == NULL)
        {
            assert(operation->right->tag == NODE_TYPE_IDENTIFIER);
            name = operation->right->identifier->name;
        }
        else
        {
            assert(operation->left->tag == NODE_TYPE_IDENTIFIER);
            name = operation->left->identifier->name;
        }
        fprintf(output_file, "DEC %s\n", name);
        break;
    case DIV_OP:
        fprintf(output_file, "DIV %s, %s, %s\n", name, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case EQ_OP:
        left_op = operation->left == NULL ? "temp3" : _node(operation->left, 1, 1, 0, 0);
        fprintf(output_file, "CMP %s, %s\n", left_op, _node(operation->right, 0, 1, 0, 0));
        *jmp = "JNE";
        break;
    case GE_OP:
        fprintf(output_file, "CMP %s, %s\n", _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        *jmp = "JL";
        break;
    case GT_OP:
        fprintf(output_file, "CMP %s, %s\n", _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        *jmp = "JLE";
        break;
    case INC_OP:
        if (operation->left == NULL)
        {
            assert(operation->right->tag == NODE_TYPE_IDENTIFIER);
            name = operation->right->identifier->name;
        }
        else
        {
            assert(operation->left->tag == NODE_TYPE_IDENTIFIER);
            name = operation->left->identifier->name;
        }
        fprintf(output_file, "INC %s\n", name);
        break;
    case LE_OP:
        fprintf(output_file, "CMP %s, %s\n", _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        *jmp = "JG";
        break;
    case LT_OP:
        fprintf(output_file, "CMP %s, %s\n", _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        *jmp = "JGE";
        break;
    case MOD_OP:
        fprintf(output_file, "MOD %s, %s, %s\n", name, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case MUL_OP:
        fprintf(output_file, "MUL %s, %s, %s\n", name, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case NE_OP:
        fprintf(output_file, "CMP %s, %s\n", _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        *jmp = "JE";
        break;
    case NOT_OP:
        fprintf(output_file, "CMP %s, 0\n", _node(operation->left, 1, 1, 0, 0));
        lbl1 = label_count();
        fprintf(output_file, "JE L%d\nMOV %s, 0\n", lbl1, name);
        lbl2 = label_count();
        fprintf(output_file, "JMP L%d\n\nL%d:\nMOV %s, 1\n\nL%d:\n", lbl2, lbl1, name, lbl2);
        break;
    case OR_OP:
        fprintf(output_file, "CMP %s, 0\n", _node(operation->left, 1, 1, 0, 0));
        lbl1 = label_count();
        fprintf(output_file, "JNE L%d\nCMP %s, 0\nJNE L%d\nMOV %s, 0\n", lbl1, _node(operation->right, 1, 1, 0, 0), lbl1, name);
        lbl2 = label_count();
        fprintf(output_file, "JMP L%d\n\nL%d:\nMOV %s, 1\n\nL%d:\n", lbl2, lbl1, name, lbl2);
        break;
    case SHL_OP:
        fprintf(output_file, "SHL %s, %s, %s\n", name, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case SHR_OP:
        fprintf(output_file, "SHR %s, %s, %s\n", name, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case SUB_OP:
        fprintf(output_file, "SUB %s, %s, %s\n", name, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case XOR_OP:
        fprintf(output_file, "XOR %s, %s, %s\n", name, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    default:
        fprintf(output_file, "UNDEF_OP %s, %s\n", "target", "val");
        name = NULL;
        break;
    }
    return name;
}

char *_condition(struct AST_Node *condition)
{
    char *ret = "JNE", *name;
    switch (condition->tag)
    {
    case NODE_TYPE_OPERATION:
        name = _inv_cond_operation(condition, &ret);
        if (ret == NULL)
        {
            fprintf(output_file, "CMP %s, 0\n", name);
            ret = "JNE";
        }
        break;
    case NODE_TYPE_IDENTIFIER:
        fprintf(output_file, "CMP %s, 1\n", condition->identifier->name);
        break;
    case NODE_TYPE_INT:
        fprintf(output_file, "CMP %d, 1\n", condition->int_value);
        break;
    case NODE_TYPE_FLOAT:
        fprintf(output_file, "CMP %f, 1\n", condition->float_value);
        break;
    case NODE_TYPE_CHAR:
        fprintf(output_file, "CMP '%c', 1\n", condition->char_value);
        break;
    case NODE_TYPE_STRING:
        fprintf(output_file, "CMP \"%s\", 1\n", condition->string_value);
        break;
    case NODE_TYPE_BOOL:
        fprintf(output_file, "CMP %d, 1\n", condition->bool_value);
        break;
    default:
        fprintf(stderr, "Invalid statement: %d\n", condition->tag);
        break;
    }
    return ret;
}

char *_if(struct AST_Node *statement, _Bool ternary, char *dest, int label, int label_cont)
{
    char *dst = dest == NULL ? "temp1" : dest;
    char *jmp = _condition(statement->condition);
    int lbl1 = label_count();
    fprintf(output_file, "%s L%d\n", jmp, lbl1);
    char *src = _node(statement->then_branch, 1, 0, label, label_cont);
    if (ternary)
    {
        assert(src != NULL);
        fprintf(output_file, "MOV %s, %s\n", dst, src);
    }

    if (statement->else_branch != NULL)
    {
        int lbl2 = label_count();
        fprintf(output_file, "JMP L%d\n\nL%d:\n", lbl2, lbl1);
        src = _node(statement->else_branch, 1, 0, label, label_cont);
        if (ternary)
        {
            assert(src != NULL);
            fprintf(output_file, "MOV %s, %s\n", dst, src);
        }
        fprintf(output_file, "\nL%d:\n", lbl2);
    }
    else
        fprintf(output_file, "\nL%d:\n", lbl1);

    return dst;
}

void _switch(struct AST_Node *statement)
{
    int lbl = label_count();
    if (statement->left->tag == NODE_TYPE_OPERATION)
        _operation_dst("temp3", statement->left);
    else if (statement->left->tag == NODE_TYPE_IF)
        _if(statement->left, 1, "temp3", lbl, 0);
    else
        fprintf(output_file, "MOV temp3, %s\n", _node(statement->left, 1, 1, 0, 0));

    assert(statement->right->tag == NODE_TYPE_STATEMENTS);
    for (unsigned int i = 0; i < statement->right->statements_count; i++)
    {
        struct AST_Node *case_statement = statement->right->statements[i];
        _node(case_statement, 1, 0, lbl, 0);
        // int lbl1 = label_count();
        // fprintf(output_file, "CMP temp3, %s\n", _node(case_statement->left, 1, 0, 0));
        // fprintf(output_file, "JE L%d\n", lbl1);
        // _node(case_statement->right, 1, 0, 0);
        // fprintf(output_file, "\nL%d:\n", lbl1);
    }
    fprintf(output_file, "\nL%d:\n", lbl);
}

void _while(struct AST_Node *statement)
{
    int lbl1 = label_count(); // continue label
    fprintf(output_file, "L%d:\n", lbl1);
    char *jmp = _condition(statement->condition);
    int lbl2 = label_count(); // break label
    fprintf(output_file, "%s L%d\n", jmp, lbl2);
    _node(statement->then_branch, 1, 0, lbl2, lbl1);
    fprintf(output_file, "JMP L%d\n\nL%d:\n", lbl1, lbl2);
}

void _do_while(struct AST_Node *statement)
{
    int lbl1 = label_count();
    int lbl2 = label_count(); // break label
    int lbl3 = label_count(); // continue label
    fprintf(output_file, "L%d:\n", lbl1);
    _node(statement->then_branch, 1, 0, lbl2, lbl3);
    char *jmp = _condition(statement->condition);
    fprintf(output_file, "%s L%d\n\nL%d:\n", reverse_jump(jmp), lbl1, lbl2);
}

char *_node(struct AST_Node *statement, _Bool left, _Bool ternary, int label, int label_cont)
{
    if (statement == NULL)
        return NULL;

    char *ret = NULL;
    switch (statement->tag)
    {
    case NODE_TYPE_IF:
        ret = _if(statement, ternary, NULL, label, label_cont);
        break;
    case NODE_TYPE_SWITCH:
        _switch(statement);
        break;
    case NODE_TYPE_WHILE:
        _while(statement);
        break;
    case NODE_TYPE_DO_WHILE:
        _do_while(statement);
        break;
    case NODE_TYPE_FOR:
        _node(statement->initialization, 1, 0, label, label_cont);
        _while(statement);
        break;
    case NODE_TYPE_BREAK:
        fprintf(output_file, "JMP L%d\n", label);
        break;
    case NODE_TYPE_CONTINUE:
        fprintf(output_file, "JMP L%d\n", label_cont);
        break;
    case NODE_TYPE_STATEMENTS:
        _block(statement, label, label_cont);
        break;
    case NODE_TYPE_OPERATION:
        ret = _operation(statement, left);
        break;
    case NODE_TYPE_IDENTIFIER:
        ret = statement->identifier->name;
        break;
    case NODE_TYPE_INT:
        asprintf(&ret, "%d", statement->int_value);
        break;
    case NODE_TYPE_FLOAT:
        asprintf(&ret, "%f", statement->float_value);
        break;
    case NODE_TYPE_CHAR:
        asprintf(&ret, "'%c'", statement->char_value);
        break;
    case NODE_TYPE_STRING:
        asprintf(&ret, "\"%s\"", statement->string_value);
        break;
    case NODE_TYPE_BOOL:
        ret = statement->bool_value ? "1" : "0";
        break;
    default:
        fprintf(stderr, "Invalid statement: %d\n", statement->tag);
        break;
    }
    return ret;
}

char *_block(struct AST_Node *block, int label, int label_cont)
{
    for (unsigned int i = 0; i < block->statements_count - 1; i++)
        _node(block->statements[i], 1, 0, label, label_cont);

    return _node(block->statements[block->statements_count - 1], 1, 0, label, label_cont);
}

void _operation_dst(char *identifier, struct AST_Node *operation)
{
    int lbl1, lbl2;
    switch (operation->op)
    {
    case COMMA_OP:
        break;
    case CALL_OP:
        _parameters_push(operation->right);
        fprintf(output_file, "CALL %s\n", operation->left->identifier->name);
        fprintf(output_file, "MOV %s, retval\n", identifier);
        break;
    case ADD_ASSIGN_OP:
        fprintf(output_file, "ADD %s, %s, %s\n", identifier, identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case AND_ASSIGN_OP:
        fprintf(output_file, "AND %s, %s, %s\n", identifier, identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case ASSIGN_OP:
        fprintf(output_file, "MOV %s, %s\n", operation->left->identifier->name, _node(operation->right, 1, 1, 0, 0));
        break;
    case DIV_ASSIGN_OP:
        fprintf(output_file, "DIV %s, %s, %s\n", identifier, identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case MOD_ASSIGN_OP:
        fprintf(output_file, "MOD %s, %s, %s\n", identifier, identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case MUL_ASSIGN_OP:
        fprintf(output_file, "MUL %s, %s, %s\n", identifier, identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case OR_ASSIGN_OP:
        fprintf(output_file, "OR %s, %s, %s\n", identifier, identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case SHL_ASSIGN_OP:
        fprintf(output_file, "SHL %s, %s, %s\n", identifier, identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case SHR_ASSIGN_OP:
        fprintf(output_file, "SHR %s, %s, %s\n", identifier, identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case SUB_ASSIGN_OP:
        fprintf(output_file, "SUB %s, %s, %s\n", identifier, identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case XOR_ASSIGN_OP:
        fprintf(output_file, "XOR %s, %s, %s\n", identifier, identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case ADD_OP:
        if (operation->left == NULL)
            fprintf(output_file, "MOV %s, %s\n", identifier, _node(operation->right, 1, 1, 0, 0));
        else
            fprintf(output_file, "ADD %s, %s, %s\n", identifier, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case AND_OP:
        fprintf(output_file, "CMP %s, 0\n", _node(operation->left, 1, 1, 0, 0));
        lbl1 = label_count();
        fprintf(output_file, "JE L%d\nCMP %s, 0\nJE L%d\nMOV %s, 1\n", lbl1, _node(operation->right, 1, 1, 0, 0), lbl1, identifier);
        lbl2 = label_count();
        fprintf(output_file, "JMP L%d\n\nL%d:\nMOV %s, 0\n\nL%d:\n", lbl2, lbl1, identifier, lbl2);
        break;
    case BIT_AND_OP:
        fprintf(output_file, "AND %s, %s, %s\n", identifier, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case BIT_NOT_OP:
        fprintf(output_file, "XOR %s, %s, -1\n", identifier, _node(operation->right, 1, 1, 0, 0));
        break;
    case BIT_OR_OP:
        fprintf(output_file, "OR %s, %s, %s\n", identifier, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case DEC_OP:
        if (operation->left == NULL)
        {
            assert(operation->right->tag == NODE_TYPE_IDENTIFIER);
            fprintf(output_file, "DEC %s\n", operation->right->identifier->name);
            fprintf(output_file, "MOV %s, %s\n", identifier, operation->right->identifier->name);
        }
        else
        {
            assert(operation->left->tag == NODE_TYPE_IDENTIFIER);
            fprintf(output_file, "MOV %s, %s\n", identifier, operation->left->identifier->name);
            fprintf(output_file, "DEC %s\n", operation->left->identifier->name);
        }
        break;
    case DIV_OP:
        fprintf(output_file, "DIV %s, %s, %s\n", identifier, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case INC_OP:
        if (operation->left == NULL)
        {
            assert(operation->right->tag == NODE_TYPE_IDENTIFIER);
            fprintf(output_file, "INC %s\n", operation->right->identifier->name);
            fprintf(output_file, "MOV %s, %s\n", identifier, operation->right->identifier->name);
        }
        else
        {
            assert(operation->left->tag == NODE_TYPE_IDENTIFIER);
            fprintf(output_file, "MOV %s, %s\n", identifier, operation->left->identifier->name);
            fprintf(output_file, "INC %s\n", operation->left->identifier->name);
        }
        break;
    case MOD_OP:
        fprintf(output_file, "MOD %s, %s, %s\n", identifier, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case MUL_OP:
        fprintf(output_file, "MUL %s, %s, %s\n", identifier, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case NE_OP:
        break;
    case NOT_OP:
        fprintf(output_file, "CMP %s, 0\n", _node(operation->right, 1, 1, 0, 0));
        lbl1 = label_count();
        fprintf(output_file, "JE L%d\nMOV %s, 0\n", lbl1, identifier);
        lbl2 = label_count();
        fprintf(output_file, "JMP L%d\n\nL%d:\nMOV %s, 1\n\nL%d:\n", lbl2, lbl1, identifier, lbl2);
        break;
    case OR_OP:
        fprintf(output_file, "CMP %s, 0\n", _node(operation->left, 1, 1, 0, 0));
        lbl1 = label_count();
        fprintf(output_file, "JNE L%d\nCMP %s, 0\nJNE L%d\nMOV %s, 0\n", lbl1, _node(operation->right, 1, 1, 0, 0), lbl1, identifier);
        lbl2 = label_count();
        fprintf(output_file, "JMP L%d\n\nL%d:\nMOV %s, 1\n\nL%d:\n", lbl2, lbl1, identifier, lbl2);
        break;
    case SHL_OP:
        fprintf(output_file, "SHL %s, %s, %s\n", identifier, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case SHR_OP:
        fprintf(output_file, "SHR %s, %s, %s\n", identifier, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case SUB_OP:
        if (operation->left == NULL)
            fprintf(output_file, "SUB %s, 0, %s\n", identifier, _node(operation->right, 1, 1, 0, 0));
        else
            fprintf(output_file, "SUB %s, %s, %s\n", identifier, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case XOR_OP:
        fprintf(output_file, "XOR %s, %s, %s\n", identifier, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case EQ_OP:
    case GE_OP:
    case GT_OP:
    case LE_OP:
    case LT_OP:
    default:
        fprintf(output_file, "UNDEF_OP %s, %s\n", "target", "val");
        break;
    }
}

char *_operation(struct AST_Node *operation, _Bool left)
{
    char *ret = left ? "temp1" : "temp2";
    int lbl1, lbl2;
    switch (operation->op)
    {
    case RET_OP:
        ret = "retval";
        if (operation->left != NULL)
        {
            if (operation->left->tag == NODE_TYPE_OPERATION)
                _operation_dst(ret, operation->left);
            else
                fprintf(output_file, "MOV %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0));
        }
        fprintf(output_file, "PUSH retadr\nRET\n");
        break;
    case COMMA_OP:
        _node(operation->left, 1, 0, 0, 0);
        _node(operation->right, 0, 0, 0, 0);
        break;
    case CALL_OP:
        _parameters_push(operation->right);
        fprintf(output_file, "CALL %s\nMOV %s, retval\n", operation->left->identifier->name, ret);
        break;
    case ADD_ASSIGN_OP:
        ret = operation->left->identifier->name;
        fprintf(output_file, "ADD %s, %s, %s\n", ret, ret, _node(operation->right, 1, 1, 0, 0));
        break;
    case AND_ASSIGN_OP:
        ret = operation->left->identifier->name;
        fprintf(output_file, "AND %s, %s, %s\n", ret, ret, _node(operation->right, 1, 1, 0, 0));
        break;
    case ASSIGN_OP:
        if (operation->right->tag == NODE_TYPE_OPERATION)
            _operation_dst(operation->left->identifier->name, operation->right);
        else
            fprintf(output_file, "MOV %s, %s\n", operation->left->identifier->name, _node(operation->right, 1, 1, 0, 0));
        ret = operation->left->identifier->name;
        break;
    case DIV_ASSIGN_OP:
        ret = operation->left->identifier->name;
        fprintf(output_file, "DIV %s, %s, %s\n", ret, ret, _node(operation->right, 1, 1, 0, 0));
        break;
    case MOD_ASSIGN_OP:
        ret = operation->left->identifier->name;
        fprintf(output_file, "MOD %s, %s, %s\n", ret, ret, _node(operation->right, 1, 1, 0, 0));
        break;
    case MUL_ASSIGN_OP:
        ret = operation->left->identifier->name;
        fprintf(output_file, "MUL %s, %s, %s\n", ret, ret, _node(operation->right, 1, 1, 0, 0));
        break;
    case OR_ASSIGN_OP:
        ret = operation->left->identifier->name;
        fprintf(output_file, "OR %s, %s, %s\n", ret, ret, _node(operation->right, 1, 1, 0, 0));
        break;
    case SHL_ASSIGN_OP:
        ret = operation->left->identifier->name;
        fprintf(output_file, "SHL %s, %s, %s\n", ret, ret, _node(operation->right, 1, 1, 0, 0));
        break;
    case SHR_ASSIGN_OP:
        ret = operation->left->identifier->name;
        fprintf(output_file, "SHR %s, %s, %s\n", ret, ret, _node(operation->right, 1, 1, 0, 0));
        break;
    case SUB_ASSIGN_OP:
        ret = operation->left->identifier->name;
        fprintf(output_file, "SUB %s, %s, %s\n", ret, ret, _node(operation->right, 1, 1, 0, 0));
        break;
    case XOR_ASSIGN_OP:
        ret = operation->left->identifier->name;
        fprintf(output_file, "XOR %s, %s, %s\n", ret, ret, _node(operation->right, 1, 1, 0, 0));
        break;
    case ADD_OP:
        fprintf(output_file, "ADD %s, %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case AND_OP:
        fprintf(output_file, "CMP %s, 0\n", _node(operation->left, 1, 1, 0, 0));
        lbl1 = label_count();
        fprintf(output_file, "JE L%d\nCMP %s, 0\nJE L%d\nMOV %s, 1\n", lbl1, _node(operation->right, 1, 1, 0, 0), lbl1, ret);
        lbl2 = label_count();
        fprintf(output_file, "JMP L%d\n\nL%d:\nMOV %s, 0\n\nL%d:\n", lbl2, lbl1, ret, lbl2);
        break;
    case BIT_AND_OP:
        fprintf(output_file, "AND %s, %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case BIT_NOT_OP:
        fprintf(output_file, "XOR %s, %s, -1\n", ret, _node(operation->left, 1, 1, 0, 0));
        break;
    case BIT_OR_OP:
        fprintf(output_file, "OR %s, %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case DEC_OP:
        assert(operation->left->tag == NODE_TYPE_IDENTIFIER);
        ret = operation->left->identifier->name;
        fprintf(output_file, "DEC %s\n", ret);
        break;
    case DIV_OP:
        fprintf(output_file, "DIV %s, %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case INC_OP:
        assert(operation->left->tag == NODE_TYPE_IDENTIFIER);
        ret = operation->left->identifier->name;
        fprintf(output_file, "INC %s\n", ret);
        break;
    case MOD_OP:
        fprintf(output_file, "MOD %s, %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case MUL_OP:
        fprintf(output_file, "MUL %s, %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case NOT_OP:
        fprintf(output_file, "CMP %s, 0\n", _node(operation->left, 1, 1, 0, 0));
        lbl1 = label_count();
        fprintf(output_file, "JE L%d\nMOV %s, 0\n", lbl1, ret);
        lbl2 = label_count();
        fprintf(output_file, "JMP L%d\n\nL%d:\nMOV %s, 1\n\nL%d:\n", lbl2, lbl1, ret, lbl2);
        break;
    case OR_OP:
        fprintf(output_file, "CMP %s, 0\n", _node(operation->left, 1, 1, 0, 0));
        lbl1 = label_count();
        fprintf(output_file, "JNE L%d\nCMP %s, 0\nJNE L%d\nMOV %s, 0\n", lbl1, _node(operation->right, 1, 1, 0, 0), lbl1, ret);
        lbl2 = label_count();
        fprintf(output_file, "JMP L%d\n\nL%d:\nMOV %s, 1\n\nL%d:\n", lbl2, lbl1, ret, lbl2);
        break;
    case SHL_OP:
        fprintf(output_file, "SHL %s, %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case SHR_OP:
        fprintf(output_file, "SHR %s, %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case SUB_OP:
        fprintf(output_file, "SUB %s, %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case XOR_OP:
        fprintf(output_file, "XOR %s, %s, %s\n", ret, _node(operation->left, 1, 1, 0, 0), _node(operation->right, 0, 1, 0, 0));
        break;
    case EQ_OP:
    case GE_OP:
    case GT_OP:
    case NE_OP:
    case LE_OP:
    case LT_OP:
        break;
    default:
        fprintf(output_file, "UNDEF_OP %s, %s\n", "target", "val");
        ret = NULL;
        break;
    }
    return ret;
}

void quadruples()
{
    for (unsigned int i = 0; i < program->statements_count; i++)
    {
        struct AST_Node *node = program->statements[i];
        switch (node->tag)
        {
        case NODE_TYPE_STATEMENTS:
            _operation(node, 1);
            break;
        case NODE_TYPE_FUNC_DEF:
            if (node->right != NULL)
            {
                fprintf(output_file, "%s():\nPOP retadr\n", node->identifier->name);
                _parameters_pop(node->left);
                char *end = _block(node->right, 0, 0);
                if (end == NULL || strcmp(end, "retval") != 0)
                    fprintf(output_file, "PUSH retadr\nRET\n");
            }
            break;
        default:
            if (node->tag == NODE_TYPE_OPERATION && node->op == COMMA_OP)
                _operation(node, 1);
            else
                fprintf(stderr, "Invalid top level statement: %d, operation %d\n", node->tag, node->op);
            break;
        }
        fprintf(output_file, "\n");
    }
}
