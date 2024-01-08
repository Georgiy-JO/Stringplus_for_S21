CC = gcc
GENLAGS = -Wall -Wextra -Werror -std=c11
COVLAGS =-fprofile-arcs -ftest-coverage #-g
CHLIB = -lcheck #string.h_flag_?
DFLAG = -D_POSIX_C_SOURCE=200809L

VALG = valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=RESULT_VALGRIND.txt ./
#VALG = valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./
CPPCH = cppcheck --enable=all --suppress=missingIncludeSystem --suppress=invalidFunctionArg --force 

OBJDIR=odj
COVOBJDIR=covodj
SRC_FILES = 
HEAD_FILE = s21_string.h
TEST_SRC= s21_test.c

#object files
OBJ_FILES = $(OBJDIR)/$(SRC_FILES:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)
OBJ_FILES_COV = $(COVOBJDIR)/$(SRC_FILES:.c=.o)

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
	./tester

tester.o:tester.c
	$(CC) $(GENLAGS) $(DFLAG) -c tester.c

#Foulder_creators--------------------------------------------------------------------------------------------------------------------
objdir:
	mkdir $(OBJDIR)

covobjdir:
	mkdir $(COVOBJDIR)

#Library_creation_+_tests-----------------------------------------------------------------------------------------------------------
# build static lib
s21_math.a: objdir $(OBJ_FILES)
	ar rcs $(LIBRARY) $(OBJ_FILES)
	rmdir -f $(OBJDIR)

# build tests with usual lib
$(TESTS): $(LIBRARY) $(TEST_OBJ)
	$(CC) $(GENLAGS) $(DFLAG) $(TEST_OBJ) -o $(TESTS) $(LIBRARY) $(CHLIB)
	rm -f *.o

#object usual
$(OBJ_FILES): %.c $(HEAD_FILE)
	$(CC) $(GENLAGS) $(DFLAG) -c $< -o $@

$(TEST_OBJ):%.c
	$(CC) $(GENLAGS) $(DFLAG) -c $< -o $@

# run tests
test: $(TESTS)
	./$(TESTS)

#Coverage_stages-------------------------------------------------------------------------------------------------------------------
# build static lib for tests report
s21_math.tst.a: covobjdir $(OBJ_FILES_COV)
	ar rcs $(COVLIBRARY) $(OBJ_FILES_COV)
	rmdir -f $(COVOBJDIR)	

# build tests for report
$(TEST_COV): $(COVLIBRARY) $(TEST_OBJ)
	$(CC) $(GENLAGS) $(COVLAGS) $(DFLAG) $(TEST_OBJ) -o $(TEST_COV) $(COVLIBRARY) $(LIBS)
	rm -f *.o

#run test for cov
test_cov: $(TEST_COV)
	./$(TEST_COV)

#object for test report
$(OBJ_FILES_COV): %.c $(HEAD_FILE)
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

clean:
	rm -f $(TEST_COV) $(TEST_COV) *.a *.gc* *.html *.css *.o RESULT_VALGRIND.txt $(OBJDIR) $(COVOBJDIR)

rebuild: clean all

.extra_list: all test clean s21_string.a gcov_report
