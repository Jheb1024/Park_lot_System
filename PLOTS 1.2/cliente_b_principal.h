#ifndef CLIENTE_B_PRINCIPAL_H
#define CLIENTE_B_PRINCIPAL_H

#include <QDialog>

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QList>
#include <QCalendarWidget>
#include <QTimeEdit>

#include "cliente_basico.h"
#include "auto.h"
#include "modificarinfo.h"
namespace Ui {
class Cliente_B_Principal;
}

class Cliente_B_Principal : public QDialog
{
    Q_OBJECT

public:
    void CargarLugares(int, QString, QString);
    void VerReservaciones(int);
    void vaciar();
    explicit Cliente_B_Principal(int);
    explicit Cliente_B_Principal(QSqlDatabase ,int b =0 ,QWidget *parent = nullptr);
    ~Cliente_B_Principal();

private slots:
    void on_pushButton_2_clicked();

    void on_Editar_Info_pushButton_clicked();

    void ObtenerObjeto();



    void on_Reserva_pushButton_clicked();

    void on_MisReservas_pushButton_clicked();

    void on_Contrato_pushButton_clicked();

    void on_Salir_pushButton_clicked();

    void on_L_1pushButton_clicked();

    void on_L_2pushButton_clicked();

    void on_L_3pushButton_clicked();

    void on_L_4pushButton_clicked();

    void on_L_5pushButton_clicked();

    void on_L_6pushButton_clicked();

    void on_L_7pushButton_clicked();

    void on_L_8pushButton_clicked();

    void on_L_9pushButton_clicked();

    void on_L_10pushButton_clicked();

    void on_Nueva_Reserva_pushButton_clicked();

    void on_Nivel3_pushButton_clicked();

    void on_Nivel2_pushButton_3_clicked();

    void on_LL_1pushButton_3_clicked();

    void on_LL_2pushButton_3_clicked();

    void on_LL_3pushButton_3_clicked();

    void on_LL_4pushButton_3_clicked();

    void on_LL_5pushButton_3_clicked();

    void on_LL_6pushButton_3_clicked();

    void on_LL_7pushButton_3_clicked();

    void on_LL_8pushButton_3_clicked();

    void on_L_9pushButton_3_clicked();

    void on_LL_10pushButton_3_clicked();

    void on_Cancel_ReservapushButton_clicked();

    void on_calendarWidget_2_selectionChanged();

    void on_H_llegadatimeEdit_2_timeChanged(const QTime &time);

    void on_Confirma_Reserva_pushButton_clicked();
    
private:

    QList<int> reservaciones;

    QSqlDatabase mDatabase;
    Ui::Cliente_B_Principal *ui;
    int Id_Usuario;
    QSqlDatabase PrincipalCliente;
    Cliente_Basico *cliente_principal;
    Auto * auto_principal;
    ModificarInfo *Principal_Actualizar;
    QList<int> Conteo; //Cuenta Cuantos atributos se modificaron
    int idPiso;
    int idCajon;
};

#endif // CLIENTE_B_PRINCIPAL_H
