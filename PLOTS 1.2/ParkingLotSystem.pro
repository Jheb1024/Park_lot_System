QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrador_principal.cpp \
    auto.cpp \
    cliente_b_principal.cpp \
    cliente_basico.cpp \
    cliente_p_principal.cpp \
    eliminarclienteb.cpp \
    forma_pago.cpp \
    main.cpp \
    inicio_sesion.cpp \
    modificarinfo.cpp \
    registar_clienteb.cpp \
    tarjeta.cpp \
    usuario.cpp \
    ingresaconreserva.cpp \
    pagar.cpp

HEADERS += \
    administrador_principal.h \
    auto.h \
    cliente_b_principal.h \
    cliente_basico.h \
    cliente_p_principal.h \
    eliminarclienteb.h \
    forma_pago.h \
    inicio_sesion.h \
    modificarinfo.h \
    registar_clienteb.h \
    tarjeta.h \
    usuario.h \
    ingresaconreserva.h \
    pagar.h

FORMS += \
    administrador_principal.ui \
    cliente_b_principal.ui \
    cliente_p_principal.ui \
    eliminarclienteb.ui \
    forma_pago.ui \
    inicio_sesion.ui \
    modificarinfo.ui \
    registar_clienteb.ui \
    ingresaconreserva.ui \
    pagar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    IMAGENES/IMG.qrc
