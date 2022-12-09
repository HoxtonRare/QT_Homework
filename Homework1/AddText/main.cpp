#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QTextEdit txt;

    txt.setHtml("<font color='red'>Hello</font>");
    w.show();
    return a.exec();
}
