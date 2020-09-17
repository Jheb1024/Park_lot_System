#ifndef MODIFICARINFO_H
#define MODIFICARINFO_H

#include <QDialog>
#include <QMessageBox>
#include "cliente_basico.h"
#include "auto.h"
#include <QDebug>
#include <QList>
namespace Ui {
class ModificarInfo;
}

class ModificarInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ModificarInfo(Cliente_Basico *,Auto *,QWidget *parent = nullptr);
    ~ModificarInfo();
    Cliente_Basico * GetCliente();
    Auto * GetAuto();
    bool GetEstado();
    QList<int> GetLista();

signals:
    void Mandar_Objeto();
    void Mandar_Base();

private slots:
    void on_Editar_buttonBox_accepted();

    void on_Editar_buttonBox_rejected();

private:
    Ui::ModificarInfo *ui;
    Cliente_Basico *Aux;
    Auto *Aux2;
    bool Actualizo;
    QList<int> actualizados;
};

#endif // MODIFICARINFO_H
