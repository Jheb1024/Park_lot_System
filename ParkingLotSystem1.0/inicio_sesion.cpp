#include "inicio_sesion.h"
#include "ui_inicio_sesion.h"

Inicio_Sesion::Inicio_Sesion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inicio_Sesion)
{
    ui->setupUi(this);

    //Realizamos la conexión con la base de datos
    mDatabase = QSqlDatabase::addDatabase("QMYSQL");
    mDatabase.setPort(3307);
    mDatabase.setHostName("localhost");
    mDatabase.setUserName("root");
    mDatabase.setPassword("");
    mDatabase.setDatabaseName("park_lot_system_db");
    Id = 0;

}

Inicio_Sesion::~Inicio_Sesion()
{
    delete ui;
}


void Inicio_Sesion::on_Entrar_pushButton_clicked()
{
    if(mDatabase.open()){
        qDebug() << "Status: Conexión Establecida";

        QString userIng, passIng,TipoUsuario;

        int band = 0; //0 Es no encontrado //1 Es Administrador // 2 Es cliente basico
        QSqlQuery Prueba;
        QSqlQuery GetAdmin;
        //QSqlQuery GetClienteB;
        //QSqlQuery GetTarjeta;
        Prueba.exec("Select id_usuario, nombre_usuario, password, tipo_usuario from usuario;");
        while(Prueba.next()){

            userIng = Prueba.value(1).toString();
            passIng = Prueba.value(2).toString();
            TipoUsuario = Prueba.value(3).toString();
            if(ui->Usuario_lineEdit->text() == userIng && ui->Contraseya_lineEdit->text() == passIng){
                qDebug() << "El usuario es de tipo : " << TipoUsuario;
                if(TipoUsuario == "administrador"){
                    Id = Prueba.value(0).toInt();
                    band = 1;
                }else{
                    if(TipoUsuario == "clientebasico"){
                    Id = Prueba.value(0).toInt();
                    band = 2;
                    }
                    else{
                    band = 0;
                    }
                }
            }
        }
        Prueba.finish();

        if(band == 0){
            QMessageBox::information(this,"Aviso de sesion","El usuario y"
                                                            "contraseña no coinciden");
            qDebug() << "El usuario y la contraseña no son válidos"; // Hay que limpiar la pantalla

        }else{
            if(band == 1){ // Hay que crear objeto administrador y pasarlo por parametro
            qDebug() << "El usuario administrador va a entrar su valor id es : " << Id;
            GetAdmin.exec(QString("select  a.id_administrador, a.nombre_admin, a.a_paterno, a.a_materno from "
                          "administrador as a where a.id_usuario = %1").arg(Id));
            while(GetAdmin.next()){
                Admin = new Administrador(GetAdmin.value(0).toInt(),GetAdmin.value(1).toString(),
                                          GetAdmin.value(2).toString(),GetAdmin.value(3).toString(),Id);

               /* qDebug() << GetAdmin.value(0).toInt();
                qDebug() << GetAdmin.value(1).toString();
                qDebug() << GetAdmin.value(2).toString();
                qDebug() << GetAdmin.value(3).toString();*/
            }
    GetAdmin.finish();
            }else{
            if(band == 2){ // Hay que crear objeto administrador y pasarlo por parametro
              qDebug() << "El usuario cliente basico va a entrar su valor id es : " << Id;

              Cliente_B_Principal *aux = new Cliente_B_Principal(this,Id); // El parametro Id que se le pasa por parametro es id de usuario
              aux->show();















             /* GetClienteB.exec("select id_cliente,nombre_cliente,aPaterno_cliente,aMaterno_cliente,correo,"
                               "telefono,pais,ciudad,estado,calle, numero_domicilio,matricula,tipo_coche from cliente"
                               "where id_usuario = 2;");*/

              /*  GetClienteB.exec(QString("select id_cliente,nombre_cliente,aPaterno_cliente,aMaterno_cliente,correo,"
                                         "telefono,pais,ciudad,estado,calle, numero_domicilio,matricula,tipo_coche from cliente"
                                         "where id_usuario = %1;").arg(Id));*/


              /*while(GetClienteB.next()){

                  qDebug() << "Si entre al cicloaaa";
                  qDebug() << GetClienteB.value(0).toInt();
                  qDebug() << GetClienteB.value(1).toString();
                  qDebug() << GetClienteB.value(2).toString();
                  qDebug() << GetClienteB.value(3).toString();
                  qDebug() << GetClienteB.value(4).toString();
                  qDebug() << GetClienteB.value(5).toString();
                  qDebug() << GetClienteB.value(6).toString();
                  qDebug() << GetClienteB.value(7).toString();
                  qDebug() << GetClienteB.value(8).toString();
                  qDebug() << GetClienteB.value(9).toString();
                  qDebug() << GetClienteB.value(10).toString();
                  qDebug() << GetClienteB.value(11).toString();
                  qDebug() << GetClienteB.value(12).toString();


              }

              GetClienteB.finish();*/

             /* GetTarjeta.exec(QString("t.id_tarjeta,t.numero_tarjeta,t.nombre_banco, t.cvc, t.caducidad,"
                                      "t.tipo_tarjeta   from cliente as c inner join datos_bancarios "
                                      "as t on c.id_tarjeta = t.id_tarjeta where c.id_cliente = %1").arg(Id));
              while(GetTarjeta.next()){

                  qDebug() << GetTarjeta.value(0).toInt();
                  qDebug() << GetTarjeta.value(1).toString();
                  qDebug() << GetTarjeta.value(2).toString();
                  qDebug() << GetTarjeta.value(3).toInt();
                  qDebug() << GetTarjeta.value(4).toInt();
                  qDebug() << GetTarjeta.value(5).toString();
              }




              GetTarjeta.finish();*/


            }

            }
        }

        //Cerramos la cone
        mDatabase.close();
    }
    else{
        qDebug() << "Status: Conexión Fallida";
    }
}

void Inicio_Sesion::on_Cancelar_pushButton_clicked()
{
    close();
}

void Inicio_Sesion::on_Registrarse_pushButton_clicked()
{
    registro = new Registar_ClienteB(this); //Agregarle el padre iniciar sesion
    registro->show();
}
