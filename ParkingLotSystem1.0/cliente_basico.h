#ifndef CLIENTE_BASICO_H
#define CLIENTE_BASICO_H


#include <QString>

class Tarjeta;

class Cliente_Basico
{
protected:

    int Id;
    QString Nombre;
    QString Apellido_Materno;
    QString Apellido_Paterno;
    QString Correo_Electronico;
    QString Telefono;
    QString Pais;
    QString Estado;
    QString Ciudad;
    QString Calle;
    QString Numero_Domicilio;
    QString Matricula;
    QString Tipo_Coche;
    int Id_Usuario;
    int Id_Tarjeta;





public:
    Cliente_Basico();
    void Registrarse(QString,QString,QString
                     ,QString,QString,QString,QString,int,int);

    void SetId(int);
    int GetId(){return Id;}

    QString GetNombre();
    QString GetMatricula();
    QString GetApellido_Materno();
    QString GetApellido_Paterno();

    QString GetPais();
    QString GetEstado();
    QString GetCiudad();
    QString GetCalle();
    QString GetNumero_Domicilio();
    QString GetCorreo_Electronico();
    QString GetTipoCoche();
    QString GetTelefono();

    void SetNombre(QString a){ Nombre = a;}
    void SetApellido_M(QString a){ Apellido_Materno = a;}
    void SetApellido_P(QString a){ Apellido_Paterno = a;}
    void SetCorreo(QString a){ Correo_Electronico = a;}
    void SetTelefono(QString a){ Telefono = a;}
    void SetPais(QString a){ Pais = a;}
    void SetEstado(QString a){ Estado = a;}
    void SetCiudad(QString a){ Ciudad = a;}
    void SetCalle(QString a){ Calle = a;}
    void SetNumero_Domicilio(QString a){ Numero_Domicilio = a;}
    void SetMatricula(QString a){ Matricula = a;}
    void SetTipo_Coche(QString a){ Tipo_Coche = a;}



};

#endif // CLIENTE_BASICO_H
