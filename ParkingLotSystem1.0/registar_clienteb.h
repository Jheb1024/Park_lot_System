#ifndef REGISTAR_CLIENTEB_H
#define REGISTAR_CLIENTEB_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "forma_pago.h"
#include "cliente_basico.h"


namespace Ui {
class Registar_ClienteB;
}

class Registar_ClienteB : public QDialog
{
    Q_OBJECT

public:
    explicit Registar_ClienteB(QWidget *parent = nullptr);
    ~Registar_ClienteB();

private slots:
    void on_Accion_buttonBox_accepted();

    void on_Accion_buttonBox_rejected();

    void on_pushButton_clicked();

private:
    Ui::Registar_ClienteB *ui;
    Forma_Pago *Ventana_Datos_Bancarios;
    Cliente_Basico *nuevo; // HAY QUE AGREGAR UN METODO EN CLIENTE QUE ME DIGA SI LA TARJETA ES NULL

};

#endif // REGISTAR_CLIENTEB_H
