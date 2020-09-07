#include "inicio_sesion.h"
#include "ui_inicio_sesion.h"

Inicio_Sesion::Inicio_Sesion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inicio_Sesion)
{
    ui->setupUi(this);

    //Realizamos la conexión con la base de datos
    setWindowTitle("Iniciar Sesion");

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

void Inicio_Sesion::Limpiar()
{
    ui->Usuario_lineEdit->clear();
    ui->Contraseya_lineEdit->clear();
}


void Inicio_Sesion::on_Entrar_pushButton_clicked()
{

    if(mDatabase.open()){
        qDebug() << "Status: Conexión Establecida";

        QString userIng, passIng,TipoUsuario;

        int band = 0; //0 Es no encontrado //1 Es Administrador // 2 Es cliente basico
        QSqlQuery Prueba;
        QSqlQuery GetAdmin;

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

            Administrador_Principal *aux2 = new Administrador_Principal(mDatabase,Id,this); // El parametro Id que se le pasa por parametro es id de usuario
            aux2->show();

           /* GetAdmin.exec(QString("select  a.id_administrador, a.nombre_admin, a.a_paterno, a.a_materno from "
                          "administrador as a where a.id_usuario = %1").arg(Id));
            while(GetAdmin.next()){
                Admin = new Administrador(GetAdmin.value(0).toInt(),GetAdmin.value(1).toString(),
                                          GetAdmin.value(2).toString(),GetAdmin.value(3).toString(),Id);


            }
             GetAdmin.finish();*/


            }else{
            if(band == 2){ // Hay que crear objeto administrador y pasarlo por parametro
              qDebug() << "El usuario cliente basico va a entrar su valor id es : " << Id;

              Cliente_B_Principal *aux = new Cliente_B_Principal(mDatabase,Id,this); // El parametro Id que se le pasa por parametro es id de usuario
              aux->show();

            }

            }
        }

        //Cerramos la cone
        mDatabase.close();
    }
    else{
        qDebug() << "Status: Conexión Fallida";
    }
    Limpiar();
}

void Inicio_Sesion::on_Cancelar_pushButton_clicked()
{

    close();
}

void Inicio_Sesion::on_Registrarse_pushButton_clicked()
{
    registro = new Registar_ClienteB(mDatabase,this); //Agregarle el padre iniciar sesion
    registro->show();
}
