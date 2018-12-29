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

    void setRotation(qreal angle);  // <- Could be redundant
    void drawOutline();

private:
    QPen m_pen;
    qreal angle;
    int m_width;
    int m_height;
    QString m_urlPath;
};

#endif // FURNITURE_HPP
