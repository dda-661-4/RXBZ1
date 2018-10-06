#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //scene = new QGraphicsScene(ui->graphicsView);
    //ui->graphicsView->setScene(scene);
       // ui->graphicsView->setMouseTracking(true);
    //ui->graphicsView->setPalette(Qt::transparent);
    //ui->graphicsView->setAttribute(Qt::WA_TranslucentBackground);
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    //ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView->

   // Grid* obj = new Grid();
    //ui->graphicsView->setScene(obj->retscene());

   //this->setStyleSheet(" background-image: url(D:/c++11/RXBZ/background.png);");

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::Gra

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));


    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));

    painter->drawEllipse(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}*/

void MainWindow::on_go_clicked()
{ //QString imaePath = QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("JPEG(*.jpg *.jpeg);;PNG(*.png)"));
    QString imagePath="D:/c++11/RXBZ/background.png";
    imageObject->load(imagePath);
    image = QPixmap::fromImage(*imageObject);
    scene= new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);
    for (qreal y=0; y<800.0; y+=30)
            {
                for (qreal x=0; x<1400.0; x+=30)
                {
                   scene->addRect(x, y, 30.0, 30.0, Qt::SolidLine, QBrush(QColor(40, 20, 20, 100)));
                }                                                  //    solidline      ( 35 80 124),qt:: SolidPattern
            }

    ui->graphicsView->setScene(scene);

    //Cloud *cloud=new Cloud();
   //connect(scene, &Grid::signalTargetCoordinate,cloud,&Cloud::slotTarget);
  //connect(scene, &Grid::signalTargetCoordinate,C,&Cloud::slotTarget);
    /*QGraphicsScene *scene = new QGraphicsScene();
    QPixmap m("D:/c++11/RXBZ/background.png");
    scene->setBackgroundBrush(m.scaled(900,1000,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->graphicsView->setScene(scene);*/
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(schetchic==0)
   {
      bsc = ui->graphicsView->pos();

       int x1 = event->x() - bsc.x();
       int y1 = event->y() - bsc.y();
        X1=event->pos().x()-25;
        Y1=event->pos().y()-100;
     scene->addEllipse(event->pos().x()-25,
                       event->pos().y()-100 ,
                       1,
                       1,
                       QPen(Qt::NoPen),
                       QBrush(Qt::red));
        str1 = QString::number(x1) + "  " + QString::number(y1);

       if((x1 < 0)||(x1 > scene->width())||(y1 < 0)||(y1 > scene->height()))
           str1 += "   out of scene";
       schetchic++;
    }
   else
   {
         target = ui->graphicsView->pos();

         int x2 = event->x() - target.x();
         int y2 = event->y() - target.y();
          X2=event->pos().x()-25;
          Y2=event->pos().y()-100;
         scene->addEllipse(event->pos().x()-25,
                           event->pos().y()-100 ,
                           1,
                           1,
                           QPen(Qt::NoPen),
                           QBrush(Qt::red));

         str2 = QString::number(x2) + "  " + QString::number(y2);

         if((x2 < 0)||(x2 > scene->width())||(y2 < 0)||(y2 > scene->height()))
             str2 += "   out of scene";
         schetchic=0;
         //ui->graphicsView->setScene(QLineF(X1,Y1,X2,Y2));

         QLineF line;
         line.setLine(X1,Y1,X2,Y2);
         qreal an=line.angle();
         //qreal len=line.length();

          qreal DX=line.dx();
          qreal DY=line.dy();

         //qDebug()<<DX;
         //qDebug()<<DY;

         scene->addLine(X1,Y1,X2,Y2,QPen(Qt::green,1,Qt::SolidLine,Qt::RoundCap));

         qDebug()<<an;
         //QPainter(this);
                 /*scene->addLine(bsc.x(),
                             bsc.y(),
                             event->scenePos().x(),
                             event->scenePos().y(),
                             QPen(Qt::green,10,Qt::SolidLine,Qt::RoundCap));*/
           qDebug()<<str1<<str2;
    }
}
    /*scene->addEllipse(event->scenePos().x()-25,
                   event->scenePos().y()-100 ,
                   10,
                   10,
                   QPen(Qt::NoPen),
                   QBrush(Qt::red));

        // Сохраняем координаты точки нажатия
        bsc = event->scenePos();
        qDebug()<<bsc;*/


/*void MainWindow::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Отрисовываем линии с использованием предыдущей координаты
   /* scene->addLine(bsc.x(),
            bsc.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::green,10,Qt::SolidLine,Qt::RoundCap));
    // Обновляем данные о предыдущей координате
    bsc = event->pos();
}*/

    /* if(schetchic==0)
    {
       bsc = ui->graphicsView->pos();

        int x1 = event->x() - bsc.x();
        int y1 = event->y() - bsc.y();
        X1=x1;
        Y1=y1;

         str1 = QString::number(x1) + "  " + QString::number(y1);

        if((x1 < 0)||(x1 > scene->width())||(y1 < 0)||(y1 > scene->height()))
            str1 += "   out of scene";
        schetchic++;
     }
    else
    {
          target = ui->graphicsView->pos();

          int x2 = event->x() - target.x();
          int y2 = event->y() - target.y();

          X2=x2;
          Y2=y2;
          str2 = QString::number(x2) + "  " + QString::number(y2);

          if((x2 < 0)||(x2 > scene->width())||(y2 < 0)||(y2 > scene->height()))
              str2 += "   out of scene";
          schetchic=0;

           //scene()->addItem(new Line(QLineF(X1,Y1,X2,Y2), scene()));

          //ui->graphicsView->setScene(QLineF(X1,Y1,X2,Y2));

          QPainter painter;
          painter.setPen(QPen(Qt::black,1));
          //QLineF angleline;
         // angleline.setP1(QPointF(bsc));
         // angleline.setP2(QPointF(target));

        painter.drawLine(QPointF(bsc),QPointF(target));
*
            qDebug()<<str1<<str2;
    }



        //ui->label->setText(str);
}*/

