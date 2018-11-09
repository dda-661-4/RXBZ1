#ifndef PAINT_H
#define PAINT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include "tcl.h"

/* Чтобы работали СЛОТЫ и СИГНАЛЫ, наследуемся от QOBJECT,
 * */
class MyPoint :  public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
     explicit MyPoint(QObject *parent = 0);
    ~MyPoint();

public slots:
    void rec_angl(int angl);
    void rec_coord(QPointF point);
    void rec_speed(int leng);
    void rec_arr(QPointF* mass,int schetchic);
signals:
    send_segv();


private:
    /* Данные методы виртуальные, поэтому их необходимо реализовать
     * в случае наследования от QGraphicsItem
     * */
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


#endif // PAINT_H
