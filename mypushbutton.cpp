#include "mypushbutton.h"
#include<QDebug>
#include<QString>
#include<QPropertyAnimation>
#include<QBitmap>
#include<QSound>

 MyPushButton::MyPushButton(QWidget* parent,bool mask,QString normalImg,QString pressedImg):normalImgPath(normalImg),pressedImgPath(pressedImg),QPushButton(parent)
 {
    setCursor(Qt::PointingHandCursor);//设置鼠标形状
    QPixmap pix;
    bool ret=pix.load(normalImgPath);//加载图片
    pix= pix.scaled(pix.size()*1.1);//改变图片大小
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    setFixedSize(pix.width(),pix.height());//调整按钮大小
    if(mask)
        setMask(pix.mask());//设置遮罩
    setStyleSheet("QPushButton{border:0px;}");//调整无边框
    setIcon(pix);//设置按钮图像
    setIconSize(QSize(pix.width(),pix.height()));//设置图像大小
 }



 void MyPushButton::mousePressEvent(QMouseEvent *e)
 {
     QSound::play(":/menu/res/tap2.wav");
     move(x()+1,y()+1);
     return QPushButton::mousePressEvent(e);
 }

 void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
 {

     move(x()-1,y()-1);
     return QPushButton::mouseReleaseEvent(e);
 }
 void MyPushButton::enterEvent(QEvent *event)
 {

     if(pressedImgPath!="")
     {
         QSound::play(":/menu/res/tap.wav");
         QPixmap pix;
         pix.load(pressedImgPath);
         pix=pix.scaled(pix.size()*1.1);
         setIcon(pix);
     }
     return QPushButton::enterEvent(event);
 }

 void MyPushButton::leaveEvent(QEvent *event)
 {
    if(pressedImgPath!="")
    {
              QPixmap pix;
              pix.load(normalImgPath);
              pix=pix.scaled(pix.size()*1.1);
              setIcon(pix);
    }
    return QPushButton::leaveEvent(event);
 }
