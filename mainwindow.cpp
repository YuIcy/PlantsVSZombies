#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapedwindow.h"
#include"mypushbutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/menu/res/pvz.ico"));
    setWindowTitle("Plants vs.Zombies");
    //设置退出弹框+按钮
    connect(ui->menu,&MyMenu::readyforquit,[=](){
        ShapedWindow* quitwindow=new ShapedWindow(this,":/menu/res/QuitWindow.png");
        quitwindow->move((this->width()-quitwindow->width())*0.5,(this->height()-quitwindow->height())*0.5);

        MyPushButton* quit=new MyPushButton(quitwindow,true,":/menu/res/QuitButton.png");
        connect(quit,&MyPushButton::clicked,[=](){
            this->close();
        });
        quit->move(40,210);


        MyPushButton* cancel=new MyPushButton(quitwindow,true,":/menu/res/CancelButton.png");
        connect(cancel,&MyPushButton::clicked,[=](){
            delete quitwindow;
        });
        cancel->move(270,210);
        quitwindow->show();
    });

    //设置帮助界面
    connect(ui->menu,&MyMenu::helpclicked,[=](){
        QMainWindow* help=new QMainWindow(this,Qt::FramelessWindowHint);
        help->setWindowModality(Qt::WindowModal);
        QPixmap pixmap;
        pixmap.load(":/menu/res/Help.png");
        help->setFixedSize(pixmap.size());
        help->setStyleSheet("background-image:url(:/menu/res/Help.png);");


        MyPushButton* back=new MyPushButton(help,true,":/menu/res/BackButton.png");
        back->move((help->width()-back->width())*0.5,600);
        connect(back,&MyPushButton::clicked,[=](){
            delete help;
        });
        help->show();

    });

    //设置选项界面
    connect(ui->menu,&MyMenu::optionclicked,[=](){
        ShapedWindow* option=new ShapedWindow(this,":/menu/res/Options.png");
        option->move((this->width()-option->width())*0.5,(this->height()-option->height())*0.5);
        MyPushButton* yes=new MyPushButton(option,true,":/menu/res/yesButton.png");
        connect(yes,&MyPushButton::clicked,[=](){
            delete option;
        });
        yes->move((option->width()-yes->width())*0.5,540);
        option->show();
    });

    //设置失效游戏内容弹窗
    connect(ui->menu,&MyMenu::unableclicked,[=](){
        ShapedWindow* unable=new ShapedWindow(this,":/menu/res/Unable.png");
        unable->move((this->width()-unable->width())*0.5,(this->height()-unable->height())*0.5);
        MyPushButton* yes=new MyPushButton(unable,true,":/menu/res/yesButton2.png");
        connect(yes,&MyPushButton::clicked,[=](){
            delete unable;
        });
        yes->move((unable->width()-yes->width())*0.5-5,215);
        unable->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
