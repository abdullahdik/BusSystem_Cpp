#include "yolcubilgisiverigirisformu.h"
#include "ui_yolcubilgisiverigirisformu.h"

YolcuBilgisiVeriGirisFormu::YolcuBilgisiVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yolcubilgisiverigirisformu)
{
    ui->setupUi(this);
    connect( ui->pbKaydet,SIGNAL(clicked()), this, SIGNAL(veriKaydet()));
}

YolcuBilgisiVeriGirisFormu::~YolcuBilgisiVeriGirisFormu()
{
    delete ui;
}


void YolcuBilgisiVeriGirisFormu::ekranGuncelle()
{
    ui->spnKoltukNo->setValue( _veri->KoltukNo());
    ui->leBiletKodu->setText( _veri->BiletKodu());
    ui->leTelefonNo->setText( _veri->TelefonNo());
    ui->leUyruk->setText( _veri->Uyruk());
    ui->leAdi->setText( _veri->Ad());
    ui->leSoyadi->setText( _veri->Soyad());
    ui->leTCKimlikNo->setText( _veri->TCKimlikNo());
    ui->leHESKodu->setText( _veri->TCKimlikNo());
    ui->rbErkek->setChecked( _veri->Cinsiyt()==Erkek);
    ui->rbKadin->setChecked( _veri->Cinsiyt()==Kadin);
    ui->dteRezervasyon->setDateTime( _veri->Rezervasyon());
}

void YolcuBilgisiVeriGirisFormu::veriGuncelle()
{
    _veri->setKoltukNo( ui->spnKoltukNo->value());
    _veri->setBiletKodu( ui->leBiletKodu->text());
    _veri->setTelefonNo( ui->leTelefonNo->text());
    _veri->setUyruk( ui->leUyruk->text());
    _veri->setAd( ui->leAdi->text());
    _veri->setSoyad( ui->leSoyadi->text());
    _veri->setHesKodu( ui->leHESKodu->text());
    _veri->setTCKimlikNo( ui->leTCKimlikNo->text());
    if ( ui->rbErkek->isChecked()){
        _veri->setCinsiyt(Erkek);
    }
    if ( ui->rbKadin->isChecked()){
        _veri->setCinsiyt(Kadin);
    }
    _veri->setRezervasyon( ui->dteRezervasyon->dateTime());
}
