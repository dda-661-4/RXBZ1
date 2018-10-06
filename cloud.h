#ifndef CLOUD_H
#define CLOUD_H

#include <QObject>
#include <QTimer>
#include <QGraphicsObject>

class Cloud : public QGraphicsObject
{
    Q_OBJECT
public:
   Cloud();

signals:

private:
    //QRectF boundingRect() const;

public slots:
    void slotTarget(QPointF point); // Слот для установки координаты, куда нужно идти

private:
    QPointF target;         // Положение курсора
    bool state;             // Статус идти/стоять
};

#endif // CLOUD_H
