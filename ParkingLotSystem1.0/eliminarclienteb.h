#ifndef ELIMINARCLIENTEB_H
#define ELIMINARCLIENTEB_H

#include <QWidget>

namespace Ui {
class EliminarClienteB;
}

class EliminarClienteB : public QWidget
{
    Q_OBJECT

public:
    explicit EliminarClienteB(QWidget *parent = nullptr);
    ~EliminarClienteB();

private:
    Ui::EliminarClienteB *ui;
};

#endif // ELIMINARCLIENTEB_H
