#ifndef MODIFICARINFO_H
#define MODIFICARINFO_H

#include <QDialog>

namespace Ui {
class ModificarInfo;
}

class ModificarInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ModificarInfo(QWidget *parent = nullptr);
    ~ModificarInfo();

private:
    Ui::ModificarInfo *ui;
};

#endif // MODIFICARINFO_H
