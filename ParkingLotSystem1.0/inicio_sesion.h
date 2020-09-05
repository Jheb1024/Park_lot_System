#ifndef INICIO_SESION_H
#define INICIO_SESION_H

#include <QMainWindow>
#include "registar_clienteb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Inicio_Sesion; }
QT_END_NAMESPACE

class Inicio_Sesion : public QMainWindow
{
    Q_OBJECT

public:
    Inicio_Sesion(QWidget *parent = nullptr);
    ~Inicio_Sesion();

private slots:
    void on_Entrar_pushButton_clicked();

    void on_Cancelar_pushButton_clicked();

    void on_Registrarse_pushButton_clicked();

private:
    Ui::Inicio_Sesion *ui;
    Registar_ClienteB *registro;
};
#endif // INICIO_SESION_H
