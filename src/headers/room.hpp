#ifndef ROOM_HPP
#define ROOM_HPP

#include <QGraphicsItem>
#include <QPen>

class Room : public QGraphicsItem
{
public:
    Room(double width, double height, QString urlPath);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;

    QString floorPath() const;
    void setFloorPath(QString urlP);
    void rotate(qreal angleParam);

private:
    qreal angle;
    double m_width;
    double m_height;
    QPen m_pen;
    QString m_urlPath;
};

#endif // ROOM_HPP
