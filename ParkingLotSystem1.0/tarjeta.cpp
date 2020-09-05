#include "tarjeta.h"

Tarjeta::Tarjeta()
{
    Nombre_Propietario = "";
    Numero_Tarjeta = "";
    Nombre_Banco = "";
    Caducidad = "";
    CVC = "";
}

void Tarjeta::Registrar_Datos(QString nom_p, QString num_t, QString nom_b, QString caducidad, QString cvc)
{
    Nombre_Propietario = nom_p;
    Numero_Tarjeta = num_t;
    Nombre_Banco = nom_b;
    Caducidad = caducidad;
    CVC = cvc;
}
