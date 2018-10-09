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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//scene = new ();
    scene= new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //ui->graphicsView->setMouseTracking(true);

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
 QPoint point = ui->graphicsView->mapFromParent(event->pos());
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
    //angl=ui->ANGLE->text().toInt();
}
