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
                     ,QString,QString,QString,
                     QString,QString,QString,QString,QString,QString,int,int);

    void Actualizar_Datos(QString,QString,QString
                          ,QString,QString,QString,
                          QString,QString,QString,QString,QString,QString); // La terjeta se actualiza con un metodo propio.
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

    void SetNombre(QString nom){ Nombre = nom;}



};

#endif // CLIENTE_BASICO_H
