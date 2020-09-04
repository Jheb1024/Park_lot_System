#include "perfiladmin.h"
#include "ui_perfiladmin.h"

perfilAdmin::perfilAdmin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::perfilAdmin)
{
    ui->setupUi(this);
}

perfilAdmin::~perfilAdmin()
{
    delete ui;
}
