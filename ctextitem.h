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
    CTextItem(const QString &text, const QRectF &bounds, QGraphicsItem *parent = 0);

    QString Text() { return m_text; }
    void SetText(const QString& text) { m_text = text; update(); }

    void SetFont(const QFont &font) { m_font = font; }
    void SetStyle(int style) { m_style = style; update(); }

    virtual QRectF boundingRect() const { return m_bounds; }
    virtual void Resize(const QRectF &bounds) { m_bounds = bounds; update(); }
    QRectF textBounds() const;// { return m_textBounds; }

private:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);


private:
    QString m_text;
    QRectF m_bounds;
    QRectF m_textBounds;
    QFont m_font;
    int m_style;

signals:

public slots:
};

#endif // CTEXTITEM_H
