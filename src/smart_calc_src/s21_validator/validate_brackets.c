#include "s21_validator.h"

int validate_brackets(char* str) {
  int tmp_i = 0;
  int flag = 1;
  for (size_t i = 0; i < strlen(str) && tmp_i >= 0; i++) {
    if (str[i] == '(') {
      tmp_i++;
    } else if (str[i] == ')') {
      tmp_i--;
    }
  }
  flag = tmp_i == 0;
  return flag;
}