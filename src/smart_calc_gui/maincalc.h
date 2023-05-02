#ifndef MAINCALC_H
#define MAINCALC_H

#include <QMainWindow>
#include <QRegularExpressionValidator>

#include "qcustomplot.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainCalc;
}
QT_END_NAMESPACE

class MainCalc : public QMainWindow {
  Q_OBJECT

 public:
  MainCalc(QWidget *parent = nullptr);
  ~MainCalc();

 private slots:
  void on_bt_1_clicked();

  void on_bt_2_clicked();

  void on_bt_3_clicked();

  void on_bt_4_clicked();

  void on_bt_5_clicked();

  void on_bt_6_clicked();

  void on_bt_7_clicked();

  void on_bt_8_clicked();

  void on_bt_9_clicked();

  void on_bt_0_clicked();

  void on_bt_dot_clicked();

  void on_bt_div_clicked();

  void on_bt_mul_clicked();

  void on_bt_min_clicked();

  void on_bt_plus_clicked();

  void on_bt_mod_clicked();

  void on_bt_cos_clicked();

  void on_bt_acos_clicked();

  void on_bt_asin_clicked();

  void on_bt_sin_clicked();

  void on_bt_atan_clicked();

  void on_bt_tan_clicked();

  void on_bt_sqrt_clicked();

  void on_bt_ln_clicked();

  void on_bt_log_clicked();

  void on_bt_pow_clicked();

  void on_bt_op_brack_clicked();

  void on_bt_cl_brack_clicked();

  void on_pushButton_clicked();

  void on_bt_AC_clicked();

  void on_bt_eq_clicked();

  void on_bt_graph_clicked();

  void on_bt_del_clicked();

  void on_btn_s_clicked();

  void on_action_triggered();

 private:
  Ui::MainCalc *ui;
  QString expression;
  QRegularExpressionValidator *validator_num;
  double x_s = 0;
  double y_s = 0;
  double s = 20;
  void dataCalc();
};
#endif  // MAINCALC_H
