//#include "mainwindow.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}

//#include <QApplication>
//#include <QLabel>

//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//    QLabel label("helloworld");
//    label.show();
//    return app.exec();
//}

/**
 *  信号和槽
 */

//#include <QApplication>
//#include <QPushButton>
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//    QPushButton button("Quit");
//    QObject::connect(&button, &QPushButton::clicked, &button, &QApplication::quit);
//    button.show();
//    app.exec();
//}

//#include <QApplication>
//#include <QPushButton>
//#include <QDebug>
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//    QPushButton button("Quit");
//    QObject::connect(&button, &QPushButton::clicked, &button, [](){qDebug() << "helloworld!";});
//    button.show();
//    app.exec();
//}

//#include <QApplication>
//#include <QPushButton>
//#include <mainwindow.h>
//#include <QDebug>
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//    MainWindow w;
//    w.show();
//    QPushButton button1("helloworld");
//    QObject::connect(&button1, &QPushButton::clicked, &button1, [](){qDebug() << "helloworld!";});
//    button1.show();
//    QPushButton button2("Quit");
//    QObject::connect(&button2, &QPushButton::clicked, &button1, &QApplication::quit);
//    button2.show();
//    app.exec();
//}



//#include <QApplication>
//#include <QPushButton>
//#include <mainwindow.h>
//#include <QDebug>
//#include <QSpinBox>
//#include <QSlider>
//#include <QHBoxLayout>
//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);

//    QWidget window;
//    window.setWindowTitle("Enter your age");

//    QSpinBox *spinBox = new QSpinBox(&window);
//    QSlider *slider = new QSlider(Qt::Horizontal, &window);
//    spinBox->setRange(0, 130);
//    slider->setRange(0, 130);

//    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
//    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
//    QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
//    spinBox->setValue(35);

//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(spinBox);
//    layout->addWidget(slider);
//    window.setLayout(layout);

//    window.show();

//    return app.exec();
//}

//#include <QApplication>
//#include <QPushButton>
//#include <mainwindow.h>
//#include <QDebug>
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    QWidget window;
//    QPushButton btn1;
//    btn1.setParent(&window);
//    btn1.setText("Quit");
//    btn1.move(100,100);
//    QObject::connect(&btn1, &QPushButton::clicked, &QApplication::quit);
//    window.show();
//    app.exec();
//}
