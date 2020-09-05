#ifndef FORMA_PAGO_H
#define FORMA_PAGO_H

#include <QDialog>

namespace Ui {
class Forma_Pago;
}

class Forma_Pago : public QDialog
{
    Q_OBJECT

public:
    explicit Forma_Pago(QWidget *parent = nullptr);
    ~Forma_Pago();

private slots:
    void on_Entrar_Pago_buttonBox_accepted();

    void on_Entrar_Pago_buttonBox_rejected();

private:
    Ui::Forma_Pago *ui;
};

#endif // FORMA_PAGO_H
