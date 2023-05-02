#include "s21_calc_test.h"

// 0 - мес  1 - лет
// 0 - дифф 1 - аннуи

START_TEST(credit_calc_test_1) {
  double sum = 30000;
  int term = 3;
  int term_type = 0;
  double percent = 90;
  int type = 1;

  double payment = 0;
  double overpayment = 0;
  double general = 0;

  double answer_payment = 11536.128845;
  double answer_overpayment = 4608.386535;
  double answer_general = 34608.386535;

  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(answer_payment, payment, EPS);
  ck_assert_double_eq_tol(answer_overpayment, overpayment, EPS);
  ck_assert_double_eq_tol(answer_general, general, EPS);
}
END_TEST

START_TEST(credit_calc_test_2) {
  double sum = -1;
  int term = 2;
  int term_type = 0;
  double percent = 10;
  int type = 0;
  double payment = 0;
  double overpayment = 0;
  double general = 0;
  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(credit_calc_test_3) {
  double sum = 100;
  int term = 0;
  int term_type = 4;
  double percent = 10;
  int type = 0;
  double payment = 0;
  double overpayment = 0;
  double general = 0;
  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(credit_calc_test_4) {
  double sum = 100;
  int term = 1;
  int term_type = 1;
  double percent = -6;
  int type = 0;
  double payment = 0;
  double overpayment = 0;
  double general = 0;
  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(credit_calc_test_5) {
  double sum = 100;
  int term = 1;
  int term_type = 6;
  double percent = 0;
  int type = 0;
  double payment = 0;
  double overpayment = 0;
  double general = 0;
  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(credit_calc_test_6) {
  double sum = 30000;
  int term = 3;
  int term_type = 1;
  double percent = 90;
  int type = 1;

  double payment = 0;
  double overpayment = 0;
  double general = 0;

  double answer_payment = 2429.834039;
  double answer_overpayment = 57474.025407;
  double answer_general = 87474.025407;

  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(answer_payment, payment, EPS);
  ck_assert_double_eq_tol(answer_overpayment, overpayment, EPS);
  ck_assert_double_eq_tol(answer_general, general, EPS);
}
END_TEST

START_TEST(credit_calc_test_7) {
  double sum = 30000;
  int term = 3;
  int term_type = 1;
  double percent = 90;
  int type = 0;

  double payment = 0;
  double overpayment = 0;
  double general = 0;

  double answer_payment = 1989.583333;
  double answer_overpayment = 41625.000000;
  double answer_general = 71625.000000;

  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(answer_payment, payment, EPS);
  ck_assert_double_eq_tol(answer_overpayment, overpayment, EPS);
  ck_assert_double_eq_tol(answer_general, general, EPS);
}
END_TEST

START_TEST(credit_calc_test_8) {
  double sum = 30000;
  int term = 3;
  int term_type = 0;
  double percent = 90;
  int type = 0;

  double payment = 0;
  double overpayment = 0;
  double general = 0;

  double answer_payment = 11500.000000;
  double answer_overpayment = 4500.000000;
  double answer_general = 34500.000000;

  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(answer_payment, payment, EPS);
  ck_assert_double_eq_tol(answer_overpayment, overpayment, EPS);
  ck_assert_double_eq_tol(answer_general, general, EPS);
}
END_TEST

START_TEST(credit_calc_test_9) {
  double sum = 30000;
  int term = 0;
  int term_type = 0;
  double percent = 90;
  int type = 0;

  double payment = 0;
  double overpayment = 0;
  double general = 0;

  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(credit_calc_test_10) {
  double sum = 30000;
  int term = 50;
  int term_type = 0;
  double percent = 50;
  int type = 0;

  double payment = 0;
  double overpayment = 0;
  double general = 0;

  double answer_payment = 1237.500000;
  double answer_overpayment = 31875.000000;
  double answer_general = 61875.000000;

  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(answer_payment, payment, EPS);
  ck_assert_double_eq_tol(answer_overpayment, overpayment, EPS);
  ck_assert_double_eq_tol(answer_general, general, EPS);
}
END_TEST

Suite *credit_calc_test(void) {
  Suite *s = suite_create("s21_credit");
  TCase *tc = tcase_create("s21_credit_case");
  tcase_add_test(tc, credit_calc_test_1);
  tcase_add_test(tc, credit_calc_test_2);
  tcase_add_test(tc, credit_calc_test_3);
  tcase_add_test(tc, credit_calc_test_4);
  tcase_add_test(tc, credit_calc_test_5);
  tcase_add_test(tc, credit_calc_test_6);
  tcase_add_test(tc, credit_calc_test_7);
  tcase_add_test(tc, credit_calc_test_8);
  tcase_add_test(tc, credit_calc_test_9);
  tcase_add_test(tc, credit_calc_test_10);
  suite_add_tcase(s, tc);
  return s;
}
