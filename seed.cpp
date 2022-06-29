#include "seed.h"

Seed::Seed(QWidget *parent,int cooldown,int sun,QString pic) : QPushButton(parent),cooldown(cooldown),sun(sun)
{
    setCursor(Qt::PointingHandCursor);
    picture.load(":/playscene/res/Card.png");
    setFixedSize(picture.width(),picture.height());
    setMask(picture.mask());
    setStyleSheet("QPushButton{border:0px;}");//调整无边框
    QPainter painter(&picture);
    QPixmap plant(pic);
    //设置鼠标指针图标
    plantpic=plant;
    QPixmap temp(plantpic.size());
    temp.fill(Qt::transparent);
    QPainter p1(&temp);
    p1.setCompositionMode(QPainter::CompositionMode_Source);
    p1.drawPixmap(0, 0, plantpic);
    p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p1.fillRect(temp.rect(), QColor(0, 0, 0, 150));
    p1.end();
    plantpic = temp;


    plant=plant.scaled(picture.size()*0.7,Qt::KeepAspectRatio);
    painter.drawPixmap((picture.width()-plant.width())*0.5,15,plant.width(),plant.height(),plant);
    painter.drawText(16,71,QString::number(sun));
    setIcon(picture);//设置按钮图像
    setIconSize(QSize(picture.width(),picture.height()));//设置图像大小
    //设置遮罩
    QPixmap maskpic(":/playscene/res/mask.png");
    mask1=new QLabel(this);
    mask1->resize(maskpic.size());
    mask1->setStyleSheet("border-image:url(:/playscene/res/mask.png);");
    mask2=new QLabel(this);
    mask2->resize(maskpic.size());
    mask2->setStyleSheet("border-image:url(:/playscene/res/mask.png);");
    mask2->move(0,-76);






}
void Seed::checksun(int sunnum)
{
    if(sunnum>=sun)
    {
        mask1->hide();
    }
    else
    {
        mask1->show();
    }
}
void Seed::cdstart()
{
    mask1->show();
    incd=true;
    QPropertyAnimation* anime=new QPropertyAnimation(mask2,"geometry");
    anime->setStartValue(QRect(0,0,mask2->width(),mask2->height()));
    anime->setEndValue(QRect(0,-76,mask2->width(),mask2->height()));
    anime->setEasingCurve(QEasingCurve::Linear);
    anime->setDuration(cooldown);
    anime->start();
    QTimer::singleShot(cooldown,[=](){
        incd=false;
        emit check();

    });
}

void Seed::mousePressEvent(QMouseEvent *e)
{
    if(mask1->isHidden())
        return QPushButton::mousePressEvent(e);
    else
        e->ignore();
}
