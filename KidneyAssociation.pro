QT       += core gui sql printsupport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Patientform.cpp \
    add_user.cpp \
    administrator.cpp \
    appointment.cpp \
    appointmentlibrary.cpp \
    baseperson.cpp \
    baseuser.cpp \
    database.cpp \
    deskemployee.cpp \
    doctor.cpp \
    doctorcontact.cpp \
    homemenu.cpp \
    login.cpp \
    main.cpp \
    patient.cpp \
    patientappointment.cpp \
    patientlibrary.cpp \
    patientregistration.cpp \
    patientreports.cpp \
    patientreportsdisplay.cpp \
    userlibrary.cpp

HEADERS += \
    Patientform.h \
    add_user.h \
    administrator.h \
    appointment.h \
    appointmentlibrary.h \
    baseperson.h \
    baseuser.h \
    database.h \
    deskemployee.h \
    doctor.h \
    doctorcontact.h \
    homemenu.h \
    login.h \
    patient.h \
    patientappointment.h \
    patientlibrary.h \
    patientregistration.h \
    patientreports.h \
    patientreportsdisplay.h \
    userlibrary.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Patientform.ui \
    add_user.ui \
    appointment.ui \
    doctorcontact.ui \
    homemenu.ui \
    login.ui \
    patientappointment.ui \
    patientregistration.ui \
    patientreports.ui \
    patientreportsdisplay.ui

RESOURCES += \
    resource.qrc

TRANSLATIONS += \
    kidney_association_en.ts \
    kidney_association_es.ts

