#include "s21_smartcalc.h"

void norm_str(char* str, char* dest) {
  char tmp[255] = {0};
  del_space(str, tmp);
  proc_sign(tmp, dest);
  replace(dest, tmp, "acos", "w");
  replace(tmp, dest, "asin", "r");
  replace(dest, tmp, "atan", "y");
  replace(tmp, dest, "sqrt", "q");
  replace(dest, tmp, "mod", "%");
  replace(tmp, dest, "sin", "s");
  replace(dest, tmp, "cos", "c");
  replace(tmp, dest, "tan", "t");
  replace(dest, tmp, "ln", "l");
  replace(tmp, dest, "log", "o");

  replace(dest, tmp, "-x", "-1*x");
  replace(tmp, dest, "-(", "-1*(");
  replace(dest, tmp, "+x", "+1*x");

  replace(tmp, dest, "-r", "-1*r");
  replace(dest, tmp, "-y", "-1*y");
  replace(tmp, dest, "-q", "-1*q");
  replace(dest, tmp, "-w", "-1*w");
  replace(tmp, dest, "-s", "-1*s");
  replace(dest, tmp, "-c", "-1*c");
  replace(tmp, dest, "-t", "-1*t");
  replace(dest, tmp, "-l", "-1*l");
  replace(tmp, dest, "-o", "-1*o");

  replace(dest, tmp, "+w", "+1*w");
  replace(tmp, dest, "+r", "+1*r");
  replace(dest, tmp, "+y", "+1*y");
  replace(tmp, dest, "+q", "+1*q");
  strcpy(dest, tmp);
  replace(tmp, dest, "+s", "+1*s");
  replace(dest, tmp, "+c", "+1*c");
  replace(tmp, dest, "+t", "+1*t");
  replace(dest, tmp, "+l", "+1*l");
  replace(tmp, dest, "+o", "+1*o");
}