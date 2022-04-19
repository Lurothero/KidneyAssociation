QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrator.cpp \
    appointment.cpp \
    appointmentlibrary.cpp \
    baseperson.cpp \
    baseuser.cpp \
    database.cpp \
    deskemployee.cpp \
    doctor.cpp \
    login.cpp \
    main.cpp \
    patient.cpp \
    patientlibrary.cpp \
    userlibrary.cpp

HEADERS += \
    administrator.h \
    appointment.h \
    appointmentlibrary.h \
    baseperson.h \
    baseuser.h \
    database.h \
    deskemployee.h \
    doctor.h \
    login.h \
    patient.h \
    patientlibrary.h \
    userlibrary.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Appointment.ui \
    DoctorContacts.ui \
    MainMenu.ui \
    NewRegistrationui.ui \
    PatientForm.ui \
    Records.ui \
    login.ui

RESOURCES += \
    resource.qrc
