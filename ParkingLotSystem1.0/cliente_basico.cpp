#include "cliente_basico.h"

Cliente_Basico::Cliente_Basico()
{
    Nombre = "";
    Apellido_Materno = "";
    Apellido_Paterno = "";
    Pais = "";
    Estado = "";
    Ciudad = "";
    Calle = "";
    Numero_Domicilio = "";
    Matricula = "";
    Tipo_Coche = "";
    Correo_Electronico = "";

}

void Cliente_Basico::Registrarse(QString nom, QString a_m, QString a_p,QString correo,QString telefono,
                                 QString pais,QString cd, QString est,
                                  QString calle, QString num_dom,
                                 QString matricula,QString tipo_coche,int id_usuario,int id_tarjeta)
{
    //Esto es parecido a un constructor con parámetros (se inicializa el cliente).
    Nombre = nom;
    Apellido_Materno = a_m;
    Apellido_Paterno = a_p;

    Pais = pais;
    Estado = est;
    Ciudad = cd;
    Calle = calle;
    Numero_Domicilio = num_dom;
    Matricula = matricula;
    Tipo_Coche = tipo_coche;
    Correo_Electronico = correo;
    Telefono = telefono;
    Id_Usuario = id_usuario;
    Id_Tarjeta = id_tarjeta;
    // Puede que se necesario instanciarlo aqui,
    //Solo tendriamos que pasar los parametros de tarjeta
}

void Cliente_Basico::Actualizar_Datos(QString nom, QString a_m, QString a_p,
                                       QString pais, QString est,
                                      QString cd, QString calle, QString num_dom,
                                      QString matricula,QString tipo_coche,QString correo,QString telefono)
{
    Nombre = nom;
    Apellido_Materno = a_m;
    Apellido_Paterno = a_p;
    Pais = pais;
    Estado = est;
    Ciudad = cd;
    Calle = calle;
    Numero_Domicilio = num_dom;
    Matricula = matricula;
    Tipo_Coche = tipo_coche;
    Correo_Electronico = correo;
    Telefono = telefono;
}

void Cliente_Basico::SetId(int i)
{
    Id = i;
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

QString Cliente_Basico::GetTipoCoche()
{
    return Tipo_Coche;
}

QString Cliente_Basico::GetTelefono()
{
    return Telefono;
}












