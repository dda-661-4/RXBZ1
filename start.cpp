#include "start.h"
#include "ui_start.h"
#include <mainwindow.h>

MainWindow *openWindow;


start::start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    openWindow=new MainWindow();
      connect(ui->RADIO,SIGNAL(clicked()),this,SLOT(on_RADIO_clicked()));
}

start::~start()
{
    delete ui;
}

void start::on_RADIO_clicked()
{
    openWindow->show();
    this->close();

}

void start::on_CHIMIO_clicked()
{

}
