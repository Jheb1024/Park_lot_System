#include "actualizar_datos.h"
#include "ui_actualizar_datos.h"

Actualizar_Datos::Actualizar_Datos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Actualizar_Datos)
{
    ui->setupUi(this);
}

Actualizar_Datos::~Actualizar_Datos()
{
    delete ui;
}
