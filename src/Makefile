# all: main

# main: main.o model.o
# 	g++ main.o model.o -o main

# main.o: main.cpp
# 	g++ -c main.cpp

# model.o: model.cpp
# 	g++ -c model.cpp

# clean:
# 	rm -rf *.o main

# SOURCES = s21_matrix_oop/sources/constructors.cpp s21_matrix_oop/sources/assign.cpp s21_matrix_oop/sources/comparison.cpp s21_matrix_oop/sources/arithmetic_operations.cpp s21_matrix_oop/sources/operators.cpp s21_matrix_oop/sources/matrix_operations.cpp s21_matrix_oop/sources/other_methods.cpp

all: test model.a

test: gtest_install
	cmake -S . -B build
	cmake --build build
	cd build && ctest --rerun-failed --output-on-failure

model.a:
	g++ -c model.cpp
	ar rcs model.a
	rm -rf *.o

gtest_install:
	if test ! -d googletest; \
	then \
	`git clone https://github.com/google/googletest.git -b v1.14.0`; \
	cd googletest; cmake -B build ..; \
	fi

gtest_uninstall:
	rm -rf googletest

# coverage: test
# 	mkdir report 
# 	gcovr --html-details report/coverage.html  -r s21_matrix_oop .

# valgrind: test
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=_valgrind_res.txt ./build/s21_matrix_tests

# style:
# 	clang-format -n s21_matrix_oop/*.*
# 	clang-format -n tests/*.*

cppcheck:
	# cppcheck --enable=all --suppress=missingIncludeSystem s21_matrix_oop/

clean:
	rm -rf build report *.o *.a *.html *.css _valgrind_res.txt