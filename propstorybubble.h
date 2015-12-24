#ifndef PROPSTORYBUBBLE_H
#define PROPSTORYBUBBLE_H

#include <QDialog>

namespace Ui {
class PropStoryBubble;
}

class PropStoryBubble : public QDialog
{
    Q_OBJECT

public:
    explicit PropStoryBubble(const QString &title, const QString &story, int order, bool locked, const QColor &color, QWidget *parent = 0);
    ~PropStoryBubble();

public:
    QString Title();
    QString Story();
    int     Order();
    bool    Locked();
    QColor  Color();

public slots:
    void ChangeColor(QColor color);

private slots:
    void on_cb_locked_toggled(bool checked);

    void on_btn_color_clicked();

private:
    QString ToStyleSheet(const QColor &background);

private:
    Ui::PropStoryBubble *ui;
};

#endif // PROPSTORYBUBBLE_H
