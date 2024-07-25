#include "tumkullaniciislemleri.h"

#include <islemler/VeriGirisi/isletmebilgisigirisislemi.h>
#include <islemler/VeriGirisi/otobusbilgisigirisislemi.h>
#include <islemler/VeriGirisi/seferbilgisigirisislemi.h>
#include <islemler/VeriGirisi/seyahatbilgisigirisislemi.h>
#include <islemler/VeriGirisi/soforbilgisigirisislemi.h>
#include <islemler/VeriGirisi/yolcubilgisigirisislemi.h>
#include <islemler/VeriListesi/isletmebilgisilisteislemi.h>


TumKullaniciIslemleri::TumKullaniciIslemleri(QObject *parent)
    : QObject{parent}
{
    _islemler.append(std::make_shared<IsletmeBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<OtobusBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<SeferBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<SeyahatBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<SoforBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<YolcuBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<IsletmeBilgisiListeIslemi>());
}

TumKullaniciIslemleri &TumKullaniciIslemleri::os() {
    static TumKullaniciIslemleri nesne;
    return nesne;
}

void TumKullaniciIslemleri::islemCalistir(int sira_no) {
    _islemler[sira_no]->main();
}

QAction *TumKullaniciIslemleri::islem(int sira_no) {
    return _islemler[sira_no]->islem();
}
