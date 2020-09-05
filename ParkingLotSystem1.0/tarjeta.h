#ifndef TARJETA_H
#define TARJETA_H

#include <QString>
class Tarjeta
{
protected:
    QString  Nombre_Propietario;
    QString Numero_Tarjeta;
    QString Nombre_Banco;
    QString Caducidad;
    QString CVC;

public:
    Tarjeta();
    void Registrar_Datos(QString nom_p, QString num_t, QString nom_b, QString caducidad, QString cvc);
    void Actualizar_datos(QString nom_p, QString num_t, QString nom_b, QString caducidad, QString cvc);
};

#endif // TARJETA_H
