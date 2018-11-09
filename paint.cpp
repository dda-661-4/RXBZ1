#include "paint.h"
#include <QPointF>
#include <math.h>
#include<qDebug>
#include "mainwindow.h"

int rad;//speed
int ang;//angl
QPointF point2;//point
QPointF mass1[100];
int quantity;//schetchic

MyPoint::MyPoint(QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    Tcl *l=new Tcl();

     connect(this,SIGNAL(send_segv()),l,SLOT(rec_segv()));
}

MyPoint::~MyPoint()
{

}

QRectF MyPoint::boundingRect() const
{
    return QRectF(-100,-100,10000,10000);
}

qreal X5,Y5;
double w=0,h=2;
//qreal vre=2;
QLineF Line;
int len_mass[100];
void MyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::green);

    X5=point2.x();
    Y5=point2.y();

    painter->translate(X5,Y5);
    painter->rotate(ang);

    w=w+pow(0.9,2);
    h=h+pow(1.1,2);
    //send_segv();
    for(int i=0;i<quantity;i++)
    {
    Line.setLine(X5,Y5,mass1[i].x(),mass1[i].y());
      len_mass[i]=Line.length();
    }

 for(int i=0;i<quantity;i++)
 {
   if(w>=len_mass[i]||h>=len_mass[i])
   {

       send_segv();

   }
}
    painter->drawEllipse(0-w/2,0,w,h);


        Q_UNUSED(option);
        Q_UNUSED(widget);

}

void MyPoint ::rec_angl(int angl)
{
    ang=angl;
}

void MyPoint::rec_coord(QPointF point)
{

    point2=point;
}

void MyPoint::rec_speed(int leng)
{
    rad=leng;
}

void MyPoint::rec_arr(QPointF* mass,int schetchic)
{
    for(int i=0;i<100;i++)
    {
        mass1[i]=mass[i];
        //qDebug()<<mass1[i];
    }
    quantity=schetchic;

   // qDebug()<<schetchic;//<<"WWWWWWWWWWWWWWW"<<11111111111111111111;


}
