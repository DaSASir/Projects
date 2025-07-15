#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void painEvent(QPaintEvent *event);

private slots:
    void on_pushButton_X_clicked();

    void on_pushButton_O_clicked();

private:
    Ui::Widget *ui;
    void setInterfaceStyle();
    void chanchXO(int num);
};
#endif // WIDGET_H
