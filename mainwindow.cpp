#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QProcess>
#include <QSizeF>
#include <QRectF>
#include <QGraphicsView>
#include <QWidget>
#include <QPainter>
#include <grid.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene= new QGraphicsScene();
    ui->graphicsView->setScene(scene);

   // ui->graphicsView->setRenderHint(QPainter::Antialiasing);
   // ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    //ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0,0,500,500);
    //ui->graphicsView->setMaximumHeight(500);
   // ui->graphicsView->setMaximumWidth(500);
     //ui->graphicsView->setCursor();
   //  scene->setSceneRect(0,0,500,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qreal X,Y,X2,Y2;

 QPointF point = ui->graphicsView->mapFromParent(event->pos());

 //len=100;

   QLineF line;
   line.setP1(point);
   line.setAngle(angl);
   line.setLength(len);

   scene->addLine(line,QPen(Qt::red));

   X2=line.x2();
   Y2=line.y2();

 X=point.x();
 Y=point.y();

 qreal height=4,width=4;


 QRectF rect;

 scene->addEllipse(rect,QPen(Qt::green));

qDebug()<<point;

 line.setP1(point);

for(qreal i=2;i<500;i=i+6)
       {
            //qDebug()<<line.p1();
            line.setLength(len);
            line.setAngle(angl);
            point=line.p2();
              //scene->addLine(line,QPen(Qt::red));
            X2=line.x2();
            Y2=line.y2();
            qreal radius=i/2;
            rect.setRect(X2-radius,Y2-radius,i,i);
            scene->addEllipse(rect,QPen(Qt::green));
            //scene->addLine(line,QPen(Qt::red));
            len=len+6;
            //qDebug()<<len;
       }
        len=4;


 scene->addLine(line,QPen(Qt::red));
 //scene->addEllipse(X,Y,30,30,QPen(Qt::green));


// scene->addEllipse()

 qDebug()<<event->pos()<<point;

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
