#ifndef AUTO_H
#define AUTO_H

#include <QString>

class Auto
{
private:
    int Id_Auto;
    QString Matricula;
    QString Tipo;
    int Id_Cliente;
public:
    Auto();
    int GetId_Auto();
    QString GetMatricula();
    QString GetTipo();
    int GetId_Cliente();
    void SetId_Auto(int);
    void SetMatricula(QString);
    void SetTipo(QString);
    void SetId_Cliente(int);

};

#endif // AUTO_H
