#ifndef TARJETA_H
#define TARJETA_H

#include <QString>
class Tarjeta
{
protected:
    QString Numero_Tarjeta;
    QString Tipo;
    QString Caducidad;
    QString CVC;

public:
    Tarjeta();
    void Registrar_Datos(QString num_t, QString tipo, QString caducidad, QString cvc);
    void Actualizar_datos(QString nom_t, QString tipo, QString caducidad, QString cvc);
    QString GetNumero_Tarjeta(){return Numero_Tarjeta;}
    QString GetTipo(){return Tipo;}
    QString GetCaducidad(){return Caducidad;}
    QString GetCVC(){return CVC;}
};

#endif // TARJETA_H
