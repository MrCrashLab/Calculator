#include "s21_lexeme_stack.h"

lexeme *peek(lexeme_stack *stack) {
  lexeme *res = NULL;
  if (stack->size != 0) {
    res = &(stack->arr_lex[stack->size - 1]);
  }
  return res;
}