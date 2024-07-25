#include "seyahatbilgisiverigirisformu.h"
#include "ui_seyahatbilgisiverigirisformu.h"

SeyahatBilgisiVeriGirisFormu::SeyahatBilgisiVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seyahatbilgisiverigirisformu)
{
    ui->setupUi(this);
    connect ( ui->pbKaydet,SIGNAL(clicked()), this, SIGNAL(veriKaydet()));
}

SeyahatBilgisiVeriGirisFormu::~SeyahatBilgisiVeriGirisFormu()
{
    delete ui;
}


void SeyahatBilgisiVeriGirisFormu::ekranGuncelle()
{
    ui->spnPeronNo->setValue( _veri->PeronNo());
    ui->dteTarihSaat->setDateTime( _veri->TarihSaat());
    ui->leIkram->setText( _veri->Ikram());
    ui->pteTesis->setPlainText( _veri->Tesis());

}


void SeyahatBilgisiVeriGirisFormu::veriGuncelle()
{
    _veri->setPeronNo( ui->spnPeronNo->value());
    _veri->setTarihSaat( ui->dteTarihSaat->dateTime());
    _veri->setIkram( ui->leIkram->text());
    _veri->setTesis( ui->pteTesis->toPlainText());

}
