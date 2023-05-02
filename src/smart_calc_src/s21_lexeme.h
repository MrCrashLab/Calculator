#ifndef SRC_S21_LEXEME_H_
#define SRC_S21_LEXEME_H_

typedef enum Priority {
  FUNC = 1,
  OPEN_BRACKETS = 2,
  CLOSE_BRACKETS = 3,
  ADDSUB = 4,
  MULDIVMOD = 5,
  POW = 6
} priority;

typedef struct Lexeme {
  priority pr;
  char op;
  double num;
} lexeme;

#endif