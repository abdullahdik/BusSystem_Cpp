#include "osotobussistemleri.h"
#include "ui_osotobussistemleri.h"
#include <islemler/islemdeposu.h>
#include <islemler/tumkullaniciislemleri.h>

OSOtobusSistemleri::OSOtobusSistemleri(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OSOtobusSistemleri)
{
    ui->setupUi(this);


    ui->menu_letme_Bilgisi->addAction(IslemDeposu::os().getAction(IslemDeposu::IsletmeBilgisiVeriGirisFormu));
    ui->menu_letme_Bilgisi->addAction(IslemDeposu::os().getAction(IslemDeposu::IsletmeBilgisiListesiIslemi));
    ui->tbIsletmeBilgisi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::IsletmeBilgisiVeriGirisFormu));
    ui->tbIsletmeListesi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::IsletmeBilgisiListesiIslemi));

    ui->menuOtob_s->addAction(IslemDeposu::os().getAction(IslemDeposu::OtobusBilgisiVeriGirisFormu));
    ui->menuOtob_s->addAction(IslemDeposu::os().getAction(IslemDeposu::OtobusBilgisiListeIslemi));
    ui->tbOtobusBilgisi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::OtobusBilgisiVeriGirisFormu));
    ui->tbOtobusListesi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::OtobusBilgisiListeIslemi));

    ui->menuSeyahat->addAction(IslemDeposu::os().getAction(IslemDeposu::SeyahatBilgisiVeriGirisFormu));
    ui->menuSeyahat->addAction(IslemDeposu::os().getAction(IslemDeposu::SeyahatBilgisiListesiIslemi));
    ui->tbSeyahatBilgisi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::SeyahatBilgisiVeriGirisFormu));
    ui->tbSeayahatListesi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::SeyahatBilgisiListesiIslemi));


    ui->menuSefer->addAction(IslemDeposu::os().getAction(IslemDeposu::SeferBilgisiVeriGirisFormu));
    ui->menuSefer->addAction(IslemDeposu::os().getAction(IslemDeposu::SeferBilgsiListeIslemi));
    ui->tbSeferBilgisi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::SeferBilgisiVeriGirisFormu));
    ui->tbSeferListesi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::SeferBilgsiListeIslemi));

    ui->menu_of_r->addAction(IslemDeposu::os().getAction(IslemDeposu::SoforBilgisiVeriGirisFormu));
    ui->menu_of_r->addAction(IslemDeposu::os().getAction(IslemDeposu::SoforBilgisiListesiIslemi));
    ui->tbSoforBilgisi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::SoforBilgisiVeriGirisFormu));
    ui->tbSoforListesi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::SoforBilgisiListesiIslemi));


    ui->menuYolcu->addAction(IslemDeposu::os().getAction(IslemDeposu::YolcuBilgisiVeriGirisFormu));
    ui->menuYolcu->addAction(IslemDeposu::os().getAction(IslemDeposu::YolcuBilgisiListesiIslemi));
    ui->tbYolcuBilgisi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::YolcuBilgisiVeriGirisFormu));
    ui->tbYolcuListesi->setDefaultAction(IslemDeposu::os().getAction(IslemDeposu::YolcuBilgisiListesiIslemi));

}

OSOtobusSistemleri::~OSOtobusSistemleri() {  delete ui; }



