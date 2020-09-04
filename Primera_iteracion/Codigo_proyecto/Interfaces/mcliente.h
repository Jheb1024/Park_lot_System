#ifndef MCLIENTE_H
#define MCLIENTE_H

#include <QWidget>

namespace Ui {
class Mcliente;
}

class Mcliente : public QWidget
{
    Q_OBJECT

public:
    explicit Mcliente(QWidget *parent = nullptr);
    ~Mcliente();

private:
    Ui::Mcliente *ui;
};

#endif // MCLIENTE_H
