#ifndef SRC_S21_STR_PREPROC_S21_STR_PREPROC_H
#define SRC_S21_STR_PREPROC_S21_STR_PREPROC_H

#include <stdlib.h>
#include <string.h>

void del_space(char* src, char* dest);
void proc_sign(char* str, char* dest);
void replace(char* str, char* dest, char* str_word, char* dst_word);

#endif