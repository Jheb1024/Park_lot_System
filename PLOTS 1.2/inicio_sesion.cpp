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
    mDatabase.close();
    delete ui;
}

void Inicio_Sesion::Limpiar()
{
    ui->Usuario_lineEdit_2->clear();
    ui->Contraseya_lineEdit_2->clear();
}


void Inicio_Sesion::on_Entrar_pushButton_clicked()
{


}

void Inicio_Sesion::on_Cancelar_pushButton_clicked()
{

    close();
}


void Inicio_Sesion::on_Ingresa_reserva_pushButton_2_clicked()
{
    mDatabase.open();
    ingresaconreserva *IngresaR = new ingresaconreserva(mDatabase,this);
    IngresaR->show();
}

void Inicio_Sesion::on_Entrar_pushButton_2_clicked()
{
    if(mDatabase.open()){
        qDebug() << "Status: Conexión Establecida";

        QString userIng, passIng,TipoUsuario;

        int band = 0; //0 Es no encontrado //1 Es Administrador // 2 Es cliente basico // 3 Cliente Premium
        QSqlQuery Prueba;
        QSqlQuery GetAdmin;

        Prueba.exec("Select id_usuario, nombre_usuario, password, tipo_usuario from usuario;");

        while(Prueba.next()){

            userIng = Prueba.value(1).toString();
            passIng = Prueba.value(2).toString();
            TipoUsuario = Prueba.value(3).toString();


            if(ui->Usuario_lineEdit_2->text() == userIng && ui->Contraseya_lineEdit_2->text() == passIng){
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
                    if(TipoUsuario == "clientepremium"){
                    Id = Prueba.value(0).toInt();
                    band = 3;
                    }else{
                    band = 0;
                    }

                    }
                }
            }
        }
        Prueba.finish();

        if(band == 0){
            QMessageBox::information(this,"Aviso de sesion","El usuario y"
                                                            "contraseña no coinciden");
            qDebug() << " usuario y la contraseña no válidos"; // Hay que limpiar la pantalla


            qDebug() << "El valor de la bandera es : " << QString::number(band);

        }else{
            if(band == 1){ // Hay que crear objeto administrador y pasarlo por parametro
            qDebug() << "El usuario administrador va a entrar su valor id es : " << Id;

            Administrador_Principal *aux2 = new Administrador_Principal(mDatabase,Id,this); // El parametro Id que se le pasa por parametro es id de usuario
            aux2->show();
            }else{
            if(band == 2){ // Hay que crear objeto administrador y pasarlo por parametro
              qDebug() << "El usuario cliente basico va a entrar su valor id es : " << Id;

              Cliente_B_Principal *aux = new Cliente_B_Principal(mDatabase,Id,nullptr); // El parametro Id que se le pasa por parametro es id de usuario
              aux->show();


            }else{
            if(band == 3){
              qDebug() << "El usuario cliente premium va a entrar su valor id es : " << Id;
            }
            }

            }
        }

        //Cerramos la cone
        //mDatabase.close();
    }
    else{
        qDebug() << "Status: Conexión Fallida";
    }
    Limpiar();
}

void Inicio_Sesion::on_Registrarse_pushButton_2_clicked()
{
    registro = new Registar_ClienteB(mDatabase,this); //Agregarle el padre iniciar sesion
    registro->show();
}
