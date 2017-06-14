#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "controller.h"

MainWidget::MainWidget(int nbOfRow, Controller *parent) :
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    move(1086,6);
    for(int i = 0 ; i < nbOfRow; i++)
    {
        PLineEdit *tmpLineEdit = new PLineEdit(this);
        tmpLineEdit->setReadOnly(true);
        tmpLineEdit->setCursor(Qt::PointingHandCursor);
        tmpLineEdit->setObjectName(QString("label_").append(QString::number(i)));
        ui->formLayoutContent->addRow(new QLabel(QString().append(QString::number(i)).append("°:"))
                                      ,tmpLineEdit);
        this->_listOfRow << tmpLineEdit;
        connect(tmpLineEdit, SIGNAL(clicked()), parent, SLOT(setTextClipboard()));
    }
    this->_mainController = parent;

}

MainWidget::~MainWidget()
{
    delete ui;
    foreach (PLineEdit *plineeditTmp, this->_listOfRow) {
        delete plineeditTmp;
    }
    qDebug() << this->pos();
}

QString MainWidget::getTextLineEdit(int lineEdit)
{
    return this->_listOfRow.at(lineEdit)->text();
}

void MainWidget::setTextLineEdit(QString value, int lineEdit)
{
    PLineEdit *tmpLineEdit = this->_listOfRow.at(lineEdit);
    tmpLineEdit->setText(value.trimmed());
}

bool MainWidget::eventFilter(QObject *object, QEvent *event)
{
    return true;
}
