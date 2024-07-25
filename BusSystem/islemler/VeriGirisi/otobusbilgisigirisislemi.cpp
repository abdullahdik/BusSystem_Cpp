#include "otobusbilgisigirisislemi.h"
#include <veri/data.h>
#include <Formlar/VeriFormlari/otobusbilgisiverigirisformu.h>


OtobusBilgisiGirisIslemi::OtobusBilgisiGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Otobüs Sistemi Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/otobus.png"));
    _islem->setShortcut(QKeySequence("2"));
    connect(_islem, &QAction::triggered, this, &OtobusBilgisiGirisIslemi::main);

}


void OtobusBilgisiGirisIslemi::main()
{
    auto veri = Data::os().otobusbilgisi().YeniNesne();
    OtobusBilgisiVeriGirisFormu *form = new OtobusBilgisiVeriGirisFormu();
    connect(form, &OtobusBilgisiVeriGirisFormu::veriKaydet, this, &OtobusBilgisiGirisIslemi::depoEkle);
    form->setVeri(veri);
    form->show();
}

void OtobusBilgisiGirisIslemi::depoEkle()
{
    OtobusBilgisiVeriGirisFormu *frmx = dynamic_cast<OtobusBilgisiVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::os().otobusbilgisi().nesneEkle(veri);
    frmx->close();
}

QAction *OtobusBilgisiGirisIslemi::islem()
{
    return _islem;
}
