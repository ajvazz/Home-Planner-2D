#ifndef ROOM_HPP
#define ROOM_HPP

#include <QGraphicsItem>
#include <QPen>

class Room : public QGraphicsItem
{
public:
    Room(int width, int height, QString urlPath);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;

    void setFloorPath(QString urlP);
    QString floorPath() const;
    void rotate(qreal angleParam);

private:
    qreal angle;
    int m_width;
    int m_height;
    QPen m_pen;
    QString m_urlPath;
};

#endif // ROOM_HPP
