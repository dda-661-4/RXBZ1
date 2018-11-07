#include "tcl.h"

int time=0;
int q=0;
int len=4;
qreal X2,Y2,X,Y;
QRectF rect;
QGraphicsScene *sc;
QLineEdit *t;


Tcl::Tcl()
{


}

Tcl::~Tcl()
{

}

void Tcl::get_in(QGraphicsScene *scene, QPointF point, QLineEdit* time)
{
    sc=scene;

    pointF=point;
    qDebug()<<pointF;
    t=time;
    //Tcl *t=new Tcl();
    //QtConcurrent::run(t,&Tcl::go);
    QRectF rect;
    qreal x,y;
    x=pointF.x();
    y=pointF.y();
    rect.setRect(x-75,y-75,150,150);
    sc->addEllipse(rect,QPen(Qt::red));
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
//QLineF line;
//qreal len=3;
qDebug()<<&sc;
//Tcl *tc=new Tcl();
//MainWindow *ma=new MainWindow();
//
for(;;)
{
   // sc->addEllipse(50,50,50,50,QPen(Qt::red));
     t->setText(QString::number(time));
     time++;
    /* line.setP1(pointF);
     line.setAngle(90);
     line.setLength(len);
     len=len+10;*/
   send_time(time);

     // sc->addLine(line,QPen(Qt::red));

    Sleep(1000);
}
}
