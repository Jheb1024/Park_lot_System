#include "forma_pago.h"
#include "ui_forma_pago.h"

Forma_Pago::Forma_Pago(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forma_Pago)
{
    ui->setupUi(this);
}

Forma_Pago::~Forma_Pago()
{
    delete ui;
}

void Forma_Pago::on_Entrar_Pago_buttonBox_accepted()
{

}

void Forma_Pago::on_Entrar_Pago_buttonBox_rejected()
{
    close();
}
