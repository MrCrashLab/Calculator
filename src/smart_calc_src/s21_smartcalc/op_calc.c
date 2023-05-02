#include "s21_smartcalc.h"

double op_calc(double a, double b, lexeme lex) {
  double res = 0;
  if (lex.op == '+') {
    res = a + b;
  } else if (lex.op == '-') {
    res = a - b;
  } else if (lex.op == '*') {
    res = a * b;
  } else if (lex.op == '/') {
    res = a / b;
  } else if (lex.op == '^') {
    res = pow(a, b);
  } else if (lex.op == '%') {
    res = fmod(a, b);
  }
  return res;
}