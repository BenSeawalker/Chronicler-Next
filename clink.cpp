#include "clink.h"



CLink::CLink(QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent), m_hover(false), m_direction(Down), m_scale(1)
{
    UpdateShape();
    setAcceptHoverEvents(true);
    
    connect(this, SIGNAL(scaleChanged()), this, SLOT(updateScale()));
    m_anim = new QPropertyAnimation(this, "scale", this);
    m_anim->setDuration(100);
}

void CLink::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    m_anim->stop();
    m_anim->setEndValue(1.5);
    m_anim->start();
    
    m_hover = true;
    UpdateShape();
}

void CLink::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    m_anim->stop();
    m_anim->setEndValue(1);
    m_anim->start();
    
    m_hover = false;
    UpdateShape();
}

void CLink::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen outline = (isSelected() ? QPen(QColor(255,200,0), 2) : QPen(m_lineColor, 1.5));
    painter->setPen(outline);
    painter->setBrush(QBrush(m_color));
    painter->drawPolygon(m_polygon, Qt::WindingFill);
}

void CLink::UpdateShape()
{
    QRectF b = QRectF(-10 * m_scale, 0, 20 * m_scale, 15 * m_scale);//(m_hover ? QRectF(-12, 0, 24, 20) : QRectF(-10, 0, 20, 15));//
    QPainterPath path;
    path.moveTo(b.x() + b.width(), b.y());
    path.lineTo(b.x(), b.y());
    path.arcTo(b, 90 * int(m_direction - 1), 180);
    
    m_polygon = path.toFillPolygon();
    setPolygon(m_polygon);
}
