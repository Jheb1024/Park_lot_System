#include "registar_clienteb.h"
#include "ui_registar_clienteb.h"

Registar_ClienteB::Registar_ClienteB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registar_ClienteB)
{
    ui->setupUi(this);
}

Registar_ClienteB::~Registar_ClienteB()
{
    delete ui;
}

void Registar_ClienteB::on_Accion_buttonBox_accepted()
{

}

void Registar_ClienteB::on_Accion_buttonBox_rejected()
{
    close(); //Hay que liberar memoria.
}

void Registar_ClienteB::on_pushButton_clicked()
{
    Ventana_Datos_Bancarios = new Forma_Pago();
    Ventana_Datos_Bancarios->show();
}
