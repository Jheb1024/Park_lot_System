#ifndef PERFILADMIN_H
#define PERFILADMIN_H

#include <QWidget>

namespace Ui {
class perfilAdmin;
}

class perfilAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit perfilAdmin(QWidget *parent = nullptr);
    ~perfilAdmin();

private:
    Ui::perfilAdmin *ui;
};

#endif // PERFILADMIN_H
