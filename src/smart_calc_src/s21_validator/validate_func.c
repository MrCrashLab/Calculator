#include "s21_validator.h"

int validate_func(char* str) {
  int flag = 1;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == 's') {
      flag = 0;
      if ((flag = !strncmp(str + i, "sin(", 4))) {
        i += 3;
      } else if ((flag = !strncmp(str + i, "sqrt(", 5))) {
        i += 4;
      }
    } else if (str[i] == 'c') {
      flag = 0;
      if ((flag = !strncmp(str + i, "cos(", 4))) {
        i += 3;
      }
    } else if (str[i] == 't') {
      flag = 0;
      if ((flag = !strncmp(str + i, "tan(", 4))) {
        i += 3;
      }
    } else if (str[i] == 'a') {
      flag = 0;
      if (!strncmp(str + i, "asin(", 5) || !strncmp(str + i, "acos(", 5) ||
          !strncmp(str + i, "atan(", 5)) {
        flag = 1;
        i += 4;
      }
    } else if (str[i] == 'm') {
      flag = 0;
      if ((flag = !strncmp(str + i, "mod", 3))) {
        i += 2;
      }
    } else if (str[i] == 'l') {
      flag = 0;
      if ((flag = !strncmp(str + i, "ln(", 3))) {
        i += 2;
      } else if ((flag = !strncmp(str + i, "log(", 4))) {
        i += 3;
      }
    }
    if (!flag) {
      break;
    }
  }
  return flag;
}