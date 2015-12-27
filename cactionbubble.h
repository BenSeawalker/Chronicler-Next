#ifndef CACTIONBUBBLE_H
#define CACTIONBUBBLE_H

#include "cbubble.h"
#include "ctextitem.h"

class CActionBubble : public CBubble
{
    Q_OBJECT

public:
    CActionBubble(QMenu *contextMenu, QGraphicsItem *parent = 0);

public:
    virtual void SetFont(const QFont &font);
    virtual void SetFontColor(const QColor &color);
    virtual void SetColor(const QColor &color);
    virtual void SetLineColor(const QColor &color);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    virtual void setShape();


private:
    QStringList * m_actions;
    CTextItem * m_text;

signals:
    void SelectedChanged(QGraphicsItem *item);

public slots:
};

#endif // CACTIONBUBBLE_H
