#include "isletmebilgisiverigirisformu.h"
#include "ui_isletmebilgisiverigirisformu.h"

IsletmeSistemiVeriGirisFormu::IsletmeSistemiVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IsletmeBilgisiVeriGirisFormu)
{
    ui->setupUi(this);
    connect( ui->pbKaydet,SIGNAL(clicked()), this, SIGNAL(veriKaydet()));
}

IsletmeSistemiVeriGirisFormu::~IsletmeSistemiVeriGirisFormu()
{
    delete ui;
}


void IsletmeSistemiVeriGirisFormu::ekranGuncelle()
{
    ui->leIsletmeAdi->setText( _veri->IsletmeAdi());
    ui->leVergiNo->setText( _veri->VergiNo());
    ui->spnSicilNo->setValue( _veri->SicilNo());
    ui->leKonum->setText( _veri->Konum());
}

void IsletmeSistemiVeriGirisFormu::veriGuncelle()
{
    _veri->setIsletmeAdi( ui->leIsletmeAdi->text());
    _veri->setVergiNo( ui->leVergiNo->text());
    _veri->setSicilNo( ui->spnSicilNo->value());
    _veri->setKonum( ui->leKonum->text());
}

void IsletmeSistemiVeriGirisFormu::baslikAta(QString baslik)
{
    ui->lbIsletmeSistemi->setText(baslik);
}
