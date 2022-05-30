# Mini-C-Compiler

A compiler for a subset of the C programming language.  
Major differences include:

- No pointers.
- No casts.
- No structs or unions.

## Notes about generated quadruples

- Assumes the presence of five registers - retval, retadr, temp1, temp2, and temp3.

## Building and Running

```shell
    make
    ./bin/compiler.exe examples/fibonacci.c
```

## TODO

- refactoring, low priority
  - 3 operation functions -> to 1 or 2
- type conversion
- ASM for comparison in non-cond expressions
- unit tests
- turn to an actual complete compiler - producing an executable
- parse complete C
- rework most memory allocations and check for leaks including enum identifiers and STs and redoing destroy_ast
- fix postfix in conditions - possibly rework conditions
- at some point, implement own lexer and parser
- refactor quadruples.c
- remove hacky code done for uni submission
- fix scope leak for for initializer
- move symbol table inserts to lexer
- string quote escapes and other escape characters, for char too
- recheck all conditional jumps
