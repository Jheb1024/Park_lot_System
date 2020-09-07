#include "cliente_b_principal.h"
#include "ui_cliente_b_principal.h"

Cliente_B_Principal::Cliente_B_Principal(int a)
{
    Id_Usuario = a;
}

Cliente_B_Principal::Cliente_B_Principal(QSqlDatabase a, int b,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cliente_B_Principal)
{
    ui->setupUi(this);
    Id_Usuario = b;
    PrincipalCliente = a;
    cliente_principal = new Cliente_Basico();



    if(PrincipalCliente.isOpen()){
        qDebug() << " La base de datos esta abierta";

    }
    else{
        qDebug() << " La base de datos estaba cerrada";
    }

    QSqlQuery *cliente = new QSqlQuery();
    if(cliente->exec("SELECT * from cliente WHERE id_usuario = "+ QString::number(Id_Usuario)+ ";")){
        while(cliente->next()){
                qDebug() << "Cuantas veces ";
                cliente_principal->SetId(cliente->value(0).toInt());
             cliente_principal->Registrarse(cliente->value(1).toString(),
                                            cliente->value(2).toString(),
                                            cliente->value(3).toString(),
                                            cliente->value(4).toString(),
                                            cliente->value(5).toString(),
                                            cliente->value(6).toString(),
                                            cliente->value(7).toString(),
                                            cliente->value(8).toString(),
                                            cliente->value(9).toString(),
                                            cliente->value(10).toString(),
                                            cliente->value(11).toString(),
                                            cliente->value(12).toString(),
                                            cliente->value(13).toInt(),
                                            cliente->value(14).toInt());

        }
    }
    else{
            qDebug() << cliente->lastError();
    }

    delete cliente;
    ui->Id_label->setText(cliente_principal->GetNombre() + " Matricula : "+ cliente_principal->GetMatricula());
    Principal_Actualizar = new ModificarInfo(cliente_principal,this);

    QObject::connect(Principal_Actualizar,SIGNAL(Mandar_Objeto()),this,SLOT(ObtenerObjeto()));



}

Cliente_B_Principal::~Cliente_B_Principal()
{
    delete ui;
}

void Cliente_B_Principal::on_pushButton_2_clicked()
{
    close();
}

void Cliente_B_Principal::on_Editar_Info_pushButton_clicked()
{

    Principal_Actualizar->show();

}

void Cliente_B_Principal::ObtenerObjeto()
{
   cliente_principal = Principal_Actualizar->GetCliente();

   qDebug() << " Obtuve objeto Actualizado : " << cliente_principal->GetNombre();
}
