#include "s21_validator.h"

int validate_op(char* str) {
  char tmp[255];
  del_space(str, tmp);
  size_t size = strlen(tmp);
  int flag =
      !(tmp[0] == '*' || tmp[0] == '/' || tmp[0] == '^' || tmp[0] == 'm' ||
        tmp[size - 1] == '(' || tmp[size - 1] == '+' || tmp[size - 1] == '-' ||
        tmp[size - 1] == '*' || tmp[size - 1] == '/' || tmp[size - 1] == '^' ||
        tmp[size - 1] == 'd');
  if (flag) {
    for (size_t i = 0; i < strlen(tmp); i++) {
      if (((tmp[i] == '(' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '^' ||
            tmp[i] == 'd' || tmp[i] == '+' || tmp[i] == '-') &&
           (tmp[i + 1] == '*' || tmp[i + 1] == '/' || tmp[i + 1] == '^' ||
            tmp[i + 1] == 'm' || tmp[i + 1] == ')')) ||
          ((tmp[i] == '(' || tmp[i] == 'c' || tmp[i] == 's' || tmp[i] == 't' ||
            tmp[i] == 'a' || tmp[i] == 's' || tmp[i] == 'l') &&
           i != 0 &&
           (IS_NUMBER(tmp[i - 1]) || tmp[i - 1] == ')' || tmp[i - 1] == 'x')) ||
          (tmp[i] == ')' && i != size - 1 &&
           (IS_NUMBER(tmp[i + 1]) || tmp[i + 1] == 'x')) ||
          (tmp[i] == 'x' &&
           ((i != 0 && IS_NUMBER(tmp[i - 1])) || IS_NUMBER(tmp[i + 1]))) ||
          (tmp[i] == '.' && tmp[i + 1] == '.') ||
          (tmp[i] == 'x' && tmp[i + 1] == 'x')) {
        flag = 0;
        break;
      }
    }
  }
  return flag;
}