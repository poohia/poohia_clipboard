#ifndef PLINEEDIT_H
#define PLINEEDIT_H

#include <QLineEdit>
#include <QDebug>

class PLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit PLineEdit(QWidget *parent = 0);

signals:
    void clicked();
public slots:

protected:
    void mousePressEvent(QMouseEvent * e);

};


#endif // PLINEEDIT_H
