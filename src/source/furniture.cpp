#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsSceneMouseEvent>

#include "../headers/furniture.hpp"

Furniture::Furniture(QString urlPath, int width, int height, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_width(width), m_height(height), m_urlPath(urlPath)
{
    setFlags(ItemIsMovable | ItemIsFocusable | ItemIsSelectable);
    setAcceptHoverEvents(true);

    angle = 0;
    zValue = 0;
    m_isFlipped = false;
    numberFurniture++;

    /* Setting position to center of scene (screen) */
    int screenWidth  = QApplication::desktop()->width();
    int screenHeight = QApplication::desktop()->height();
    setPos(screenWidth/3, screenHeight/3);
}

Furniture::~Furniture()
{
    numberFurniture--;
//    QGraphicsItem::~QGraphicsItem();
}

/* Necessary for QGraphicsItem casting (not needed) */
int Furniture::type() const {
    return Type;
}

/* Initialization of a static variable */
int Furniture::numberFurniture = 0;

void Furniture::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);

    /* If furniture is selected, draw green outline around its boundingRect */
    if (isSelected()) {
        painter->setPen(m_pen);
        m_pen.setWidth(1);
        m_pen.setColor(Qt::green);
        painter->drawRect(boundingRect());
    }

    if (isFlipped())    // Draws a horizontally flipped image
        painter->drawPixmap(0,0, m_width, m_height,
                            QPixmap(m_urlPath).transformed(QTransform().scale(-1,1)));
    else
        painter->drawPixmap(0,0, m_width, m_height, QPixmap(m_urlPath));
}

QRectF Furniture::boundingRect() const {
    return QRectF(0,0, m_width, m_height);
}

void Furniture::keyPressEvent(QKeyEvent *event)
{
    /* Translation + SHIFT = 5px, else 1px */
    bool shiftPressed = event->modifiers() & Qt::ShiftModifier;

    switch ( event->key() )
    {
        /* Moving */
        case Qt::Key_Right:
            if (shiftPressed)
                move(5, 0);
            else
                move(1, 0);
            break;

        case Qt::Key_Left:
            if (shiftPressed)
                move(-5, 0);
            else
                move(-1, 0);
            break;

        case Qt::Key_Up:
            if (shiftPressed)
                move(0, -5);
            else
                move(0, -1);
            break;

        case Qt::Key_Down:
            if (shiftPressed)
                move(0, 5);
            else
                move(0, 1);
            break;

        /* Rotation + SHIFT = 90, else 5 */
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

        case Qt::Key_F:
            swapFlipped();
            break;

        case Qt::Key_Delete:
            delete this;
            break;
    }

    this->update();
}

/* We realized too late that this function is not necessary */
void Furniture::move(qreal x, qreal y)
{
    moveBy(x, y);
}

void Furniture::rotate(qreal angleParam)
{
    /* Rotation origin point needs to be moved to the center of the object */
    setTransformOriginPoint(m_width/2, m_height/2);
    angle += angleParam;
    setRotation(angle);
}

/* Never used, just for debugging */
bool Furniture::isFlipped() const
{
    return m_isFlipped;
}

void Furniture::swapFlipped()
{
    m_isFlipped = !m_isFlipped;
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
//    this->setZValue(1);     // Experimenting
}

void Furniture::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();
    //    this->setZValue(-1);    // Experimenting
}

void Furniture::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        zValue++;
        /* Constraining maximum depth of z-buffer to 5 */
        if (zValue > 5)
            zValue = 5;
    }

    else if (event->button() == Qt::RightButton) {
        zValue--;
        /* This negative value check is needed because if there is a room in the scene,
         * going negative will draw furniture UNDER the room. Other solution is to set
         * zValue of rooms to -50 e.g. This is easier. */
        if (zValue < 0)
            zValue = 0;
    }

    this->setZValue(zValue);
}
