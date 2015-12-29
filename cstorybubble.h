#ifndef CSTORYBUBBLE_H
#define CSTORYBUBBLE_H


#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

#include "cbubble.h"
#include "ctextitem.h"


class CStoryBubble : public CBubble
{
    Q_OBJECT

public:
    friend class CStoryProperties;

public:
    CStoryBubble(QMenu *contextMenu, QGraphicsItem *parent = 0);

public:
    virtual void SetFont(const QFont &font);
    virtual void SetFontColor(const QColor &color);
    virtual void SetColor(const QColor &color);
    virtual void SetLineColor(const QColor &color);


protected:
    virtual void UpdateShape();


    virtual void mousePressEvent(QGraphicsSceneMouseEvent *evt);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *evt);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *evt);

    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *evt);
//    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *evt);

private:
    CTextItem * m_title;
    CTextItem * m_story;

    bool m_resize;
    QPointF m_offset;
    QRectF m_lastBounds;
};

#endif // CSTORYBUBBLE_H
