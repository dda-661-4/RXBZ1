#ifndef TCL_H
#define TCL_H

#include <QtConcurrent/QtConcurrentRun>
#include <QGraphicsScene>
#include <QPointF>
#include <QDebug>
#include <QLineEdit>
#include<windows.h>
#include <mainwindow.h>

class Tcl:public QObject
{
    Q_OBJECT
public:
    Tcl();
    ~Tcl();

    void go();


    //VAR //////////////////////////////////////////


    QPointF pointF;
    QLineEdit L1,L2,L3;


signals:
    send_time(int time);

    // //////////////////////////////////////
public slots:
    void get_in(QGraphicsScene *graphicsView,  QLineEdit * time);
    void Vrem();
    void get_coor(QPointF point);
    void set_false();
    void set_true();
    void rec_segv();

};



#endif // TCL_H
