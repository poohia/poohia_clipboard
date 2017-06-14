#include "copytextobject.h"

copyTextObject::copyTextObject(QString value, QObject *parent) :
    QObject(parent),
    _maxCaract(30)
{
    this->_value = value;
    this->createResumeValue();
}

void copyTextObject::sendToPaste(QClipboard *clipboard)
{
    clipboard->setText(this->_value);
}

void copyTextObject::createResumeValue()
{
    if(this->_value.count() > this->_maxCaract)
    {
        this->_resumeValue = this->_value.section("",0,this->_maxCaract).append(" [...]");
    }
    else
        this->_resumeValue = this->_value;
}
