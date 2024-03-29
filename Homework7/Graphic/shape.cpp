#include "shape.h"

shape::shape(QObject *parent) : QObject(parent), QGraphicsItem()
{
    srand(clock());
    x = 0;
    y = 0;
    brush.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
    brush.setStyle(Qt::BrushStyle::SolidPattern); // Полностью закрашивать
    geometry = Geometry::RECTANGLE; // По умолчанию - прямоугольник
    setPos(0,0);
}

void shape::setGeometry(Geometry geom)
{
    geometry = geom;
}

QPointF shape::getBoundingRectCenter()
{
    return this->boundingRect().center();
}

void shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    QPolygon star;
    star << QPoint(x+0, y+85) << QPoint(x+75, y+75)
         << QPoint(x+100, y+10) << QPoint(x+125, y+75)
         << QPoint(x+200, y+85) << QPoint(x+150, y+125)
         << QPoint(x+160, y+190) << QPoint(x+100, y+150)
         << QPoint(x+40, y+190) << QPoint(x+50, y+125)
         << QPoint(x+0, y+85);

    if (geometry == Geometry::ELLIPS)
    {
        painter->drawEllipse(x, y, 200, 100);
    }
    if (geometry == Geometry::RECTANGLE)
    {
        painter->drawRect(x, y, 200, 100);
    }
    if (geometry == Geometry::STAR)
    {
        painter->drawPolygon(star);
    }

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF shape::boundingRect() const
{
    if(geometry == Geometry::STAR)
    {
        return QRectF(x, y, 200, 200);
    }
    return QRectF(x, y, 200, 100);
}

void shape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::MiddleButton)
    {
        this->setCursor(QCursor(Qt::PointingHandCursor));
        rotate = true;
    }
    else
    {
        this->setTransformOriginPoint(this->boundingRect().center());
        this->setCursor(QCursor(Qt::SizeAllCursor));
    }
}

void shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    rotate = false;
    Q_UNUSED(event);
}

void shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(rotate)
    {
        this->setTransformOriginPoint(this->boundingRect().center());
        this->setRotation(event->pos().ry() > 0 ?  this->rotation() + 1 : this->rotation() - 1);
    }
    else
    {
        this->setPos(mapToScene(event->pos() - this->boundingRect().center()));
    }
}
