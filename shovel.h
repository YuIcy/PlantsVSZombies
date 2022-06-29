#ifndef SHOVEL_H
#define SHOVEL_H

#include <QPushButton>
#include<QBitmap>
#include<QPainter>

class Shovel : public QPushButton
{
    Q_OBJECT
public:
    explicit Shovel(QWidget *parent = 0);
    QPixmap picture1;
    QPixmap picture2;
    QPixmap shovel;
signals:

public slots:
};

#endif // SHOVEL_H
