#include "propstorybubble.h"
#include "ui_propstorybubble.h"

PropStoryBubble::PropStoryBubble(const QString &title, const QString &story, int order, bool locked, QColor &color, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropStoryBubble)
{
    ui->setupUi(this);

    ui->txt_title->setText(title);
    ui->txt_story->setText(story);

    ui->txt_order->setText(QString::number(order));
    ui->txt_order->setEnabled(locked);
    ui->cb_locked->setChecked(locked);

    QString style = QString("background-color: rgb(%1, %2, %3); color: rgb(255, 255, 255)").arg(QString::number(color.red()),
                                                                                                QString::number(color.green()),
                                                                                                QString::number(color.blue()));
    ui->btn_color->setAutoFillBackground(true);
    ui->btn_color->setStyleSheet(style);
}

PropStoryBubble::~PropStoryBubble()
{
    delete ui;
}

void PropStoryBubble::on_cb_locked_toggled(bool checked)
{
    ui->txt_order->setEnabled(checked);
}


QString PropStoryBubble::Title()
{
    return ui->txt_title->text();
}
