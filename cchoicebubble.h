#ifndef CCHOICEBUBBLE_H
#define CCHOICEBUBBLE_H


#include "cbubble.h"
#include "ctextitem.h"

class CChoiceBubble : public CBubble
{
    Q_OBJECT

public:
    friend class CConditionProperties;

public:
    CChoiceBubble(QMenu *contextMenu, QGraphicsItem *parent = 0);

public:
    virtual void SetFont(const QFont &font);
    virtual void SetFontColor(const QColor &color);

    void AddChoice(const QString &choice);

protected:
    virtual void UpdateShape();
    void AdjustMinSize();

private:
    QString m_label;
    QList<CTextItem *> m_choices;
};

#endif // CCHOICEBUBBLE_H
