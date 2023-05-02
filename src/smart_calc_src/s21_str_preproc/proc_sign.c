#include "s21_str_preproc.h"

void proc_sign(char* str, char* dest) {
  int i_d = 0;
  int tmp = 1;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] != '+' && str[i] != '-') {
      dest[i_d++] = str[i];
    } else {
      for (; str[i] == '+' || str[i] == '-'; i++) {
        tmp *= str[i] == '+' ? 1 : -1;
      }
      i--;
      dest[i_d++] = tmp == -1 ? '-' : '+';
      tmp = 1;
    }
  }
  dest[i_d] = 0;
}