#pragma once
#ifndef PARSETEXT_H
#define PARSETEXT_H
#include <QString>
#include <QMap>
class ParseText
{
public:
    ParseText();
    bool change(QString);
    QString getText();
private:
    QString text;
    QString preText;
    QMap<QString,QString> tegsList;
    QString key, value;
    qint32 pos;
};
#endif // PARSETEXT_H
