#ifndef COPYTEXTOBJECT_H
#define COPYTEXTOBJECT_H

#include <QObject>
#include <QMenu>
#include <QClipboard>
#include <QDebug>

class copyTextObject : public QObject
{
    Q_OBJECT
public:
    explicit copyTextObject(QString value = 0, QObject *parent = 0);
    inline void setValue(QString value){this->_value = value; this->createResumeValue();}

    QString getResumeValue(){ return this->_resumeValue ; }

    QString value(){return this->_value;}


signals:

public slots:
    void sendToPaste(QClipboard *clipboard);
private:
    void createResumeValue();

private:
    QString _value;
    QString _resumeValue;



    QAction *_mainAction;
    QMenu   *_mainMenu;

    int _maxCaract;



};

#endif // COPYTEXTOBJECT_H
