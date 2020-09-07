#include "usuario.h"

Usuario::Usuario()
{
    Estado = 1;
}

void Usuario::AgregarDatos(QString nombre_usuario, QString password, QString repeat_password, QString tipo)
{
       Nombre_Usuario = nombre_usuario;
       Password = password;
       Repeat_Password = repeat_password;
       Tipo_Usuario = tipo;
}

QString Usuario::GetNombre_Usuario()
{
    return Nombre_Usuario;
}

QString Usuario::GetPassword()
{
    return Password;
}

bool Usuario::Exito()
{
    if(Password == Repeat_Password)
        return  true;
    else
        false;
}

QString Usuario::GetTipo_Usuario()
{
    return Tipo_Usuario;
}

int Usuario::GetEstado()
{
    return Estado;

}

