#ifndef SRC_S21_LEXEM_STACK_S21_LEXEM_STACK_H_
#define SRC_S21_LEXEM_STACK_S21_LEXEM_STACK_H_

#include <stdlib.h>

#include "../s21_lexeme.h"

typedef struct s21_lexeme_stack {
  int size;
  int loc_size;
  lexeme* arr_lex;
} lexeme_stack;

void init_stack(lexeme_stack* stack);
void push(lexeme_stack* stack, lexeme lex);
lexeme* pop(lexeme_stack* stack);
lexeme* peek(lexeme_stack* stack);
void clear(lexeme_stack* stack);

void create_lexeme(lexeme* lex, char op);

#endif