#include "s21_lexeme_stack.h"

void push(lexeme_stack *stack, lexeme lex) {
  stack->size++;
  if (stack->size > stack->loc_size) {
    stack->loc_size *= 2;
    stack->arr_lex =
        (lexeme *)realloc(stack->arr_lex, sizeof(lexeme) * stack->loc_size);
  }
  stack->arr_lex[stack->size - 1] = lex;
}