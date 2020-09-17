#include "ingresaconreserva.h"
#include "ui_ingresaconreserva.h"

ingresaconreserva::ingresaconreserva(QSqlDatabase bd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ingresaconreserva)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint); //Elimina el ícono de ayuda del qdialog
    base = bd;
    idRes = -1;
    ui->setupUi(this);
}

ingresaconreserva::~ingresaconreserva()
{

    delete ui;
}

void ingresaconreserva::on_Pagar_pushButton_clicked()
{
    if(idRes == -1)
        QMessageBox::critical(this,"Error","No ha ingresado un ID de reservación válido","Aceptar");
    else{
        pagar *Pago = new pagar(base,idRes,this);
        Pago->show();
    }
    this->close();
}

void ingresaconreserva::on_Cancel_pushButton_clicked()
{
    close();
}

void ingresaconreserva::on_Acept_pushButton_clicked()
{
    QSqlQuery *entra = new QSqlQuery();

    QString id = ui->Codigo_lineEdit->text();

    if(entra->exec("SELECT id_piso, id_cajon, fecha, h_entrada FROM reservacion WHERE id_reservacion = "+ui->Codigo_lineEdit->text()+";")){
        while(entra->next()){
            idRes = id.toInt();
            QMessageBox info;
            info.setWindowTitle("Datos de Reservación");
            info.setText("Bienvenido/a <<Agregar Nombre>>\n Su cajón es el "+entra->value(1).toString()+" y su piso es el "+entra->value(0).toString()+".");
            info.setStandardButtons(QMessageBox::Ok);
            info.setButtonText(QMessageBox::Ok,"Aceptar");
            info.exec();
        }
    }
    else{
        QMessageBox::critical(this,"Error","No existe una reservación para ese ID","Aceptar");
    }
    delete entra;
}
