#include "zombies.h"

#include <QDebug>

Zombies::Zombies(){
    timer = new QTimer(this);
    aww = new QSound(":/zombie/groan.wav",this);//僵尸出场 ┗|｀O′|┛ 嗷~~
    aww->setLoops(1);
    aww->play();
    this->setAttribute(Qt::WA_TransparentForMouseEvents, true);//不要遮挡下面的控件
}

int Zombies::WMx(int x)
{
    int bias=-20;
    if(x<56+bias)
        return 1;
    if(x<151+bias)
        return 2;
    if(x<243+bias)
        return 3;
    if(x<346+bias)
        return 4;
    if(x<437+bias)
        return 5;
    if(x<540+bias)
        return 6;
    if(x<636+bias)
        return 7;
    if(x<730+bias)
        return 8;
    if(x<815+bias)
        return 9;
    else
        return 10;
}

//血量低到某一个线时，改变状态
void Zombies::ZChange()
{
    if(hp<=hp_ch[1])
        if(state != 1)
        {
            state=1;
            Change();
        }
        else{}
    else
        if(hp<=hp_ch[2])
            if(state!=2)
            {
                state=2;
                Change();
            }
            else{}
        else
            if(hp<=hp_ch[3])
                if(state!=3)
                {
                    state=3;
                    Change();
                }
}

//暂停
void Zombies::Zstop()
{
    movie->stop();
    if(hp<=0)
        return;
    timer->disconnect();
}

//恢复
void Zombies::Zstart()
{
    movie->start();
    if(IfEat)
    {
        connect(timer,&QTimer::timeout,[=](){
            aww->play();
            ZChange();
        }); //定义计时器，并连接槽函数
    }
    else
    {
        connect(timer,&QTimer::timeout,[=](){
            move(x()-WalkSpeed/100,y());
            ZChange();
        }); //定义计时器，并连接槽函数
    }
}

//改变状态后，改变图片
void Zombies::Change()
{
    if(Znumber==2)
    {
        switch(state)
        {
        case 1:
        {
            WalkPath=":/zombie/ZombieWalk1.gif";
            EatPath=":/zombie/ZombieAttack.gif";
            break;
        }
        case 2:
        {
            WalkPath=":/zombie/ConeZombieWalk3.gif";
            EatPath=":/zombie/ConeZombieAttack3.gif";
            break;
        }
        case 3:
        {
            WalkPath=":/zombie/ConeZombieWalk2.gif";
            EatPath=":/zombie/ConeZombieAttack2.gif";
            break;
        }
        default:break;
        }
    }
    if(Znumber==3)
    {
        switch(state)
        {
        case 1:
        {
            WalkPath=":/zombie/ZombieWalk1.gif";
            EatPath=":/zombie/ZombieAttack.gif";
            break;
        }
        case 2:
        {
            WalkPath=":/zombie/BucketZombieWalk3.gif";
            EatPath=":/zombie/BucketZombieAttack3.gif";
            break;
        }
        case 3:
        {
            WalkPath=":/zombie/BucketZombieWalk2(1).gif";
            EatPath=":/zombie/BucketZombieAttack2.gif";
            break;
        }
        default:break;
        }
    }
    if(IfEat)
    {
        int n=movie->currentFrameNumber();
        delete movie;
        movie=new QMovie(EatPath,QByteArray(),this);
        movie->setSpeed(EatSpeed/10);
        this->setMovie(movie);
        movie->jumpToFrame(n);
        movie->start();
        this->show();
    }
    else
    {
        int n=movie->currentFrameNumber();
        delete movie;
        movie=new QMovie(WalkPath,QByteArray(),this);
        movie->setSpeed(WalkSpeed);
        this->setMovie(movie);
        movie->jumpToFrame(n);
        movie->start();
        this->show();
    }
}

//受击
void Zombies::GetHurt(int attack, bool burn)
{
    hp -= attack;
    if(hp<=0)
    {
        if(burn)
            DiePath=":/zombie/Burn.gif";
    }
//如果僵尸受击过密，此段代码会造成bug
//    if(aww!=nullptr)
//    {
//        delete aww;
//    }
    if(Znumber==1||Znumber==2)
        aww = new QSound(":/zombie/splat.wav",this);
    else
        aww = new QSound(":/zombie/shieldhit.wav",this);
    aww->setLoops(1);
    aww->play();
}

//走路
void Zombies::Walk(QString Gif)
{
    switch(this->y())
    {
    case 50:{My = 1;break;}
    case 170:{My = 2;break;}
    case 290:{My = 3;break;}
    case 400:{My = 4;break;}
    default:{My = 5;break;}
    }

    IfEat=false;
    int n = 0;
    if(movie!=nullptr)
    {
        n = movie->currentFrameNumber();
        delete movie;
    }
    movie = new QMovie(Gif,QByteArray(),this);
    movie->setSpeed(WalkSpeed);
    this->setMovie(movie);
    movie->jumpToFrame(n);
    movie->start();
    this->show();
    timer->disconnect();
    timer->stop();
    connect(timer,&QTimer::timeout,[=](){
        move(x()-WalkSpeed/100,y());
        Mx = WMx(x()-WalkSpeed/100);
        ZChange();

    }); //定义计时器，并连接槽函数
    timer->start(100);
}

//吃
void Zombies::Eat(QString Gif)
{
    IfEat=true;
    int n=0;
    if(movie!=nullptr)
    {
        n=movie->currentFrameNumber();
        delete movie;
    }
    movie = new QMovie(Gif,QByteArray(),this);
    movie->setSpeed(EatSpeed/10);
    this->setMovie(movie);
    movie->jumpToFrame(n);
    movie->start();
    this->show();
    if(aww!=nullptr)
        delete aww;
    aww = new QSound(":/zombie/chompsoft.wav",this);
    timer->disconnect();
    timer->stop();
    connect(timer,&QTimer::timeout,[=](){//此处可连接植物受伤
        aww->play();
        ZChange();
    }); //定义计时器，并连接槽函数
    timer->start(EatSpeed);
}

//僵尸死亡
void Zombies::Die(QString Gif)
{
    if(IfDie)
        return;
    if(movie!=nullptr)
    {
        delete movie;
    }
    movie = new QMovie(Gif,QByteArray(),this);
    movie->setSpeed(100);
    this->setMovie(movie);
    movie->start();
    this->show();
    IfDie=true;
    timer->disconnect();
}


NormalZombie::NormalZombie()
{
    hp = 100;
    WalkSpeed = 100;
    EatSpeed = 1000;
    Hurt = 50;
    state = 1;
    WalkPath=":/zombie/ZombieWalk1.gif";
    EatPath=":/zombie/ZombieAttack.gif";
    DiePath=":/zombie/ZombieDie.gif";
}

ConeZombie::ConeZombie()
{
    hp = 750;
    WalkSpeed = 100;
    EatSpeed = 1000;
    Hurt = 50;
    state = 4;
    hp_ch[1]=200;
    hp_ch[2]=400;
    hp_ch[3]=600;
    WalkPath=":/zombie/ConeZombieWalk.gif";
    EatPath=":/zombie/ConeZombieAttack.gif";
    DiePath=":/zombie/ZombieDie.gif";
}

BucketZombie::BucketZombie()
{
    hp = 950;
    WalkSpeed = 400;
    EatSpeed = 1000;
    Hurt = 50;
    state = 4;
    hp_ch[1]=200;
    hp_ch[2]=500;
    hp_ch[3]=800;
    WalkPath=":/zombie/BucketZombieWalk.gif";
    EatPath=":/zombie/BucketZombieAttack.gif";
    DiePath=":/zombie/ZombieDie.gif";
}

FootballZombie::FootballZombie()
{
    hp = 1250;
    WalkSpeed = 400;
    EatSpeed = 1000;
    Hurt = 50;
    state = 1;
    hp_ch[1]=10000;//只有一个状态的图片，所以阻止状态改变
    hp_ch[2]=10000;
    hp_ch[3]=10000;
    WalkPath=":/zombie/FootballZombieWalk.gif";
    EatPath=":/zombie/FootballZombieAttack.gif";
    DiePath=":/zombie/FootballZombieDie.gif";
}





