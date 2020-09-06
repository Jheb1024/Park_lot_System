#ifndef CLIENTE_B_PRINCIPAL_H
#define CLIENTE_B_PRINCIPAL_H

#include <QDialog>

namespace Ui {
class Cliente_B_Principal;
}

class Cliente_B_Principal : public QDialog
{
    Q_OBJECT

public:
    explicit Cliente_B_Principal(int);
    explicit Cliente_B_Principal(QWidget *parent = nullptr,int i = 0);
    ~Cliente_B_Principal();

private:
    Ui::Cliente_B_Principal *ui;
    int Id_Cliente;
};

#endif // CLIENTE_B_PRINCIPAL_H
