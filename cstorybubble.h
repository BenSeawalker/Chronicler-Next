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

protected:
    virtual void setShape();
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *evt);

private:
    CTextItem * m_title;
    CTextItem * m_story;
    int m_order;
    bool m_locked;
    QColor m_color;

    PropStoryBubble * m_properties;

public slots:
    void PropertiesAccepted();
};

#endif // CSTORYBUBBLE_H
