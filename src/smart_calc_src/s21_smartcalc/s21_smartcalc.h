#ifndef SRC_S21_SMARTCALC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_S21_SMARTCALC_H_

#include <math.h>

#include "../s21_lexeme_stack/s21_lexeme_stack.h"
#include "../s21_validator/s21_validator.h"

#define OK 0
#define ERROR 1

double calc(char* str, double x);
double func_calc(double a, lexeme lex);
double op_calc(double a, double b, lexeme lex);
int s21_smartcalc(char* str, double x, double* res);
void norm_str(char* str, char* dest);
void pop_push_op(lexeme_stack* num, lexeme_stack* op);
void pop_push_func(lexeme_stack* num, lexeme_stack* op);

#endif