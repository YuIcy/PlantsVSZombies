#include "mysun.h"

MySun::MySun(QWidget *parent) : QLabel(parent)
{
    setCursor(Qt::PointingHandCursor);
    resize(80,80);
    QMovie *movie=new QMovie(":/pltimg/plantimages/Sun.gif");
    movie->setParent(this);
    setMovie(movie);
    setScaledContents(true);
    movie->start();
    QTimer::singleShot(10000,[=](){
        delete this;
    });
}
void MySun::mousePressEvent(QMouseEvent *ev)
{
    emit suncollected();
}
