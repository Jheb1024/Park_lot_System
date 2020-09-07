#include "administrador.h"

Administrador::Administrador()
{
    Id_Administrador = 0;
    Nombre_Admin = "";
    Apellido_Paterno = "";
    Apellido_Materno = "";
    Id_Usuario = 0;
}

Administrador::Administrador(int id_adm, QString nom_adm, QString ap_pat, QString ap_mat,int id_us)
{
    Id_Administrador = id_adm;
    Nombre_Admin = nom_adm;
    Apellido_Paterno = ap_pat;
    Apellido_Materno = ap_mat;
    Id_Usuario = id_us;
}
void Administrador::Eliminar_cliente()
{

}
