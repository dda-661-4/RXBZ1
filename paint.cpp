#include "paint.h"
#include <QPointF>
#include <math.h>
#include<qDebug>

int rad;//speed
int ang;//angl
QPointF point2;//point
QPointF mass1[100];

MyPoint::MyPoint(QObject *parent)
    : QObject(parent), QGraphicsItem()
{

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

void MyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::green);

    X5=point2.x();
    Y5=point2.y();

    painter->translate(X5,Y5);
    painter->rotate(ang);

    w=w+pow(0.9,2);
    h=h+pow(1.1,2);

    painter->drawEllipse(0-w/2,0,w,h);



        Q_UNUSED(option);
        Q_UNUSED(widget);
    //vre++;
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

void MyPoint::rec_arr(QPointF mass[])
{
    for(int i=0;i<100;i++)
    {
        mass1[i]=mass[i];
        qDebug()<<mass1[i];
    }


}
