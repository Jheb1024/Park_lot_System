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
    QSqlQuery *admin = new QSqlQuery();
    if(admin->exec("select * from administrador where id_usuario = " + QString::number(Id_Usuario)+ ";")){
        while(admin->next()){
                qDebug() << "Cuantas veces ";
            administrador.SetIdAdministrador(admin->value(0).toInt());
            administrador.SetNombre_Admin(admin->value(1).toString());
            administrador.SetApellido_Paterno(admin->value(2).toString());
            administrador.SetApellido_Materno(admin->value(3).toString());
        }
    }
    else{
            qDebug() << admin->lastError();
    }

    delete admin;
    ui->Nombre_Adminlabel->setText(administrador.GetNombre() + " " +
                                   administrador.GetApellido_Paterno() + " "+
                                   administrador.GetApellido_Materno());

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
