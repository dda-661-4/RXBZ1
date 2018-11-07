#include "tcl.h"

int time=0;
int q=0;
int len=4;
qreal X2,Y2,X,Y;
QRectF rect;
QGraphicsScene *sc;
QLineEdit *t;
bool F=true;

Tcl::Tcl()
{


}

Tcl::~Tcl()
{

}

void Tcl::get_in(QGraphicsScene *scene,  QLineEdit* time)
{
    sc=scene;

    //qDebug()<<pointF;
    t=time;

    qDebug()  << "YAYAYA";
}

void Tcl::go()
{
   QLineF line;
        time++;
        q=q+10;

           line.setP1(pointF);
           line.setAngle(90);
           line.setLength(len);

          //sc->addEllipse(50,50,50,50,QPen(Qt::red));

           //scene->addLine(line,QPen(Qt::red));

           X2=line.x2();
           Y2=line.y2();
           X=pointF.x();
           Y=pointF.y();
           line.setP1(pointF);

           line.setLength(len);

           pointF=line.p2();

           X2=line.x2();
           Y2=line.y2();

           qreal radius=q/2;
           rect.setRect(X2-radius,Y2-radius,q,q);
          // scene->addEllipse(rect,QPen(Qt::green));

           len=len+1;
}

void Tcl::Vrem()
{
qDebug()<<&sc;

 while(F)
 {
     t->setText(QString::number(time));
     time++;

   send_time(time);

    Sleep(1000);
 }
}

void Tcl::get_coor(QPointF point)
{
    pointF=point;
    qDebug()<<pointF;
}

void Tcl::set_false()//power off
{
    F=false;
    time=0;
       t->setText(QString::number(time));
}

void Tcl::set_true()
{
    F=true;
}
