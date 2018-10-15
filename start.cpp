#include "start.h"
#include "ui_start.h"
#include <mainwindow.h>
#include <chimio.h>


MainWindow *openWindow;
CHIMIO * openChimio;

start::start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    openWindow=new MainWindow();
      connect(ui->RADIO,SIGNAL(clicked()),this,SLOT(on_RADIO_clicked()));
    openChimio=new CHIMIO();
      connect(ui->CHIMIO,SIGNAL(clicked()),this,SLOT(on_CHIMIO_clicked()));

}

start::~start()
{
    delete ui;
}

void start::on_RADIO_clicked()
{
    openWindow->show();
    //this->close();

}

void start::on_CHIMIO_clicked()
{
  openChimio->show();

}
