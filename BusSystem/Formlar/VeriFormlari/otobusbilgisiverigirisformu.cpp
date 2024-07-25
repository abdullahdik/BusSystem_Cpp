#include "otobusbilgisiverigirisformu.h"
#include "ui_otobusbilgisiverigirisformu.h"

OtobusBilgisiVeriGirisFormu::OtobusBilgisiVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtobusBilgisiVeriGirisFormu)
{
    ui->setupUi(this);
    connect( ui->pbKaydet,SIGNAL(clicked()), this, SIGNAL(veriKaydet()));

}

OtobusBilgisiVeriGirisFormu::~OtobusBilgisiVeriGirisFormu()
{
    delete ui;
}


void OtobusBilgisiVeriGirisFormu::ekranGuncelle()
{
    ui->leKoltukSayisi->setText( _veri->KoltukSayisi());
    ui->lePlaka->setText( _veri->Plaka());
    ui->leRenk->setText( _veri->Renk());
    ui->leRuhsat->setText( _veri->Ruhsat());
    ui->deMuayeneTarihi->setDate( _veri->MuayeneTarih());
}

void OtobusBilgisiVeriGirisFormu::veriGuncelle()
{
    _veri->setKoltukSayisi( ui->leKoltukSayisi->text());
    _veri->setPlaka( ui->lePlaka->text());
    _veri->setRenk( ui->leRenk->text());
    _veri->setRuhsat( ui->leRuhsat->text());
    _veri->setMuayeneTarih( ui->deMuayeneTarihi->date());
}
