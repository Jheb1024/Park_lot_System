#include "administrador_principal.h"
#include "ui_administrador_principal.h"

Administrador_Principal::Administrador_Principal(QSqlDatabase a, int b,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administrador_Principal)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint); //Elimina el ícono de ayuda del qdialog
    ui->setupUi(this);
    Id_Usuario = b;
    PrincipalAdministrador = a;
    if(!PrincipalAdministrador.isOpen()){
        if(PrincipalAdministrador.open()){
                qDebug() << " La base de datos se abrio ";
        }else{
            qDebug() << PrincipalAdministrador.lastError();
        }
    }else{
        qDebug() << "Base de datos abierta";
    }


}

Administrador_Principal::~Administrador_Principal()
{
    delete ui;
}

void Administrador_Principal::on_Salir_pushButton_clicked()
{
    close();
}

void Administrador_Principal::on_Eliminar_pushButton_clicked()
{
    principal_eliminar = new EliminarClienteB();
    principal_eliminar->show();
}

void Administrador_Principal::on_VerClientes_pushButton_2_clicked()
{
    ui->Admi_ventanas->setCurrentIndex(0);

    clientemodel = new QSqlTableModel(this);
    clientemodel->setTable("cliente");
    clientemodel->select();
    clientemodel->setHeaderData(0, Qt::Horizontal, tr("ID CLIENTE"));
    clientemodel->setHeaderData(1, Qt::Horizontal, tr("NOMBRE"));
    clientemodel->setHeaderData(2, Qt::Horizontal, tr("APELLIDO PATERNO"));
    clientemodel->setHeaderData(3, Qt::Horizontal, tr("APELLIDO MATERNO"));
    clientemodel->setHeaderData(4, Qt::Horizontal, tr("CORREO"));
    clientemodel->setHeaderData(5, Qt::Horizontal, tr("TELEFONO"));
    clientemodel->setHeaderData(6, Qt::Horizontal, tr("CALLE"));
    clientemodel->setHeaderData(7, Qt::Horizontal, tr("NÚMERO DE CASA"));
    clientemodel->setHeaderData(8, Qt::Horizontal, tr("ID USUARIO"));
    clientemodel->setHeaderData(8, Qt::Horizontal, tr("ID TARJETA"));
    ui->Clientes_tableView->setModel(clientemodel);
}

void Administrador_Principal::on_VerReservas_pushButton_2_clicked()
{
    ui->Admi_ventanas->setCurrentIndex(1);

    reservasmodel = new QSqlTableModel(this);
    reservasmodel->setTable("reservacion");
    reservasmodel->select();
    reservasmodel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    reservasmodel->setHeaderData(1, Qt::Horizontal, tr("FECHA"));
    reservasmodel->setHeaderData(2, Qt::Horizontal, tr("HORA ENTRADA"));
    reservasmodel->setHeaderData(3, Qt::Horizontal, tr("HORA SALIDA"));
    reservasmodel->setHeaderData(4, Qt::Horizontal, tr("CAJON"));
    reservasmodel->setHeaderData(5, Qt::Horizontal, tr("DÍAS"));
    reservasmodel->setHeaderData(6, Qt::Horizontal, tr("FECHA INICIO"));
    reservasmodel->setHeaderData(7, Qt::Horizontal, tr("FECHA FIN"));
    reservasmodel->setHeaderData(8, Qt::Horizontal, tr("USUARIO"));
    ui->Reservaciones_tableView->setModel(reservasmodel);
}

void Administrador_Principal::on_Entradas_Salidas_pushButton_2_clicked()
{
    ui->Admi_ventanas->setCurrentIndex(2);
}
