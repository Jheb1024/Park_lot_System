#include "registar_clienteb.h"
#include "ui_registar_clienteb.h"

Registar_ClienteB::Registar_ClienteB(QSqlDatabase a, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registar_ClienteB)
{
    ui->setupUi(this);

    setWindowTitle("Registrar Cliente");
    PrincipalRegistro = a;
    ui->Coche_comboBox->addItem("Camioneta");
    ui->Coche_comboBox->addItem("Sedan");
    ui->Coche_comboBox->addItem("Familiar");
    ui->Coche_comboBox->addItem("Pick-up");
    ui->Coche_comboBox->addItem("Auto-Compacto");
    ui->Aceptar_pushButton->setDisabled(true);
    VerificarBase();
    ProbarBase();
    id_usuario = 0;
    id_tarjeta = 0;

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
    usuario_nuevo = new Usuario();
    usuario_nuevo->AgregarDatos(ui->mail_lineEdit->text(),ui->Password_lineEdit->text(),
                                ui->Repeat_password_lineEdit->text(),"cliente_basico");

     if(usuario_nuevo->Exito()){//La funcion exito ayudara a saber si las contraseñas son identicas
         qDebug() << "Se registrara un usuario a la bd con la siguiente informacion : ";
         qDebug() << "Usuario : " << usuario_nuevo->GetNombre_Usuario();
         qDebug() << "Contraseña : " << usuario_nuevo->GetPassword();
         qDebug() << "Tipo: " << usuario_nuevo->GetTipo_Usuario();

         /*---------Agregar a base de datos ------------*/




         /*--------- Recuperar Id Cliente ------------*/




         /*---------------Ya esta registrada la terjeta  necesito el id de tarjeta  --------------------------*/



         qDebug() << "Se registraran los siguientes datos de tarjeta ";
         qDebug() << tarjeta->GetNombre_Banco();
         qDebug() << tarjeta->GetNombre_Propietario();
         qDebug() << tarjeta->GetNumero_Tarjeta();

         //Puedo agregar un boleano para saber si ya registro tarjeta
       nuevo = new Cliente_Basico();
       nuevo->Registrarse(ui->Nombre_lineEdit->text(),ui->ApellidoM_lineEdit->text(),
                          ui->ApellidoP_lineEdit->text(),ui->mail_lineEdit->text(),
                          ui->Telefono_lineEdit->text(),
                          ui->Pais_lineEdit->text(),
                          ui->Ciudad_lineEdit->text(),ui->Estado_lineEdit->text(),
                          ui->Calle_lineEdit->text(),ui->NumeroDom_lineEdit->text(),
                          ui->Matricula_lineEdit->text(),ui->Coche_comboBox->currentText(),
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
             if(InsTarjeta.exec(QString("INSERT INTO datos_bancarios(nombre_propietario,numero_tarjeta,cvc,"
                                        "caducidad,tipo_tarjeta,nombre_banco)"
                                         "values('%1','%2',%3,%4,'Debito','%5');").arg(tarjeta->GetNombre_Propietario(),
                                                                                   tarjeta->GetNumero_Tarjeta(),
                                                                                   tarjeta->GetCVC(),
                                                                                   tarjeta->GetCaducidad(),
                                                                                   tarjeta->GetNombre_Banco()))){
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
                                        "`correo`,`telefono`,`pais`,`ciudad`,`estado`,`calle`,`numero_domicilio`,`matricula` ,"
                                        "`tipo_coche`,`id_usuario`,`id_tarjeta`)"
                                        " VALUES "
                                        "('" + nuevo->GetNombre() + "', '" + nuevo->GetApellido_Paterno() + "',"
                                        " '" + nuevo->GetApellido_Materno()+ "', '" + nuevo->GetCorreo_Electronico()+ "',"
                                        "'" +nuevo->GetTelefono() + "','" + nuevo->GetPais()+ "',"
                                        "'"+nuevo->GetCiudad() +"','"+  nuevo->GetEstado() +"','"+  nuevo->GetCalle() + "',"
                                        "'" +  nuevo->GetNumero_Domicilio() + "',"
                                        "'"+nuevo->GetMatricula() + "','"+nuevo->GetTipoCoche() + "',"
                                         "'"+ QString::number(id_usuario) + "','"+ QString::number(id_tarjeta) + "');")){

                 qDebug() << "El cliente se inserto correctamente con id usuario" << id_usuario << " y id tarjeta" << id_tarjeta;
             }
             else{
                 qDebug() << "Error query : " << InsTarjeta.lastError();
             }




         }else{
             qDebug() << " Conexion Fallo";
         }








    /*Ya que la tarjeta este registrada en la base se le asigna y se
     * registra el cliente al numero de id de la forma de pago*/


     }else{
       QMessageBox::critical(this,"Informacion","Las contraseñas no son iguales, vuelve a intentarlo");

     }

}

void Registar_ClienteB::on_Cancelar_pushButton_clicked()
{
    close();
}
