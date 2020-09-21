#ifndef RESER_H
#define RESER_H

#include <QDebug>
#include <QString>
class Reser
{
    int Id_reservacion;
    int Intervalo;
    QString Hora_Entrada;
    QString Hora_Salida;

    QString Fecha_Inicio;
    QString Fecha_Fin;
    int Dias;


public:
    Reser();
    void Set_IdReservacion(int);
    void Set_HoraEntrada(QString);
    void Set_HoraSalida(QString);
    void Set_FechaInicio(QString);
    void Set_FechaFin(QString);
    void Set_Dias(int);
    void SetIntervalo(int);
    int GetIdReservacion(){return Id_reservacion;}
    QString GetHora_Entrada(){return Hora_Entrada;}
    QString GetHora_Salida(){return Hora_Salida;}
    QString GetFecha_Inicio(){return Fecha_Inicio;}
    QString GetFecha_Fin(){return Fecha_Fin;}
    int GetDias(){return Dias;}
    int GetIntervalo(){return Intervalo;}

};

#endif // RESER_H
