#ifndef SRC_S21_CREDIT_CALC_S21_CREDIT_CALC_H_
#define SRC_S21_CREDIT_CALC_S21_CREDIT_CALC_H_

#include <math.h>

#define OK 0
#define ERROR 1

int s21_credit_calc(double sum, int term, int term_type, double percent,
                    int type, double* payment, double* overpayment,
                    double* general);

#endif