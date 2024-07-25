#include "seferbilgisiverigirisformu.h"
#include "ui_seferbilgisiverigirisformu.h"

SeferBilgisiVeriGirisFormu::SeferBilgisiVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seferbilgisiverigirisformu)
{
    ui->setupUi(this);
    connect( ui->pbKaydet,SIGNAL(clicked()), this, SIGNAL(veriKaydet()));

}

SeferBilgisiVeriGirisFormu::~SeferBilgisiVeriGirisFormu()
{
    delete ui;
}


void SeferBilgisiVeriGirisFormu::ekranGuncelle()
{
    ui->dteBaslangicSaati->setDateTime( _veri->BaslangicSaati());
    ui->dteBitisSaati->setDateTime( _veri->BitisSaati());
    ui->spnSeferNo->setValue( _veri->SeferNo());
    ui->pteHatlar->setPlainText( _veri->Hatlar());
    ui->leTarife->setText( _veri->Tarife());
    ui->leSeferKodu->setText( _veri->SeferKodu());
}

void SeferBilgisiVeriGirisFormu::veriGuncelle()
{
    _veri->setBaslangicSaati( ui->dteBaslangicSaati->dateTime());
    _veri->setBitisSaati( ui->dteBitisSaati->dateTime());
    _veri->setSeferNo( ui->spnSeferNo->value());
    _veri->setHatlar( ui->pteHatlar->toPlainText());
    _veri->setTarife( ui->leTarife->text());
    _veri->setSeferKodu( ui->leSeferKodu->text());
}
