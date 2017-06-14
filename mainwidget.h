#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include <QLabel>
#include <QDesktopWidget>
#include "plineedit.h"

class Controller;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(int nbOfRow, Controller *parent = 0);
    ~MainWidget();
    QString getTextLineEdit(int lineEdit);
public slots:
    void setTextLineEdit(QString value, int lineEdit);

private:
    Ui::MainWidget *ui;
    QList<PLineEdit*> _listOfRow;
    Controller *_mainController;

protected:
    bool eventFilter(QObject* object, QEvent* event);
};

#endif // MAINWIDGET_H
