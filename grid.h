#ifndef GRID_H
#define GRID_H
#include "QGraphicsScene"
#include <QMouseEvent>

class Grid : public QGraphicsScene
{
public:
    Grid();
    ~Grid();
    QGraphicsScene *scene;
     QGraphicsScene* retscene();
     //Cloud *cloud;

signals:
    // Сигнал для передачи координат положения курсора мыши
    //void signalTargetCoordinate(QPointF point);

private:
    // Функция, в которой производится отслеживание положения мыши



   // QGraphicsScene* retscene();
protected:
   //virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
private:

};


#endif // GRID_H
