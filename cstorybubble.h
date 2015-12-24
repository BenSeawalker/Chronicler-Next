#ifndef CSTORYBUBBLE_H
#define CSTORYBUBBLE_H


#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

#include "cbubble.h"
#include "propstorybubble.h"
#include "ctextitem.h"


class CStoryBubble : public CBubble
{
    Q_OBJECT

public:
    CStoryBubble(QMenu *contextMenu, QGraphicsItem *parent = 0);

public:
    void SetFont(const QFont &font);
    void SetFontColor(const QColor &color);
    void SetColor(const QColor &color);
    void SetLineColor(const QColor &color);


protected:
    virtual void setShape();
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);


    virtual void mousePressEvent(QGraphicsSceneMouseEvent *evt);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *evt);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *evt);

    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *evt);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *evt);


    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

private:
    PropStoryBubble * m_properties;

    CTextItem * m_title;
    CTextItem * m_story;

    bool m_resize;
    QPointF m_offset;
    QRectF m_lastBounds;
    QSizeF m_minSize;


signals:
    void SelectedChanged(QGraphicsItem *item);

private slots:
    void PropertiesAccepted();
};

#endif // CSTORYBUBBLE_H
