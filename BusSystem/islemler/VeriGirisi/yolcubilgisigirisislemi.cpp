#include "yolcubilgisigirisislemi.h"
#include <veri/data.h>
#include <Formlar/VeriFormlari/yolcubilgisiverigirisformu.h>

YolcuBilgisiGirisIslemi::YolcuBilgisiGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Yolcu Bilgisi Giriş"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/yolcu.png"));
    _islem->setShortcut(QKeySequence("4"));
    connect(_islem, &QAction::triggered,this, &YolcuBilgisiGirisIslemi::main);
}


void YolcuBilgisiGirisIslemi::main()
{
    auto veri = Data::os().yolcubilgisi().YeniNesne();
    YolcuBilgisiVeriGirisFormu *form = new YolcuBilgisiVeriGirisFormu();
    connect(form, &YolcuBilgisiVeriGirisFormu::veriKaydet, this, &::YolcuBilgisiGirisIslemi::depoEkle);
    form->setVeri(veri);
    form->show();
}

void YolcuBilgisiGirisIslemi::depoEkle()
{
    YolcuBilgisiVeriGirisFormu *frmx = dynamic_cast<YolcuBilgisiVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::os().yolcubilgisi().nesneEkle(veri);
    frmx->close();
}

QAction *YolcuBilgisiGirisIslemi::islem()
{
    return _islem;
}
