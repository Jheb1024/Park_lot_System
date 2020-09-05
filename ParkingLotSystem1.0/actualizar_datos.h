#ifndef ACTUALIZAR_DATOS_H
#define ACTUALIZAR_DATOS_H

#include <QWidget>

namespace Ui {
class Actualizar_Datos;
}

class Actualizar_Datos : public QWidget
{
    Q_OBJECT

public:
    explicit Actualizar_Datos(QWidget *parent = nullptr);
    ~Actualizar_Datos();

private:
    Ui::Actualizar_Datos *ui;
};

#endif // ACTUALIZAR_DATOS_H
