#include "plineedit.h"

PLineEdit::PLineEdit(QWidget *parent)
{
    this->setParent(parent);
}

void PLineEdit::mousePressEvent(QMouseEvent * e)
{
    this->selectAll();
    emit this->clicked();
}
