#include "grid.h"




Grid::Grid(QObject *parent) : QGraphicsScene(parent)
{

}

Grid::~Grid()
{

}

void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // When you press the mouse button, draw the ellipse
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(Qt::red));
    // Save the coordinates of the point of pressing
    previousPoint = event->scenePos();
}
