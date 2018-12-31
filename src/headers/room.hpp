#ifndef ROOM_HPP
#define ROOM_HPP

#include <QGraphicsItem>

class Room : public QGraphicsItem
{
public:
    Room(int width, int height);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;

private:
    int m_width;
    int m_height;
};

#endif // ROOM_HPP
