#ifndef INGRESACONRESERVA_H
#define INGRESACONRESERVA_H

#include <QDialog>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include "pagar.h"

namespace Ui {
class ingresaconreserva;
}

class ingresaconreserva : public QDialog
{
    Q_OBJECT

public:
    explicit ingresaconreserva(QSqlDatabase, QWidget *parent = nullptr);
    ~ingresaconreserva();

private slots:
    void on_Cancel_pushButton_clicked();

    void on_Pagar_pushButton_clicked();

    void on_Acept_pushButton_clicked();

private:

    QSqlDatabase base;
    int idRes;
    Ui::ingresaconreserva *ui;
};

#endif // INGRESACONRESERVA_H
