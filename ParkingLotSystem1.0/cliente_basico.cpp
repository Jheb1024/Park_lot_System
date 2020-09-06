#include "cliente_basico.h"

Cliente_Basico::Cliente_Basico()
{
    Nombre = "";
    Apellido_Materno = "";
    Apellido_Paterno = "";
    Id = 0;
    Pais = "";
    Estado = "";
    Ciudad = "";
    Calle = "";
    Numero_Domicilio = "";
    Matricula = "";
    Correo_Electronico = "";
    C_Tarjeta = nullptr;
}

void Cliente_Basico::Registrarse(QString nom, QString a_m, QString a_p,
                                 int id, QString pais, QString est,
                                 QString cd, QString calle, QString num_dom,
                                 QString matricula,QString correo, Tarjeta *tarjeta)
{
    //Esto es parecido a un constructor con parámetros (se inicializa el cliente).
    Nombre = nom;
    Apellido_Materno = a_m;
    Apellido_Paterno = a_p;
    Id = id;
    Pais = pais;
    Estado = est;
    Ciudad = cd;
    Calle = calle;
    Numero_Domicilio = num_dom;
    Matricula = matricula;
    Correo_Electronico = correo;
    C_Tarjeta = tarjeta; // Puede que se necesario instanciarlo aqui,
    //Solo tendriamos que pasar los parametros de tarjeta
}

void Cliente_Basico::Actualizar_Datos(QString nom, QString a_m, QString a_p,
                                      int id, QString pais, QString est,
                                      QString cd, QString calle, QString num_dom,
                                      QString matricula,QString correo)
{
    Nombre = nom;
    Apellido_Materno = a_m;
    Apellido_Paterno = a_p;
    Id = id;
    Pais = pais;
    Estado = est;
    Ciudad = cd;
    Calle = calle;
    Numero_Domicilio = num_dom;
    Matricula = matricula;
    Correo_Electronico = correo;
}

QString Cliente_Basico::GetNombre()
{
    return Nombre;
}

QString Cliente_Basico::GetMatricula()
{
    return Matricula;
}

QString Cliente_Basico::GetApellido_Materno()
{
    return Apellido_Materno;
}

QString Cliente_Basico::GetApellido_Paterno()
{
    return Apellido_Paterno;
}

int Cliente_Basico::GetId()
{
    return Id;
}

QString Cliente_Basico::GetPais()
{
    return Pais;
}

QString Cliente_Basico::GetEstado()
{
    return Estado;
}

QString Cliente_Basico::GetCiudad()
{
    return Ciudad;
}

QString Cliente_Basico::GetCalle()
{
    return Calle;
}

QString Cliente_Basico::GetNumero_Domicilio()
{
    return Numero_Domicilio;
}

QString Cliente_Basico::GetCorreo_Electronico()
{
    return Correo_Electronico;
}

Tarjeta *Cliente_Basico::GetC_Tarjeta()
{
    return C_Tarjeta;
}










