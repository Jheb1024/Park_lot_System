#ifndef ACTUALIZAR_DATOS_H
#define ACTUALIZAR_DATOS_H

#include <QWidget>
#include "cliente_basico.h"
#include <QDebug>

namespace Ui {
class Actualizar_Datos;
}

class Actualizar_Datos : public QWidget
{
    Q_OBJECT

public:
    explicit Actualizar_Datos(Cliente_Basico *,QWidget *parent = nullptr);
    ~Actualizar_Datos();
    Cliente_Basico * GetCliente();
    bool GetEstado();

signals:
    void Mandar_Objeto();
    void Mandar_Base();
private slots:
    void on_Editar_Personales_pushButton_clicked();

    void on_Editar_Auto_pushButton_clicked();

    void on_Editar_buttonBox_accepted();

    void on_Editar_buttonBox_rejected();

private:
    Ui::Actualizar_Datos *ui;
    Cliente_Basico *Aux;
    bool Actualizo;
};

#endif // ACTUALIZAR_DATOS_H
