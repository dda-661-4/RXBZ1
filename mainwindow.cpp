#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QProcess>

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


}

void MainWindow::mousePressEvent(QMouseEvent *event)
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
      // schetchic++;

         QPointF point;
         point.setX(X1);
         point.setY(Y1);
         qDebug()<<X1<<Y1;

         line.setP1(point);
         line.setAngle(angl);
         line.setLength(len);
         scene->addLine(line,QPen(Qt::green));
         point=line.p2();



        /* void count()
         {
             blablabla
         }
         int main()
         {
             QProcess p = new QProcess(count());p.start();
         }*/

         //line.setAngle(angl);
         //angl=line.angle();
         //qDebug()<<angl;
         //line.setLine(X1,Y1,X2,Y2);
         //qDebug()<<line.angle()<<line.length()<<line.p2();
         //line=line.fromPolar(len,angl);
         //line.setP1(point);

         //qDebug()<<line.angle()<<line.length()<<line.p2();
        //scene->addLine(line,QPen(Qt::red));
         //qDebug()<<line2.length();

         //qDebug()<<line.angle();
         //line.setAngle(angl);

         //angl=line.angle();
         //qDebug()<<angl;
         //qreal len=line.length();

        // qreal DX=line.dx();
         // qreal DY=line.dy();

         //qDebug()<<DX;
         //qDebug()<<DY;

         //scene->addLine(X1,Y1,X2,Y2,QPen(Qt::green,1,Qt::SolidLine,Qt::RoundCap));

         //qDebug()<<an;

    }



void MainWindow::on_OK_NEWS_clicked()
{
    angl=ui->ANGLE->text().toInt();
}
