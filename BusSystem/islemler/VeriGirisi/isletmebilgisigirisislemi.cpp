#include "isletmebilgisigirisislemi.h"
#include <veri/data.h>
#include <Formlar/VeriFormlari/isletmebilgisiverigirisformu.h>

IsletmeBilgisiGirisIslemi::IsletmeBilgisiGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("İşletme Bilgisi Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/isletme.png"));
    _islem->setShortcut(QKeySequence("1"));
    connect(_islem, &QAction::triggered, this, &IsletmeBilgisiGirisIslemi::main);
}


void IsletmeBilgisiGirisIslemi::main()
{
    auto veri = Data::os().isletmebilgisi().YeniNesne();
    IsletmeSistemiVeriGirisFormu *form = new IsletmeSistemiVeriGirisFormu();
    connect(form, &IsletmeSistemiVeriGirisFormu::veriKaydet, this, &IsletmeBilgisiGirisIslemi::depoEkle);
    form->setVeri(veri);
    form->show();
}

void IsletmeBilgisiGirisIslemi::depoEkle()
{
    IsletmeSistemiVeriGirisFormu *frmx = dynamic_cast<IsletmeSistemiVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::os().isletmebilgisi().nesneEkle(veri);
    frmx->close();
}

QAction *IsletmeBilgisiGirisIslemi::islem()
{
    return _islem;
}
