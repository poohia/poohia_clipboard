#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent),
    _ignore(false),
    _nbOfRows(5)
{
    this->_clipboard =  QApplication::clipboard();
    this->_mainWidget = new MainWidget(_nbOfRows+1,this);
    this->_mainWidget->show();
    /************** INIT LIST *********************/
    for(int i = 0 ; i < (_nbOfRows+1) ; i++)
    {
        copyTextObject* tmpCopyTextObject = new copyTextObject(" ",this);
        this->_listOfClipboard << tmpCopyTextObject;
    }
    connect(this->_clipboard,SIGNAL(changed(QClipboard::Mode)),this, SLOT(clipboardChanged(QClipboard::Mode)));
}

Controller::~Controller()
{
    delete this->_mainWidget;
    foreach(copyTextObject* copytextobjectTmp, this->_listOfClipboard)
        delete copytextobjectTmp;

}

void Controller::setTextClipboard()
{
    QObject *emetteur = sender();
    this->_clipboard->setText(
  this->_listOfClipboard.at(emetteur->objectName().remove("label_").toInt())->value()
       );
    this->_ignore = true;
}

void Controller::clipboardChanged(QClipboard::Mode mode)
{
    if(!this->_ignore)
    {
        const QMimeData *mimeData = this->_clipboard->mimeData();
        QString clipboardValue = NULL;
        if(mimeData->hasText())
        {
            clipboardValue = this->_clipboard->text(mode);
        }
        if(!clipboardValue.contains("file:///"))
        {
            copyTextObject *currentCopy = new copyTextObject(clipboardValue);
            QList<copyTextObject*> tmpList;
            this->_listOfClipboard.push_front(currentCopy);
            this->_listOfClipboard.removeLast();
            for(int i = 0 ; i < this->_listOfClipboard.count(); i++)
            {
                tmpList.push_back(this->_listOfClipboard.at(i));
                this->_mainWidget->setTextLineEdit(this->_listOfClipboard.at(i)->getResumeValue(),i);
            }
            this->_listOfClipboard = tmpList;
        }
    }
    else
        this->_ignore = false;
}
