#include "reser.h"

Reser::Reser()
{
    Id_reservacion = 0;
     Intervalo = 0;
    Hora_Entrada = "";
    Hora_Salida = "";

     Fecha_Inicio = "";
     Fecha_Fin = "";
     Dias = 0;
}

void Reser::Set_IdReservacion(int a)
{
    Id_reservacion = a;
}

void Reser::Set_HoraEntrada(QString a)
{
    Hora_Entrada = a;
}
void Reser::Set_HoraSalida(QString a)
{
    Hora_Salida = a;
}
void Reser::Set_FechaInicio(QString a)
{
    Fecha_Inicio = a;
}
void Reser::Set_FechaFin(QString a)
{
    Fecha_Fin = a;
}

void Reser::Set_Dias(int a)
{
    Dias = a;
}

void Reser::SetIntervalo(int a)
{
    Intervalo = a;
}
