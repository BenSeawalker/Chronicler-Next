#ifndef CBUBBLE_H
#define CBUBBLE_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>

QT_BEGIN_NAMESPACE
class QPixmap;
class QGraphicsItem;
class QTextEdit;
class QGraphicsSceneMouseEvent;
class QStyleOptionGraphicsItem;
class QWidget;
class QPolygonF;
QT_END_NAMESPACE

class Arrow;


class CBubble : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT

public:
    enum BType { Story, Condition, Choice};

    CBubble(QGraphicsItem *parent);
    CBubble(QMenu *contextMenu, QGraphicsItem *parent = 0);

public:
    void addArrow(Arrow *arrow);
    void removeArrow(Arrow *arrow);
    void removeArrows();

    virtual QPixmap image() const;

    QPolygonF polygon() const { return m_polygon; }

    virtual void SetFont(const QFont &font);
    QFont GetFont() { return m_font; }

    virtual void SetFontColor(const QColor &color);
    virtual void SetColor(const QColor &color);
    virtual void SetLineColor(const QColor &color);


    BType GetType() const { return m_type; }

protected:
    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    virtual void UpdateShape() = 0;

protected:
    QRectF m_bounds;
    QPolygonF m_polygon;
    QMenu *m_contextMenu;
    QList<Arrow *> m_links;
    QList<Arrow *> m_connections;
    int m_order;
    bool m_locked;
    QColor m_color;
    QColor m_lineColor;
    QFont m_font;
    QColor m_fontColor;
    BType m_type;
    QSizeF m_minSize;


signals:
    void Selected(QGraphicsItem *item);
};

#endif // CBUBBLE_H
