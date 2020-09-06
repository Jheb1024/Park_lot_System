#include "cliente_b_principal.h"
#include "ui_cliente_b_principal.h"

Cliente_B_Principal::Cliente_B_Principal(int a)
{
    Id_Cliente = a;
}

Cliente_B_Principal::Cliente_B_Principal(QWidget *parent, int i) :
    QDialog(parent),
    ui(new Ui::Cliente_B_Principal)
{
    ui->setupUi(this);
    Id_Cliente = i;
    ui->Id_label->setText(QString::number(Id_Cliente));
}

Cliente_B_Principal::~Cliente_B_Principal()
{
    delete ui;
}
