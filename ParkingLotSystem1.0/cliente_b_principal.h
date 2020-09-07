#ifndef CLIENTE_B_PRINCIPAL_H
#define CLIENTE_B_PRINCIPAL_H

#include <QDialog>
#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

#include "cliente_basico.h"
#include "actualizar_datos.h"
namespace Ui {
class Cliente_B_Principal;
}

class Cliente_B_Principal : public QDialog
{
    Q_OBJECT

public:
    explicit Cliente_B_Principal(int);
    explicit Cliente_B_Principal(QSqlDatabase ,int b =0 ,QWidget *parent = nullptr);
    ~Cliente_B_Principal();

private slots:
    void on_pushButton_2_clicked();

    void on_Editar_Info_pushButton_clicked();

    void ObtenerObjeto();



private:
    Ui::Cliente_B_Principal *ui;
    int Id_Usuario;
    QSqlDatabase PrincipalCliente;
    Cliente_Basico *cliente_principal;
    Actualizar_Datos *Principal_Actualizar;

};

#endif // CLIENTE_B_PRINCIPAL_H
