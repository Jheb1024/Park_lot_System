#include "eliminarclienteb.h"
#include "ui_eliminarclienteb.h"

EliminarClienteB::EliminarClienteB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EliminarClienteB)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint); //Elimina el ícono de ayuda del qdialog
    ui->setupUi(this);
    nModel = new QSqlTableModel(this);
    nModel->setTable("cliente");
    nModel->select();
    ui->tableView->setModel(nModel);



}

EliminarClienteB::~EliminarClienteB()
{
    delete ui;
}


void EliminarClienteB::on_Eliminar_pushButton_clicked()
{
  qDebug() << "Linea en teoria a eliminar : " << ui->tableView->currentIndex().row();
  nModel->removeRow(ui->tableView->currentIndex().row());
  nModel->select();
  ui->tableView->setModel(nModel);
}



void EliminarClienteB::on_Salir_pushButton_clicked()
{
    close();
}
