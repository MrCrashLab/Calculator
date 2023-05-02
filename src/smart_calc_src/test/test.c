#include <stdio.h>

#include "s21_calc_test.h"

int main(void) {
  int failed = 0;
  SRunner *runner;

  Suite *s_smart = smart_calc_test();
  Suite *s_credit = credit_calc_test();
  //   Suite *s_deposit = deposit_calc_test();

  runner = srunner_create(s_smart);
  srunner_add_suite(runner, s_credit);
  //   srunner_add_suite(runner, s_deposit);

  // srunner_run_all(runner, CK_NORMAL);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_ENV);

  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  printf("Количество ошибок: %d", failed);
  printf("\n");
}
