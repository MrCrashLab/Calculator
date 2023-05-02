#include "s21_str_preproc.h"

void del_space(char* src, char* dest) {
  if (src != NULL && dest != NULL) {
    int i_d = 0;
    for (size_t i = 0; i < strlen(src); i++) {
      if (src[i] != ' ') {
        dest[i_d++] = src[i];
      }
    }
    dest[i_d] = 0;
  }
}