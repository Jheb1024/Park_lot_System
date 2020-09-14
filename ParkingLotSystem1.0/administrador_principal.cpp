#include "administrador_principal.h"
#include "ui_administrador_principal.h"

Administrador_Principal::Administrador_Principal(QSqlDatabase a, int b,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administrador_Principal)
{
    ui->setupUi(this);
    Id_Usuario = b;
    PrincipalAdministrador = a;
    if(!PrincipalAdministrador.isOpen()){
        if(PrincipalAdministrador.open()){
                qDebug() << " La base de datos se abrio ";
        }else{
            qDebug() << PrincipalAdministrador.lastError();
        }
    }else{
        qDebug() << "Base de datos abierta";
    }


}

Administrador_Principal::~Administrador_Principal()
{
    delete ui;
}

void Administrador_Principal::on_Salir_pushButton_clicked()
{
    close();
}

void Administrador_Principal::on_Eliminar_pushButton_clicked()
{
    principal_eliminar = new EliminarClienteB();
    principal_eliminar->show();
}
