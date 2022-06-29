#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QWidget>
#include<QSound>
#include<Qlabel>
#include<QPropertyAnimation>
#include<QTimer>
#include<QDebug>
#include<QPainter>
#include"seed.h"
class playscene : public QWidget
{
    Q_OBJECT
public:
    explicit playscene(QWidget *parent = 0);
    QSound *battelbgm;
    int sunnum=1000;
    QLabel *sunlabel;
    Seed* seedBank[5];
    int sunsequence[5]={50,100,200,50,25};
    int cooldownsequence[5]={7500,7500,7500,30000,30000};
    int isPlanting=-1;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:
    void gamestart();
    void mainmenu();
    void sunchanged(int sun);
public slots:
};

#endif // PLAYSCENE_H
