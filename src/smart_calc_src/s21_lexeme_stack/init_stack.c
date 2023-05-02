#include "s21_lexeme_stack.h"

void init_stack(lexeme_stack *stack) {
  if (stack != NULL) {
    stack->size = 0;
    stack->loc_size = 10;
    stack->arr_lex = (lexeme *)calloc(stack->loc_size, sizeof(lexeme));
  }
}