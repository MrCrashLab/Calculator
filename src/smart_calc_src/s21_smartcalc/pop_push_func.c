#include "s21_smartcalc.h"

void pop_push_func(lexeme_stack* num, lexeme_stack* op) {
  double a = pop(num)->num;
  lexeme* lex_tmp = {0};
  lex_tmp = pop(op);
  double c = func_calc(a, *lex_tmp);
  lexeme lex_num = {0};
  lex_num.num = c;
  push(num, lex_num);
}