#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    QString text = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit_2->moveCursor(QTextCursor::End);
    ui->plainTextEdit_2->insertPlainText(text);
    ui->plainTextEdit_2->moveCursor(QTextCursor::End);
}


void MainWindow::on_pushButton_2_pressed()
{
    QString text = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit_2->insertPlainText(text);
}


void MainWindow::on_pushButton_3_pressed()
{
   QTextEdit txt;
   txt.setHtml("<font color='red'>Hello</font>");
   txt.resize(320, 250);
   txt.show();
}


void MainWindow::on_pushButton_4_clicked()
{
    close();
}
