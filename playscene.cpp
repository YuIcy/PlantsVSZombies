#include "playscene.h"
#include"shapedwindow.h"
#include"mypushbutton.h"

playscene::playscene(QWidget *parent) : QWidget(parent)
{
    setFixedSize(960,720);
    battelbgm=new QSound(":/playscene/res/battelbgm.wav",this);
    battelbgm->setLoops(-1);
    connect(this,&playscene::gamestart,[=](){
        QSound::play(":/playscene/res/readysetplant.wav");

        //设置开场动画
        QLabel *ready=new QLabel(this);
        QLabel  *mask=new QLabel(this);
        mask->setFixedSize(size());
        QPixmap readypix(":/playscene/res/StartReady.png");
        ready->resize(readypix.size());
        ready->setPixmap(readypix);
        ready->move((width()-ready->width())*0.5,(height()-ready->height())*0.5);
        mask->show();
        ready->show();

        QTimer::singleShot(620,[=](){
            QPixmap setpix(":/playscene/res/StartSet.png");
            ready->resize(setpix.size());
            ready->setPixmap(setpix);
            ready->move((width()-ready->width())*0.5,(height()-ready->height())*0.5);

            QTimer::singleShot(620,[=](){
                QPixmap palntpix(":/playscene/res/StartPlant.png");
                ready->resize(palntpix.size());
                ready->setPixmap(palntpix);
                ready->move((width()-ready->width())*0.5,(height()-ready->height())*0.5);
                QTimer::singleShot(800,[=](){
                    delete ready;
                    delete mask;
                    battelbgm->play();
                });
            });
        });



    });


    //设置种子包
    QPixmap seedbank(":/playscene/res/Shop.png");
    QLabel* bank=new QLabel(this);
    bank->resize(seedbank.size());
    bank->setPixmap(seedbank);
    bank->move(200,0);
    bank->show();
    sunlabel=new QLabel(QString::number(sunnum),this);
    sunlabel->setAlignment(Qt::AlignCenter);
    sunlabel->move(bank->x()+27,65);
    sunlabel->show();
    for(int i=0;i<5;i++)
    {
        seedBank[i]=new Seed(bank,cooldownsequence[i],sunsequence[i],":/playscene/res/SunFlower.png");
        seedBank[i]->checksun(sunnum);
        connect(seedBank[i],&Seed::clicked,[=](){
            if(sunnum>=seedBank[i]->sun)
            {
                QSound::play(":/playscene/res/seedlift.wav");
                setCursor(QCursor(seedBank[i]->plantpic));
                for(int i=0;i<5;i++)
                {
                    if(!seedBank[i]->incd)
                        seedBank[i]->checksun(sunnum);
                }
                seedBank[i]->mask1->show();
                isPlanting=i;


            }
        });
        connect(seedBank[i],&Seed::check,[=](){
                    seedBank[i]->checksun(sunnum);
        });
        seedBank[i]->move(67+55*i,5);
        seedBank[i]->show();
    }

    //设置菜单按钮
    MyPushButton* menu=new MyPushButton(this,true,":/playscene/res/MenuButton.png");
    qDebug()<<size();
    menu->move(this->width()-menu->width(),0);
    menu->show();
    connect(menu,&MyPushButton::clicked,[=](){
        QSound::play(":/playscene/res/pause.wav");
        ShapedWindow* option=new ShapedWindow(this,":/menu/res/Options.png");
        option->move((this->width()-option->width())*0.5,(this->height()-option->height())*0.5);
        //返回按钮
        MyPushButton* Return=new MyPushButton(option,true,":/playscene/res/returnButton.png");
        connect(Return,&MyPushButton::clicked,[=](){
            delete option;
        });
        Return->move((option->width()-Return->width())*0.5,540);
        //主菜单按钮
        MyPushButton* menu=new MyPushButton(option,true,":/playscene/res/mainMenu.png");
        connect(menu,&MyPushButton::clicked,[=](){
            battelbgm->stop();
            emit mainmenu();
        });
        menu->move((option->width()-menu->width())*0.5,450);
        option->show();
    });


}


void playscene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage bg(":/playscene/res/Background.jpg");
    bg=bg.scaled(size(),Qt::KeepAspectRatioByExpanding);
    painter.drawImage(-250,0,bg);
}
void playscene::mousePressEvent(QMouseEvent *event)
{
    if(isPlanting>-1)
    {
        if(event->button()==Qt::RightButton)
        {
            setCursor(Qt::ArrowCursor);
            seedBank[isPlanting]->checksun(sunnum);
            isPlanting=-1;
            return;
        }
        else if(QRect(60,100,860,580).contains(event->pos()))
        {

            setCursor(Qt::ArrowCursor);
            sunnum-=seedBank[isPlanting]->sun;
            sunlabel->setText(QString::number(sunnum));
            seedBank[isPlanting]->cdstart();

            for(int i=0;i<5;i++)
            {
                if(!seedBank[i]->incd)
                    seedBank[i]->checksun(sunnum);
            }
            QSound::play(":/playscene/res/plant.wav");
            isPlanting=-1;
            return;
        }
    }
    return QWidget::mousePressEvent(event);
}
