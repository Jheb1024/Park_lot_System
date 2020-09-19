#ifndef CLIENTE_P_PRINCIPAL_H
#define CLIENTE_P_PRINCIPAL_H

#include <QDialog>

namespace Ui {
class Cliente_P_Principal;
}

class Cliente_P_Principal : public QDialog
{
    Q_OBJECT

public:
    explicit Cliente_P_Principal(QWidget *parent = nullptr);
    ~Cliente_P_Principal();

private:
    Ui::Cliente_P_Principal *ui;
};

#endif // CLIENTE_P_PRINCIPAL_H
