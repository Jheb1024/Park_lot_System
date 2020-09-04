#include "perfilcliente.h"
#include "ui_perfilcliente.h"

perfilCliente::perfilCliente(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::perfilCliente)
{
    ui->setupUi(this);
}

perfilCliente::~perfilCliente()
{
    delete ui;
}
