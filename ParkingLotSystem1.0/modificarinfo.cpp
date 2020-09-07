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


    ui->tabWidget->setTabText(0,"Datos Personales");
    ui->tabWidget->setTabText(1,"Datos del Automovil");
}

ModificarInfo::~ModificarInfo()
{
    delete ui;
}

Cliente_Basico *ModificarInfo::GetCliente()
{
    return Aux;
}

QList<int> ModificarInfo::GetLista()
{
    return actualizados;
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

    if(Aux->GetNombre() != ui->NOmbre_lineEdit->text()){
        actualizados << 1;
        Aux->SetNombre(ui->NOmbre_lineEdit->text());

    }
    if(Aux->GetApellido_Paterno() != ui->ApellidoP_lineEdit_2->text()){
        actualizados << 2;
        Aux->SetApellido_P(ui->ApellidoP_lineEdit_2->text());

    }
    if(Aux->GetApellido_Materno() != ui->ApellidoM_lineEdit->text()){
        actualizados << 3;
        Aux->SetApellido_M(ui->ApellidoM_lineEdit->text());
    }
    if(Aux->GetCorreo_Electronico() != ui->mail_lineEdit->text()){
        actualizados << 4;
        Aux->SetCorreo(ui->mail_lineEdit->text());
    }
    if(Aux->GetTelefono() != ui->NumeroT_lineEdit->text()){
        actualizados << 5;
        Aux->SetTelefono(ui->NumeroT_lineEdit->text());
    }
    if(Aux->GetPais() != ui->Pais_lineEdit->text()){
        actualizados << 6;
        Aux->SetPais(ui->Pais_lineEdit->text());
    }
    if(Aux->GetCiudad() != ui->Ciudad_lineEdit->text()){
        actualizados << 7;
        Aux->SetCiudad(ui->Ciudad_lineEdit->text());
    }
    if(Aux->GetEstado() != ui->Estado_lineEdit->text()){
        actualizados << 8;
        Aux->SetEstado(ui->Estado_lineEdit->text());
    }
    if(Aux->GetCalle() != ui->Calle_lineEdit_2->text()){
        actualizados << 9;
        Aux->SetCalle(ui->Calle_lineEdit_2->text());
    }
    if(Aux->GetNumero_Domicilio() != ui->NumeroC_lineEdit->text()){
        actualizados << 10;
        Aux->SetNumero_Domicilio(ui->NumeroC_lineEdit->text());
    }

    QMessageBox::information(this,"Informacion","Se actualizaran sus datos personales");


}

void ModificarInfo::on_Editar_Auto_pushButton_clicked()
{
        Actualizo = true;
        if(Aux->GetMatricula() != ui->Matricula_lineEdit->text()){
            actualizados << 11;
            Aux->SetMatricula(ui->Matricula_lineEdit->text());
        }
        if(Aux->GetTipoCoche() != ui->Tipo_Coche_comboBox->currentText()){
            actualizados << 12;
            Aux->SetTipo_Coche(ui->Tipo_Coche_comboBox->currentText());
        }
   QMessageBox::information(this,"Informacion","Se actualizaran los datos del automovil");
}
