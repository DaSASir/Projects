#include "widget.h"
#include "ui_widget.h"
#include <QTabBar>
#include "stylehelper.h"
#include <QStyleOption>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();
    setInterfaceStyle();


}

Widget::~Widget()
{
    delete ui;
}

void Widget::painEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void Widget::setInterfaceStyle()
{
    this->setStyleSheet(StyleHelper::getMainWidgetStyle());

    ui->pushButton_X->setStyleSheet(StyleHelper::getStartXButtonsActiveStyle());
    ui->pushButton_O->setStyleSheet(StyleHelper::getStartOButtonsStyle());

}

void Widget::chanchXO(int num)
{
    if(num == 1){
        ui->pushButton_X->setStyleSheet(StyleHelper::getStartXButtonsActiveStyle());
        ui->pushButton_O->setStyleSheet(StyleHelper::getStartOButtonsStyle());
    }else{
        ui->pushButton_X->setStyleSheet(StyleHelper::getStartXButtonsStyle());
        ui->pushButton_O->setStyleSheet(StyleHelper::getStartOButtonsActiveStyle());
    }
}

void Widget::on_pushButton_X_clicked()
{
    chanchXO(1);
}

void Widget::on_pushButton_O_clicked()
{
    chanchXO(0);
}
