#include "s21_smartcalc.h"

int s21_smartcalc(char* str, double x, double* res) {
  int flag = OK;
  *res = 0;
  if (str == NULL || res == NULL || strlen(str) > 255 || !validate(str)) {
    flag = ERROR;
  } else {
    char tmp[255] = {0};
    norm_str(str, tmp);
    *res = calc(tmp, x);
  }
  return flag;
}