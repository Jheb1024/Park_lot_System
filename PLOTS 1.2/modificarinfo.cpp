#include "modificarinfo.h"
#include "ui_modificarinfo.h"

ModificarInfo::ModificarInfo(Cliente_Basico *a,Auto *b,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarInfo)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint); //Elimina el ícono de ayuda del qdialog
    ui->setupUi(this);
    Aux = new Cliente_Basico();
    Aux2 = new Auto();
    Aux = a;
    Aux2 = b;
    Actualizo = false;

    ui->NOmbre_lineEdit->setText(Aux->GetNombre());
    ui->ApellidoP_lineEdit_2->setText(Aux->GetApellido_Paterno());
    ui->ApellidoM_lineEdit->setText(Aux->GetApellido_Materno());
    ui->Calle_lineEdit_2->setText(Aux->GetCalle());
    ui->NumeroT_lineEdit->setText(Aux->GetTelefono());
    ui->NumeroC_lineEdit->setText(Aux->GetNumero_Domicilio());
    ui->mail_lineEdit->setText(Aux->GetCorreo_Electronico());


    ui->Matricula_lineEdit->setText(Aux2->GetMatricula());


    ui->Tipo_Coche_comboBox->addItem("Camioneta");
    ui->Tipo_Coche_comboBox->addItem("Sedan");
    ui->Tipo_Coche_comboBox->addItem("Familiar");
    ui->Tipo_Coche_comboBox->addItem("Pick-up");
    ui->Tipo_Coche_comboBox->addItem("Auto-Compacto");
    ui->Tipo_Coche_comboBox->addItem("Motocicleta");



}

ModificarInfo::~ModificarInfo()
{
    delete ui;
}

Cliente_Basico *ModificarInfo::GetCliente()
{
    return Aux;
}

Auto * ModificarInfo::GetAuto()
{
    return Aux2;
}

QList<int> ModificarInfo::GetLista()
{
    return actualizados;
}




void ModificarInfo::on_Editar_buttonBox_accepted()
{
    QMessageBox::StandardButton reply;
         reply = QMessageBox::question(this, "Confirmacion de cambios", "Deseas guardar los cambios establecidos",
                                       QMessageBox::Yes|QMessageBox::No);
         if (reply == QMessageBox::Yes) {
           qDebug() << "Yes was clicked";

           if(Aux->GetNombre() != ui->NOmbre_lineEdit->text()){
               Actualizo = true;
               actualizados << 1;
               Aux->SetNombre(ui->NOmbre_lineEdit->text());

           }
           if(Aux->GetApellido_Paterno() != ui->ApellidoP_lineEdit_2->text()){
               Actualizo = true;
               actualizados << 2;
               Aux->SetApellido_P(ui->ApellidoP_lineEdit_2->text());

           }
           if(Aux->GetApellido_Materno() != ui->ApellidoM_lineEdit->text()){
               Actualizo = true;
               actualizados << 3;
               Aux->SetApellido_M(ui->ApellidoM_lineEdit->text());
           }
           if(Aux->GetCorreo_Electronico() != ui->mail_lineEdit->text()){
               Actualizo = true;
               actualizados << 4;
               Aux->SetCorreo(ui->mail_lineEdit->text());
           }
           if(Aux->GetTelefono() != ui->NumeroT_lineEdit->text()){
               Actualizo = true;
               actualizados << 5;
               Aux->SetTelefono(ui->NumeroT_lineEdit->text());
           }
           if(Aux->GetCalle() != ui->Calle_lineEdit_2->text()){
               Actualizo = true;
               actualizados << 6;
               Aux->SetCalle(ui->Calle_lineEdit_2->text());
           }
           if(Aux->GetNumero_Domicilio() != ui->NumeroC_lineEdit->text()){
               Actualizo = true;
               actualizados << 7;
               Aux->SetNumero_Domicilio(ui->NumeroC_lineEdit->text());
           }
           if(Aux2->GetMatricula() != ui->Matricula_lineEdit->text()){
               Actualizo = true;
               actualizados << 8;
               Aux2->SetMatricula(ui->Matricula_lineEdit->text());
           }
           if(Aux2->GetTipo() != ui->Tipo_Coche_comboBox->currentText()){
               Actualizo = true;
               actualizados << 9;
               Aux2->SetTipo(ui->Tipo_Coche_comboBox->currentText());
           }

           if(Actualizo){
               emit (Mandar_Objeto());
               qDebug() << " Se emitio la señal 1";

           }


           accept();


         } else {
           qDebug() << "Yes was *not* clicked";
         }















}

void ModificarInfo::on_Editar_buttonBox_rejected()
{
    reject();
}

