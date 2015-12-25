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
public:
    enum BType { Story, Condition, Action};

    CBubble(QGraphicsItem *parent);
    CBubble(QMenu *contextMenu, QGraphicsItem *parent = 0);

public:
    void addArrow(Arrow *arrow);
    void removeArrow(Arrow *arrow);
    void removeArrows();

    virtual QPixmap image() const;

    QPolygonF polygon() const { return m_polygon; }

    virtual void SetFont(const QFont &font) = 0;
    QFont GetFont() { return m_font; }

    BType GetType() const { return m_type;}

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    virtual void setShape() = 0;

protected:
    QRectF m_bounds;
    QPolygonF m_polygon;
    QMenu *m_contextMenu;
    QList<Arrow *> m_arrows;
    int m_order;
    bool m_locked;
    QColor m_color;
    QFont m_font;
    BType m_type;
};

#endif // CBUBBLE_H
