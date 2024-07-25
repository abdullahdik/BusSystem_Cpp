#include "seyahatbilgisigirisislemi.h"
#include <veri/data.h>
#include <Formlar/VeriFormlari/seyahatbilgisiverigirisformu.h>

SeyahatBilgisiGirisIslemi::SeyahatBilgisiGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Seyahat Bilgisi Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/seyahat.png"));
    _islem->setShortcut(QKeySequence("5"));
    connect(_islem, &QAction::triggered,this, &SeyahatBilgisiGirisIslemi::main);

}


void SeyahatBilgisiGirisIslemi::main()
{
    auto veri = Data::os().seyahatbilgisi().YeniNesne();
    SeyahatBilgisiVeriGirisFormu *form = new SeyahatBilgisiVeriGirisFormu();
    connect(form, &SeyahatBilgisiVeriGirisFormu::veriKaydet, this, &SeyahatBilgisiGirisIslemi::depoEkle);
    form->setVeri(veri);
    form->show();
}

void SeyahatBilgisiGirisIslemi::depoEkle()
{
    SeyahatBilgisiVeriGirisFormu *frmx = dynamic_cast<SeyahatBilgisiVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::os().seyahatbilgisi().nesneEkle(veri);
    frmx->close();
}

QAction *SeyahatBilgisiGirisIslemi::islem()
{
    return _islem;
}
