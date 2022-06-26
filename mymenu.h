#ifndef MYMENU_H
#define MYMENU_H

#include <QWidget>
#include<QImage>
#include<QPainter>
#include<QSound>
#include"mypushbutton.h"
class MyMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MyMenu(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
signals:
    void readyforquit();
    void helpclicked();
    void optionclicked();
    void unableclicked();
public slots:
};

#endif // MYMENU_H
