#include <QString>
#include <QtTest>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "basedatos.h"

class PruebasIteracion1Test : public QObject
{
    Q_OBJECT

public:
    PruebasIteracion1Test();
    basedatos *conexion;

private Q_SLOTS:
    //Prueba básica de conexión
    void conexionbase();
    //Historia 1, inicio sesión cliente
    void iniciarCliente();
    //Historia 2, inicio sesión admin
    void iniciarAdmin();
    //Historia 3, registrar cliente
    void registrarDatos();
    void registrarBancario();
    //Historia 5, editar perfil
    //void eliminarCliente();
    //Historia 4, eliminar cuenta
    void editarPerfil();

};

PruebasIteracion1Test::PruebasIteracion1Test()
{
    conexion = new basedatos();
}

void PruebasIteracion1Test::conexionbase()
{
    QVERIFY(conexion->mDatabase.open());
}

void PruebasIteracion1Test::iniciarAdmin(){
    QCOMPARE(conexion->iniciarAdmin("admi@gmail.com","1234"),true);
}

void PruebasIteracion1Test::iniciarCliente(){
    QCOMPARE(conexion->iniciarCliente("john@gmail.com","1234"),true);
}
void PruebasIteracion1Test::registrarDatos(){
    QVERIFY(conexion->registrarDatos("Daniel","Pérez","Montiel","daniel@gmail.com","2225031556","Alcatraces","TTM6314","Sedán",97));
}

void PruebasIteracion1Test::registrarBancario(){
    QVERIFY(conexion->registrarBancario("Daniel Pérez Montiel","37174567817510",9987,0721,"credito","AMEX"));
}

void PruebasIteracion1Test::editarPerfil(){
    QVERIFY(conexion->editarPerfil("Daniel","Pérez","Montiel","dann@gmail.com","22249707990","Alcatraces","TTM6314","Sedan",97));
}

QTEST_APPLESS_MAIN(PruebasIteracion1Test)

#include "tst_pruebasiteracion1test.moc"
