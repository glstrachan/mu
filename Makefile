CC = clang++
FLAGS = -std=c++11 -I include

lexgen: util/lexutilsgen.cc
	$(CC) $(FLAGS) util/lexutilsgen.cc -o util/lexutilsgen

lexertest:
	$(CC) $(FLAGS) tests/lexertest.cc src/lexer/lexer.cc src/lexer/lexid.cc src/lexer/lextoken.cc src/error/error.cc -o tests/lexertest

clean:
	rm tests/lexertest util/lexutilsgen