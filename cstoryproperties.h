#ifndef CSTORYPROPERTIES_H
#define CSTORYPROPERTIES_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QIntValidator>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringListModel>

#include "ctextedit.h"

class CBubble;
class CStoryBubble;


class CStoryProperties : public QWidget
{
    Q_OBJECT

public:
    CStoryProperties(CBubble *bbl, QStringListModel *model, QWidget *parent = 0);

public:
    void SetBubble(CBubble *bbl);

    virtual void setFont(const QFont &font);

private:
    CStoryBubble *m_bbl;

    QLineEdit *m_title;
    CTextEdit *m_story;
    QStringListModel *m_model;

    QLineEdit *m_order;
    QCheckBox *m_lock;



signals:

private slots:
    void TitleChanged(QString title);
    void StoryChanged();
    void OrderChanged(QString order);
    void LockedChanged(bool locked);
};

#endif // CSTORYPROPERTIES_H
