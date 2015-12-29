#ifndef CCONDITIONPROPERTIES_H
#define CCONDITIONPROPERTIES_H


#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QIntValidator>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringListModel>

#include "clineedit.h"

class CBubble;
class CConditionBubble;


class CConditionProperties : public QWidget
{
    Q_OBJECT

public:
    CConditionProperties(CBubble *bbl, QStringListModel *model, QWidget *parent = 0);

public:
    void SetBubble(CBubble *bbl);

    virtual void setFont(const QFont &font);

private:
    CConditionBubble *m_bbl;

    QLineEdit *m_labelEdit;
    CLineEdit *m_conditionEdit;
    QStringListModel *m_model;

    QLineEdit *m_orderEdit;
    QCheckBox *m_lockEdit;


signals:

private slots:
    void LabelChanged(QString title);
    void ConditionChanged();
    void OrderChanged(QString order);
    void LockedChanged(bool locked);
};

#endif // CCONDITIONPROPERTIES_H
