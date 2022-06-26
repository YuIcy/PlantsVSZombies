#include "mymenu.h"

MyMenu::MyMenu(QWidget *parent) : QWidget(parent)
{
    //bgm播放
    QSound* bgm=new QSound(":/menu/res/menu.wav");
    bgm->setLoops(-1);
    bgm->play();

    //按钮设置
    MyPushButton* newgame=new MyPushButton(this,true,":/menu/res/SelectorScreen_StartAdventure_Button1.png",":/menu/res/SelectorScreen_StartAdventure_Highlight.png");
    newgame->move(515,125);
    connect(newgame,&MyPushButton::clicked,[=](){

    });
    MyPushButton* survival=new MyPushButton(this,true,":/menu/res/SelectorScreen_Survival_button.png");
    survival->move(515,240);
    connect(survival,&MyPushButton::clicked,[=](){
        emit unableclicked();
    });
    MyPushButton* adventure=new MyPushButton(this,true,":/menu/res/SelectorScreen_Challenges_button.png");
    adventure->move(520,334);
    connect(adventure,&MyPushButton::clicked,[=](){
        emit unableclicked();
    });
    MyPushButton* littlegame=new MyPushButton(this,true,":/menu/res/SelectorScreen_Vasebreaker_button.png");
    littlegame->move(520,410);
    connect(littlegame,&MyPushButton::clicked,[=](){
        emit unableclicked();
    });
    //帮助按钮
    MyPushButton* help=new MyPushButton(this,false,":/menu/res/SelectorScreen_Help1.png",":/menu/res/SelectorScreen_Help2.png");
    help->move(790,635);
    connect(help,&MyPushButton::clicked,[=](){
        emit helpclicked();
    });
    //选项按钮
    MyPushButton* options=new MyPushButton(this,false,":/menu/res/SelectorScreen_Options1.png",":/menu/res/SelectorScreen_Options2.png");
    options->move(692,596);
    connect(options,&MyPushButton::clicked,[=](){
        emit optionclicked();
    });
    //退出按钮
    MyPushButton* quit=new MyPushButton(this,false,":/menu/res/SelectorScreen_Quit1.png",":/menu/res/SelectorScreen_Quit2.png");
    quit->move(870,628);
    connect(quit,&MyPushButton::clicked,[=](){
        emit readyforquit();
    });


}
//背景设置
void MyMenu::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage bg(":/menu/res/bg.png");
    bg=bg.scaled(size(),Qt::KeepAspectRatioByExpanding);
    painter.drawImage(0,0,bg);

}
