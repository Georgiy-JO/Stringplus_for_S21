CC = gcc
GENLAGS = -Wall -Wextra -Werror -std=c11
LIBS = -lm
DFLAG = -D_POSIX_C_SOURCE=200809L
LIB = s21_math.a
HEADER = s21_math.h
SRC_CL=../materials/linters/.clang-format
MAIN = testing
#------------------------------------------------------------------------------------------------------------------------------------
all: mk bring $(MAIN)

test: $(MAIN).c $(LIB)
	cp $(SRC_CL) .clang-format
	clang-format -i *.c
	clang-format -i *.h
	$(CC) $(GENLAGS) $(DFLAG) $(MAIN).c $(LIB) $(LIBS) -o $(MAIN) 
	rm -f *.o
	rm -f .clang-format

$(MAIN): test
	./$(MAIN)
#------------------------------------------------------------------------------------------------------------------------------------
bring: 
	cp ../src/$(HEADER) $(HEADER)
	mv ../src/$(LIB) $(LIB)

copy: 
	cp ../src/$(HEADER) $(HEADER)
	cp ../src/$(LIB) $(LIB)
#------------------------------------------------------------------------------------------------------------------------------------
mk:
	sh libmaker.sh

clean:
	rm -f  *.o $(MAIN) .clang-format

clean_all: clean
	rm -f $(LIB) $(HEADER) 

clean_all_all: clean_all
	rm -f  ../src/s21_math.a

rebuild: clean all

.PHONY: all test clean s21_math.a gcov_report
