#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QRectF>
#include <QGraphicsView>
#include <QWidget>
#include "tcl.h"
#include <windows.h>
#include "paint.h"

 int schetchic=0;
 int vre;
 QPointF p2;
 QLineF line;
 qreal leng=3;
  QGraphicsScene *scene1;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene= new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  //  ui->graphicsView->
    scene->setSceneRect(0,0,1200,801);


//        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    scene1=new QGraphicsScene();
    ui->graphicsView_2->setScene(scene1);
    ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  imagePath="D:/c++11/RXBZ/background.png";
  imageObject->load(imagePath);
  image = QPixmap::fromImage(*imageObject);
   scene1->addPixmap(image);

 // scene->setSceneRect(image.rect());

  for (qreal y=0; y<800.0; y+=30)
          {
              for (qreal x=0; x<1400.0; x+=30)
              {
                 scene1->addRect(x, y, 30.0, 30.0, Qt::SolidLine, QBrush(QColor(40, 20, 20, 100)));
              }                                                  //    solidline      ( 35 80 124),qt:: SolidPattern
          }

  // ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //QtConcurrent::run(&m,&MainWindow::vremy);

    MainWindow::on_go_clicked();

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*void MainWindow::slotTimerAlarm()
{
 QLineF line;
     time++;
     t=t+10;
    if(L==true)
    {
        line.setP1(point);
        line.setAngle(angl);
        line.setLength(len);
        scene->addLine(line,QPen(Qt::red));

        X2=line.x2();
        Y2=line.y2();
         X=point.x();
         Y=point.y();
      line.setP1(point);

       line.setLength(len);

       point=line.p2();

       X2=line.x2();
       Y2=line.y2();

       qreal radius=t/2;
       rect.setRect(X2-radius,Y2-radius,t,t);
       scene->addEllipse(rect,QPen(Qt::green));

       len=len+1;
  }

      qDebug()<<" L ";

           ui->time->setText(QString::number(time));
}
*/

int j=0;
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    send_true();
     if(event->button()==Qt::LeftButton&&R==false)
     {
          point = ui->graphicsView->mapFromParent(event->pos());
          send_coord(point);
          send_arr(mass,schetchic);
         qreal Xx=point.x();
         qreal Yy=point.y();
          //ui->graphicsView_2->translate(Xx,Yy);
          //scene1->setSceneRect(Xx,Yy,1200,801);

         send_coor(point);

         qDebug()<<22222;
       vrem();
          R=true;
     }
   /*if(event->button()==Qt::LeftButton)
     {
             qDebug()<<"time";
              QLineF line;
              line.setP1(point);
              line.setAngle(angl);
              line.setLength(len);

              scene->addLine(line,QPen(Qt::red));

              X2=line.x2();
              Y2=line.y2();

               X=point.x();
               Y=point.y();

            line.setP1(point);

            bool check=false;

           //for(qreal i=2;i<500;i=i+1)//i -radius of ellipse
                //  {
                    while(true)
                    {
                      QLineF l;
             qDebug()<<"time";
                       line.setLength(len);
                       line.setAngle(angl);
                       point=line.p2();

                       X2=line.x2();
                       Y2=line.y2();

                       for(int g=0;g<schetchic;g++)
                       {
                           l.setLine(mass[g].x(),mass[g].y(),X2,Y2);
                           if((X2-mass[g].x())*(X2-mass[g].x())+(Y2-mass[g].y())*(Y2-mass[g].y())<(time+rad)*(time+rad))
                           {
                               check = true;
                               break;
                           }
                       }

                       qreal radius=time/2;
                       rect.setRect(X2-radius,Y2-radius,time,time);
                       scene->addEllipse(rect,QPen(Qt::green));
                       if(check==true)
                       {
                          break;
                       }
                       len=len+1;
                  }

                   len=4;

            scene->addLine(line,QPen(Qt::red));
           }
           */
    if(event->button()==Qt::RightButton)
      {

        QPainter painter(ui->graphicsView_2);

        //    //////////////////////////////////////////////////////////////////////////////////////////

          pointR = ui->graphicsView->mapFromParent(event->pos());//экранские координаты


        mass[schetchic]=pointR;
        X=pointR.x();
        Y=pointR.y();

        rect.setRect(X-3,Y-3,rad0,rad0);
        scene1->addEllipse(rect,QPen(Qt::yellow));

        rect.setRect(X-5,Y-5,rad,rad);
        scene1->addEllipse(rect,QPen(Qt::blue));
qDebug()<<pointR<<"global";
        schetchic++;

    }
}

void MainWindow::on_go_clicked()
{
    MyPoint *my=new MyPoint();
    Tcl *c=new Tcl();
    connect(this,SIGNAL(send_angl(int)),my,SLOT(rec_angl(int)));
    connect(this,SIGNAL(send_coord(QPointF)),my,SLOT(rec_coord(QPointF)));
    connect(this,SIGNAL(send_speed(int)),my,SLOT(rec_speed(int)));
    connect(this,SIGNAL(send_arr(QPointF*,int)),my,SLOT(rec_arr(QPointF*,int)));

    connect(this,SIGNAL(send(QGraphicsScene*,QLineEdit*)),c,SLOT(get_in(QGraphicsScene*,QLineEdit*)));
    send(scene ,ui-> time);
     connect(this,SIGNAL(send_coor(QPointF)),c,SLOT(get_coor(QPointF)));
     connect(this,SIGNAL(send_false()),c,SLOT(set_false()));
       connect(this,SIGNAL(send_true()),c,SLOT(set_true()));
       send_false();

    /*timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimerAlarm()));
      timer->start(1000);
*/
    R=false;
    L=false;

    leng=3;
    time=0;

}
;
void MainWindow::on_OK_NEWS_clicked()
{
    angl=ui->ANGLE->text().toInt();
    send_angl(angl);


}

void MainWindow::vrem()
{
  Tcl *t=new Tcl();
  connect(t,SIGNAL(send_time(int)),this,SLOT(rec_time(int)));

  QtConcurrent::run(t,&Tcl::Vrem);

  qDebug()<<22222;
  //  Sleep(1000);
}

QPointF P2;

qreal X4,Y4;
qreal X3,Y3;

MyPoint *point1;

void MainWindow::rec_time(int time)
{
    vre=time;
    send_speed(leng);

    qDebug()<<vre;

    line.setP1(point);
    line.setAngle(angl);
    line.setLength(1000);
    //scene->addLine(line,QPen(Qt::green));

    //scene->addEllipse(150,150,100,100,QPen(Qt::green));

    P2=line.p2();

    X4=P2.x();//end
    Y4=P2.y();

    X3=point.x();//start
    Y3=point.y();
    qreal h=50;
    qreal w=20;

    point1=new MyPoint();
    scene1->addItem(point1);

    qDebug()<<point;

    /*rect.setRect(X3-h/2,Y3-w/2,w,h);
   scene->addEllipse(rect,QPen(Qt::green));


    //rect.setRect(X3-leng/2);

    //point=line.p2();
    //point=P2;
    X2=point.x();
    Y2=point.y();
   qreal y=vre*10/2;

    rect.setRect(X2-y,Y2,6+vre*10,10+vre*10);
    //scene->addEllipse(rect,QPen(Qt::green));


*/

    //leng=leng+10;
}



