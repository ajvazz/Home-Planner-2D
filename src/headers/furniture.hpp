#ifndef FURNITURE_HPP
#define FURNITURE_HPP

#include <QGraphicsItem>

class Furniture : public QGraphicsItem
{
public:
    Furniture (QGraphicsItem *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;

    void keyPressEvent(QKeyEvent *event) override;
};

#endif // FURNITURE_HPP
