#include <QApplication>
#include "MainWindow.h"
int main(int argc, char *argv[])
{
  QApplication a(argc,argv);
  MainWindow mw = MainWindow();
  mw.show();
  return a.exec();

}

