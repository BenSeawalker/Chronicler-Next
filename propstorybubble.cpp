#include "propstorybubble.h"
#include "ui_propstorybubble.h"
#include <QColorDialog>

PropStoryBubble::PropStoryBubble(const QString &title, const QString &story, int order, bool locked, const QColor &color, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropStoryBubble)
{
    ui->setupUi(this);

    ui->txt_title->setText(title);
    ui->txt_story->setText(story);

    ui->txt_order->setValidator(new QIntValidator(this));
    ui->txt_order->setText(QString::number(order));
    ui->txt_order->setEnabled(locked);
    ui->cb_locked->setChecked(locked);

    ui->btn_color->setAutoFillBackground(true);
    ui->btn_color->setStyleSheet(ToStyleSheet(color));
}

PropStoryBubble::~PropStoryBubble()
{
    delete ui;
}

void PropStoryBubble::on_cb_locked_toggled(bool checked)
{
    ui->txt_order->setEnabled(checked);
}

void PropStoryBubble::on_btn_color_clicked()
{
    QColorDialog * cd = new QColorDialog(this);
    cd->setCurrentColor(Color());
    connect(cd, SIGNAL(colorSelected(QColor)), this, SLOT(ChangeColor(QColor)));
    cd->show();
}

void PropStoryBubble::ChangeColor(QColor color)
{
    ui->btn_color->setStyleSheet(ToStyleSheet(color));
}


QString PropStoryBubble::Title()
{
    return ui->txt_title->text();
}

QString PropStoryBubble::Story()
{
    return ui->txt_story->toPlainText();
}

int PropStoryBubble::Order()
{
    return ui->txt_order->text().toInt();
}

bool PropStoryBubble::Locked()
{
    return ui->cb_locked->isChecked();
}

QColor PropStoryBubble::Color()
{
    return ui->btn_color->palette().color(QPalette::Background);
}


QString PropStoryBubble::ToStyleSheet(const QColor &background)
{
    QString style = QString("background-color: rgb(%1, %2, %3); color: rgb(255, 255, 255)").arg(QString::number(background.red()),
                                                                                             QString::number(background.green()),
                                                                                             QString::number(background.blue()));

    return style;
}
