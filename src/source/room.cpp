#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>

#include "../headers/room.hpp"

Room::Room(double width, double height, QString urlPath)
    : m_width(width), m_height(height), m_urlPath(urlPath)
{
    setFlags(ItemIsMovable | ItemIsFocusable | ItemIsSelectable);

    angle = 0;
    numberRooms++;

    /* Setting position of room to center of scene (screen) */
    int screenWidth  = QApplication::desktop()->width();
    int screenHeight = QApplication::desktop()->height();
    setPos(screenWidth/3, screenHeight/3);
}

Room::~Room()
{
    numberRooms--;
//    QGraphicsItem::~QGraphicsItem();
}

/* Initialization of a static variable */
int Room::numberRooms= 0;

double Room::getArea() const
{
    /* Dividing by 33 because 1m equals 33px */
    return m_width * m_height / (33 * 33);
}

void Room::setFloorPath(QString urlP)
{
    this->m_urlPath = urlP;
}

/* Unnecessary function, never used */
QString Room::floorPath() const
{
    return m_urlPath;
}

void Room::rotate(qreal angleParam)
{
    /* Rotation origin point needs to be moved to the center of the object */
    setTransformOriginPoint(m_width/2, m_height/2);
    angle += angleParam;
    setRotation(angle);
}

void Room::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);

    /* If room is selected, draw green outline around its boundingRect */
    if (isSelected()) {
        painter->setPen(m_pen);
        m_pen.setWidth(1);
        m_pen.setColor(Qt::green);
        painter->drawRect(boundingRect());
    }

    /* Is floor texture selected or not ? */
    if (m_urlPath.isEmpty()) {
        /* Default grey floor */
        QColor *myColor = new QColor(175, 175, 175, 255);
        painter->fillRect(boundingRect(), myColor->rgb());
    }
    else {
        /* The user has chosen a floor texture, setFloorPath has been set
         * with an appropriate path, now it is not empty and can be drawn */

        /* Instead of fixed values for scale, this could be parametrized.
         * This may be a reason why some textures are low resolution. */
        QBrush brush(QPixmap(m_urlPath).scaled(35, 35));
        painter->setBrush(brush);
        painter->drawRect(boundingRect());
    }

    /* m_width and m_height are doubles, need to be int */
    painter->drawRect(0, 0, static_cast<int>(m_width), static_cast<int>(m_height) );
}

QRectF Room::boundingRect() const
{
    return QRectF(0,0, m_width, m_height);
}

void Room::keyPressEvent(QKeyEvent *event)
{
    /* Translation + SHIFT = 10px, else 1px */
    bool shiftPressed = event->modifiers() & Qt::ShiftModifier;

    switch ( event->key() )
    {
        /* Moving */
        case Qt::Key_Right:
            if (shiftPressed)
                moveBy(5, 0);
            else
                moveBy(1, 0);
            break;

        case Qt::Key_Left:
            if (shiftPressed)
                moveBy(-5, 0);
            else
                moveBy(-1, 0);
            break;

        case Qt::Key_Up:
            if (shiftPressed)
                moveBy(0, -5);
            else
                moveBy(0, -1);
            break;

        case Qt::Key_Down:
            if (shiftPressed)
                moveBy(0, 5);
            else
                moveBy(0, 1);
            break;
    }

    this->update();
}
