#include "tcl.h"

int time=0;
int q=0;
int len=4;
qreal X2,Y2,X,Y;
QRectF rect;
QLineEdit *t;

Tcl::Tcl()
{

}

Tcl::~Tcl()
{

}

void Tcl::get_in(QGraphicsScene *sc, QPointF point, QLineEdit* time)
{
    scene=sc;
    pointF=point;
    t=time;
    //Tcl *t=new Tcl();
    //QtConcurrent::run(t,&Tcl::go);
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

          scene->addEllipse(50,50,50,50,QPen(Qt::red));

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

for(;;)
{
     t->setText(QString::number(time));
     time++;
    qDebug()<<1111;
    Sleep(1000);
}
}
