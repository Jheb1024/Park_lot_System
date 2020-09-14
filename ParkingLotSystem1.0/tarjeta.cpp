#include "tarjeta.h"

Tarjeta::Tarjeta()
{

    Numero_Tarjeta = "";
    Tipo = "";
    Caducidad = "";
    CVC = "";
}

void Tarjeta::Registrar_Datos(QString num_t, QString tipo, QString caducidad, QString cvc)
{

    Numero_Tarjeta = num_t;
    Tipo = tipo;
    Caducidad = caducidad;
    CVC = cvc;
}
