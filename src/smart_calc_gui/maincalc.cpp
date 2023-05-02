#include "maincalc.h"

#include "./ui_maincalc.h"
#include "creditdialog.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "../smart_calc_src/s21_smartcalc/s21_smartcalc.h"
#ifdef __cplusplus
};
#endif

MainCalc::MainCalc(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainCalc) {
  ui->setupUi(this);
  ui->text->setAlignment(Qt::AlignRight | Qt::AlignCenter);

  ui->plot->setBackground(QColor("#212121"));

  ui->plot->yAxis->setRange(y_s - s / 2.0, y_s + s / 2.0);
  ui->plot->yAxis->setBasePen(QPen(Qt::white));
  ui->plot->yAxis->setTickPen(QPen(Qt::white));
  ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
  ui->plot->yAxis->setTickLabelColor(Qt::white);
  ui->plot->yAxis->setLabelColor(Qt::white);
  ui->plot->yAxis->grid()->setPen(QPen(Qt::white, 0, Qt::SolidLine));
  ui->plot->yAxis->grid()->setSubGridPen(QPen(Qt::white, 0, Qt::DotLine));

  ui->plot->xAxis->setRange(x_s - s / 2.0, x_s + s / 2.0);
  ui->plot->xAxis->setBasePen(QPen(Qt::white));
  ui->plot->xAxis->setTickPen(QPen(Qt::white));
  ui->plot->xAxis->setSubTickPen(QPen(Qt::white));
  ui->plot->xAxis->setTickLabelColor(Qt::white);
  ui->plot->xAxis->setLabelColor(Qt::white);
  ui->plot->xAxis->grid()->setPen(QPen(Qt::white, 0, Qt::SolidLine));
  ui->plot->xAxis->grid()->setSubGridPen(QPen(Qt::white, 0, Qt::DotLine));

  ui->plot->addGraph();

  validator_num = new QRegularExpressionValidator(
      QRegularExpression("^[-+]?[0-9]+[.]?[0-9]*"));
  ui->text_x->setValidator(validator_num);
  ui->line_x_s->setValidator(validator_num);
  ui->line_y_s->setValidator(validator_num);
  ui->line_s->setValidator(validator_num);

  ui->line_s->setPlaceholderText(QString::number(s));
  ui->line_x_s->setPlaceholderText(QString::number(x_s));
  ui->line_y_s->setPlaceholderText(QString::number(y_s));
}

MainCalc::~MainCalc() { delete ui; }

void MainCalc::on_bt_1_clicked() {
  QString str = ui->text->text();
  str.append('1');
  ui->text->setText(str);
}

void MainCalc::on_bt_2_clicked() {
  QString str = ui->text->text();
  str.append('2');
  ui->text->setText(str);
}

void MainCalc::on_bt_3_clicked() {
  QString str = ui->text->text();
  str.append('3');
  ui->text->setText(str);
}

void MainCalc::on_bt_4_clicked() {
  QString str = ui->text->text();
  str.append('4');
  ui->text->setText(str);
}

void MainCalc::on_bt_5_clicked() {
  QString str = ui->text->text();
  str.append('5');
  ui->text->setText(str);
}

void MainCalc::on_bt_6_clicked() {
  QString str = ui->text->text();
  str.append('6');
  ui->text->setText(str);
}

void MainCalc::on_bt_7_clicked() {
  QString str = ui->text->text();
  str.append('7');
  ui->text->setText(str);
}

void MainCalc::on_bt_8_clicked() {
  QString str = ui->text->text();
  str.append('8');
  ui->text->setText(str);
}

void MainCalc::on_bt_9_clicked() {
  QString str = ui->text->text();
  str.append('9');
  ui->text->setText(str);
}

void MainCalc::on_bt_0_clicked() {
  QString str = ui->text->text();
  str.append('0');
  ui->text->setText(str);
}

void MainCalc::on_bt_dot_clicked() {
  QString str = ui->text->text();
  str.append('.');
  ui->text->setText(str);
}

void MainCalc::on_bt_div_clicked() {
  QString str = ui->text->text();
  str.append('/');
  ui->text->setText(str);
}

void MainCalc::on_bt_mul_clicked() {
  QString str = ui->text->text();
  str.append('*');
  ui->text->setText(str);
}

void MainCalc::on_bt_min_clicked() {
  QString str = ui->text->text();
  str.append('-');
  ui->text->setText(str);
}

void MainCalc::on_bt_plus_clicked() {
  QString str = ui->text->text();
  str.append('+');
  ui->text->setText(str);
}

void MainCalc::on_bt_mod_clicked() {
  QString str = ui->text->text();
  str.append("mod");
  ui->text->setText(str);
}

void MainCalc::on_bt_cos_clicked() {
  QString str = ui->text->text();
  str.append("cos(");
  ui->text->setText(str);
}

void MainCalc::on_bt_acos_clicked() {
  QString str = ui->text->text();
  str.append("acos(");
  ui->text->setText(str);
}

void MainCalc::on_bt_asin_clicked() {
  QString str = ui->text->text();
  str.append("asin(");
  ui->text->setText(str);
}

void MainCalc::on_bt_sin_clicked() {
  QString str = ui->text->text();
  str.append("sin(");
  ui->text->setText(str);
}

void MainCalc::on_bt_atan_clicked() {
  QString str = ui->text->text();
  str.append("atan(");
  ui->text->setText(str);
}

void MainCalc::on_bt_tan_clicked() {
  QString str = ui->text->text();
  str.append("tan(");
  ui->text->setText(str);
}

void MainCalc::on_bt_sqrt_clicked() {
  QString str = ui->text->text();
  str.append("sqrt(");
  ui->text->setText(str);
}

void MainCalc::on_bt_ln_clicked() {
  QString str = ui->text->text();
  str.append("ln(");
  ui->text->setText(str);
}

void MainCalc::on_bt_log_clicked() {
  QString str = ui->text->text();
  str.append("log(");
  ui->text->setText(str);
}

void MainCalc::on_bt_pow_clicked() {
  QString str = ui->text->text();
  str.append('^');
  ui->text->setText(str);
}

void MainCalc::on_bt_op_brack_clicked() {
  QString str = ui->text->text();
  str.append('(');
  ui->text->setText(str);
}

void MainCalc::on_bt_cl_brack_clicked() {
  QString str = ui->text->text();
  str.append(')');
  ui->text->setText(str);
}

void MainCalc::on_pushButton_clicked() {
  QString str = ui->text->text();
  str.append('x');
  ui->text->setText(str);
}

void MainCalc::on_bt_AC_clicked() { ui->text->setText(""); }

void MainCalc::on_bt_eq_clicked() {
  QString tmp = ui->text->text();
  double x = !ui->text_x->displayText().isEmpty()
                 ? ui->text_x->displayText().toDouble()
                 : 0;
  double y = 0;
  int error = s21_smartcalc(tmp.toUtf8().data(), x, &y);
  if (!error) {
    ui->text->setText(QString::number(y));
  } else {
    ui->statusbar->showMessage("Ошибка!!!", 5000);
    ui->text->setText("");
  }
}

void MainCalc::on_bt_graph_clicked() {
  expression = ui->text->text();
  MainCalc::dataCalc();
}

void MainCalc::on_bt_del_clicked() {
  QString str = ui->text->text();
  str.chop(1);
  ui->text->setText(str);
}

void MainCalc::on_btn_s_clicked() {
  x_s = !ui->line_x_s->displayText().isEmpty()
            ? ui->line_x_s->displayText().toDouble()
            : x_s;
  y_s = !ui->line_y_s->displayText().isEmpty()
            ? ui->line_y_s->displayText().toDouble()
            : y_s;
  s = !ui->line_s->displayText().isEmpty()
          ? ui->line_s->displayText().toDouble()
          : s;
  ui->plot->yAxis->setRange(y_s - s / 2.0, y_s + s / 2.0);
  ui->plot->xAxis->setRange(x_s - s / 2.0, x_s + s / 2.0);
  ui->line_s->setPlaceholderText(QString::number(s));
  ui->line_x_s->setPlaceholderText(QString::number(x_s));
  ui->line_y_s->setPlaceholderText(QString::number(y_s));
  if (expression.isEmpty()) {
    ui->plot->replot();
  } else {
    MainCalc::dataCalc();
  }
}

void MainCalc::dataCalc() {
  int count = 100000;
  int error = 0;
  double x_t = x_s - s / 2.0;
  QVector<double> x(count), y(count);
  for (int i = 0; i < count; i++) {
    x_t += (double)s / (double)count;
    x[i] = x_t;
    error = s21_smartcalc(expression.toUtf8().data(), x[i], &y[i]);
    if (error) {
      ui->statusbar->showMessage("Ошибка!!!", 5000);
      ui->text->setText("");
      break;
    }
  }
  if (!error) {
    ui->plot->graph(0)->setData(x, y);
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->plot->graph(0)->setPen(QPen(Qt::white, 0.5));
    ui->plot->replot();
  }
}

void MainCalc::on_action_triggered() {
  CreditDialog creditWindow;
  creditWindow.setModal(true);
  creditWindow.setFixedSize(460, 405);
  creditWindow.setWindowTitle("Кредитный калькулятор");
  creditWindow.exec();
}
