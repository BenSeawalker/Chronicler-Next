#include "cbubble.h"

#include "arrow.h"



CBubble::CBubble(QMenu *contextMenu, QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent), m_contextMenu(contextMenu), m_order(0), m_locked(false)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}


void CBubble::removeArrow(Arrow *arrow)
{
    int index = m_arrows.indexOf(arrow);

    if (index != -1)
        m_arrows.removeAt(index);
}


void CBubble::removeArrows()
{
    foreach (Arrow *arrow, m_arrows) {
        arrow->startItem()->removeArrow(arrow);
        arrow->endItem()->removeArrow(arrow);
        scene()->removeItem(arrow);
        delete arrow;
    }
}


void CBubble::addArrow(Arrow *arrow)
{
    m_arrows.append(arrow);
}


QPixmap CBubble::image() const
{
    QPixmap pixmap(250, 250);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
    painter.translate(125, 125);
    painter.drawPolyline(m_polygon);

    return pixmap;
}


void CBubble::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    scene()->clearSelection();
    setSelected(true);
    m_contextMenu->exec(event->screenPos());
}


QVariant CBubble::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange) {
        foreach (Arrow *arrow, m_arrows) {
            arrow->updatePosition();
        }
    }

    return value;
}
