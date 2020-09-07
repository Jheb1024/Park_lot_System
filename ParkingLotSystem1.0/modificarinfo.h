#ifndef MODIFICARINFO_H
#define MODIFICARINFO_H

#include <QDialog>
#include "cliente_basico.h"
#include <QDebug>
namespace Ui {
class ModificarInfo;
}

class ModificarInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ModificarInfo(Cliente_Basico *,QWidget *parent = nullptr);
    ~ModificarInfo();
    Cliente_Basico * GetCliente();
    bool GetEstado();

signals:
    void Mandar_Objeto();
    void Mandar_Base();

private slots:
    void on_Editar_buttonBox_accepted();

    void on_Editar_buttonBox_rejected();

    void on_Editar_Personales_pushButton_clicked();

    void on_Editar_Auto_pushButton_clicked();

private:
    Ui::ModificarInfo *ui;
    Cliente_Basico *Aux;
    bool Actualizo;
};

#endif // MODIFICARINFO_H
