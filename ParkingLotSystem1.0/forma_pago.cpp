#include "forma_pago.h"
#include "ui_forma_pago.h"

Forma_Pago::Forma_Pago(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forma_Pago)
{
    ui->setupUi(this);
    setWindowTitle("Datos Bancarios");
    Aux = new Tarjeta();
    QStringList Bancos = {"Santander","HSBC","BBVA Bancomer","Banamex","BanCoopel","Banco Azteca",
                         "Imbursa","Banco del Bienestar"};
    ui->Banco_comboBox->addItems(Bancos);
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
    if(ui->Nombre_Propietario_lineEdit->text() == "")
        return false;
    if(ui->Numero_Tarjeta_lineEdit->text() == "")
        return false;
    if(ui->Caducidad_lineEdit->text() == "")
        return false;
    if(ui->spinBox->value() == 0)
        return false;

    return true;
}

void Forma_Pago::on_Entrar_Pago_buttonBox_accepted()
{
    //FaltaVerificarCaposVacios
    if(VerificacionCampos()){
    Aux->Registrar_Datos(ui->Nombre_Propietario_lineEdit->text(),
                         ui->Numero_Tarjeta_lineEdit->text(),
                         ui->Banco_comboBox->currentText(),
                         ui->Caducidad_lineEdit->text(),
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
