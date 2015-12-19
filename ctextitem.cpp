#include "ctextitem.h"

#include <QPen>

CTextItem::CTextItem(const QString &text, const QRectF &rect, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_text(text), m_rect(rect)
{}


void CTextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QFont font = painter->font();
    font.setPixelSize(16);
    painter->setFont(font);

    QRectF bRect;
    painter->drawText(boundingRect(), Qt::TextWordWrap, m_text, &bRect);
}
