#ifndef CPROPERTIESVIEW_H
#define CPROPERTIESVIEW_H

#include <QWidget>
#include <QStringListModel>

#include "cstoryproperties.h"

class CPropertiesView : public QWidget
{
    Q_OBJECT

public:
    explicit CPropertiesView(QStringListModel *model, QWidget *parent = 0);

public:
    void SetBubble(CBubble *bbl);

private:
    //CBubble::BType ItemType(QGraphicsItem *item);

private:
    QVBoxLayout * m_layout;

    CStoryProperties *m_storyProperties;



signals:

public slots:
//    void SelectedItemChanged(QGraphicsItem *item);
};

#endif // CPROPERTIESVIEW_H
