#include "cstorybubble.h"

#include <QPainterPath>


CStoryBubble::CStoryBubble(QMenu *contextMenu, QGraphicsItem *parent)
    : CBubble(contextMenu, parent), m_properties(0), m_resize(false)
{
    setPolygon(QPolygonF(QRectF(-100,-100,200,200)));

    m_type = Story;

    m_color = QColor(124, 140, 230);//(106,116,163);//(106,136,213);//(150,150,255);

    m_title = new CTextItem("Story And a Half", QRectF(), this);
    m_title->SetStyle(Qt::AlignHCenter);

    QString s("Allow miles wound place the leave had. To sitting subject no improve studied limited. Ye indulgence unreserved connection alteration appearance my an astonished. Up as seen sent make he they of. Her raising and himself pasture believe females. Fancy she stuff after aware merit small his. Charmed esteems luckily age out. By an outlived insisted procured improved am. Paid hill fine ten now love even leaf. Supplied feelings mr of dissuade recurred no it offering honoured. Am of of in collecting devonshire favourable excellence. Her sixteen end ashamed cottage yet reached get hearing invited. Resources ourselves sweetness ye do no perfectly. Warmly warmth six one any wisdom. Family giving is pulled beauty chatty highly no. Blessing appetite domestic did mrs judgment rendered entirely. Highly indeed had garden not. Post no so what deal evil rent by real in. But her ready least set lived spite solid. September how men saw tolerably two behaviour arranging. She offices for highest and replied one venture pasture. Applauded no discovery in newspaper allowance am northward. Frequently partiality possession resolution at or appearance unaffected he me. Engaged its was evident pleased husband. Ye goodness felicity do disposal dwelling no. First am plate jokes to began of cause an scale. Subjects he prospect elegance followed no overcame possible it on. Looking started he up perhaps against. How remainder all additions get elsewhere resources. One missed shy wishes supply design answer formed. Prevent on present hastily passage an subject in be. Be happiness arranging so newspaper defective affection ye. Families blessing he in to no daughter. Do so written as raising parlors spirits mr elderly. Made late in of high left hold. Carried females of up highest calling. Limits marked led silent dining her she far. Sir but elegance marriage dwelling likewise position old pleasure men. Dissimilar themselves simplicity no of contrasted as. Delay great day hours men. Stuff front to do allow to asked he. Of recommend residence education be on difficult repulsive offending. Judge views had mirth table seems great him for her. Alone all happy asked begin fully stand own get. Excuse ye seeing result of we. See scale dried songs old may not. Promotion did disposing you household any instantly. Hills we do under times at first short an.");

    m_story = new CTextItem(s, QRectF(), this);
    m_story->SetStyle(Qt::TextWordWrap);

    setCursor(Qt::PointingHandCursor);
    setAcceptHoverEvents(true);

    setShape();
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

//void CStoryBubble::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *evt)
//{
//    QGraphicsItem::mouseDoubleClickEvent(evt);

//    m_properties = new PropStoryBubble(m_title->Text(), m_story->Text(), m_order, m_locked, m_color);
//    connect(m_properties, SIGNAL(accepted()), this, SLOT(PropertiesAccepted()));
//    m_properties->show();
//}

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

    delete m_properties;
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
    QPen outline = (isSelected() ? QPen(QColor(255,200,0), 2) : QPen(m_lineColor, 1.5));
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
    m_story->Resize(QRectF(b.x() + 10, b.y() + th + 10, b.width() - 20, b.height() - th - 12));
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

void CStoryBubble::SetFontColor(const QColor &color)
{
    if(color != m_fontColor)
    {
        m_fontColor = color;
        m_title->SetColor(m_fontColor);
        m_story->SetColor(m_fontColor);
    }
}

void CStoryBubble::SetColor(const QColor &color)
{
    if(color != m_color)
    {
        m_color = color;
        update();
    }
}

void CStoryBubble::SetLineColor(const QColor &color)
{
    if(color != m_lineColor)
    {
        m_lineColor = color;
        update();
    }
}
