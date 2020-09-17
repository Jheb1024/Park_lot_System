#include "registar_clienteb.h"
#include "ui_registar_clienteb.h"

Registar_ClienteB::Registar_ClienteB(QSqlDatabase a, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registar_ClienteB)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint); //Elimina el ícono de ayuda del qdialog
    ui->setupUi(this);

    setWindowTitle("Registrar Cliente");
    PrincipalRegistro = a;
    ui->Coche_comboBox->addItem("Camioneta");
    ui->Coche_comboBox->addItem("Sedan");
    ui->Coche_comboBox->addItem("Familiar");
    ui->Coche_comboBox->addItem("Pick-up");
    ui->Coche_comboBox->addItem("Auto-Compacto");
    ui->Coche_comboBox->addItem("Motocicleta");
    ui->Aceptar_pushButton->setDisabled(true);
    VerificarBase();
    ProbarBase();
    id_usuario = 0;
    id_tarjeta = 0;
    id_cliente = 0;

}

Registar_ClienteB::~Registar_ClienteB()
{
    delete ui;
}

void Registar_ClienteB::VerificarBase()
{
    if(PrincipalRegistro.isOpen()){
        qDebug() << " La base de datos esta abierta";

    }
    else{
        qDebug() << " La base de datos estaba cerrada";
    }
}

void Registar_ClienteB::ProbarBase()
{

}

bool Registar_ClienteB::VerificarCamposVacios()
{
        if(ui->Nombre_lineEdit->text() == "")
            return false;
        if(ui->ApellidoP_lineEdit->text() == "")
            return false;
        if(ui->ApellidoM_lineEdit->text() == "")
            return false;
        if(ui->NumeroDom_lineEdit->text() == "")
            return false;
        if(ui->Calle_lineEdit->text() == "")
            return false;
        if(ui->mail_lineEdit->text() == "")
            return false;
        if(ui->Telefono_lineEdit->text() == "")
            return false;
        if(ui->Matricula_lineEdit->text() == "")
            return false;
        if(ui->Coche_comboBox->currentText() == "")
            return false;
        if(ui->Password_lineEdit->text() == "")
            return false;
        if(ui->Repeat_password_lineEdit->text() == "")
            return false;

        return true;
}





void Registar_ClienteB::on_pushButton_clicked()
{
    Ventana_Datos_Bancarios = new Forma_Pago(this);
    Ventana_Datos_Bancarios->show();//Hay que lo registre en la base
    tarjeta = new Tarjeta();
    tarjeta = Ventana_Datos_Bancarios->GetTarjeta();
    ui->Aceptar_pushButton->setEnabled(true);

}

void Registar_ClienteB::on_Aceptar_pushButton_clicked()
{
    if(VerificarCamposVacios()){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmacion de cambios", "Deseas guardar los cambios establecidos",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
    usuario_nuevo = new Usuario();
    usuario_nuevo->AgregarDatos(ui->mail_lineEdit->text(),ui->Password_lineEdit->text(),
                                ui->Repeat_password_lineEdit->text(),"cliente_basico");

     if(usuario_nuevo->Exito()){//La funcion exito ayudara a saber si las contraseñas son identicas
         qDebug() << "Se registrara un usuario a la bd con la siguiente informacion : ";
         qDebug() << "Usuario : " << usuario_nuevo->GetNombre_Usuario();
         qDebug() << "Contraseña : " << usuario_nuevo->GetPassword();
         qDebug() << "Tipo: " << usuario_nuevo->GetTipo_Usuario();



         /*---------------Ya esta registrada la terjeta  necesito el id de tarjeta  --------------------------*/



         qDebug() << "Se registraran los siguientes datos de tarjeta ";

         qDebug() << tarjeta->GetNumero_Tarjeta();

         //Puedo agregar un boleano para saber si ya registro tarjeta
       nuevo = new Cliente_Basico();
       nuevo->Registrarse(ui->Nombre_lineEdit->text(),ui->ApellidoM_lineEdit->text(),
                          ui->ApellidoP_lineEdit->text(),ui->mail_lineEdit->text(),
                          ui->Telefono_lineEdit->text(),
                          ui->Calle_lineEdit->text(),ui->NumeroDom_lineEdit->text(),
                          0,0);//Le paso los cero `porque me estorban



         if(PrincipalRegistro.open()){

             qDebug() << " Conexion Exito";
            QSqlQuery InsUsuario;
             if(InsUsuario.exec(QString("INSERT INTO usuario(nombre_usuario,password,tipo_usuario,estado)"
                             "values('%1','%2','clientebasico',1);").arg(usuario_nuevo->GetNombre_Usuario(),
                                                                         usuario_nuevo->GetPassword()))){
                 qDebug() << "El usuario se inserto correctamente";
             }
             else{
                 qDebug() << "Error query : " << InsUsuario.lastError();
             }
            QSqlQuery VerUsuario;
            if(VerUsuario.exec("SELECT id_usuario FROM usuario;")){
             while(VerUsuario.next()){
                 id_usuario = VerUsuario.value(0).toInt();
                 qDebug() << " Recopilo id del usuario :)" << id_usuario;
             }
             VerUsuario.finish();

            }else{
                qDebug() << " Error : " << VerUsuario.lastError();
            }

            /*------------Insercion de datos bancarios ------------*/

            QSqlQuery InsTarjeta;
             if(InsTarjeta.exec(QString("INSERT INTO datos_bancarios(numero_tarjeta,cvc,"
                                        "caducidad,tipo_tarjeta)"
                                         "values('%1','%2',%3,'%4');").arg(tarjeta->GetNumero_Tarjeta(),
                                                                         tarjeta->GetCVC(),
                                                                         tarjeta->GetCaducidad(),
                                                                         tarjeta->GetTipo()))){
                 qDebug() << "La tarjeta se inserto correctamente";
             }
             else{
                 qDebug() << "Error query : " << InsTarjeta.lastError();
             }
            QSqlQuery VerTarjeta;
            if(VerTarjeta.exec("SELECT id_tarjeta FROM datos_bancarios;")){
             while(VerTarjeta.next()){
                 id_tarjeta = VerTarjeta.value(0).toInt();
                 qDebug() << " Recopilo id de la tarjeta :)" << id_tarjeta;
             }
             VerTarjeta.finish();

            }else{
                qDebug() << " Error : " << VerTarjeta.lastError();
            }

            /*              QUERY PARA INSERTAR EL MEGA CLIENTE*/

            QSqlQuery InsCliente;
             if(InsCliente.exec("INSERT INTO `cliente` (`nombre_cliente`,`aPaterno_cliente`,`aMaterno_cliente`,"
                                        "`correo`,`telefono`,`calle`,`numero_domicilio`,"
                                        "`id_usuario`,`id_tarjeta`)"
                                        " VALUES "
                                        "('" + nuevo->GetNombre() + "', '" + nuevo->GetApellido_Paterno() + "',"
                                        " '" + nuevo->GetApellido_Materno()+ "', '" + nuevo->GetCorreo_Electronico()+ "',"
                                        "'" +nuevo->GetTelefono() + "',"
                                        "'"+  nuevo->GetCalle() + "',"
                                        "'" +  nuevo->GetNumero_Domicilio() + "',"
                                         "'"+ QString::number(id_usuario) + "','"+ QString::number(id_tarjeta) + "');")){

                 qDebug() << "El cliente se inserto correctamente con id usuario" << id_usuario << " y id tarjeta" << id_tarjeta;

             }
             else{
                 qDebug() << "Error query : " << InsTarjeta.lastError();
             }


             /*Necesito encontrar el id del cliente para poder registrar el auto a su nombre*/
             QSqlQuery VerCliente;
             if(VerCliente.exec("SELECT id_cliente FROM cliente where id_usuario = "+ QString::number(id_usuario) + ";")){
              while(VerCliente.next()){
                  id_cliente = VerCliente.value(0).toInt();
                  qDebug() << " Recopilo id de la tarjeta :)" << id_cliente;
              }
              VerCliente.finish();

             }else{
                 qDebug() << " Error : " << VerCliente.lastError();
             }


             QSqlQuery InsAuto;
              if(InsAuto.exec("INSERT INTO auto (`matricula`,`tipo_de_coche`,`id_cliente`)"
                                         " VALUES "
                                         "('" + ui->Matricula_lineEdit->text() + "', '" + ui->Coche_comboBox->currentText() + "',"
                                         + QString::number(id_cliente) + ");")){

                  qDebug() << "El cliente auto se inserto correctamente";
              }
              else{
                  qDebug() << "Error query : " << InsAuto.lastError();
              }







         }else{
             qDebug() << " Conexion Fallo";
         }








    /*Ya que la tarjeta este registrada en la base se le asigna y se
     * registra el cliente al numero de id de la forma de pago*/


     }else{
       QMessageBox::critical(this,"Informacion","Las contraseñas no son iguales, vuelve a intentarlo");

     }
    close();
    }
    else{
        qDebug() << " Cancelaron el registro ";
    }//Aqui va la ventana emergente !!!
  }else{
        QMessageBox::information(this,"Campos Vacios","Todos los campos son obligatorios");
    }

}

void Registar_ClienteB::on_Cancelar_pushButton_clicked()
{
    close();
}
