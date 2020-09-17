#include "pagar.h"
#include "ui_pagar.h"

pagar::pagar(QSqlDatabase bd, int pID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pagar)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint); //Elimina el ícono de ayuda del qdialog
    base = bd;
    id = pID;
    ui->setupUi(this);
}

pagar::~pagar()
{
    delete ui;
}

void pagar::on_pushButton_clicked()
{
    QSqlQuery *pagar = new QSqlQuery();

    if(pagar->exec("DELETE FROM reservacion WHERE id_reservacion = "+QString::number(id)+";")){
        QMessageBox info;
        info.setWindowTitle("¡Pago exitoso!");
        info.setText("Su pago fue realizado con éxito.\n¡Gracias por usar nuestro servicio!");
        info.setStandardButtons(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }
    delete pagar;
    this->close();
}
