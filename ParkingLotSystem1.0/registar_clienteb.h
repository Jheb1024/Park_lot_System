#ifndef REGISTAR_CLIENTEB_H
#define REGISTAR_CLIENTEB_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "forma_pago.h"
#include "cliente_basico.h"
#include "forma_pago.h"
#include "usuario.h"
#include "tarjeta.h"
#include <QMessageBox>


namespace Ui {
class Registar_ClienteB;
}

class Registar_ClienteB : public QDialog
{
    Q_OBJECT

public:
    explicit Registar_ClienteB(QSqlDatabase ,QWidget *parent = nullptr);
    ~Registar_ClienteB();

    void VerificarBase();
    void ProbarBase();

    bool VerificarCamposVacios();


private slots:

    void on_pushButton_clicked();

    void on_Aceptar_pushButton_clicked();

    void on_Cancelar_pushButton_clicked();

private:
    Ui::Registar_ClienteB *ui;
    Forma_Pago *Ventana_Datos_Bancarios;
    Cliente_Basico *nuevo; // HAY QUE AGREGAR UN METODO EN CLIENTE QUE ME DIGA SI LA TARJETA ES NULL
    Usuario *usuario_nuevo;
    Tarjeta *tarjeta;
    Forma_Pago *pago_nuevo;
    QSqlDatabase PrincipalRegistro;
    int id_usuario;
    int id_tarjeta;

};

#endif // REGISTAR_CLIENTEB_H
