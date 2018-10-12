#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "QPainter"
#include <grid.h>
#include <QString>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    qreal len=4;
    qreal angl=90;

    qreal rad=10;
    qreal rad0=6;
    QPointF mass[100];


private slots:
    void on_go_clicked();

    void on_OK_NEWS_clicked();

private:
    Ui::MainWindow *ui;
    //Grid * item;
    QGraphicsScene  *scene;
    QPixmap image;
    QImage *imageObject;
    QPainter painter;

    //QRectF rect;
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
