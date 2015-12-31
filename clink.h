#ifndef CLINK_H
#define CLINK_H

#include <QObject>
#include <QGraphicsPolygonItem>
#include <QPainterPath>
#include <QRectF>
#include <QPainter>
#include <QPropertyAnimation>


class CLink : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT
    Q_PROPERTY(qreal scale MEMBER m_scale NOTIFY scaleChanged)
public:
    enum Direction { Right, Up, Left, Down };
    
public:
    CLink(QGraphicsItem *parent = 0);
    
protected:
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
    
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    
private:
    void UpdateShape();
    
private:
    bool m_hover;
    QPolygonF m_polygon;
    QColor m_color;
    QColor m_lineColor;
    
    Direction m_direction;
    
    QPropertyAnimation *m_anim;
    qreal m_scale;
    
signals:
    void scaleChanged();
    
private slots:
    void updateScale() { UpdateShape(); }
};

#endif // CLINK_H
