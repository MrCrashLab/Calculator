#include "s21_validator.h"

int validate_symb(char* str) {
  char* symb = SYMB;
  int flag = 1;
  for (size_t i = 0; i < strlen(str); i++) {
    if (strchr(symb, str[i]) == NULL) {
      flag = 0;
      break;
    }
  }
  return flag;
}