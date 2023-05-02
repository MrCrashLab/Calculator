#ifndef CREDITDIALOG_H
#define CREDITDIALOG_H

#include <QDialog>
#include <QValidator>

namespace Ui {
class CreditDialog;
}

class CreditDialog : public QDialog {
  Q_OBJECT

 public:
  explicit CreditDialog(QWidget *parent = nullptr);
  ~CreditDialog();

 private slots:
  void on_btn_clicked();

 private:
  Ui::CreditDialog *ui;
};

#endif  // CREDITDIALOG_H
