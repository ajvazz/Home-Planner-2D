#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>

#include <QtDebug>
#include "../headers/furniture.hpp"

Furniture::Furniture(QString urlPath, int width, int height, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_urlPath(urlPath), m_width(width), m_height(height)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable |
             QGraphicsItem::ItemIsSelectable);
    setAcceptHoverEvents(true);

    angle = 0;

    /* Setting position to center of scene (screen) */
    int screenWidth  = QApplication::desktop()->width();
    int screenHeight = QApplication::desktop()->height();
    setPos(screenWidth/3, screenHeight/3);
}

void Furniture::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);

    if (isSelected()) {
        painter->setPen(m_pen);
        m_pen.setWidth(2);
        m_pen.setColor(Qt::green);
        painter->drawRect(boundingRect());
    }

    painter->drawPixmap(0,0, m_width, m_height, QPixmap(m_urlPath));
}

QRectF Furniture::boundingRect() const
{
    return QRectF(0,0, m_width, m_height);
}

void Furniture::keyPressEvent(QKeyEvent *event)
{
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

void Furniture::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    this->setFocus();
}

void Furniture::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    QApplication::setOverrideCursor(Qt::PointingHandCursor);
}

void Furniture::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();
}

// Angle normalization is not needed, Qt already does that
void Furniture::setRotation(qreal angle)
{
    QGraphicsItem::setRotation(angle);
}
