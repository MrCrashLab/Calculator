#include "s21_credit_calc.h"

int s21_credit_calc(double sum, int term, int term_type, double percent,
                    int type, double* payment, double* overpayment,
                    double* general) {
  int flag = OK;
  (*payment) = 0;
  (*general) = 0;
  (*overpayment) = 0;
  if (sum <= 0 || term <= 0 || percent < 0 || percent > 100 || type < 0 ||
      type > 1 || term_type < 0 || term_type > 1) {
    flag = ERROR;
  } else {
    term = term_type ? term * 12 : term;
    if (type) {
      double tmp = (percent / (100 * 12));
      (*payment) = sum * (tmp) / (1 - pow(1 + tmp, -term));
      (*general) = (*payment) * (double)term;
    } else {
      double fsum = sum;
      double tmp = fsum / (double)term;
      for (int i = 0; i < term; i++) {
        double tmp2 = (fsum * (percent / 100.0)) / 12;
        (*general) += tmp + tmp2;
        fsum -= tmp;
      }

      (*payment) = (*general) / (double)term;
    }
    (*overpayment) = (*general) - sum;
  }
  return flag;
}