#ifndef TCL_H
#define TCL_H

#include <QtConcurrent/QtConcurrentRun>
#include <QGraphicsScene>
#include <QPointF>
#include <QDebug>
#include <QLineEdit>
#include<windows.h>

class Tcl:public QObject
{
    Q_OBJECT
public:
    Tcl();
    ~Tcl();

    void go();
    //VAR //////////////////////////////////////////

QGraphicsScene *scene;
    QPointF pointF;
    QLineEdit L1,L2,L3;

    // //////////////////////////////////////
public slots:
    void get_in(QGraphicsScene *sc, QPointF point, QLineEdit * time);
    void Vrem();

};



#endif // TCL_H
