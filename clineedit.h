#ifndef CLINEEDIT_H
#define CLINEEDIT_H

#include <QWidget>
#include <QStringListModel>
#include <QFont>

#include "ctextedit.h"

class CLineEdit : public CTextEdit
{
public:
    CLineEdit(QWidget *parent, QStringListModel *model, const QString &text = "");

public:
    void SetFont(const QFont &font);

protected:
//    virtual void keyPressEvent(QKeyEvent *e);

private:
    void AdjustHeight();
};

#endif // CLINEEDIT_H
