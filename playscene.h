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
    int sunsequence[5]={50,100,50,25,200};
    int cooldownsequence[5]={7500,7500,30000,30000,7500};
    QString namesequence[5]={"SunFlower","Peashooter","WallNut","PotatoMine","Repeater"};
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
//<<<<<<< HEAD
//植物部分
//=======
//游戏胜利，失败
    void Pwin();
    void Zwin();
    QSound * WeCome = nullptr;

/***************************************************************************************************/
//>>>>>>> 56cdef394400ffb177aada4b3c280155e717f2da

    void createplant(int planttype);
    int map[10][6],clix,cliy,xlimit[10],ylimit[6];
//    map为地图数组，值为0表示无植物，1-5表示不同植物种类
//    clix/y:clickX and clickY,int，表示鼠标点击位置位于第几行第几列
//    x/ylimit:用于调用事先保存的显示gif的具体坐标
    bool visited(int x,int y);
    void born(int planttype);
    int xtrans();//将10以内的格子行（列）坐标转换成用于显示动图的位置坐标
    int ytrans();//同上
    int plthp[10][6];//植物生命值数组
    QLabel * pic[10][6];//用于存放指向植物原图的指针
    bool hit(int x,int y);//豌豆子弹击中僵尸
    bool peadetect(int x,int y);//豌豆检测到僵尸
    bool potatodetect(int x,int y);//土豆地雷检测到僵尸



signals:
    void gamestart();
    void mainmenu();
    void sunchanged(int sun);
public slots:
};

#endif // PLAYSCENE_H
