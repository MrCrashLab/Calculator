#include "s21_smartcalc.h"

double func_calc(double a, lexeme lex) {
  double res = 0;
  if (lex.op == 'c') {
    res = cos(a);
  } else if (lex.op == 's') {
    res = sin(a);
  } else if (lex.op == 't') {
    res = tan(a);
  } else if (lex.op == 'w') {
    res = acos(a);
  } else if (lex.op == 'r') {
    res = asin(a);
  } else if (lex.op == 'y') {
    res = atan(a);
  } else if (lex.op == 'q') {
    res = sqrt(a);
  } else if (lex.op == 'l') {
    res = log(a);
  } else if (lex.op == 'o') {
    res = log10(a);
  }
  return res;
}