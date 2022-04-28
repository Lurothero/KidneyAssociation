QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Patientform.cpp \
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
    patientrecords.cpp \
    patientregistration.cpp \
    userlibrary.cpp

HEADERS += \
    Patientform.h \
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
    patientrecords.h \
    patientregistration.h \
    userlibrary.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Patientform.ui \
    appointment.ui \
    doctorcontact.ui \
    homemenu.ui \
    login.ui \
    patientappointment.ui \
    patientrecords.ui \
    patientregistration.ui

RESOURCES += \
    resource.qrc
