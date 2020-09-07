#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

class Usuario
{
private:
    QString Nombre_Usuario;
    QString Password;
    QString Repeat_Password;
    int Estado;
    QString Tipo_Usuario;

public:
    Usuario();
    void AgregarDatos(QString,QString,QString,QString);
    QString GetNombre_Usuario();
    QString GetPassword();
    bool Exito(); // Funcion que especifica si las contraseñas son identicas
    QString GetTipo_Usuario();
    int GetEstado();


};


#endif // USUARIO_H
