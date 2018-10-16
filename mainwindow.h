#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "QPainter"
#include <QString>
#include <QMouseEvent>
#include <QTimer>
#include <QMutex>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool R=false;
    bool L=false;
    int t=5;

    qreal len=4;
    qreal angl=90;

    qreal rad=6;
    qreal rad0=3;
    QPointF mass[10];
    QPointF point;
    qreal X,Y,X2,Y2;
    QRectF rect;

     int time=0;
     QRect t_rect;

    QTimer *timer;

    //QRectF rect;

private slots:
    void on_go_clicked();

    void on_OK_NEWS_clicked();

    void slotTimerAlarm();

private:
    Ui::MainWindow *ui;
    //Grid * item;
    QGraphicsScene  *scene;
    QPixmap image;
    QImage *imageObject;
    //QPainter painter;
     QString imagePath;

     void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
