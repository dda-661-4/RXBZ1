#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QRectF>
#include <QGraphicsView>
#include <QWidget>
#include <QMutex>

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

    MainWindow::on_go_clicked();

    timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimerAlarm()));
      timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimerAlarm()
{
   //qreal z=100,z1=100;
   //t_rect.setRect(z,z1,time,time);
 // scene->addEllipse(t_rect,QPen(Qt::red));
          //mutex.lock();
           time++;
           ui->time->setText(QString::number(time));
           qDebug()<<"time1";
           //mutex.unlock();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

     time=0;

     point = ui->graphicsView->mapFromParent(event->pos());

    // mutex.lock();
    if(event->button()==Qt::LeftButton)
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

for(qreal i=2;i<500;i=i+1)//i -radius of ellipse
       {
      //timer->stop();
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
                if((X2-mass[g].x())*(X2-mass[g].x())+(Y2-mass[g].y())*(Y2-mass[g].y())<(i+rad)*(i+rad))
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
    else
    {
        mass[schetchic]=point;
        X=point.x();
        Y=point.y();

        rect.setRect(X-3,Y-3,rad0,rad0);
        scene->addEllipse(rect,QPen(Qt::yellow));

        rect.setRect(X-5,Y-5,rad,rad);
        scene->addEllipse(rect,QPen(Qt::blue));

        //qDebug()<<"left"<<mass[schetchic];

        schetchic++;
    }

   // mutex.unlock();
// scene->addEllipse()

// qDebug()<<event->pos()<<point;

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
}

void MainWindow::on_OK_NEWS_clicked()
{
    angl=ui->ANGLE->text().toInt();
}

