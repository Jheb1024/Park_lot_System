#ifndef FORMA_PAGO_H
#define FORMA_PAGO_H

#include <QDialog>
#include "tarjeta.h"

namespace Ui {
class Forma_Pago;
}

class Forma_Pago : public QDialog
{
    Q_OBJECT

public:
    explicit Forma_Pago(QWidget *parent = nullptr);
    ~Forma_Pago();
    Tarjeta * GetTarjeta(); // Regreso Tarjeta;



private slots:
    void on_Entrar_Pago_buttonBox_accepted();

    void on_Entrar_Pago_buttonBox_rejected();

private:
    Ui::Forma_Pago *ui;
    Tarjeta *Aux;
};

#endif // FORMA_PAGO_H
