#include "inicio_sesion.h"
#include "ui_inicio_sesion.h"

Inicio_Sesion::Inicio_Sesion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inicio_Sesion)
{
    ui->setupUi(this);


}

Inicio_Sesion::~Inicio_Sesion()
{
    delete ui;
}


void Inicio_Sesion::on_Entrar_pushButton_clicked()
{

}

void Inicio_Sesion::on_Cancelar_pushButton_clicked()
{
    close();
}

void Inicio_Sesion::on_Registrarse_pushButton_clicked()
{
    registro = new Registar_ClienteB(); //Agregarle el padre iniciar sesion
    registro->show();
}
