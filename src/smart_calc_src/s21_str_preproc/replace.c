#include "s21_str_preproc.h"

void replace(char* str, char* dest, char* str_word, char* dst_word) {
  int i_d = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] != str_word[0]) {
      dest[i_d++] = str[i];
    } else {
      int flag = 1;
      size_t j_d = 0;
      for (size_t j = i; j_d < strlen(str_word); j++) {
        if (str[j] != str_word[j_d++]) {
          flag = 0;
          dest[i_d++] = str[i];
          break;
        }
      }
      if (flag) {
        for (size_t j = 0; j < strlen(dst_word); j++) {
          dest[i_d++] = dst_word[j];
        }
        i += strlen(str_word) - 1;
      }
    }
  }
  dest[i_d] = 0;
}