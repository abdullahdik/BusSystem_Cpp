#include "seferbilgisigirisislemi.h"
#include <veri/data.h>
#include <Formlar/VeriFormlari/seferbilgisiverigirisformu.h>

SeferBilgisiGirisIslemi::SeferBilgisiGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Sefer Bilgisi Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/sefer.png"));
    _islem->setShortcut(QKeySequence("3"));
    connect(_islem, &QAction::triggered,this, &SeferBilgisiGirisIslemi::main);
}


void SeferBilgisiGirisIslemi::main()
{
    auto veri = Data::os().seferbilgisi().YeniNesne();
    SeferBilgisiVeriGirisFormu *form = new SeferBilgisiVeriGirisFormu();
    connect(form, &SeferBilgisiVeriGirisFormu::veriKaydet, this, &SeferBilgisiGirisIslemi::depoEkle);
    form->setVeri(veri);
    form->show();
}

void SeferBilgisiGirisIslemi::depoEkle()
{
    SeferBilgisiVeriGirisFormu *frmx = dynamic_cast<SeferBilgisiVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::os().seferbilgisi().nesneEkle(veri);
    frmx->close();
}

QAction *SeferBilgisiGirisIslemi::islem()
{
    return _islem;
}
