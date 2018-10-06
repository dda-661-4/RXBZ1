#include "grid.h"
#include "mainwindow.h"
#include <QObject>
#include <QDebug>

Grid::Grid() :
    QGraphicsScene()
{
   scene = new QGraphicsScene(this);
   for (qreal y=0; y<800.0; y+=30)
           {
               for (qreal x=0; x<1400.0; x+=30)
               {
                  scene->addRect(x, y, 30.0, 30.0, Qt::SolidLine, QBrush(QColor(40, 20, 20, 100)));
               }                                                  //    solidline      ( 35 80 124),qt:: SolidPattern
           }
}

Grid::~Grid()
{

}

QGraphicsScene *Grid::retscene()
{
    return scene;
}

/*void Grid::mousePressEvent(QMouseEvent *event)
{





   /* if(QApplication::mouseButtons() == Qt::LeftButton){
        emit signalTargetCoordinate(event->scenePos()); // Передаём данный о местоположении клика
    }
}*/

/*void moves::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    if (mouseEvent->button()==Qt::LeftButton)
    {
        QGraphicsRectItem *rec=(QGraphicsRectItem*) itemAt(mouseEvent->scenePos(),QTransform()); // это Ваша строка во втором коде, немного изменяем, по хорошему тут надо проверять что это за итем, но раз у Вас только прямоугольники :)
        rec->setBrush(QBrush(QColor(128, 128, 128)));
        qDebug()<<"Press";
    }
}
 *
 */


/*
 *scene = new QGraphicsScene(this);
    for (qreal y=0; y<300.0; y+=30)//рисуем игровое поле из квадратов
        {
            for (qreal x=0; x<300.0; x+=30)
            {
               scene->addRect(x, y, 30.0, 30.0, Qt::SolidLine, QBrush(QColor(35, 80, 124), Qt::SolidPattern));
            }
        }
 *
 * /

/*void grid::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    if (mouseEvent->button()==Qt::LeftButton)
    {
        QGraphicsRectItem *rec=(QGraphicsRectItem*) itemAt(mouseEvent->scenePos(),QTransform()); // это Ваша строка во втором коде, немного изменяем, по хорошему тут надо проверять что это за итем, но раз у Вас только прямоугольники :)
        rec->setBrush(QBrush(QColor(128, 128, 128)));
        qDebug()<<"Press";
    }
}*/
