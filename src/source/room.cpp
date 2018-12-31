#include <QDebug>
#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>

#include "../headers/room.hpp"

Room::Room(int width, int height)
    : m_width(width), m_height(height)
{
    setFlags(ItemIsMovable | ItemIsFocusable | ItemIsSelectable);

    /* Setting position to center of scene (screen) */
    int screenWidth  = QApplication::desktop()->width();
    int screenHeight = QApplication::desktop()->height();
    setPos(screenWidth/3, screenHeight/3);

}

void Room::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);

    QColor *myColor = new QColor(71, 71, 71, 255);
    painter->drawRect(0, 0, m_width, m_height);
    painter->fillRect(boundingRect(), myColor->rgb());
}

QRectF Room::boundingRect() const
{
    return QRectF(0,0, m_width, m_height);
}
