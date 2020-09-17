#ifndef PAGAR_H
#define PAGAR_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class pagar;
}

class pagar : public QDialog
{
    Q_OBJECT

public:
    explicit pagar(QSqlDatabase, int, QWidget *parent = 0);
    ~pagar();

private slots:
    void on_pushButton_clicked();

private:
    QSqlDatabase base;
    int id;
    Ui::pagar *ui;
};

#endif // PAGAR_H
