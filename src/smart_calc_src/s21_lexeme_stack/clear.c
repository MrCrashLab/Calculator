#include "s21_lexeme_stack.h"

void clear(lexeme_stack* stack) {
  if (stack != NULL) {
    stack->size = 0;
    stack->loc_size = 0;
    free(stack->arr_lex);
    stack->arr_lex = NULL;
  }
}