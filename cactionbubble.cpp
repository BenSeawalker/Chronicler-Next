#include "cactionbubble.h"

CActionBubble::CActionBubble(QMenu *contextMenu, QGraphicsItem *parent)
    : CBubble(contextMenu, parent)
{
    m_type = Action;

    m_color = QColor(131,118,166);

    m_text = new CTextItem("", QRectF(), this);

    setShape();
}


QVariant CActionBubble::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged && value.toBool())
        emit SelectedChanged(this);

    return CBubble::itemChange(change, value);
}


void CActionBubble::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen outline = (isSelected() ? QPen(QColor(255,200,0), 2) : QPen(m_lineColor, 1.5));
    painter->setPen(outline);
    painter->setBrush(QBrush(m_color));
    painter->drawPolygon(m_polygon, Qt::WindingFill);
}


void CActionBubble::setShape()
{
    //setPolygon(QPolygon(m_text->textBounds()));
    QRectF b = m_text->textBounds();
    b = QRectF(boundingRect().x(), boundingRect().y(), qMax<float>(b.width(), m_minSize.width()),
                                                       qMax<float>(b.height(), m_minSize.height()));

    m_text->Resize(b);

    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRoundedRect(b, 10, 10);
//    path.addRect( QRectF( b.x(), b.y() + th, b.width()*3/4, b.height()/2 ) ); // Top left corner not rounded
//    path.addRect( QRectF( b.x() + b.width()/2, b.y() + b.height()/2, b.width()/2, b.height()/2 ) ); // Bottom right corner not rounded
//    path.moveTo(b.x(), b.y() + th);
//    path.lineTo(b.x() + 10, b.y());
//    path.lineTo(b.x() + tm - 10, b.y());
//    path.lineTo(b.x() + tm, b.y() + th);
//    path = path.simplified();

    m_polygon = path.toFillPolygon();

    setPolygon(m_polygon);
}




void CActionBubble::SetFont(const QFont &font)
{
    CBubble::SetFont(font);
    m_text->SetFont(m_font);
    setShape();
}

void CActionBubble::SetFontColor(const QColor &color)
{
    CBubble::SetFontColor(color);
    m_text->SetColor(m_fontColor);
}

void CActionBubble::SetColor(const QColor &color)
{
    CBubble::SetColor(color);
}

void CActionBubble::SetLineColor(const QColor &color)
{
    CBubble::SetColor(color);
}
