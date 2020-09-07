#ifndef ELIMINARCLIENTEB_H
#define ELIMINARCLIENTEB_H

#include <QWidget>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>


namespace Ui {
class EliminarClienteB;
}

class QSqlTableModel;
class EliminarClienteB : public QWidget
{
    Q_OBJECT

public:
    explicit EliminarClienteB(QWidget *parent = nullptr);
    ~EliminarClienteB();


private slots:
    void on_Eliminar_pushButton_clicked();


    void on_Salir_pushButton_clicked();

private:
    Ui::EliminarClienteB *ui;
    QSqlTableModel *nModel;
};

#endif // ELIMINARCLIENTEB_H
