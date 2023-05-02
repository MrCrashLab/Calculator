#include "s21_calc_test.h"
#define EPS 1e-6

START_TEST(smart_calc_test_1) {
  char str[255] = "";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_2) {
  char str[255] = "1";
  double answer = 1;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_3) {
  char str[255] = "1)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_4) {
  char str[255] = "1+2";
  double answer = 3;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_5) {
  char str[255] = "2*5";
  double answer = 10;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_6) {
  char str[255] = "4/5";
  double answer = 0.8;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_7) {
  char str[255] = "3^3";
  double answer = 27;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_8) {
  char str[255] = "3*";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_9) {
  char str[255] = "2.5*3/8";
  double answer = 0.9375;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_10) {
  char str[255] = "***";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_11) {
  char str[255] = "25/0";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(isinf(result), 1);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_12) {
  char str[255] = "sin";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_13) {
  char str[255] = "sin(1)";
  double answer = 0.841471;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_14) {
  char str[255] = "cos(1)";
  double answer = 0.540302;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_15) {
  char str[255] = "log(5)";
  double answer = 0.69897;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_16) {
  char str[255] = "ln(5)";
  double answer = 1.609438;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_17) {
  char str[255] = "asin(0.2)";
  double answer = 0.201358;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_18) {
  char str[255] = "acos(0.2)";
  double answer = 1.369438;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_19) {
  char str[255] = "tan(0.8)";
  double answer = 1.029639;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_20) {
  char str[255] = "atan(0.8)";
  double answer = 0.674741;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_21) {
  char str[255] = "2+7";
  double answer = 9;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_22) {
  char str[255] = "4.5*3";
  double answer = 13.5;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_23) {
  char str[255] = "1**24-1/0*sin()-1^^2";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_24) {
  char str[255] = "sin(cos(sin(cos(";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_25) {
  char str[255] = "7(7";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_26) {
  char str[255] = "sqrt(9)";
  double answer = 3;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_27) {
  char str[255] = "2.6-1.11";
  double answer = 1.49;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_28) {
  char str[255] = "7mod3";
  double answer = 1;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_29) {
  char str[255] = "x*2";
  double answer = 10;
  double result = 0;
  int error = s21_smartcalc(str, 5, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_30) {
  char str[255] = "-1";
  double answer = -1;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_31) {
  char str[255] = "+1";
  double answer = 1;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_32) {
  char str[255] = "2**2";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_33) {
  char str[255] = "cos";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_34) {
  char str[255] = "cos(5).6";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_35) {
  char str[255] = "cos(5)/";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_36) {
  char str[255] = "sqrt(-1)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(isnan(result), 1);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_37) {
  char str[255] = "asin(5)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(isnan(result) > 0, 1);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_38) {
  char str[255] = "acos(-5)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(isnan(result) > 0, 1);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_39) {
  char str[255] = "x+5";
  double answer = 10;
  double result = 0;
  int error = s21_smartcalc(str, 5, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_40) {
  char str[255] = "x*3";
  double answer = 15;
  double result = 0;
  int error = s21_smartcalc(str, 5, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_41) {
  char str[255] = "x/2";
  double answer = 2.5;
  double result = 0;
  int error = s21_smartcalc(str, 5, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_42) {
  char str[255] = "xmod1.5";
  double answer = 0.5;
  double result = 0;
  int error = s21_smartcalc(str, 5, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_43) {
  char str[255] = "sin(cos(2))";
  double answer = -0.404239;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_44) {
  char str[255] = "ln(2)+ln(3)-4+(5*6)^3.2+sin(10)";
  double answer = 53304.710856;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_45) {
  char str[255] = "5-3*2^4+5*(2.2*4.3)^2.1*5";
  double answer = 2757.988947;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_46) {
  char str[255] = "asin(0.1)^(2+0.5)*3-1";
  double answer = -0.990473;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_47) {
  char str[255] = "acos(2)";
  double answer = 0;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(isnan(result) > 0, 1);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_48) {
  char str[255] = "acoa(2)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_49) {
  char str[255] = "mad(2)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_50) {
  char str[255] = "2acos(2)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_51) {
  char str[255] = "(*1 + 2 * acos(2))";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_52) {
  char str[255] = "(1 + 2 + z * acos(2))";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_53) {
  char str[255] = "lon(2)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_54) {
  char str[255] = "2+ sqort(66)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_55) {
  char str[255] = "2+ 2maz3";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_56) {
  char str[255] = "2+ asim(77)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_57) {
  char str[255] = "ln()";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_58) {
  char str[255] = "2.acos(2)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_59) {
  char str[255] =
      "tan(cos(sin(1 mod 2 mod 3) ^ 5) * sqrt(--5))  + 45 * 234.768";
  double answer = 10562.58750046;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_60) {
  char str[255] = "2x";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_61) {
  char str[255] = "2+(5+6))";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_62) {
  char str[255] = "2+((5+6)";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_63) {
  char str[255] =
      "sin(cos(sin(cos(sin(cos(sin(cos(sin(cos(sin(cos(10))))))))))))";
  double answer = 0.693770667;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_64) {
  char str[255] = "-(5)";
  double answer = -5;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_65) {
  char str[255] = "-(-1)";
  double answer = 1;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_66) {
  char str[255] = "-x";
  double answer = -10;
  double result = 0;
  int error = s21_smartcalc(str, 10, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_67) {
  char str[255] = "-(--x)";
  double answer = -10;
  double result = 0;
  int error = s21_smartcalc(str, 10, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_68) {
  char str[255] = "x2";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_69) {
  char str[255] = "-(--cos(x))";
  double answer = -1;
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_double_eq_tol(answer, result, EPS);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(smart_calc_test_70) {
  char str[255] = "3..3";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(smart_calc_test_71) {
  char str[255] = "xxx";
  double result = 0;
  int error = s21_smartcalc(str, 0, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST

Suite *smart_calc_test(void) {
  Suite *s = suite_create("s21_smart");
  TCase *tc = tcase_create("s21_smart_case");
  tcase_add_test(tc, smart_calc_test_1);
  tcase_add_test(tc, smart_calc_test_2);
  tcase_add_test(tc, smart_calc_test_3);
  tcase_add_test(tc, smart_calc_test_4);
  tcase_add_test(tc, smart_calc_test_5);
  tcase_add_test(tc, smart_calc_test_6);
  tcase_add_test(tc, smart_calc_test_7);
  tcase_add_test(tc, smart_calc_test_8);
  tcase_add_test(tc, smart_calc_test_9);
  tcase_add_test(tc, smart_calc_test_10);
  tcase_add_test(tc, smart_calc_test_11);
  tcase_add_test(tc, smart_calc_test_12);
  tcase_add_test(tc, smart_calc_test_13);
  tcase_add_test(tc, smart_calc_test_14);
  tcase_add_test(tc, smart_calc_test_15);
  tcase_add_test(tc, smart_calc_test_16);
  tcase_add_test(tc, smart_calc_test_17);
  tcase_add_test(tc, smart_calc_test_18);
  tcase_add_test(tc, smart_calc_test_19);
  tcase_add_test(tc, smart_calc_test_20);
  tcase_add_test(tc, smart_calc_test_21);
  tcase_add_test(tc, smart_calc_test_22);
  tcase_add_test(tc, smart_calc_test_23);
  tcase_add_test(tc, smart_calc_test_24);
  tcase_add_test(tc, smart_calc_test_25);
  tcase_add_test(tc, smart_calc_test_26);
  tcase_add_test(tc, smart_calc_test_27);
  tcase_add_test(tc, smart_calc_test_28);
  tcase_add_test(tc, smart_calc_test_29);
  tcase_add_test(tc, smart_calc_test_30);
  tcase_add_test(tc, smart_calc_test_31);
  tcase_add_test(tc, smart_calc_test_32);
  tcase_add_test(tc, smart_calc_test_33);
  tcase_add_test(tc, smart_calc_test_34);
  tcase_add_test(tc, smart_calc_test_35);
  tcase_add_test(tc, smart_calc_test_36);
  tcase_add_test(tc, smart_calc_test_37);
  tcase_add_test(tc, smart_calc_test_38);
  tcase_add_test(tc, smart_calc_test_39);
  tcase_add_test(tc, smart_calc_test_40);
  tcase_add_test(tc, smart_calc_test_41);
  tcase_add_test(tc, smart_calc_test_42);
  tcase_add_test(tc, smart_calc_test_43);
  tcase_add_test(tc, smart_calc_test_44);
  tcase_add_test(tc, smart_calc_test_45);
  tcase_add_test(tc, smart_calc_test_46);
  tcase_add_test(tc, smart_calc_test_47);
  tcase_add_test(tc, smart_calc_test_48);
  tcase_add_test(tc, smart_calc_test_49);
  tcase_add_test(tc, smart_calc_test_50);
  tcase_add_test(tc, smart_calc_test_51);
  tcase_add_test(tc, smart_calc_test_52);
  tcase_add_test(tc, smart_calc_test_53);
  tcase_add_test(tc, smart_calc_test_54);
  tcase_add_test(tc, smart_calc_test_55);
  tcase_add_test(tc, smart_calc_test_56);
  tcase_add_test(tc, smart_calc_test_57);
  tcase_add_test(tc, smart_calc_test_58);
  tcase_add_test(tc, smart_calc_test_59);
  tcase_add_test(tc, smart_calc_test_60);
  tcase_add_test(tc, smart_calc_test_61);
  tcase_add_test(tc, smart_calc_test_62);
  tcase_add_test(tc, smart_calc_test_63);
  tcase_add_test(tc, smart_calc_test_64);
  tcase_add_test(tc, smart_calc_test_65);
  tcase_add_test(tc, smart_calc_test_66);
  tcase_add_test(tc, smart_calc_test_67);
  tcase_add_test(tc, smart_calc_test_68);
  tcase_add_test(tc, smart_calc_test_69);
  tcase_add_test(tc, smart_calc_test_70);
  tcase_add_test(tc, smart_calc_test_71);
  suite_add_tcase(s, tc);
  return s;
}
