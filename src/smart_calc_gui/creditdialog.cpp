#include "creditdialog.h"

#include <QMessageBox>

#include "ui_creditdialog.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../smart_calc_src/s21_credit_calc/s21_credit_calc.h"
#ifdef __cplusplus
};
#endif

CreditDialog::CreditDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreditDialog) {
  ui->setupUi(this);
  ui->type_1->setChecked(true);
  ui->type_0->setChecked(false);
  ui->line_sum->setValidator(
      new QRegularExpressionValidator(QRegularExpression("^[0-9]+[.]?[0-9]*")));
  ui->line_percent->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^([1][0][0]|[1-9][0-9]|[0-9])")));
  ui->line_term->setValidator(
      new QRegularExpressionValidator(QRegularExpression("^[0-9]+")));
}

CreditDialog::~CreditDialog() { delete ui; }

void CreditDialog::on_btn_clicked() {
  double payment = 0;
  double overpayment = 0;
  double general = 0;
  double sum =
      !ui->line_sum->text().isEmpty() ? ui->line_sum->text().toDouble() : 0;
  int term =
      !ui->line_term->text().isEmpty() ? ui->line_term->text().toInt() : 0;
  double percent = !ui->line_percent->text().isEmpty()
                       ? ui->line_percent->text().toDouble()
                       : 0;
  int type = ui->type_1->isChecked() && !ui->type_0->isChecked();
  int term_type = !ui->comboBox->currentIndex();
  int error = s21_credit_calc(sum, term, term_type, percent, type, &payment,
                              &overpayment, &general);
  if (error) {
    QMessageBox msg = QMessageBox();
    msg.setText("Введены некоректные данные");
    msg.setWindowTitle("ОШИБКА!!!");
    msg.setIcon(QMessageBox::Critical);
    msg.setStandardButtons(QMessageBox::Close);
    msg.setDefaultButton(QMessageBox::Close);
    msg.button(QMessageBox::Close)
        ->setStyleSheet(
            "color: white;font:\"Helvetica\"; background-color: "
            "#fe9402;border-radius: 5px;");
    msg.button(QMessageBox::Close)->setMinimumSize(100, 20);
    msg.button(QMessageBox::Close)->setMaximumSize(100, 20);
    msg.button(QMessageBox::Close)->setText("Закрыть");
    msg.setStyleSheet("background-color: black; color: white;");
    msg.exec();
  } else {
    ui->text_payment->setText(QString::number(payment));
    ui->text_overplay->setText(QString::number(overpayment));
    ui->text_general->setText(QString::number(general));
  }
}
