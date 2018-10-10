#ifndef GRID_H
#define GRID_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

class Grid : public QGraphicsItem
{

        public:
            Grid()
            {
                setFlag(ItemIgnoresTransformations, true);
            }

        /*    QRectF boundingRect() const
            {
                //return QRectF(-5, -5, 10, 10);
            }*/

            void paint(QPainter *painter)
            {
                QPen pen = painter->pen();
                pen.setCosmetic(true);
                pen.setWidth(5);
                pen.setColor(QColor(Qt::red));
                painter->setPen(pen);
                QBrush brush = painter->brush();
                brush.setStyle(Qt::SolidPattern);
                painter->setBrush(brush);
                painter->drawEllipse(250,250, 10, 10);
            }
        };

#endif // GRID_H
