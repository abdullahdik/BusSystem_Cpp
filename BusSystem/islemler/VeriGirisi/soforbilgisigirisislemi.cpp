#include "soforbilgisigirisislemi.h"
#include <veri/data.h>
#include <Formlar/VeriFormlari/soforbilgisiverigirisformu.h>

SoforBilgisiGirisIslemi::SoforBilgisiGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Şoför Bilgisi Giriş"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/sofor.png"));
    _islem->setShortcut(QKeySequence("6"));
    connect(_islem, &QAction::triggered,this, &SoforBilgisiGirisIslemi::main);

}


void SoforBilgisiGirisIslemi::main()
{
    auto veri = Data::os().soforbilgisi().YeniNesne();
    SoforBilgisiVeriGirisFormu *form = new SoforBilgisiVeriGirisFormu();
    connect(form, &SoforBilgisiVeriGirisFormu::veriKaydet, this, &::SoforBilgisiGirisIslemi::depoEkle);
    form->setVeri(veri);
    form->show();
}

void SoforBilgisiGirisIslemi::depoEkle()
{
    SoforBilgisiVeriGirisFormu *frmx = dynamic_cast<SoforBilgisiVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::os().soforbilgisi().nesneEkle(veri);
    frmx->close();
}



QAction *SoforBilgisiGirisIslemi::islem()
{
    return _islem;
}
