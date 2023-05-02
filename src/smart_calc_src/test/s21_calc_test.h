#ifndef SRC_TEST_S21_CALC_TEST_H_
#define SRC_TEST_S21_CALC_TEST_H_

#include <check.h>

#include "../s21_credit_calc/s21_credit_calc.h"
#include "../s21_smartcalc/s21_smartcalc.h"
#define EPS 1e-6

Suite* smart_calc_test(void);
Suite* credit_calc_test(void);

#endif