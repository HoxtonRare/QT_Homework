#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList list {"C++", "Python", "Java", "C#", "PHP", "JavaScript"};
    model = new QStandardItemModel(list.size(),1,this);
    for(int i = 0; i <model->rowCount(); ++i)
    {
        QModelIndex index = model->index(i, 0);
        QString str = list[i];
        model->setData(index, str, Qt::DisplayRole);
        model->setData(index, QIcon("D:/icons/"+str+".png"), Qt::DecorationRole);
    }

    ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);
    ui->listView->setDragDropMode(QAbstractItemView::DragDrop);
    ui->listView->setDefaultDropAction(Qt::MoveAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString txt = QInputDialog::getText(this, tr("Ввод"), tr("Название языка:"), QLineEdit::Normal, "Default");
    model->insertRow(model->rowCount());
    QModelIndex index = model->index(model->rowCount() -1, 0);
    model->setData(index, txt, Qt::DisplayRole);
    model->setData(index, QIcon("D:/icons/Default.png"), Qt::DecorationRole);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->listView->selectionModel()->selectedIndexes().size())
    {
        model->removeRow(ui->listView->selectionModel()->selectedIndexes()[0].row());
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1)
    {
        ui->listView->setViewMode(QListView::IconMode);
    } else {
    ui->listView->setViewMode(QListView::ListMode);
    }
}
