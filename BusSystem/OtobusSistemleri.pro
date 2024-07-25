QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Formlar/VeriFormlari/isletmebilgisiverigirisformu.cpp \
    Formlar/VeriFormlari/otobusbilgisiverigirisformu.cpp \
    Formlar/VeriFormlari/seferbilgisiverigirisformu.cpp \
    Formlar/VeriFormlari/seyahatbilgisiverigirisformu.cpp \
    Formlar/VeriFormlari/soforbilgisiverigirisformu.cpp \
    Formlar/VeriFormlari/yolcubilgisiverigirisformu.cpp \
    Formlar/VeriListesi/isletmebilgisilisteformu.cpp \
    Formlar/VeriListesi/otobusbilgisilisteformu.cpp \
    Formlar/VeriListesi/seferbilgisilisteformu.cpp \
    Formlar/VeriListesi/seyahatbilgisilisteformu.cpp \
    Formlar/VeriListesi/soforbilgisilisteformu.cpp \
    Formlar/VeriListesi/yolcubilgisilistesiformu.cpp \
    islemler/VeriGirisi/isletmebilgisigirisislemi.cpp \
    islemler/VeriGirisi/otobusbilgisigirisislemi.cpp \
    islemler/VeriGirisi/seferbilgisigirisislemi.cpp \
    islemler/VeriGirisi/seyahatbilgisigirisislemi.cpp \
    islemler/VeriGirisi/soforbilgisigirisislemi.cpp \
    islemler/VeriGirisi/yolcubilgisigirisislemi.cpp \
    islemler/VeriGuncelle/isletmebilgisiguncellemeislemi.cpp \
    islemler/VeriListesi/isletmebilgisilisteislemi.cpp \
    islemler/VeriListesi/otobusbilgisilistesiislemi.cpp \
    islemler/VeriListesi/seferbilgisilistesiislemi.cpp \
    islemler/VeriListesi/seyahatbilgisilisteislemi.cpp \
    islemler/VeriListesi/soforbilgisilisteislemi.cpp \
    islemler/VeriListesi/yolcubilgisilisteislemi.cpp \
    islemler/VeriSilme/isletmebilgisisilmeislemi.cpp \
    islemler/islemdeposu.cpp \
    islemler/tumkullaniciislemleri.cpp \
    main.cpp \
    osotobussistemleri.cpp \
    veri/Ayarlar/ayarlar.cpp \
    veri/VeriDepolari/isletmebilgisideposu.cpp \
    veri/VeriDepolari/otobusbilgisideposu.cpp \
    veri/VeriDepolari/seferbilgisideposu.cpp \
    veri/VeriDepolari/seyahatbilgisideposu.cpp \
    veri/VeriDepolari/soforbilgisideposu.cpp \
    veri/VeriDepolari/yolcubilgisideposu.cpp \
    veri/VeriSiniflari/insanbilgisi.cpp \
    veri/VeriSiniflari/isletmebilgisi.cpp \
    veri/VeriSiniflari/otobusbilgisi.cpp \
    veri/VeriSiniflari/seferbilgisi.cpp \
    veri/VeriSiniflari/seyahatbilgisi.cpp \
    veri/VeriSiniflari/soforbilgisi.cpp \
    veri/VeriSiniflari/temelverisinifi.cpp \
    veri/VeriSiniflari/yolcubilgisi.cpp \
    veri/data.cpp

HEADERS += \
    Formlar/VeriFormlari/TemelVeriGirisi.h \
    Formlar/VeriFormlari/isletmebilgisiverigirisformu.h \
    Formlar/VeriFormlari/otobusbilgisiverigirisformu.h \
    Formlar/VeriFormlari/seferbilgisiverigirisformu.h \
    Formlar/VeriFormlari/seyahatbilgisiverigirisformu.h \
    Formlar/VeriFormlari/soforbilgisiverigirisformu.h \
    Formlar/VeriFormlari/yolcubilgisiverigirisformu.h \
    Formlar/VeriListesi/isletmebilgisilisteformu.h \
    Formlar/VeriListesi/otobusbilgisilisteformu.h \
    Formlar/VeriListesi/seferbilgisilisteformu.h \
    Formlar/VeriListesi/seyahatbilgisilisteformu.h \
    Formlar/VeriListesi/soforbilgisilisteformu.h \
    Formlar/VeriListesi/yolcubilgisilistesiformu.h \
    islemler/TemelKullaniciIslemleri.h \
    islemler/VeriGirisi/isletmebilgisigirisislemi.h \
    islemler/VeriGirisi/otobusbilgisigirisislemi.h \
    islemler/VeriGirisi/seferbilgisigirisislemi.h \
    islemler/VeriGirisi/seyahatbilgisigirisislemi.h \
    islemler/VeriGirisi/soforbilgisigirisislemi.h \
    islemler/VeriGirisi/yolcubilgisigirisislemi.h \
    islemler/VeriGuncelle/isletmebilgisiguncellemeislemi.h \
    islemler/VeriListesi/isletmebilgisilisteislemi.h \
    islemler/VeriListesi/otobusbilgisilistesiislemi.h \
    islemler/VeriListesi/seferbilgisilistesiislemi.h \
    islemler/VeriListesi/seyahatbilgisilisteislemi.h \
    islemler/VeriListesi/soforbilgisilisteislemi.h \
    islemler/VeriListesi/yolcubilgisilisteislemi.h \
    islemler/VeriSilme/isletmebilgisisilmeislemi.h \
    islemler/islemdeposu.h \
    islemler/tumkullaniciislemleri.h \
    osotobussistemleri.h \
    veri/Ayarlar/ayarlar.h \
    veri/VeriDepolari/TemelVeriDeposu.h \
    veri/VeriDepolari/isletmebilgisideposu.h \
    veri/VeriDepolari/otobusbilgisideposu.h \
    veri/VeriDepolari/seferbilgisideposu.h \
    veri/VeriDepolari/seyahatbilgisideposu.h \
    veri/VeriDepolari/soforbilgisideposu.h \
    veri/VeriDepolari/yolcubilgisideposu.h \
    veri/VeriSiniflari/insanbilgisi.h \
    veri/VeriSiniflari/isletmebilgisi.h \
    veri/VeriSiniflari/otobusbilgisi.h \
    veri/VeriSiniflari/seferbilgisi.h \
    veri/VeriSiniflari/seyahatbilgisi.h \
    veri/VeriSiniflari/soforbilgisi.h \
    veri/VeriSiniflari/temelverisinifi.h \
    veri/VeriSiniflari/yolcubilgisi.h \
    veri/data.h \
    veri/tanimlar.h

FORMS += \
    Formlar/VeriFormlari/isletmebilgisiverigirisformu.ui \
    Formlar/VeriFormlari/otobusbilgisiverigirisformu.ui \
    Formlar/VeriFormlari/seferbilgisiverigirisformu.ui \
    Formlar/VeriFormlari/seyahatbilgisiverigirisformu.ui \
    Formlar/VeriFormlari/soforbilgisiverigirisformu.ui \
    Formlar/VeriFormlari/yolcubilgisiverigirisformu.ui \
    Formlar/VeriListesi/isletmebilgisilisteformu.ui \
    Formlar/VeriListesi/otobusbilgisilisteformu.ui \
    Formlar/VeriListesi/seferbilgisilisteformu.ui \
    Formlar/VeriListesi/seyahatbilgisilisteformu.ui \
    Formlar/VeriListesi/soforbilgisilisteformu.ui \
    Formlar/VeriListesi/yolcubilgisilistesiformu.ui \
    osotobussistemleri.ui

TRANSLATIONS += \
    OtobusSistemleri_tr_TR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Kaynaklar.qrc
