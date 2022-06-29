#ifndef SEED_H
#define SEED_H

#include <QPushButton>
#include<QPixmap>
#include<Qpainter>
#include<QBitmap>
#include<QLabel>
#include<QPropertyAnimation>
#include<QTimer>
#include<QMouseEvent>
class Seed : public QPushButton
{
    Q_OBJECT
public:
    explicit Seed(QWidget *parent,int cooldown,int sun,QString pic);
    int sun,cooldown;
    QPixmap picture;
    QPixmap plantpic;
    QLabel* mask1,*mask2;
    bool incd=false;
    void mousePressEvent(QMouseEvent *e);
signals:
    void check();
public slots:
    void checksun(int sunnum);
    void cdstart();
};

#endif // SEED_H
