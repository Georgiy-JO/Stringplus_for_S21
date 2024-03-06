CC = gcc
GENLAGS = -std=c11 -Wall -Wextra -Werror 
COVLAGS =-fprofile-arcs -ftest-coverage -g
CHLIB  = -lcheck -lm #-lsubunit
ifeq ($(OS), Linux)
	CHLIB += -lsubunit
endif

DFLAG = -D_POSIX_C_SOURCE=200809L

VALG = valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=RESULT_VALGRIND.txt ./
#VALG = valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./
CPPCH = cppcheck --enable=all --suppress=missingIncludeSystem --suppress=invalidFunctionArg --force 

OBJDIR=odj
COVOBJDIR=covodj
SRC_FILES = s21_len.c s21_cpy_cat.c s21_memset.c s21_delta_ln2.c s21_strtok.c s21_memchr.c s21_memcmp.c s21_strchr.c s21_strncmp.c s21_strrchr.c s21_strstr.c s21_strerror.c s21_sprintf.c s21_sscanf.c s21_extra_functions.c
HEAD_FILE = s21_string.h
TEST_SRC= s21_test.c

#object files
OBJ_FILES = $(SRC_FILES:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)
#OBJ_FILES_COV = $(SRC_FILES:.c=.o)

# static libs: usual and for tests report
LIBRARY = $(HEAD_FILE:.h=.a)
COVLIBRARY = $(HEAD_FILE:.h=.tst.a)

# tests
TESTS = $(TEST_SRC:.c=)
TEST_COV = $(TEST_SRC:.c=_cov)

# format src
SRC_CL=../materials/linters/.clang-format

all: s21_string.a
#Hand_tests_(temp)-------------------------------------------------------------------------------------------------------------------
tester: $(LIBRARY) tester.o
	$(CC) $(GENLAGS) $(DFLAG) tester.o -o tester $(LIBRARY)
	rm -f *.o
#	 ./tester

tester.o:tester.c
	$(CC) $(GENLAGS) $(DFLAG) -c tester.c

#Library_creation_+_tests-----------------------------------------------------------------------------------------------------------
# build static lib
s21_string.a: clear_o $(OBJ_FILES)
	ar rcs $(LIBRARY) $(OBJ_FILES)
	rm -f *.o

# build tests with usual lib
$(TESTS): $(LIBRARY) $(TEST_OBJ)
	$(CC) $(GENLAGS) $(DFLAG) $(TEST_OBJ) -o $(TESTS) $(LIBRARY) $(CHLIB)
	rm -f *.o

#object usual
$(OBJ_FILES):%.o: %.c $(HEAD_FILE)
	$(CC) $(GENLAGS) $(DFLAG) -c $< -o $@

$(TEST_OBJ):$(TEST_SRC)
	$(CC) $(GENLAGS) $(DFLAG) -c $< -o $@ $(CHLIB)

# run tests
test: $(TESTS)
	./$(TESTS)

#Coverage_stages-------------------------------------------------------------------------------------------------------------------
# build static lib for tests report
s21_string.tst.a: clear_o $(OBJ_FILES_COV)
	ar rcs $(COVLIBRARY) $(OBJ_FILES_COV)
	rm -f *.o	

# build tests for report
$(TEST_COV): $(COVLIBRARY) $(TEST_OBJ)
	$(CC) $(GENLAGS) $(COVLAGS) $(DFLAG) $(TEST_OBJ) -o $(TEST_COV) $(COVLIBRARY) $(CHLIB)
	rm -f *.o

#run test for cov
test_cov: $(TEST_COV)
	./$(TEST_COV)

#object for test report
$(OBJ_FILES_COV):%.o: %.c $(HEAD_FILE)
	$(CC) $(GENLAGS) $(COVLAGS) $(DFLAG) -c $< -o $@

# coverage
coverage: test_cov
	gcov $(SRC_FILES)

#report
gcov_report: coverage
	gcovr -r . --html --html-details -o coverage_report.html
	rm -f *.gc* 

#Checkers-------------------------------------------------------------------------------------------------------------------------
#code check 1
valgrind: $(TESTS)
	$(VALG)$(TESTS)

#code check 2
cpp_check: 
	$(CPPCH) *.c *.h

# format code style
clang_all:
	cp $(SRC_CL) .clang-format
	clang-format -i *.c
	clang-format -i *.h
	rm -f .clang-format

#------------------------------------------------------------------------------------------------------------------------------------

clear:
	rm -f $(TEST_COV) $(TESTS) *.a *.gc* *.html *.css *.o RESULT_VALGRIND.txt tester 
#tester-temp
clear_o:
	rm -f *.o

rebuild: clear all

rebuild_test: clear test

.extra_list: all test clean s21_string.a gcov_report
