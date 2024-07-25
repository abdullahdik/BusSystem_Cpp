#include "islemdeposu.h"
#include <islemler/VeriGirisi/isletmebilgisigirisislemi.h>
#include <islemler/VeriGirisi/otobusbilgisigirisislemi.h>
#include <islemler/VeriGirisi/seferbilgisigirisislemi.h>
#include <islemler/VeriGirisi/seyahatbilgisigirisislemi.h>
#include <islemler/VeriGirisi/soforbilgisigirisislemi.h>
#include <islemler/VeriGirisi/yolcubilgisigirisislemi.h>

#include <islemler/VeriListesi/isletmebilgisilisteislemi.h>
#include <islemler/VeriListesi/otobusbilgisilistesiislemi.h>
#include <islemler/VeriListesi/seferbilgisilistesiislemi.h>
#include <islemler/VeriListesi/seyahatbilgisilisteislemi.h>
#include <islemler/VeriListesi/soforbilgisilisteislemi.h>
#include <islemler/VeriListesi/yolcubilgisilisteislemi.h>

#include <islemler/VeriSilme/isletmebilgisisilmeislemi.h>



#include <islemler/VeriGuncelle/isletmebilgisiguncellemeislemi.h>



IslemDeposu &IslemDeposu::os()
{
    static IslemDeposu ob;
    return ob;
}

QAction *IslemDeposu::getAction(IslemSirasi x){ return _islemler[x]->islem(); }

void IslemDeposu::calistir(IslemSirasi y) { _islemler[y]->main(); }

std::shared_ptr<TemelKullaniciIslemleri> IslemDeposu::getIslem(IslemSirasi z)
{
    return _islemler[z];
}



IslemDeposu::IslemDeposu(QObject *parent)
    : QObject{parent}
{
    _islemler.append(std::make_shared<IsletmeBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<OtobusBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<SeferBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<YolcuBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<SeyahatBilgisiGirisIslemi>());
    _islemler.append(std::make_shared<SoforBilgisiGirisIslemi>());

    _islemler.append(std::make_shared<IsletmeBilgisiListeIslemi>());
    _islemler.append(std::make_shared<OtobusBilgisiListesiIslemi>());
    _islemler.append(std::make_shared<SeferBilgisiListesiIslemi>());
    _islemler.append(std::make_shared<SeyahatBilgisiListeIslemi>());
    _islemler.append(std::make_shared<YolcuBilgisiListeIslemi>());
    _islemler.append(std::make_shared<SoforBilgisiListeIslemi>());

    _islemler.append(std::make_shared<IsletmeBilgisiSilmeIslemi>());


     _islemler.append(std::make_shared<IsletmeBilgisiGuncellemeIslemi>());

}

