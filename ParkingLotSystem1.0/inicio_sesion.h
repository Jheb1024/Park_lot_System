#ifndef INICIO_SESION_H
#define INICIO_SESION_H

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMainWindow>
#include "registar_clienteb.h"
#include "cliente_basico.h"
#include <QMessageBox>
#include "administrador.h"
#include "cliente_basico.h"
#include "cliente_b_principal.h"
#include "administrador_principal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Inicio_Sesion; }
QT_END_NAMESPACE

class Inicio_Sesion : public QMainWindow
{
    Q_OBJECT

public:
    Inicio_Sesion(QWidget *parent = nullptr);
    ~Inicio_Sesion();
    QSqlDatabase mDatabase;
    void Limpiar();

private slots:
    void on_Entrar_pushButton_clicked();

    void on_Cancelar_pushButton_clicked();

    void on_Registrarse_pushButton_clicked();

private:
    Ui::Inicio_Sesion *ui;

    Registar_ClienteB *registro;
    Administrador *Admin;
    Cliente_Basico *Cliente_B;
    int Id;
};
#endif // INICIO_SESION_H
