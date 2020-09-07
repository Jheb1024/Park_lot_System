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
    ui->Id_label->setText( " Matricula : "+ cliente_principal->GetMatricula() + " Id Cliente : " + QString::number(cliente_principal->GetId()));
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
   if(PrincipalCliente.open()){
   QSqlQuery *a = new QSqlQuery();
   cliente_principal = Principal_Actualizar->GetCliente();
   Conteo = Principal_Actualizar->GetLista();
   int tope = Conteo.size();
   int datoactualizar = 0;
   for(int i = 0; i < tope; i++){
       datoactualizar = Conteo[i];
   switch(datoactualizar){
   case 1:{
       qDebug() << "Se actualizara nombre : " << cliente_principal->GetNombre();
       if(a->exec("UPDATE cliente SET nombre_cliente = '"+ cliente_principal->GetNombre() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 2:{
       qDebug() << "Se actualizara paterno : " << cliente_principal->GetApellido_Paterno();
       if(a->exec("UPDATE cliente SET aPaterno_cliente = '"+ cliente_principal->GetApellido_Paterno() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 3:{
       qDebug() << "Se actualizara materno : " << cliente_principal->GetApellido_Materno();
       if(a->exec("UPDATE cliente SET aMaterno_cliente = '"+ cliente_principal->GetApellido_Materno() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 4:{
       qDebug() << "Se actualizara correo : " << cliente_principal->GetCorreo_Electronico();
       if(a->exec("UPDATE cliente SET correo = '"+ cliente_principal->GetCorreo_Electronico() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 5:{
       qDebug() << "Se actualizara telefono : " << cliente_principal->GetTelefono();
       if(a->exec("UPDATE cliente SET telefono = '"+ cliente_principal->GetTelefono() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 6:{
       qDebug() << "Se actualizara pais : " << cliente_principal->GetPais();
       if(a->exec("UPDATE cliente SET pais = '"+ cliente_principal->GetPais() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 7:{
       qDebug() << "Se actualizara ciudad : " << cliente_principal->GetCiudad();
       if(a->exec("UPDATE cliente SET ciudad = '"+ cliente_principal->GetCiudad() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 8:{
       qDebug() << "Se actualizara estado : " << cliente_principal->GetEstado();
       if(a->exec("UPDATE cliente SET estado = '"+ cliente_principal->GetEstado()+ "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 9:{
       qDebug() << "Se actualizara calle : " << cliente_principal->GetCalle();
       if(a->exec("UPDATE cliente SET calle = '"+ cliente_principal->GetCalle() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 10:{
       qDebug() << "Se actualizara numero domicilio : " << cliente_principal->GetNumero_Domicilio();
       if(a->exec("UPDATE cliente SET numero_domicilio = '"+ cliente_principal->GetNumero_Domicilio() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 11:{
       qDebug() << "Se actualizara matricula : " << cliente_principal->GetMatricula();
       if(a->exec("UPDATE cliente SET matricula = '"+ cliente_principal->GetMatricula() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }
   case 12:{
       qDebug() << "Se actualizara tipo de coche : " << cliente_principal->GetTipoCoche();
       if(a->exec("UPDATE cliente SET tipo_coche = '"+ cliente_principal->GetTipoCoche() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
           qDebug() << " Se actualo la base de datos ";
       }
       else{
           qDebug() << a->lastError();
       }
       break;
   }

   }

}
delete a;
}else{
       qDebug() << "No se puedo tener acceso o abrir la base de datos";
   }
}
