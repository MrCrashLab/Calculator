#include "s21_validator.h"

int validate(char* str) {
  return strlen(str) > 0 && strlen(str) < 256 && validate_symb(str) &&
         validate_brackets(str) && validate_func(str) && validate_op(str);
}