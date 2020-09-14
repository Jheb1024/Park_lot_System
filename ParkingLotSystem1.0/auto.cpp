#include "auto.h"

Auto::Auto()
{
   Id_Cliente = 0;
   Matricula = "";
   Tipo = "";
   Id_Auto = 0;
}

int Auto::GetId_Auto()
{
    return Id_Auto;
}

QString Auto::GetMatricula()
{
    return Matricula;
}

QString Auto::GetTipo()
{
    return Tipo;
}

int Auto::GetId_Cliente()
{
    return Id_Cliente;
}

void Auto::SetId_Auto(int a)
{
    Id_Auto = a;
}

void Auto::SetMatricula(QString a)
{
    Matricula = a;
}

void Auto::SetTipo(QString a)
{
    Tipo = a;
}

void Auto::SetId_Cliente(int a)
{
    Id_Cliente = a;
}
