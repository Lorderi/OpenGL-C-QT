#include <QApplication>
#include <QMessageBox>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
  try {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
  } catch (const std::exception& e) {
    QMessageBox::critical(nullptr, "Error", e.what());
    return -1;
  }
}
