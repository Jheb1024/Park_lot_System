#ifndef PERFILCLIENTE_H
#define PERFILCLIENTE_H

#include <QWidget>

namespace Ui {
class perfilCliente;
}

class perfilCliente : public QWidget
{
    Q_OBJECT

public:
    explicit perfilCliente(QWidget *parent = nullptr);
    ~perfilCliente();

private:
    Ui::perfilCliente *ui;
};

#endif // PERFILCLIENTE_H
