#ifndef BASEDATOS_H
#define BASEDATOS_H

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QString>

class basedatos
{
public:
    basedatos();
    QSqlDatabase mDatabase;

    //Historia 1, inicio sesión cliente
    bool iniciarCliente(QString,QString);
    //Historia 2, inicio sesión admin
    bool iniciarAdmin(QString,QString);
    //Historia 3, registrar cliente
    bool registrarDatos(QString,QString,QString,QString,QString,QString,QString,QString,int);
    bool registrarBancario(QString,QString,int,int,QString,QString);
    //Historia 4, editar perfil
    bool eliminarCliente();
    //Historia 5, eliminar cuenta
    bool editarPerfil(QString,QString,QString,QString,QString,QString,QString,QString,int);
};

#endif // BASEDATOS_H
