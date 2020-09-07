#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <QString>
class Administrador
{
protected:
    int Id_Administrador;
    QString Nombre_Admin;
    QString Apellido_Paterno;
    QString Apellido_Materno;
    int Id_Usuario;

public:
    Administrador();
    Administrador(int,QString,QString,QString,int);
    void Cerrar_Sesion();
    void Eliminar_cliente();
    void SetIdAdministrador(int a){Id_Administrador = a;}
    void SetNombre_Admin(QString a){Nombre_Admin = a;}
    void SetApellido_Paterno(QString a){Apellido_Paterno = a;}
    void SetApellido_Materno(QString a){Apellido_Materno = a;}
    void SetId_Usuario(int a){ Id_Usuario = a;}
    int GetId_Administrador(){return Id_Administrador;}
    QString GetNombre(){return Nombre_Admin;}
    QString GetApellido_Paterno(){return Apellido_Paterno;}
    QString GetApellido_Materno(){return Apellido_Materno;}
    int GetId_Usuario(){return Id_Usuario;}

};

#endif // ADMINISTRADOR_H
