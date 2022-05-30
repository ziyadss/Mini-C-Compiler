FILES = $(LEXER) $(PARSER) src/quadruples.c src/ast.c src/symbol_table.c src/main.c

CFLAGS = -Wall -Wextra -g -fdiagnostics-color=always
CPPFLAGS = -I src

LFILE = src/lexer.l
LEXER = build/lex.yy.c

YFILE = src/parser.y
YFLAGS = -d -Wall
PARSER = build/y.tab.c

EXECUTABLE = bin/compiler.exe

all: $(EXECUTABLE)

$(EXECUTABLE): bin $(FILES)
	$(CC)  $(CFLAGS) $(CPPFLAGS) -o $@ $(FILES)

$(LEXER): build $(LFILE)
	$(LEX) $(LFLAGS) -o $@ $(LFILE)

$(PARSER): build $(YFILE)
	$(YACC) $(YFLAGS) -o $@ $(YFILE)

build bin:
	mkdir -p $@

clean:
	rm -fr bin

maintainer-clean:
	rm -fr bin build
