#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QClipboard>
#include <QApplication>
#include <QMimeData>
#include <QDebug>
#include "mainwidget.h"
#include "copytextobject.h"


class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    ~Controller();
    int k;

signals:

public slots:
    void setTextClipboard();

private slots:
    void clipboardChanged(QClipboard::Mode mode);

private:
    MainWidget *_mainWidget;
    QList<copyTextObject*> _listOfClipboard;
    QClipboard *_clipboard;

    int _nbOfRows;
    bool _ignore;


};

#endif // CONTROLLER_H
