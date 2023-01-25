
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parseText = new ParseText();
    if (!parseText) close();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (parseText)
    {
        delete parseText;
        parseText = nullptr;
    }
}

void MainWindow::on_plainTextEdit_textChanged()
{
    QString str = ui->plainTextEdit->toPlainText();
    if (parseText->change(str))
    {
        ui->plainTextEdit->setPlainText(parseText->getText());
        QTextCursor cur(ui->plainTextEdit->textCursor());
        cur.setPosition(ui->plainTextEdit->toPlainText().size());
        ui->plainTextEdit->setTextCursor(cur);
    }
}

