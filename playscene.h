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
#include"shovel.h"

/***************************************************************************************************/
//僵尸头文件
#include "zombies.h"

/***************************************************************************************************/

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
    Shovel* shovel;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

/***************************************************************************************************/
//僵尸函数
    QTimer * timer = nullptr;//监视僵尸是否死亡的函数（可以替换）
    QTimer * Ctimer = nullptr;//僵尸生成定时器
    int FCraw[10]={0,3,2,1,2,4,0,3,1,4};//僵尸随机生成行数组
    int FCzombie[10] = {1,2,1,3,1,1,2,3,1,4};//僵尸随机生成数组
    int Zcnt=0;
    Zombies ** zombie = nullptr;//活着的僵尸数组
    int ZombieNumber = 0;//活着的僵尸的数量
    int MaxNumber = 20;//僵尸最大数量限制
    int raw_h[5]={50,170,290,400,520};
    void Born(int Number, int raw);//僵尸出生函数 参数1 僵尸枚举类型 参数2 出生在第几行
/***************************************************************************************************/



signals:
    void gamestart();
    void mainmenu();
    void sunchanged(int sun);
public slots:
};

#endif // PLAYSCENE_H
