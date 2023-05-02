#ifndef SRC_S21_VALIDATOR_S21_VALIDATOR_H
#define SRC_S21_VALIDATOR_S21_VALIDATOR_H

#include "../s21_str_preproc/s21_str_preproc.h"
#define SYMB "()+-*/^modcsintaqrlog0123456789x. "
#define IS_NUMBER(c) ((c >= '0' && c <= '9') || c == '.')

int validate(char* str);
int validate_symb(char* str);
int validate_func(char* str);
int validate_op(char* str);
int validate_brackets(char* str);

#endif