#include "s21_lexeme_stack.h"

void create_lexeme(lexeme* lex, char op) {
  lex->op = op;
  if (op == '+' || op == '-') {
    lex->pr = ADDSUB;
  } else if (op == '*' || op == '%' || op == '/') {
    lex->pr = MULDIVMOD;
  } else if (op == '(') {
    lex->pr = OPEN_BRACKETS;
  } else if (op == ')') {
    lex->pr = CLOSE_BRACKETS;
  } else if (op == '^') {
    lex->pr = POW;
  } else if (op == 'c' || op == 's' || op == 't' || op == 'w' || op == 'r' ||
             op == 'y' || op == 'q' || op == 'l' || op == 'o') {
    lex->pr = FUNC;
  }
}