#include "cstorybubble.h"

#include <QPainterPath>
#include <QTextDocument>

#include <QDebug>


CStoryBubble::CStoryBubble(QMenu *contextMenu, QGraphicsItem *parent)
    : CBubble(contextMenu, parent), m_order(0), m_locked(false), m_color(QColor(255,255,255)), m_properties(0)
{
    setShape();

    QRectF bounds(boundingRect().x() + 10, boundingRect().y() + 20, boundingRect().width() - 20, boundingRect().height() - 40);
    QRectF tbounds(boundingRect().x() + 10, boundingRect().y() + 10, boundingRect().width() - 20, 20);

    m_title = new CTextItem("Story", tbounds, this);
    m_title->setFlag(QGraphicsItem::ItemIsMovable, false);
    m_title->setFlag(QGraphicsItem::ItemIsSelectable, false);

    m_story = new CTextItem("Hello world an all who inhabit it, yes that means you", bounds, this);
    m_story->setFlag(QGraphicsItem::ItemIsMovable, false);
    m_story->setFlag(QGraphicsItem::ItemIsSelectable, false);
//    m_story->setX(m_story->x() + 20);
//    m_story->setY(m_story->y() + 20);

    update();
    show();
}


void CStoryBubble::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *evt)
{
    QGraphicsItem::mouseDoubleClickEvent(evt);

    m_properties = new PropStoryBubble(m_title->Text(), m_story->Text(), m_order, m_locked, m_color);
    connect(m_properties, SIGNAL(accepted()), this, SLOT(PropertiesAccepted()));
    m_properties->show();
}

void CStoryBubble::PropertiesAccepted()
{
    if(m_properties)
    {
        qDebug << m_properties->Title().toStdString().c_str();
    }

    m_properties = NULL;
}


QVariant CStoryBubble::itemChange(GraphicsItemChange change, const QVariant &value)
{
    CBubble::itemChange(change, value);

    if (change == QGraphicsItem::ItemPositionChange)
    {

    }

    return value;
}


void CStoryBubble::setShape()
{
    QPainterPath path;
    path.addRoundedRect(-100,-100,200,200,20,20);
    m_polygon = path.toFillPolygon();
//    path.moveTo(-100, -90);
//    path.arcTo(-90, -100, 10, 10, 90, 90);
//    path.lineTo(90, -100);
//    path.arcTo(100, -90, 10, 10, 0, 90);
//    path.lineTo(100, 90);
//    path.arcTo(90, 50, 50, 50, 180, 90);
//    path.arcTo(150, 50, 50, 50, 270, 90);
//    path.lineTo(200, 25);

//    m_polygon << QPointF(-100, -100) << QPointF(100, -100)
//              << QPointF(100, 100) << QPointF(-100, 100)
//              << QPointF(-100, -100);

    setPolygon(m_polygon);
}
