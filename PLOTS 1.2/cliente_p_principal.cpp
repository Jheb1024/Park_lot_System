#include "cliente_p_principal.h"
#include "ui_cliente_p_principal.h"

Cliente_P_Principal::Cliente_P_Principal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cliente_P_Principal)
{
    ui->setupUi(this);
}

Cliente_P_Principal::~Cliente_P_Principal()
{
    delete ui;
}
