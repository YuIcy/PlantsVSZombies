#ifndef MYSUN_H
#define MYSUN_H

#include <QLabel>
#include<QMovie>
#include<QTimer>

class MySun : public QLabel
{
    Q_OBJECT
public:
    explicit MySun(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
signals:
    void suncollected();
public slots:
};

#endif // MYSUN_H
