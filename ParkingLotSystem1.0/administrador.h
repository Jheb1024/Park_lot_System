#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <QString>
class Administrador
{
protected:
    int Id_Administrador;
    QString Nombre_admin;
    QString Apellido_Paterno;
    QString Apellido_Materno;
    int Id_Usuario;

public:
    Administrador();
    Administrador(int,QString,QString,QString,int);
    void Cerrar_Sesion();
    void Eliminar_cliente();
};

#endif // ADMINISTRADOR_H
