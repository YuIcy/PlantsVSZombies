#ifndef ZOMBIES_H
#define ZOMBIES_H

#include <QLabel>
#include <QMovie>
#include <QSound>
#include <QTimer>


class Zombies : public QLabel
{
    Q_OBJECT
public:
    Zombies();
    //僵尸血条，速度，啃食速度，伤害
    int hp;
    int WalkSpeed;
    int EatSpeed;
    int Hurt;
    int state;
    int Znumber;
    int Mx = 10,My;
    bool IfEat = false;
    QMovie * movie = nullptr;
    QString WalkPath;
    QString EatPath;
    QString DiePath;
    QTimer * timer = nullptr;
    QSound * aww = nullptr;
    bool IfDie=false;
    int hp_ch[4]={0};

    //变换动作
    void Eat(QString Gif);
    void Die(QString Gif);
    void Walk(QString Gif);
    void GetHurt(int attack, bool burn = false);
    void Change();
    void Zstop();
    void Zstart();
    void ZChange();
    int WMx(int x);

signals:

public slots:
};

//普通僵尸
class NormalZombie : public Zombies
{
    Q_OBJECT
public:
    NormalZombie();

signals:

public slots:
};

class ConeZombie : public Zombies
{
    Q_OBJECT
public:
    ConeZombie();

signals:

public slots:
};

class BucketZombie : public Zombies
{
    Q_OBJECT
public:
    BucketZombie();

signals:

public slots:
};

class FootballZombie : public Zombies
{
    Q_OBJECT
public:
    FootballZombie();

signals:

public slots:
};

#endif // ZOMBIES_H
