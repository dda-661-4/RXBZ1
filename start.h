#ifndef START_H
#define START_H

#include <QMainWindow>

namespace Ui {
class start;
}

class start : public QMainWindow
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();

private slots:
    void on_RADIO_clicked();

    void on_CHIMIO_clicked();

private:
    Ui::start *ui;
};

#endif // START_H
