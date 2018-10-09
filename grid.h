#ifndef GRID_H
#define GRID_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

class Grid : public QGraphicsScene

{

public:
    explicit Grid(QObject *parent = 0);
    ~Grid();

     //Cloud *cloud;

private:
    QPointF     previousPoint;

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};


#endif // GRID_H
