#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>

#include <QtDebug>
#include "../headers/furniture.hpp"

Furniture::Furniture(QString urlPath, int width, int height, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_width(width), m_height(height), m_urlPath(urlPath)
{
    setFlags(ItemIsMovable | ItemIsFocusable | ItemIsSelectable);
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
    switch ( event->key() )
    {
        /* Moving */
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

        /* Rotating */
        case Qt::Key_R:

            setTransformOriginPoint(m_width/2, m_height/2);

            /* If SHIFT is pressed, rotate 90 degrees, else normal */
            if (event->modifiers() & Qt::ShiftModifier) {
                angle += 90;
                setRotation(angle);
            } else {
                angle += 5;
                setRotation(angle);
            }

            break;

        case Qt::Key_E:

            setTransformOriginPoint(m_width/2, m_height/2);

            /* If SHIFT is pressed, rotate 90 degrees, else normal */
            if (event->modifiers() & Qt::ShiftModifier) {
                angle -= 90;
                setRotation(angle);
            } else {
                angle -= 5;
                setRotation(angle);
            }

            break;

        /* Deleting */
        case Qt::Key_Delete:
            delete this;
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
