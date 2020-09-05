#include "inicio_sesion.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Inicio_Sesion w;
    w.show();
    return a.exec();
}
