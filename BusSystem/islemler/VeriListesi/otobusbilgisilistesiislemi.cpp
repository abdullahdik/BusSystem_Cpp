#include "otobusbilgisilistesiislemi.h"
#include <veri/data.h>
#include <Formlar/VeriListesi/otobusbilgisilisteformu.h>

OtobusBilgisiListesiIslemi::OtobusBilgisiListesiIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Otobüs Sistemi Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/otobus.png"));
    _islem->setShortcut(QKeySequence("s"));
    connect(_islem, &QAction::triggered, this, &OtobusBilgisiListesiIslemi::main);
}


void OtobusBilgisiListesiIslemi::main()
{
    auto veri = Data::os().otobusbilgisi().tumunuBul([](std::shared_ptr<OtobusBilgisi>) {return true;});
    OtobusBilgisiListeFormu *form = new OtobusBilgisiListeFormu(Data::os().otobusbilgisi());

    form->setListe(veri);

    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);

    form->show();
}

QAction *OtobusBilgisiListesiIslemi::islem()
{
    return _islem;
}
