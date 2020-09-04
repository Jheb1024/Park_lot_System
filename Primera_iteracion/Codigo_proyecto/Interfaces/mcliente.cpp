#include "mcliente.h"
#include "ui_mcliente.h"

Mcliente::Mcliente(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mcliente)
{
    ui->setupUi(this);
}

Mcliente::~Mcliente()
{
    delete ui;
}
