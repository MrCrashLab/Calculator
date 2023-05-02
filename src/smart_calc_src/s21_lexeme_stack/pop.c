#include "s21_lexeme_stack.h"

lexeme *pop(lexeme_stack *stack) {
  lexeme *res = NULL;
  if (stack->size != 0) {
    stack->size--;
    res = &(stack->arr_lex[stack->size]);
  }
  return res;
}