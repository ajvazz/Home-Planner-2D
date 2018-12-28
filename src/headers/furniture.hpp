#ifndef FURNITURE_HPP
#define FURNITURE_HPP

#include <QGraphicsItem>
#include <QPen>

class Furniture : public QGraphicsItem
{
public:
    Furniture (QString urlPath, int width, int height, QGraphicsItem *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    void setRotation(qreal angle);
    void drawOutline();

    /* Variables */

private:
    QPen m_pen;
    qreal angle;
    QString m_urlPath;
    int m_width;
    int m_height;
};

#endif // FURNITURE_HPP
