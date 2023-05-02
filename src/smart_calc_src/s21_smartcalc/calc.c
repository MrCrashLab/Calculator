#include "s21_smartcalc.h"

double calc(char *str, double x) {
  double res;
  lexeme_stack op;
  lexeme_stack num;
  init_stack(&op);
  init_stack(&num);
  for (size_t i = 0; i < strlen(str); i++) {
    if (IS_NUMBER(str[i]) ||
        ((i == 0 || str[i - 1] == '(' || str[i - 1] == '*' ||
          str[i - 1] == '/' || str[i - 1] == '^' || str[i - 1] == '%') &&
         (str[i] == '+' || str[i] == '-')) ||
        str[i] == 'x') {
      int j = 1;
      for (; IS_NUMBER(str[i + j]); j++)
        ;
      lexeme lex_num = {0};
      lex_num.num = str[i] == 'x' ? x : atof(str + i);
      push(&num, lex_num);
      i += j - 1;
    } else {
      lexeme lex_op = {0};
      create_lexeme(&lex_op, str[i]);
      if (lex_op.pr == CLOSE_BRACKETS) {
        while (peek(&op)->pr != OPEN_BRACKETS) {
          pop_push_op(&num, &op);
        }
        pop(&op);
        if (op.size != 0 && peek(&op)->pr == FUNC) {
          pop_push_func(&num, &op);
        }
      } else if (lex_op.pr != FUNC && lex_op.pr != OPEN_BRACKETS &&
                 op.size > 0 && peek(&op)->pr >= lex_op.pr) {
        while (op.size > 0 && peek(&op)->pr >= lex_op.pr &&
               peek(&op)->pr != OPEN_BRACKETS) {
          pop_push_op(&num, &op);
        }
        push(&op, lex_op);
      } else {
        push(&op, lex_op);
      }
    }
  }

  while (op.size != 0) {
    if (peek(&op)->pr == FUNC) {
      pop_push_func(&num, &op);
    } else {
      pop_push_op(&num, &op);
    }
  }
  res = peek(&num)->num;
  clear(&op);
  clear(&num);
  return res;
}