CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++17
GCOV_FLAG = -fprofile-arcs -ftest-coverage 
LIB = matrix_oop

all: matrix_oop.a test

matrix_oop.a: clean
	$(CC) -c $(FLAGS) $(LIB).cpp -o $(LIB).o
	ar rcs $(LIB).a $(LIB).o
	ranlib $@

test: clean
	$(CC) $(GCOV_FLAG) matrix_oop.cpp test.cpp -o test -lgtest
	./test

cppcheck:
	@echo "it is cppcheck"
	cppcheck --enable=all --suppress=missingIncludeSystem --language=c++ --std=c++17 *.cpp *.h

linter:
	@echo "it is linter"
	cp ../materials/linters/CPPLINT.cfg . 
	python3 ../materials/linters/cpplint.py --extensions=cpp $(LIB).cpp test.cpp 
	python3 ../materials/linters/cpplint.py --extensions=h *.h 
	rm -f CPPLINT.cfg

clean:
	rm -f *.o *.a *.gcno *.gcda *.info test a.out
	rm -rf report/

t:
	$(CC) $(LIB).cpp -o test
	./test
	
leaks:
ifeq ($(OS), Linux)
	CK_FORK=no valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test
else
	CK_FORK=no leaks -atExit -- ./test
endif

gcov_report: test
	lcov --no-external -t "test" -o test.info -c -d ./
	genhtml -o report test.info
	open report/index.html
