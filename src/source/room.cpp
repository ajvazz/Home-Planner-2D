#include <QDebug>
#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>

#include "../headers/room.hpp"

Room::Room(int width, int height, QString urlPath)
    : m_width(width), m_height(height), m_urlPath(urlPath)
{
    setFlags(ItemIsMovable | ItemIsFocusable | ItemIsSelectable);

    /* Setting position to center of scene (screen) */
    int screenWidth  = QApplication::desktop()->width();
    int screenHeight = QApplication::desktop()->height();
    setPos(screenWidth/3, screenHeight/3);

}

void Room::setFloorPath(QString urlP)
{
    this->m_urlPath = urlP;
}

QString Room::floorPath() const
{
    return m_urlPath;
}

void Room::rotate(qreal angleParam)
{
    setTransformOriginPoint(m_width/2, m_height/2);
    angle += angleParam;
    setRotation(angle);
}

void Room::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);

    if (isSelected()) {
        painter->setPen(m_pen);
        m_pen.setWidth(3);
        m_pen.setColor(Qt::green);
        painter->drawRect(boundingRect());
    }

    if (m_urlPath.isEmpty()) {
        /* Default grey floor */
        QColor *myColor = new QColor(171, 171, 171, 255);
        painter->fillRect(boundingRect(), myColor->rgb());
    }
    else {

        /* The user has chosen a floor texture, setFloorPath has been set
         * with an appropriate path, now it is not empty and can be drawn */

        QBrush brush(QPixmap(m_urlPath).scaled(35, 35));
        painter->setBrush(brush);
        painter->drawRect(boundingRect());
    }

    painter->drawRect(0, 0, m_width, m_height);
}

QRectF Room::boundingRect() const
{
    return QRectF(0,0, m_width, m_height);
}
