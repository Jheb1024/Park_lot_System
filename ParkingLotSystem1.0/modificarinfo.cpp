#include "modificarinfo.h"
#include "ui_modificarinfo.h"

ModificarInfo::ModificarInfo(Cliente_Basico *a,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarInfo)
{
    ui->setupUi(this);
    Aux = new Cliente_Basico();
    Aux = a;
    Actualizo = false;

    ui->NOmbre_lineEdit->setText(Aux->GetNombre());
    ui->ApellidoP_lineEdit_2->setText(Aux->GetApellido_Paterno());
    ui->ApellidoM_lineEdit->setText(Aux->GetApellido_Materno());
    ui->Pais_lineEdit->setText(Aux->GetPais());
    ui->Estado_lineEdit->setText(Aux->GetEstado());
    ui->Ciudad_lineEdit->setText(Aux->GetCiudad());
    ui->Calle_lineEdit_2->setText(Aux->GetCalle());
    ui->NumeroT_lineEdit->setText(Aux->GetTelefono());
    ui->NumeroC_lineEdit->setText(Aux->GetNumero_Domicilio());
    ui->mail_lineEdit->setText(Aux->GetCorreo_Electronico());
    ui->Matricula_lineEdit->setText(Aux->GetMatricula());


    ui->Tipo_Coche_comboBox->addItem("Camioneta");
    ui->Tipo_Coche_comboBox->addItem("Sedan");
    ui->Tipo_Coche_comboBox->addItem("Familiar");
    ui->Tipo_Coche_comboBox->addItem("Pick-up");
    ui->Tipo_Coche_comboBox->addItem("Auto-Compacto");
}

ModificarInfo::~ModificarInfo()
{
    delete ui;
}

Cliente_Basico *ModificarInfo::GetCliente()
{
        return Aux;
}




void ModificarInfo::on_Editar_buttonBox_accepted()
{
    if(Actualizo){
        emit (Mandar_Objeto());
        qDebug() << " Se emitio la señal 1";

    }

    close();
}

void ModificarInfo::on_Editar_buttonBox_rejected()
{
    close();
}

void ModificarInfo::on_Editar_Personales_pushButton_clicked()
{
    Actualizo = true;
    Aux->SetNombre(ui->NOmbre_lineEdit->text());
}

void ModificarInfo::on_Editar_Auto_pushButton_clicked()
{
        Actualizo = true;
}
