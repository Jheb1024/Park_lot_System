#include "cliente_p_principal.h"
#include "ui_cliente_p_principal.h"

void Cliente_P_Principal::vaciar(){
    ui->L_1pushButton->setStyleSheet("#L_1pushButton{border-image: url(:/Img/mas (1).png);background-color: transparent;}");
    ui->L_1pushButton->setEnabled(true);
    ui->L_2pushButton->setStyleSheet("#L_2pushButton{border-image: url(:/Img/mas (1).png);background-color: transparent;}");
    ui->L_2pushButton->setEnabled(true);
    ui->L_3pushButton->setStyleSheet("#L_3pushButton{border-image: url(:/Img/mas (1).png);background-color: transparent;}");
    ui->L_3pushButton->setEnabled(true);
    ui->L_4pushButton->setStyleSheet("#L_4pushButton{border-image: url(:/Img/mas (1).png);background-color: transparent;}");
    ui->L_4pushButton->setEnabled(true);
    ui->L_5pushButton->setStyleSheet("#L_5pushButton{border-image: url(:/Img/mas (1).png);background-color: transparent;}");
    ui->L_5pushButton->setEnabled(true);
    ui->L_6pushButton->setStyleSheet("#L_6pushButton{border-image: url(:/Img/mas (1).png);background-color: transparent;}");
    ui->L_6pushButton->setEnabled(true);
    ui->L_7pushButton->setStyleSheet("#L_7pushButton{border-image: url(:/Img/mas (1).png);background-color: transparent;}");
    ui->L_7pushButton->setEnabled(true);
    ui->L_8pushButton->setStyleSheet("#L_8pushButton{border-image: url(:/Img/mas (1).png);background-color: transparent;}");
    ui->L_8pushButton->setEnabled(true);
    ui->L_9pushButton->setStyleSheet("#L_9pushButton{border-image: url(:/Img/mas (1).png);background-color: transparent;}");
    ui->L_9pushButton->setEnabled(true);
    ui->L_10pushButton->setStyleSheet("#L_10pushButton{border-image: url(:/Img/mas (1).png);background-color: transparent;}");
    ui->L_10pushButton->setEnabled(true);
}


void Cliente_P_Principal::CargarLugares(int id, QString calendario, QString reloj){

    QSqlQuery *buscar = new QSqlQuery();
    if(buscar->exec("SELECT id_cajon FROM reservacion WHERE id_piso ="+QString::number(id)+" AND fecha = "+calendario+" AND h_entrada = '"+reloj+"';")){
        while(buscar->next()){
            int a = buscar->value(0).toInt();
            switch (a) {
                case 1:
                    ui->L_1pushButton->setStyleSheet("#L_1pushButton{border-image: url(:/Img/minus.png);background-color: transparent;}");
                    ui->L_1pushButton->setEnabled(false);
                    break;
                case 2:
                    ui->L_2pushButton->setStyleSheet("#L_2pushButton{border-image: url(:/Img/minus.png);background-color: transparent;}");
                    ui->L_2pushButton->setEnabled(false);
                    break;
                case 3:
                    ui->L_3pushButton->setStyleSheet("#L_3pushButton{border-image: url(:/Img/minus.png);background-color: transparent;}");
                    ui->L_3pushButton->setEnabled(false);
                    break;
                case 4:
                    ui->L_4pushButton->setStyleSheet("#L_4pushButton{border-image: url(:/Img/minus.png);background-color: transparent;}");
                    ui->L_4pushButton->setEnabled(false);
                    break;
                case 5:
                    ui->L_5pushButton->setStyleSheet("#L_5pushButton{border-image: url(:/Img/minus.png);background-color: transparent;}");
                    ui->L_5pushButton->setEnabled(false);
                    break;
                case 6:
                    ui->L_6pushButton->setStyleSheet("#L_6pushButton{border-image: url(:/Img/minus.png);background-color: transparent;}");
                    ui->L_6pushButton->setEnabled(false);
                    break;
                case 7:
                    ui->L_7pushButton->setStyleSheet("#L_7pushButton{border-image: url(:/Img/minus.png);background-color: transparent;}");
                    ui->L_7pushButton->setEnabled(false);
                    break;
                case 8:
                    ui->L_8pushButton->setStyleSheet("#L_8pushButton{border-image: url(:/Img/minus.png);background-color: transparent;}");
                    ui->L_8pushButton->setEnabled(false);
                    break;
                case 9:
                    ui->L_9pushButton->setStyleSheet("#L_9pushButton{border-image: url(:/Img/minus.png);background-color: transparent;}");
                    ui->L_9pushButton->setEnabled(false);
                    break;
                case 10:
                    ui->L_10pushButton->setStyleSheet("#L_10pushButton{border-image: url(:/Img/minus.png);background-color: transparent;}");
                    ui->L_10pushButton->setEnabled(false);
                    break;

                default:
                    break;
            }
        }
    }

    else{
        qDebug()<<buscar->lastError();
    }
    delete buscar;
}



void Cliente_P_Principal::VerReservaciones(int id){
    QSqlQuery *reservaciones = new QSqlQuery();
    if(reservaciones->exec("Select id_reservacion, fecha, h_entrada, h_salida, id_cajon, id_piso, id_reservacion,fecha_fin From reservacion WHERE id_cliente ="
        +QString::number(id)+";")){

        int fila;
        while(reservaciones->next()){
            //reservaciones[fila-1] = reservaciones->value(5).toInt();
            ui->Mis_rservas_tableWidget->insertRow(ui->Mis_rservas_tableWidget->rowCount());
            fila = ui->Mis_rservas_tableWidget->rowCount()-1;
            ui->Mis_rservas_tableWidget->setItem(fila,0,new QTableWidgetItem(reservaciones->value(0).toString()));
            ui->Mis_rservas_tableWidget->setItem(fila,1,new QTableWidgetItem(reservaciones->value(1).toString()));
            ui->Mis_rservas_tableWidget->setItem(fila,2,new QTableWidgetItem(reservaciones->value(2).toString()));
            ui->Mis_rservas_tableWidget->setItem(fila,3,new QTableWidgetItem(reservaciones->value(3).toString()));
            ui->Mis_rservas_tableWidget->setItem(fila,4,new QTableWidgetItem(reservaciones->value(4).toString()));
            ui->Mis_rservas_tableWidget->setItem(fila,5,new QTableWidgetItem(reservaciones->value(5).toString()));
            ui->Mis_rservas_tableWidget->setItem(fila,6,new QTableWidgetItem(reservaciones->value(7).toString()));


        }
    }
    delete reservaciones;





}

void Cliente_P_Principal::Ver_HistorialReservaciones(int id)
{
    //DEFINO LA FUNCIÓN PARA VER EL HISTORIAL DE RESERVACIONES
    qDebug()<<"Entro a la mera funcion";

    QSqlQuery *Historial_resv = new QSqlQuery();
    if (Historial_resv->exec("SELECT id_reservacion, fecha, h_entrada, h_salida, fecha_inicio, fecha_fin, id_cajon, id_piso FROM reservacion WHERE id_cliente = "+QString::number(id)+" and fecha < CURDATE();"))
        qDebug()<<"hago el query";
    {
        qDebug()<<Historial_resv->lastError();

        int indice = 0;
        while(Historial_resv->next())
        {
            qDebug()<<"Empiezo a mostrar datos tabla";
            ui->tabla_reservaciones_tableWidget->insertRow(ui->tabla_reservaciones_tableWidget->rowCount());
            indice = ui->tabla_reservaciones_tableWidget->rowCount()-1;
            ui->tabla_reservaciones_tableWidget->setItem(indice, 0, new QTableWidgetItem(Historial_resv->value(0).toString()));
            ui->tabla_reservaciones_tableWidget->setItem(indice, 1, new QTableWidgetItem(Historial_resv->value(1).toString()));
            ui->tabla_reservaciones_tableWidget->setItem(indice, 2, new QTableWidgetItem(Historial_resv->value(2).toString()));
            ui->tabla_reservaciones_tableWidget->setItem(indice, 3, new QTableWidgetItem(Historial_resv->value(3).toString()));
            ui->tabla_reservaciones_tableWidget->setItem(indice, 4, new QTableWidgetItem(Historial_resv->value(4).toString()));
            ui->tabla_reservaciones_tableWidget->setItem(indice, 5, new QTableWidgetItem(Historial_resv->value(5).toString()));
            ui->tabla_reservaciones_tableWidget->setItem(indice, 6, new QTableWidgetItem(Historial_resv->value(6).toString()));
            ui->tabla_reservaciones_tableWidget->setItem(indice, 7, new QTableWidgetItem(Historial_resv->value(7).toString()));
        }
    }
    delete Historial_resv;

}



Cliente_P_Principal::Cliente_P_Principal(int a)
{
    Id_Usuario = a;
}



Cliente_P_Principal::Cliente_P_Principal(QSqlDatabase a, int b,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cliente_P_Principal)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint); //Elimina el ícono de ayuda del qdialog
    ui->setupUi(this);
    Id_Usuario = b;
    PrincipalCliente = a;
    cliente_principal = new Cliente_Basico();
    auto_principal = new Auto();

    //datos para la tabla

    if(PrincipalCliente.isOpen()){
        qDebug() << " La base de datos esta abierta ggg";
    }
    else{
        qDebug() << " La base de datos estaba cerrada";
    }

    QSqlQuery *cliente = new QSqlQuery();
    if(cliente->exec("SELECT * from cliente WHERE id_usuario = "+ QString::number(Id_Usuario)+ ";")){
        while(cliente->next()){
            qDebug() << "Cuantas veces Aqui !!";
            cliente_principal->SetId(cliente->value(0).toInt());
            cliente_principal->Registrarse(cliente->value(1).toString(),
                                           cliente->value(2).toString(),
                                           cliente->value(3).toString(),
                                           cliente->value(4).toString(),
                                           cliente->value(5).toString(),
                                           cliente->value(6).toString(),
                                           cliente->value(7).toString(),
                                           cliente->value(8).toInt(),
                                           cliente->value(9).toInt());
        }
    }
    else{
        qDebug() << cliente->lastError();
    }

    delete cliente;

    QSqlQuery *recuperar_auto = new QSqlQuery();
    if(recuperar_auto->exec("SELECT * from auto WHERE id_cliente = "+ QString::number(cliente_principal->GetId())+ ";")){
        while(recuperar_auto->next()){
            auto_principal->SetId_Auto(recuperar_auto->value(0).toInt());
            auto_principal->SetMatricula(recuperar_auto->value(1).toString());
            auto_principal->SetTipo(recuperar_auto->value(2).toString());
            auto_principal->SetId_Cliente(recuperar_auto->value(3).toInt());
            qDebug() << "id :" << recuperar_auto->value(0).toInt();
            qDebug() << "Matricula :" << recuperar_auto->value(1).toString();
            qDebug() << "Tipo de auto :"<<  recuperar_auto->value(2).toString();
            qDebug() << "id cliente :" << recuperar_auto->value(3).toInt();
        }
    }
    else{
        qDebug() << " Entro a este error auto otra vez ";
        qDebug() << recuperar_auto->lastError();
    }

    delete recuperar_auto;
    /*---------------------------------------------------------------------------------------------------------------------------*/


    ui->Id_label->setText( ""+ cliente_principal->GetNombre() +
                           " " + cliente_principal->GetApellido_Paterno() +
                           " " + cliente_principal->GetApellido_Materno() +
                           " Id Cliente : " + QString::number(cliente_principal->GetId()));



    Principal_Actualizar = new ModificarInfo(cliente_principal,auto_principal,this);
    QObject::connect(Principal_Actualizar,SIGNAL(Mandar_Objeto()),this,SLOT(ObtenerObjeto()));




    /*------------------------------------------------*/
    ui->intervalos_tableWidget->setRowCount(0);
    QStringList titulos;
    titulos<<"Fecha Incial"<<"Fecha Final"<<"Hora Inicial" << " Hora final" << "Dias";
    ui->intervalos_tableWidget->setColumnCount(5);
    ui->intervalos_tableWidget->setHorizontalHeaderLabels(titulos);

    ListaIntervalos = new QList<Reser>();

    /*------------------------------------------------*/

}

Cliente_P_Principal::~Cliente_P_Principal()
{
    delete ui;
    delete cliente_principal;
    delete auto_principal;
}
/* Solo esta de mas en la aplicacion original
void Cliente_P_Principal::on_pushButton_2_clicked()
{
    close();
}*/

void Cliente_P_Principal::on_Editar_Info_pushButton_clicked()
{
    Principal_Actualizar->show();
}

void Cliente_P_Principal::ObtenerObjeto()
{
    if(PrincipalCliente.open()){
        QSqlQuery *a = new QSqlQuery();
        cliente_principal = Principal_Actualizar->GetCliente();
        auto_principal = Principal_Actualizar->GetAuto();
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
                qDebug() << "Se actualizara calle : " << cliente_principal->GetCalle();
                if(a->exec("UPDATE cliente SET calle = '"+ cliente_principal->GetCalle() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
                    qDebug() << " Se actualo la base de datos ";
                }
                else{
                    qDebug() << a->lastError();
                }
                break;
            }
            case 7:{
                qDebug() << "Se actualizara numero domicilio : " << cliente_principal->GetNumero_Domicilio();
                if(a->exec("UPDATE cliente SET numero_domicilio = '"+ cliente_principal->GetNumero_Domicilio() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
                    qDebug() << " Se actualo la base de datos ";
                }
                else{
                    qDebug() << a->lastError();
                }
                break;
            }
            case 8:{
                qDebug() << "Se actualizara matricula : " << auto_principal->GetMatricula();
                if(a->exec("UPDATE auto SET matricula = '"+ auto_principal->GetMatricula() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
                    qDebug() << " Se actualo la base de datos ";
                }
                else{
                    qDebug() << a->lastError();
                }
                break;
            }
            case 9:{
                qDebug() << "Se actualizara tipo de coche : " << auto_principal->GetTipo();
                if(a->exec("UPDATE auto SET tipo_de_coche = '"+ auto_principal->GetTipo() + "' WHERE id_cliente = "+ QString::number(cliente_principal->GetId()) +";")){
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
    }
    else{
        qDebug() << "No se puedo tener acceso o abrir la base de datos";
    }
}


void Cliente_P_Principal::on_Cancel_ReservapushButton_clicked()
{
    QSqlQuery *elimina = new QSqlQuery();

    int fila = ui->Mis_rservas_tableWidget->currentRow();
    int id = ui->Mis_rservas_tableWidget->item(fila,0)->text().toInt();

    QMessageBox ask;
    ask.setWindowTitle("\t\tAdvertencia");
    ask.setText("La reservación seleccionada será eliminada");
    ask.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    ask.setDefaultButton(QMessageBox::Yes);
    ask.setButtonText(QMessageBox::Yes,"Aceptar");
    ask.setButtonText(QMessageBox::No,"Cancelar");

    if(ask.exec()==QMessageBox::Yes){
        if(elimina->exec("DELETE FROM reservacion WHERE id_reservacion = "+QString::number(id)+";")){

            QMessageBox info;
            info.setWindowTitle("Datos de Reservación");
            info.setText("Su reservación ha sido cancelada de forma exitosa.");
            info.setStandardButtons(QMessageBox::Ok);
            info.setButtonText(QMessageBox::Ok,"Aceptar");
            info.exec();
            ui->Mis_rservas_tableWidget->clear();
            ui->Mis_rservas_tableWidget->setRowCount(0);
            QStringList titulos;
            titulos<<"ID Reservación"<<"Fecha"<<"Hora Entrada"<<"Hora Salida"<<"Num. Cajón"<<"Num. Piso";
            ui->Mis_rservas_tableWidget->setColumnCount(6);
            ui->Mis_rservas_tableWidget->setHorizontalHeaderLabels(titulos);
            VerReservaciones(cliente_principal->GetId());
        }
        else{
            qDebug()<<"NO se eliminó nada";
        }
    }
}


void Cliente_P_Principal::on_Reserva_pushButton_clicked()
{
    ui->Ventanas->setCurrentIndex(0);
}


void Cliente_P_Principal::on_MisReservas_pushButton_clicked()
{
    ui->Mis_rservas_tableWidget->clear();
    ui->Mis_rservas_tableWidget->setRowCount(0);
    QStringList titulos;
    titulos<<"ID Reservación"<<"Fecha"<<"Hora Entrada"<<"Hora Salida"<<"Num. Cajón"<<"Num. Piso" <<" Fecha Fin";
    ui->Mis_rservas_tableWidget->setColumnCount(7);
    ui->Mis_rservas_tableWidget->setHorizontalHeaderLabels(titulos);
    VerReservaciones(cliente_principal->GetId());
    ui->Ventanas->setCurrentIndex(3);
}

void Cliente_P_Principal::on_Contrato_pushButton_clicked()
{
    ui->Ventanas->setCurrentIndex(6);
}


void Cliente_P_Principal::on_Salir_pushButton_clicked()
{
    close();
}

void Cliente_P_Principal::on_L_1pushButton_clicked()
{
    idCajon = 1;
    idPiso = 2;
    ui->calendarWidget->setSelectedDate(ui->calendarWidget_2->selectedDate());
    ui->H_llegadatimeEdit->setTime(ui->H_llegadatimeEdit_2->time());
    QTime haux = ui->H_llegadatimeEdit_2->time();
    ui->H_salidatimeEdit->setTime(haux.addSecs(3600));
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_L_4pushButton_clicked()
{
    idCajon = 4;
    idPiso = 2;
    ui->calendarWidget->setSelectedDate(ui->calendarWidget_2->selectedDate());
    ui->H_llegadatimeEdit->setTime(ui->H_llegadatimeEdit_2->time());
    QTime haux = ui->H_llegadatimeEdit_2->time();
    ui->H_salidatimeEdit->setTime(haux.addSecs(3600));
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_L_2pushButton_clicked()
{
    idCajon = 2;
    idPiso = 2;
    ui->calendarWidget->setSelectedDate(ui->calendarWidget_2->selectedDate());
    ui->H_llegadatimeEdit->setTime(ui->H_llegadatimeEdit_2->time());
    QTime haux = ui->H_llegadatimeEdit_2->time();
    ui->H_salidatimeEdit->setTime(haux.addSecs(3600));
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_L_3pushButton_clicked()
{
    idCajon = 3;
    idPiso = 2;
    ui->calendarWidget->setSelectedDate(ui->calendarWidget_2->selectedDate());
    ui->H_llegadatimeEdit->setTime(ui->H_llegadatimeEdit_2->time());
    QTime haux = ui->H_llegadatimeEdit_2->time();
    ui->H_salidatimeEdit->setTime(haux.addSecs(3600));
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_L_5pushButton_clicked()
{
    idCajon = 5;
    idPiso = 2;
    ui->calendarWidget->setSelectedDate(ui->calendarWidget_2->selectedDate());
    ui->H_llegadatimeEdit->setTime(ui->H_llegadatimeEdit_2->time());
    QTime haux = ui->H_llegadatimeEdit_2->time();
    ui->H_salidatimeEdit->setTime(haux.addSecs(3600));
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_L_6pushButton_clicked()
{
    idCajon = 6;
    idPiso = 2;
    ui->calendarWidget->setSelectedDate(ui->calendarWidget_2->selectedDate());
    ui->H_llegadatimeEdit->setTime(ui->H_llegadatimeEdit_2->time());
    QTime haux = ui->H_llegadatimeEdit_2->time();
    ui->H_salidatimeEdit->setTime(haux.addSecs(3600));
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_L_7pushButton_clicked()
{
    idCajon = 7;
    idPiso = 2;
    ui->calendarWidget->setSelectedDate(ui->calendarWidget_2->selectedDate());
    ui->H_llegadatimeEdit->setTime(ui->H_llegadatimeEdit_2->time());
    QTime haux = ui->H_llegadatimeEdit_2->time();
    ui->H_salidatimeEdit->setTime(haux.addSecs(3600));
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_L_8pushButton_clicked()
{
    idCajon = 8;
    idPiso = 2;
    ui->calendarWidget->setSelectedDate(ui->calendarWidget_2->selectedDate());
    ui->H_llegadatimeEdit->setTime(ui->H_llegadatimeEdit_2->time());
    QTime haux = ui->H_llegadatimeEdit_2->time();
    ui->H_salidatimeEdit->setTime(haux.addSecs(3600));
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_L_9pushButton_clicked()
{
    idCajon = 9;
    idPiso = 2;
    ui->calendarWidget->setSelectedDate(ui->calendarWidget_2->selectedDate());
    ui->H_llegadatimeEdit->setTime(ui->H_llegadatimeEdit_2->time());
    QTime haux = ui->H_llegadatimeEdit_2->time();
    ui->H_salidatimeEdit->setTime(haux.addSecs(3600));
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_L_10pushButton_clicked()
{
    idCajon = 10;
    idPiso = 2;
    ui->calendarWidget->setSelectedDate(ui->calendarWidget_2->selectedDate());
    ui->H_llegadatimeEdit->setTime(ui->H_llegadatimeEdit_2->time());
    QTime haux = ui->H_llegadatimeEdit_2->time();
    ui->H_salidatimeEdit->setTime(haux.addSecs(3600));
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_Nueva_Reserva_pushButton_clicked()
{
    ui->Ventanas->setCurrentIndex(0);
}


void Cliente_P_Principal::on_Nivel3_pushButton_clicked()
{
    ui->Ventanas->setCurrentIndex(1);
}

void Cliente_P_Principal::on_Nivel2_pushButton_3_clicked()
{
    ui->Ventanas->setCurrentIndex(0);
}

void Cliente_P_Principal::on_LL_1pushButton_3_clicked()
{
    idCajon = 1;
    idPiso = 3;
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_LL_2pushButton_3_clicked()
{
    idCajon = 2;
    idPiso = 3;
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_LL_3pushButton_3_clicked()
{
    idCajon = 3;
    idPiso = 3;
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_LL_4pushButton_3_clicked()
{
    idCajon = 4;
    idPiso = 3;
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_LL_5pushButton_3_clicked()
{
    idCajon = 5;
    idPiso = 3;
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_LL_6pushButton_3_clicked()
{
    idCajon = 6;
    idPiso = 3;
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_LL_7pushButton_3_clicked()
{
    idCajon = 7;
    idPiso = 3;
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_LL_8pushButton_3_clicked()
{
    idCajon = 8;
    idPiso = 3;
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_L_9pushButton_3_clicked()
{
    idCajon = 9;
    idPiso = 3;
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_LL_10pushButton_3_clicked()
{
    idCajon = 10;
    idPiso = 3;
    ui->Ventanas->setCurrentIndex(2);
}

void Cliente_P_Principal::on_calendarWidget_2_selectionChanged()
{
    qDebug()<<"evento calendario";
    QDate fecha = ui->calendarWidget_2->selectedDate();
    QString f_entrada = fecha.toString("yyyyMMdd");
    QTime hora = ui->H_llegadatimeEdit_2->time();
    QString h_entrada = hora.toString();
    vaciar();
    CargarLugares(2,f_entrada,h_entrada);
}

void Cliente_P_Principal::on_H_llegadatimeEdit_2_timeChanged(const QTime &time)
{
    qDebug()<<"evento tiempo";
    QDate fecha = ui->calendarWidget_2->selectedDate();
    QString f_entrada = fecha.toString("yyyyMMdd");
    QTime hora = ui->H_llegadatimeEdit_2->time();
    QString h_entrada = hora.toString();
    vaciar();
    CargarLugares(2,f_entrada,h_entrada);
}
/*RSERVA POR INTERVALOS DE TIEMPO*/

void Cliente_P_Principal::on_Confirma_Reserva_pushButton_clicked()
{

    int i;
    qDebug() << "*****************";
    for(i = 0; i < ListaIntervalos->size(); ++i){
       Reser aux2 = ListaIntervalos->at(i);
       qDebug() << "Fecha Inici : "<< aux2.GetFecha_Inicio();
       qDebug() << "Fecha Fin : "<< aux2.GetFecha_Fin();
    }
    qDebug() << "*****************";


    QMessageBox ask;
     ask.setWindowTitle("\t\tReservacion por intervalos");
     ask.setText("¿Desea agregar mas intervalos de reservacion?");
     ask.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
     ask.setDefaultButton(QMessageBox::Yes);
     ask.setButtonText(QMessageBox::Yes,"Agregar Reservaciones");
     ask.setButtonText(QMessageBox::No,"Cancelar");

      if(ask.exec()==QMessageBox::Yes){ // Agregar mas intervalos al objeto
        int inte;
        QSqlQuery *insertar = new QSqlQuery();
        Reser aux3;
          for(inte = 0; inte < ListaIntervalos->size(); ++inte){
               aux3 = ListaIntervalos->at(inte);


             if(insertar->exec("Insert into reservacion(fecha, h_entrada, h_salida, num_cajones, num_dias, fecha_inicio, fecha_fin, id_cliente, id_cajon, id_piso) VALUES('"+aux3.GetFecha_Inicio()+"','"+aux3.GetHora_Entrada()+"','"+aux3.GetHora_Salida()+"','1','"+QString::number(aux3.GetDias()) +"','"+ aux3.GetFecha_Inicio()+"','"+ aux3.GetFecha_Fin()+"','"+QString::number(cliente_principal->GetId())+"','"+QString::number(idCajon)+"','"+QString::number(idPiso)+"')")){
                 qDebug() << "** Correcto ** ";
             }else{
                 qDebug() << "xx Incorrecto xx " << insertar->lastError();
             }

          }

          delete insertar;
          QMessageBox info;
          info.setWindowTitle("Datos de Reservación");
          info.setText("Su reservación ha sido agendada.");
          info.setStandardButtons(QMessageBox::Ok);
          info.setButtonText(QMessageBox::Ok,"Aceptar");
          info.exec();
          ui->intervalos_tableWidget->clear();
          ui->intervalos_tableWidget->setRowCount(0);

      }
}



void Cliente_P_Principal::on_Aceptar_pushButton_clicked()
{

    QSqlQuery *a = new QSqlQuery();
    QSqlQuery *b = new QSqlQuery();           /*Aqui van los QUERYS para insertar la suscripcion y actualizar el usuario*/
    QMessageBox ask;
     ask.setWindowTitle("\t\tAviso Importante");
     ask.setText("¿Esta seguro de cambiar el modo de perfil?.\n"
                  "Pasara de cliente premium a clente basico\n"
                  "Perdera muchisimos beneficios");
     ask.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
     ask.setDefaultButton(QMessageBox::Yes);
     ask.setButtonText(QMessageBox::Yes,"Aceptar");
     ask.setButtonText(QMessageBox::No,"Cancelar");

      if(ask.exec()==QMessageBox::Yes){


       if(a->exec("DELETE FROM suscripción where id_cliente ="+ QString::number(cliente_principal->GetId()) +";")){

                        if(b->exec("UPDATE usuario SET tipo_usuario='clientebasico' where id_usuario="+QString::number(cliente_principal->GetIdUsuario()) +";")){
                            QMessageBox info;
                            info.setWindowTitle("Suscripcion Premium Cancelada");
                            info.setText("Su SUSCRIPCION PREMIUM a sido cancelada exitosamente, vuelva a INICIAR SESION");
                            info.setStandardButtons(QMessageBox::Ok);
                            info.setButtonText(QMessageBox::Ok,"Aceptar");
                            info.exec();
                            close();


                        }
                        else{
                            qDebug()<<"Fallo Actualizacion de usuario " << b->lastError();
                        }

                }
                else{
                    qDebug()<<"Fallo inssercion de suscripcion " << a->lastError();
                }
            }




}

void Cliente_P_Principal::on_Historial_reserv_pushButton_clicked()
{
    ui->Ventanas->setCurrentIndex(4);
    ui->Mis_rservas_tableWidget->clear();
    //Datos para la tabla "Historial de reservaciones"
    QStringList titles_tabla_Historial;
    titles_tabla_Historial<<"ID Reservación"<<"Fecha"<<"Hora Entrada"<<"Hora Salida"<<"Fecha inicial" <<"Fecha final" <<"Num. Cajón"<<"Num. Piso";
    ui->tabla_reservaciones_tableWidget ->setColumnCount(8);
    ui->tabla_reservaciones_tableWidget->setHorizontalHeaderLabels(titles_tabla_Historial);
    //Mando a llamar a la funcion
    Ver_HistorialReservaciones(cliente_principal->GetId());
}
/*El siguiente metodo pertenece a la historia de reservacion
premium agrega elementos para reservaciones por intervalos*/
void Cliente_P_Principal::on_agregar_pushButton_clicked()
{
    QDate fecha = ui->calendarWidget->selectedDate();
    QString f_entrada = fecha.toString("yyyyMMdd");

    QDate fecha_fin = ui->fincalendarWidget_3->selectedDate();
    QString f_fin = fecha_fin.toString("yyyyMMdd");

    QTime hora = ui->H_llegadatimeEdit->time();
    QString h_entrada = hora.toString();
    QTime salida = ui->H_salidatimeEdit->time();
    QString h_salida = salida.toString();
    Reser aux;
    int d = 0;

    int diferencia =fecha_fin.month() - fecha.month();

    if(diferencia == 0){
        d = fecha_fin.day() - fecha.day();
    }
    else{
        d = (diferencia * 30) + (fecha_fin.day() - fecha.day());
    }

    aux.Set_FechaInicio(f_entrada);
    aux.Set_FechaFin(f_fin);
    aux.Set_HoraEntrada(h_entrada);
    aux.Set_HoraSalida(h_salida);

    aux.Set_Dias(d);
    int fila;

           ui->intervalos_tableWidget->insertRow(ui->intervalos_tableWidget->rowCount());
           fila = ui->intervalos_tableWidget->rowCount() - 1;
           // ui->Mis_rservas_tableWidget->insertRow(ui->Mis_rservas_tableWidget->rowCount());
           // fila = ui->Mis_rservas_tableWidget->rowCount()-1;
           ui->intervalos_tableWidget->setItem(fila,0,new QTableWidgetItem(aux.GetFecha_Inicio()));
           ui->intervalos_tableWidget->setItem(fila,1,new QTableWidgetItem(aux.GetFecha_Fin()));
           ui->intervalos_tableWidget->setItem(fila,2,new QTableWidgetItem(aux.GetHora_Entrada()));
           ui->intervalos_tableWidget->setItem(fila,3,new QTableWidgetItem(aux.GetHora_Salida()));
           ui->intervalos_tableWidget->setItem(fila,4,new QTableWidgetItem(QString::number(aux.GetDias())));

     // Igualar calentarios
    ui->calendarWidget->showToday();
    ui->fincalendarWidget_3->showToday();
    ListaIntervalos->append(aux);
    qDebug() << " Se agrego sin pedos ";

}

/*Cancelar la reservacion.*/
void Cliente_P_Principal::on_cancelar_reser_pushButton_clicked()
{

    ui->intervalos_tableWidget->clear();
    ui->intervalos_tableWidget->setRowCount(0);

    ui->Ventanas->setCurrentIndex(0);
    ui->calendarWidget->showToday();
    ui->fincalendarWidget_3->showToday();
    delete ListaIntervalos;
    ListaIntervalos = new QList<Reser>();
    qDebug() << " Todo correcot ";

}
