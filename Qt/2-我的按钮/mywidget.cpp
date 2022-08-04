#include "mywidget.h"
#include <QPushButton> // 按钮控件的头文件
#include "mypushbutton.h"
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    // 创建一个按钮
    QPushButton *btn1 = new QPushButton;

    // 让btn1对象依赖在myWidget窗口里
    btn1->setParent(this);

    // 显示文本
    btn1->setText("hello");

    btn1->move(100, 100);
    btn1->show();
    btn1->resize(60,30);

    // 创建第二个按钮，按照控件大小创建窗口
    QPushButton *btn2 = new QPushButton("hello2", this);

    btn2->move(200, 100);
    btn2->show();

    // 设置窗口大小
    resize(600, 400);
    // 设置窗口固定大小
    setFixedSize(600, 400);
    // 设置窗口标题
    setWindowTitle("按钮");

    // 创建一个自己的按钮对象
    MyPushButton *mbtn1 = new MyPushButton;
    mbtn1->setText("我的按钮");
    mbtn1->move(100, 300);
    mbtn1->setParent(this);
    mbtn1->show();

}

myWidget::~myWidget()
{
}

