#include "controller.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));

    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette p = qApp->palette();
    /*p.setColor(QPalette::Window, QColor(53,53,53));
p.setColor(QPalette::Button, QColor(255,102,0));*/
    //p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::Highlight, QColor(255,102,0));
    p.setColor(QPalette::ButtonText, QColor(0,0,0));
    p.setColor(QPalette::WindowText, QColor(0,0,0));
    qApp->setPalette(p);
    Controller controller;


    return a.exec();
}
