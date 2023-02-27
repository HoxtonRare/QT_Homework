#ifndef TASKS_H
#define TASKS_H

#include <QApplication>
#include <QObject>
#include <QDir>
#include <QFile>
#include <QFileDialog>

class Tasks : public QObject
{
    Q_OBJECT
public:
    explicit Tasks(QObject *parent = nullptr);
    virtual ~Tasks();
    Q_INVOKABLE void addTask(QString);
    Q_INVOKABLE void save_as();
    void open();
    Q_INVOKABLE int getNumOfTasks();

private:
    QWidget *widget;
    QString task;
    QFile file;
    int numOfTasks = 0;
    QString lastFile;
};

#endif // TASKS_H
