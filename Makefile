ast_full = expressions.o ast.o

error_handler.o: error_handler.cpp error_handler.h
	g++ -c error_handler.cpp -o error_handler.o

expressions.o: expressions.cpp expressions.h
	g++ -c expressions.cpp -o expressions.o

ast.o: ast.cpp ast.h types.h
	g++ -c ast.cpp -o ast.o

symbol_table.o: symbol_table.h symbol_table.cpp
	g++ -c symbol_table.cpp -o symbol_table.o

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

lex.yy.c: j.lex j.tab.h
	flex j.lex

j.tab.h: j.tab.c

j.tab.c: j.y error_handler.h
	bison -d -v j.y 

j.tab.o: j.tab.c
	g++ -c j.tab.c -o j.tab.o

test.o: test.cpp
	g++ -c test.cpp -o test.o

test: lex.yy.o j.tab.o test.o symbol_table.o ${ast_full} error_handler.o
	g++ j.tab.o lex.yy.o test.o symbol_table.o ${ast_full} error_handler.o -o test.out
	./test.out test.j

clean:
	rm -rf lex.yy.o test.o test.out symbol_table.o
	rm -rf lex.yy.c j.tab.c j.tab.h j.output j.tab.o
	rm -rf ${ast_full} error_handler.o
