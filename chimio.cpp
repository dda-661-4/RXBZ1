#include "chimio.h"
#include "ui_chimio.h"

CHIMIO::CHIMIO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CHIMIO)
{
    ui->setupUi(this);
}

CHIMIO::~CHIMIO()
{
    delete ui;
}
