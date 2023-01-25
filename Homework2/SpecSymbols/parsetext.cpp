#include "parsetext.h"
#include <QRegularExpression>
#include <QDebug>


ParseText::ParseText()
{
    text = " #@COP@ © #@PPM@ ‰ #@TDM@ ® #@EUR@ € #@RUB@ ₽";
    preText = "";
    key = "";
    value = "";
    QString::Iterator iter = text.begin();
    pos = 0;
    for (QString::Iterator i = text.begin(); i != text.end(); i++)
    {
        if (i->isSpace())
        {
            key = QString(iter, i - iter);
            value = *(i + 1);
            i += 2;
            iter = i + 1;
            tegsList.insert(key, value);
        }
    }
}

bool ParseText::change(QString istr)
{
    QRegularExpression regex("#@[A-Z]+@");
    pos = 0;
    bool chg = false;
    qint32 fnd = 0;
    preText = istr;
    auto i = regex.match(preText, pos);

    while(i.captured(0) != "")
    {
        if (tegsList.contains(i.captured(0)))
        {
            fnd = preText.indexOf(i.captured(0), pos);
            preText.remove(fnd, i.captured(0).size());
            preText.insert(fnd, tegsList[i.captured(0)]);
            pos = fnd;
            chg = true;
            i = regex.match(preText, pos);
            continue;
        }
        pos = preText.indexOf(i.captured(0), pos) + 2;
        i = regex.match(preText, pos);
    }
    pos = 0;

    while(i.captured(0) != "")
    {
        if (tegsList.contains(i.captured(0)))
        {
            fnd = preText.indexOf(i.captured(0), pos);
            preText.remove(fnd, i.captured(0).size());
            preText.insert(fnd, tegsList[i.captured(0)]);
            pos = fnd;
            chg = true;
            continue;
        }
        pos = preText.indexOf('.', pos) + 1;
    }
    return chg;
}

QString ParseText::getText()
{
    return preText;
}
