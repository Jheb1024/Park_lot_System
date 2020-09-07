#include "modificarinfo.h"
#include "ui_modificarinfo.h"

ModificarInfo::ModificarInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarInfo)
{
    ui->setupUi(this);
}

ModificarInfo::~ModificarInfo()
{
    delete ui;
}
