#include "shovel.h"

Shovel::Shovel(QWidget *parent) : QPushButton(parent)
{
    setCursor(Qt::PointingHandCursor);
    picture1.load(":/playscene/res/ShovelBank.png");
    picture2.load(":/playscene/res/ShovelBank.png");
    setFixedSize(picture1.width(),picture1.height());
    setMask(picture1.mask());
    setStyleSheet("QPushButton{border:0px;}");//调整无边框
    QPainter painter(&picture1);
    shovel.load(":/playscene/res/Shovel.png");
    shovel=shovel.scaled(shovel.size()*0.65);
    painter.drawPixmap((picture1.width()-shovel.width())*0.5,(picture1.height()-shovel.height())*0.5,shovel.width(),shovel.height(),shovel);
    setIcon(picture1);//设置按钮图像
    setIconSize(QSize(picture1.width(),picture1.height()));//设置图像大小
}
