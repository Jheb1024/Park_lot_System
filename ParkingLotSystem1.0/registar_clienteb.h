#ifndef REGISTAR_CLIENTEB_H
#define REGISTAR_CLIENTEB_H

#include <QDialog>
#include "forma_pago.h"

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
};

#endif // REGISTAR_CLIENTEB_H
