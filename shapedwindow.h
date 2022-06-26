#ifndef SHAPEDWINDOW_H
#define SHAPEDWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QBitmap>

class ShapedWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ShapedWindow(QWidget *parent ,QString pix);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    QPixmap pixmap;
    QPoint mousepos;
    bool LeftBtnPress;
signals:

public slots:
};

#endif // SHAPEDWINDOW_H
