#include "forma_pago.h"
#include "ui_forma_pago.h"

Forma_Pago::Forma_Pago(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forma_Pago)
{
    ui->setupUi(this);
    setWindowTitle("Datos Bancarios");
    Aux = new Tarjeta();
    QStringList Tipos = {"Credito","Debito","Departamental","Otros"};
    ui->tipo_comboBox->addItems(Tipos);
}

Forma_Pago::~Forma_Pago()
{
    delete Aux;
    delete ui;
}

Tarjeta *Forma_Pago::GetTarjeta()
{
    return Aux;
}

bool Forma_Pago::VerificacionCampos()
{


    if(ui->Numero_Tarjeta_lineEdit->text() == "")
        return false;
    if(ui->Caducidad_lineEdit->text() == "")
        return false;
    if(ui->Caducidad_lineEdit_2->text() == "")
        return false;
    if(ui->spinBox->value() == 0)
        return false;

    return true;
}

void Forma_Pago::on_Entrar_Pago_buttonBox_accepted()
{
    //FaltaVerificarCaposVacios

    QString cadu = ui->Caducidad_lineEdit->text() + ui->Caducidad_lineEdit_2->text();
    if(VerificacionCampos()){
    Aux->Registrar_Datos(ui->Numero_Tarjeta_lineEdit->text(),
                         ui->tipo_comboBox->currentText(),
                         cadu,
                         QString::number(ui->spinBox->value()));
    accept();
    }else{
        QMessageBox::information(this,"Campos Vacios","Todos los campos son obligatorios");
    }



}

void Forma_Pago::on_Entrar_Pago_buttonBox_rejected()
{
    reject();
}
