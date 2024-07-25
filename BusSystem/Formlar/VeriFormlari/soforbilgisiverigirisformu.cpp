#include "soforbilgisiverigirisformu.h"
#include "ui_soforbilgisiverigirisformu.h"

SoforBilgisiVeriGirisFormu::SoforBilgisiVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SoforBilgisiVeriGirisFormu)
{
    ui->setupUi(this);
    connect( ui->pbKaydet,SIGNAL(clicked()), this, SIGNAL(veriKaydet()));
}

SoforBilgisiVeriGirisFormu::~SoforBilgisiVeriGirisFormu()
{
    delete ui;
}


void SoforBilgisiVeriGirisFormu::ekranGuncelle()
{
    ui->leEhliyetSinifi->setText( _veri->EhliyetSinifi());
    ui->leTecrubesi->setText( _veri->Tecrubesi());
    ui->leHESKodu->setText( _veri->HesKodu());
    ui->leAdi->setText( _veri->Ad());
    ui->leSoyadi->setText( _veri->Soyad());
    ui->leTCKimlikNo->setText( _veri->TCKimlikNo());
    ui->rbErkek->setChecked( _veri->Cinsiyt()==Erkek);
    ui->rbKadin->setChecked( _veri->Cinsiyt()==Kadin);
}

void SoforBilgisiVeriGirisFormu::veriGuncelle()
{
    _veri->setEhliyetSinifi( ui->leEhliyetSinifi->text());
    _veri->setTecrubesi( ui->leTecrubesi->text());
    _veri->setHesKodu( ui->leHESKodu->text());
    _veri->setAd( ui->leAdi->text());
    _veri->setSoyad( ui->leSoyadi->text());
    _veri->setTCKimlikNo( ui->leTCKimlikNo->text());
    if ( ui->rbErkek->isChecked()) {
        _veri->setCinsiyt(Erkek);
    }
    if ( ui->rbKadin->isChecked()) {
        _veri->setCinsiyt(Kadin);
    }

}
