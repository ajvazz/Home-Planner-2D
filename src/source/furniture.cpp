#include <QtGui>

#include "../headers/furniture.hpp"

Furniture::Furniture(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    // Testing...
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Furniture::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Testing...
    painter->drawPixmap(0,0,25,25, QPixmap(":/img/furniture/armchairs/armchair_1_green.png"));
}

QRectF Furniture::boundingRect() const
{
    // Testing...
    return QRectF(0,0, 25,25);
}

void Furniture::keyPressEvent(QKeyEvent *event)
{
    // Testing...
    switch (event->key())
    {
        case Qt::Key_Right:
            moveBy(10, 0);
            break;
        case Qt::Key_Left:
            moveBy(-10, 0);
            break;
        case Qt::Key_Up:
            moveBy(0, -10);
            break;
        case Qt::Key_Down:
            moveBy(0, 10);
            break;
    }
    update();
}
