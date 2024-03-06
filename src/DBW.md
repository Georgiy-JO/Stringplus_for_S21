# Dead Branches Will

## feature/rk_jo_1 last commit:

Minor changies nothing special! ( ͡° ͜ʖ ͡°)    
JK  (ಠ_ಠ)

So that's, what is done:
1)A little bit modified --> added step to rebuild tests --> src/Makefile;
2)modified --> some bugs fixed &&/|| unneeded comments deleted -->  src/s21_cpy_cat.c;
                                                                    src/s21_delta_ln2.c;
                                                                    src/s21_strtok.c;
                                                                    src/s21_len.c;
                                                                    src/s21_memset.c;
3)Remcreated function to work fuster --> src/s21_delta_ln2.c;
4)More inportant changies in functions stucture --> src/s21_strtok.c;
                                                    src/s21_cpy_cat.c;
5)modified --> minor chngies + better NULL --> src/s21_string.h
6)created 258 complex tests --> for strlen, memcpy, memset, strncpy, strncat, strcspn, strpbrk, strtok -->src/s21_test.c
7)Created and updated list of all created tests --> src/test_list.txt
8)Updeted --> according do existing tests --> src/New_README.md src/New_README_rus.md.

<【☯】‿【☯】>

## develop 31.01 commit:

feature/rk_jo_1 and feature/shadowmm merged 
283 complex tests present

## feature/rk_jo_2 last commit (25.02.24):
This branch summery: FULL WORKABLE VERSION OF s21_sscanf!

New branch reason:
    The testing showed that it probably would be easier to change the structure of a buch of functions.
    The problem is that this changes are so massive it can break everything.
    I'm going to start a new branch for it.

## feature/rk_jo_rework_check(06.03.24):
This branch summery: 
FULL WORKABLE & CHECKED VERSION OF s21_sscanf WITH TESTS!
   
    Commit:
        Working version of s21_sscanf.c;
        All the tests done.

    Issue: the version is not optimal.
    Next:   Optimization of the s21_sscanf.c;
            Clang-format;
            Valgrind;
            Gcov;
            Makefile issues.

    PS. This branch is fully operational, has a lot of commented "printfs", due to that is usefull for troubleshooting.
    PSS. %c && %lc  -- are not working properly and prbaly never will.

## feature/rk_jo_final(06.03.24):
This branch summery: The final vesion for my self.

This branch last commit:
Step_3. ~FINAL FORM~
        Commit with some author's comments.
            Note: This commit is for myself.
    
    Status:     s21_sscanf works;
                Tests for "s21_sscanf" are done;
                Oprimization finished;
                Uninformative comments cleaned;
                Debugging comments cleaned.
    
    Next:   Clang-format;
            Valgrind;
            Gcov;
            Makefile issues.

    *%c && %lc  -- are not working properly and prbaly never will.
