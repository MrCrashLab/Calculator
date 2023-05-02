#include "s21_smartcalc.h"

void pop_push_op(lexeme_stack* num, lexeme_stack* op) {
  lexeme* lex_tmp = {0};
  double b = pop(num)->num;
  double a = pop(num)->num;
  lex_tmp = pop(op);
  double c = op_calc(a, b, *lex_tmp);
  lexeme lex_num = {0};
  lex_num.num = c;
  push(num, lex_num);
}