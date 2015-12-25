#include "cstorybubble.h"

#include <QPainterPath>


CStoryBubble::CStoryBubble(QMenu *contextMenu, QGraphicsItem *parent)
    : CBubble(contextMenu, parent), m_properties(0), m_resize(false), m_minSize(QSizeF(150,150))
{
    setPolygon(QPolygonF(QRectF(-100,-100,200,200)));

    m_type = Story;

    m_color = QColor(150,150,255);

    m_title = new CTextItem("Story And a Half", QRectF(), this);
    m_title->SetStyle(Qt::AlignHCenter);

    m_story = new CTextItem("Hello world and all who inhabit it, yes that means you. Go on and believe that I'm not talking about you. But I indeed am, and there is nothing you can do to stop me from talking about you", QRectF(), this);
    m_story->SetStyle(Qt::TextWordWrap);

    setCursor(Qt::PointingHandCursor);
    setAcceptHoverEvents(true);

    setShape();
    show();
}

void CStoryBubble::mousePressEvent(QGraphicsSceneMouseEvent *evt)
{
    CBubble::mousePressEvent(evt);

    QRectF b = sceneBoundingRect();
    QRectF resizeRect(QPointF(b.x() + b.width() - 20, b.y() + b.height() - 20), QSizeF(20,20));

    if(resizeRect.contains(evt->scenePos()))
    {
        m_resize = true;
        m_offset = evt->scenePos();
        m_lastBounds = boundingRect();
    }
}

void CStoryBubble::mouseReleaseEvent(QGraphicsSceneMouseEvent *evt)
{
    CBubble::mouseReleaseEvent(evt);
    m_resize = false;
}

void CStoryBubble::mouseMoveEvent(QGraphicsSceneMouseEvent *evt)
{
    if(m_resize)
    {
        QPointF delta(evt->scenePos() - m_offset);
        // to update boundingRect....
        setPolygon(QRectF(m_lastBounds.x(), m_lastBounds.y(),
                          qMax<float>(m_lastBounds.width() + delta.x(), m_minSize.width()),
                          qMax<float>(m_lastBounds.height() + delta.y(), m_minSize.height())));
        setShape();
    }
    else
        CBubble::mouseMoveEvent(evt);
}

void CStoryBubble::hoverMoveEvent(QGraphicsSceneHoverEvent *evt)
{
    QRectF b = sceneBoundingRect();
    QRectF resizeRect(QPointF(b.x() + b.width() - 20, b.y() + b.height() - 20), QSizeF(20,20));

    if(resizeRect.contains(evt->scenePos()))
        setCursor(Qt::SizeFDiagCursor);
    else
        setCursor(Qt::PointingHandCursor);
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
        m_title->SetText(m_properties->Title());
        m_story->SetText(m_properties->Story());
        m_order = m_properties->Order();
        m_locked = m_properties->Locked();
        m_color = m_properties->Color();
    }

    m_properties = NULL;
}


QVariant CStoryBubble::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged && value.toBool())
        emit SelectedChanged(this);

    return CBubble::itemChange(change, value);
}


void CStoryBubble::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen outline = (isSelected() ? QPen(QColor(255,200,0), 2) : QPen(Qt::black, 1.5));
    painter->setPen(outline);
    painter->setBrush(QBrush(m_color));
    painter->drawPolygon(m_polygon, Qt::WindingFill);
}


void CStoryBubble::setShape()
{
    QRectF b = boundingRect();
    qreal th = m_title->textBounds().height() + 10.0f;
    qreal tm = b.width()*2/3;

    m_title->Resize(QRectF(b.x() + 10, b.y() + 2, tm - 20, th));
    m_story->Resize(QRectF(b.x() + 10, b.y() + th, b.width() - 20, b.height() - th - 2));
    if(m_title->textBounds().width() > m_title->boundingRect().width())
        m_title->SetStyle(Qt::AlignLeft);
    else
        m_title->SetStyle(Qt::AlignHCenter);

    QPainterPath path;
    path.setFillRule( Qt::WindingFill );
    path.addRoundedRect( QRectF(b.x(),b.y() + th, b.width(), b.height() - th ), 10, 10 );
    path.addRect( QRectF( b.x(), b.y() + th, b.width()*3/4, b.height()/2 ) ); // Top left corner not rounded
    path.addRect( QRectF( b.x() + b.width()/2, b.y() + b.height()/2, b.width()/2, b.height()/2 ) ); // Bottom right corner not rounded
    path.moveTo(b.x(), b.y() + th);
    path.lineTo(b.x() + 10, b.y());
    path.lineTo(b.x() + tm - 10, b.y());
    path.lineTo(b.x() + tm, b.y() + th);
    path = path.simplified();

    m_polygon = path.toFillPolygon();

    setPolygon(m_polygon);
}

void CStoryBubble::SetFont(const QFont &font)
{
    if(font != m_font)
    {
        m_font = font;
        m_title->SetFont(m_font);
        m_story->SetFont(m_font);
        setShape();
    }
}
