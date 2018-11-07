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

 int schetchic=0;

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
    scene->setSceneRect(0,0,500,500);


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
void MainWindow::mousePressEvent(QMouseEvent *event)
{
     len=4;
     point = ui->graphicsView->mapFromParent(event->pos());
     send(scene , point,ui-> time);
     if(event->button()==Qt::LeftButton)
     {
       vrem();

         // emit send(scene,point,ui->thread1,ui->thread2,ui->thread3);
        // time=0;
         //t=5;
        // L=true;
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
        mass[schetchic]=point;
        X=point.x();
        Y=point.y();

        rect.setRect(X-3,Y-3,rad0,rad0);
        scene->addEllipse(rect,QPen(Qt::yellow));

        rect.setRect(X-5,Y-5,rad,rad);
        scene->addEllipse(rect,QPen(Qt::blue));

        schetchic++;
    }
}

void MainWindow::on_go_clicked()
{ //QString imagePath = QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("JPEG(*.jpg *.jpeg);;PNG(*.png)"));
    imagePath="D:/c++11/RXBZ/background.png";
    imageObject->load(imagePath);
    image = QPixmap::fromImage(*imageObject);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    for (qreal y=0; y<800.0; y+=30)
            {
                for (qreal x=0; x<1400.0; x+=30)
                {
                   scene->addRect(x, y, 30.0, 30.0, Qt::SolidLine, QBrush(QColor(40, 20, 20, 100)));
                }                                                  //    solidline      ( 35 80 124),qt:: SolidPattern
            }

    Tcl *c=new Tcl();

    connect(this,SIGNAL(send(QGraphicsScene*,QPointF,QLineEdit*)),c,SLOT(get_in(QGraphicsScene*,QPointF,QLineEdit*)));

    /*timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimerAlarm()));
      timer->start(1000);
*/
    R=false;
    L=false;
}

void MainWindow::on_OK_NEWS_clicked()
{
    angl=ui->ANGLE->text().toInt();
    //ui->
}

void MainWindow::vrem()
{
  Tcl *t=new Tcl();
  connect(t,SIGNAL(send_time(int)),this,SLOT(rec_time(int)));

  QtConcurrent::run(t,&Tcl::Vrem);

  qDebug()<<22222;
  //  Sleep(1000);
}

int vre;
QPointF p2;
QLineF line;
qreal leng=3;

void MainWindow::rec_time(int time)
{
    vre=time;
    qDebug()<<vre;


    line.setP1(point);
    line.setAngle(90);
    line.setLength(leng);
    leng=leng+10;
    //p1=line.p2();

    scene->addLine(line,QPen(Qt::green));

   // scene->addEllipse(vre,vre,vre,vre,QPen(Qt::red));
}




