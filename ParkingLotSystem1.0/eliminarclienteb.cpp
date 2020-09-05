#include "eliminarclienteb.h"
#include "ui_eliminarclienteb.h"

EliminarClienteB::EliminarClienteB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EliminarClienteB)
{
    ui->setupUi(this);
}

EliminarClienteB::~EliminarClienteB()
{
    delete ui;
}
