#ifndef CLIENTE_BASICO_H
#define CLIENTE_BASICO_H


#include <QString>

class Tarjeta;

class Cliente_Basico
{
protected:

    QString Nombre;
    QString Apellido_Materno;
    QString Apellido_Paterno;
    int Id;
    QString Pais;
    QString Estado;
    QString Ciudad;
    QString Calle;
    QString Numero_Domicilio;
    QString Matricula;
    QString Correo_Electronico;
    Tarjeta * C_Tarjeta;

public:
    Cliente_Basico();
    void Registrarse(QString,QString,QString
                     ,int,QString,QString,QString,
                     QString,QString,QString,QString, Tarjeta *);

    void Actualizar_Datos(QString,QString,QString
                          ,int,QString,QString,QString,
                          QString,QString,QString,QString); // La terjeta se actualiza con un metodo propio.
    QString GetNombre();
    QString GetMatricula();



};

#endif // CLIENTE_BASICO_H
