#include <assert.h>
#include <stdio.h>

extern int yyparse();
extern FILE *yyin;
extern FILE *output_file;

extern void create_program();
extern void scope_down();
extern void quadruples();
extern void destroy_global_table();
extern void destroy_program();
extern char *get_error_message();

extern int yylineno;

_Bool errored = 0;

int yyerror(char *error)
{
    char *message = get_error_message();
    message = message == NULL ? error : message;
    assert(message != NULL);
    fprintf(stderr, "Error on line %d: %s\n", yylineno, message);

    errored = 1;
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL)
    {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    create_program();

    scope_down();

    printf("Parsing...\n");

    yyparse();

    fclose(yyin);

    printf("Parsing complete.\n");

    if (!errored)
    {
        char *output_filename = "output.asm";
        output_file = fopen(output_filename, "w");
        if (output_file == NULL)
        {
            fprintf(stderr, "Error: Could not open file %s\n", output_filename);
            return 1;
        }

        quadruples();

        fclose(output_file);

        printf("\nCode generation complete.\n");
    }

    destroy_global_table();
    destroy_program();

    printf("\nCleanup successful.\n");

    return 0;
}
