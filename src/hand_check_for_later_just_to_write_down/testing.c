#include <math.h>
//--
#include <stdio.h>
#include <stdlib.h>
//--
#define NA printf("n/a")
#include "s21_math.h"

int main() {
  double input1 = 12345, input2 = 0;
  long int i = 0;

  for (int j = 10; input1 != 54321 && i != 54321; j++) {
    if (j % 10 == 0 || input1 == 12345)
      printf(
          "1-ln; 2-exp; 3-pow; 4-floor; 5-ceil; 6-abs; 7-fabs; 8-cos; "
          "\n9-sqrt; "
          "10-sin; 11-fmod; 12-tan; 13-atan; 14-acos; 15-asin; \n54321-exit; "
          "12345-change function\n");
    if (input1 == 12345) scanf("%ld", &i);
    switch (i) {
      case 1:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", log(input1), log(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_log(input1), s21_log(input1));
        break;
      case 2:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", exp(input1), exp(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_exp(input1), s21_exp(input1));
        break;
      case 3:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        scanf("%lf", &input2);
        printf("%.16lf\t%.6lf\n", pow(input1, input2), pow(input1, input2));
        printf("%.16Lf\t%.6Lf\n\n", s21_pow(input1, input2),
               s21_pow(input1, input2));
        break;
      case 4:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", floor(input1), floor(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_floor(input1), s21_floor(input1));
        break;
      case 5:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", ceil(input1), ceil(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_ceil(input1), s21_ceil(input1));
        break;
      case 6:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%d\n", abs((int)input1));
        printf("%d\n\n", s21_abs((int)input1));
        break;
      case 7:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", fabs(input1), fabs(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_fabs(input1), s21_fabs(input1));
        break;
      case 8:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", cos(input1), cos(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_cos(input1), s21_cos(input1));
        break;
      case 9:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", sqrt(input1), sqrt(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_sqrt(input1), s21_sqrt(input1));
        break;
      case 10:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", sin(input1), sin(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_sin(input1), s21_sin(input1));
        break;
      case 11:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        scanf("%lf", &input2);
        printf("%.16lf\t%.6lf\n", fmod(input1, input2), fmod(input1, input2));
        printf("%.16Lf\t%.6Lf\n\n", s21_fmod(input1, input2),
               s21_fmod(input1, input2));
        break;
      case 12:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", tan(input1), tan(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_tan(input1), s21_tan(input1));
        break;
      case 14:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", acos(input1), acos(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_acos(input1), s21_acos(input1));
        break;
      case 15:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", asin(input1), asin(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_asin(input1), s21_asin(input1));
        break;
      case 13:
        scanf("%lf", &input1);
        if (input1 == 12345 || input1 == 54321) continue;
        printf("%.16lf\t%.6lf\n", atan(input1), atan(input1));
        printf("%.16Lf\t%.6Lf\n\n", s21_atan(input1), s21_atan(input1));
        break;
      case 54321:
        break;
      default:
        NA;
        break;
    }
  }
}