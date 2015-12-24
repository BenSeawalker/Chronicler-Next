#include "ctextitem.h"

#include <QPen>
#include <QFontMetrics>

CTextItem::CTextItem(const QString &text, const QRectF &bounds, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_text(text), m_bounds(bounds), m_textBounds(bounds)
{
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setFlag(QGraphicsItem::ItemIsSelectable, false);
}


void CTextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //QFont font = painter->font();
    //font.setPixelSize(16);
    painter->setFont(m_font);
    painter->drawText(boundingRect(), m_style, m_text, &m_textBounds);
}


QRectF CTextItem::textBounds() const
{
    QFontMetrics fm(m_font);
    return fm.boundingRect(m_text);
}
