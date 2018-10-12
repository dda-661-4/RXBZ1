#ifndef CHIMIO_H
#define CHIMIO_H

#include <QMainWindow>

namespace Ui {
class CHIMIO;
}

class CHIMIO : public QMainWindow
{
    Q_OBJECT

public:
    explicit CHIMIO(QWidget *parent = 0);
    ~CHIMIO();

private:
    Ui::CHIMIO *ui;
};

#endif // CHIMIO_H
