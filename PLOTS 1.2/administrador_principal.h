#ifndef ADMINISTRADOR_PRINCIPAL_H
#define ADMINISTRADOR_PRINCIPAL_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>


#include "eliminarclienteb.h"

namespace Ui {
class Administrador_Principal;
}

class Administrador_Principal : public QDialog
{
    Q_OBJECT

public:
    explicit Administrador_Principal(QSqlDatabase , int b = 0,QWidget *parent = nullptr);
    ~Administrador_Principal();

private slots:
    void on_Salir_pushButton_clicked();

    void on_Eliminar_pushButton_clicked();

private:
    Ui::Administrador_Principal *ui;
    int Id_Usuario;
    QSqlDatabase PrincipalAdministrador;
    EliminarClienteB *principal_eliminar;
};

#endif // ADMINISTRADOR_PRINCIPAL_H
