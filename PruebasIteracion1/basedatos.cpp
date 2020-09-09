#include "basedatos.h"
#include <QTest>
#include <QDebug>

basedatos::basedatos()
{
    mDatabase = QSqlDatabase::addDatabase("QMYSQL");
    mDatabase.setPort(3306);
    mDatabase.setHostName("localhost");
    mDatabase.setUserName("root");
    mDatabase.setPassword("root");
    mDatabase.setDatabaseName("park_lot_system_db");
}

bool basedatos::iniciarCliente(QString usuario, QString pass){

    QSqlQuery datos;
    bool resultado = false;
    QString info;

    datos.exec("SELECT * FROM usuario WHERE nombre_usuario = '"+usuario+"' and password = '"+pass+"' and tipo_usuario = 'clientebasico'");
    while(datos.next()){
        info=datos.value(1).toString();
        resultado = true;
    }
    qDebug() << "datos "+info;
    return resultado;
}

bool basedatos::iniciarAdmin(QString usuario, QString pass){

    QSqlQuery datos;
    bool resultado = false;
    QString info;

    datos.exec("SELECT * FROM usuario WHERE nombre_usuario = '"+usuario+"' and password = '"+pass+"' and tipo_usuario = 'administrador'");
    while(datos.next()){
        info=datos.value(1).toString();
        resultado = true;
    }
    qDebug() << "datos "+info;
    return resultado;
}

bool basedatos::registrarDatos(QString nombre,QString paterno,QString materno,QString mail,QString tel,
                               QString calle,QString mat,QString tipo,int num){

    QSqlQuery InsCliente;

    if(InsCliente.exec("INSERT INTO cliente (nombre_cliente,aPaterno_cliente,aMaterno_cliente,correo,telefono,calle,numero_domicilio,matricula,"
                       "tipo_coche,id_usuario) VALUES ('"+nombre+"','"+paterno+"','"+materno+"','"+mail+"','"+tel+"'"
                       ",'"+calle+"','"+QString::number(num)+"','"+mat+"','"+tipo+"','3')"))
        return true;
    else
        return false;
}

bool basedatos::registrarBancario(QString nom,QString num,int seg,int cad,QString tipo,QString banco){
    QSqlQuery InsCliente;
    if(InsCliente.exec("INSERT INTO datos_bancarios (nombre_propietario,numero_tarjeta,cvc,caducidad, tipo_tarjeta, nombre_banco)"
                       "VALUES ('"+nom+"','"+num+"','"+QString::number(seg)+"','"+QString::number(cad)+"','"+tipo+"','"+banco+"')"))
        return true;
    else
        return false;
}

bool basedatos::eliminarCliente(){}

bool basedatos::editarPerfil(QString nombre,QString paterno,QString materno,QString mail,QString tel,
                             QString calle,QString mat,QString tipo,int num){
    QSqlQuery datos;
    if(datos.exec("UPDATE cliente SET nombre_cliente = '"+nombre+"', aPaterno_cliente = '"+paterno+"', aMaterno_cliente = '"+materno+"',"
                  "correo = '"+mail+"', telefono = '"+tel+"', calle = '"+calle+"', numero_domicilio = '"+QString::number(num)+"',"
                  "matricula = '"+mat+"', tipo_coche = '"+tipo+"', id_usuario = '3' WHERE id_cliente = '1'"))
        return true;
    else
        return false;
}
