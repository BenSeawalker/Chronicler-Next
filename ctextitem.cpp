#include "ctextitem.h"

#include <QPen>
#include <QFontMetrics>

CTextItem::CTextItem(const QString &text, const QRectF &bounds, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_text(text), m_bounds(bounds), m_textBounds(bounds), m_color(Qt::black)
{
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setFlag(QGraphicsItem::ItemIsSelectable, false);
}


void CTextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //QFont font = painter->font();
    //font.setPixelSize(16);
    painter->setPen(QPen(m_color));
    painter->setFont(m_font);
    painter->drawText(boundingRect(), m_style, m_text, &m_textBounds);
}


QRectF CTextItem::textBounds() const
{
    QFontMetrics fm(m_font);
    return fm.boundingRect(m_text);
}


void CTextItem::SetColor(const QColor &color)
{
    m_color = color;
    update();
}
