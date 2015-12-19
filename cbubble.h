#ifndef CBUBBLE_H
#define CBUBBLE_H


#include <QGraphicsPixmapItem>
#include <QList>

QT_BEGIN_NAMESPACE
class QPixmap;
class QGraphicsItem;
class QGraphicsScene;
class QTextEdit;
class QGraphicsSceneMouseEvent;
class QMenu;
class QGraphicsSceneContextMenuEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QPolygonF;
QT_END_NAMESPACE

class Arrow;


class CBubble : public QObject, public QGraphicsPolygonItem
{
public:
    enum { Type = UserType + 16 };

    CBubble(QGraphicsItem *parent);
    CBubble(QMenu *contextMenu, QGraphicsItem *parent = 0);

    void removeArrow(Arrow *arrow);
    void removeArrows();
    QPolygonF polygon() const { return m_polygon; }
    void addArrow(Arrow *arrow);
    QPixmap image() const;
    int type() const Q_DECL_OVERRIDE { return Type;}

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    virtual void setShape() = 0;

protected:
    QPolygonF m_polygon;
    QMenu *m_contextMenu;
    QList<Arrow *> m_arrows;
};

#endif // CBUBBLE_H
