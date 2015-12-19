#ifndef CTEXTITEM_H
#define CTEXTITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

class CTextItem : public QGraphicsItem
{
public:
    enum { Type = UserType + 1 };
public:
    CTextItem(const QString &text, const QRectF &rect, QGraphicsItem *parent = 0);

    QString Text() { return m_text; }
    void Text(const QString& text) { m_text = text; }

    virtual QRectF boundingRect() const { return m_rect; }

private:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);


private:
    QString m_text;
    QRectF m_rect;

signals:

public slots:
};

#endif // CTEXTITEM_H
