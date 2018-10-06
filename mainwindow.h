#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QGraphicsScene"
#include "QPainter"
#include <grid.h>
#include <QString>
#include <QGraphicsSceneMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString coord1;
    QString coord2;
    int schetchic=0;
    QString str1,str2;
     QPointF bsc,target;
    qreal X1,Y1,X2,Y2;

private slots:
    void on_go_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene  *scene;
    QPixmap image;
    QImage *imageObject;
    void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
                                      //QMOUSEEvent
};

#endif // MAINWINDOW_H
