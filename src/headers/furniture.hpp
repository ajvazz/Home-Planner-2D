#ifndef FURNITURE_HPP
#define FURNITURE_HPP

#include <QGraphicsItem>
#include <QPen>

class Furniture : public QGraphicsItem
{
public:
    Furniture (QString urlPath, int width, int height, QGraphicsItem *parent = nullptr);
    ~Furniture() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

    QRectF boundingRect() const override;
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

public:

    /* Necessary for QGraphicsItem casting */
    enum { Type = UserType + 1 };
    int type() const override;

    void move(qreal x, qreal y);
    void rotate(qreal angleParam);
    void swapFlipped();
    bool isFlipped() const;
    static int numberFurniture;     // Furniture counter

private:
    QPen m_pen;
    qreal angle;
    int m_width;
    int m_height;
    qreal zValue;
    bool m_isFlipped;
    QString m_urlPath;
};

#endif // FURNITURE_HPP
