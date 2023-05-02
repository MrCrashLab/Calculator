#include <QApplication>

#include "maincalc.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainCalc w;
  w.setFixedSize(1000, 500);
  w.setWindowTitle("Калькулятор");
  w.show();
  return a.exec();
}
