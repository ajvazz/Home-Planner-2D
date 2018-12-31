#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>

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

/* Necessary for QGraphicsItem casting */
int Furniture::type() const {
    return Type;
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

QRectF Furniture::boundingRect() const {
    return QRectF(0,0, m_width, m_height);
}

void Furniture::keyPressEvent(QKeyEvent *event)
{
    /*
     * SHIFT makes every transformation action 'bigger'
     * Rotation + SHIFT = 90 deg, else 5 deg
     * Translation + SHIFT = 10px, else 2px
     */
    bool shiftPressed = event->modifiers() & Qt::ShiftModifier;

    switch ( event->key() )
    {
        /* Moving */
        case Qt::Key_Right:
            if (shiftPressed)
                move(10, 0);
            else
                move(2, 0);
            break;

        case Qt::Key_Left:
            if (shiftPressed)
                move(-10, 0);
            else
                move(-2, 0);
            break;

        case Qt::Key_Up:
            if (shiftPressed)
                move(0, -10);
            else
                move(0, -2);
            break;

        case Qt::Key_Down:
            if (shiftPressed)
                move(0, 10);
            else
                move(0, 2);
            break;

        /* Rotating */
        case Qt::Key_R:
            if (shiftPressed)
                rotate(90);
            else
                rotate(5);
            break;

        case Qt::Key_E:
            if (shiftPressed)
                rotate(-90);
            else
                rotate(-5);
            break;

        /* Deleting */
        case Qt::Key_Delete:
            /* BUG - this deletes only the last selected item.
             * Use button to delete all */
            delete this;
            break;
    }

    update();   // Apparently unnecessary?
}

void Furniture::move(qreal x, qreal y)
{
    moveBy(x, y);
}

void Furniture::rotate(qreal angleParam)
{
    setTransformOriginPoint(m_width/2, m_height/2);
    angle += angleParam;
    setRotation(angle);
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
