#include "seferbilgisilistesiislemi.h"
#include <veri/data.h>
#include <Formlar/VeriListesi/seferbilgisilisteformu.h>

SeferBilgisiListesiIslemi::SeferBilgisiListesiIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Sefer Listesi Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/sefer.png"));
    _islem->setShortcut(QKeySequence("d"));
    connect(_islem, &QAction::triggered,this, &SeferBilgisiListesiIslemi::main);
}


void SeferBilgisiListesiIslemi::main()
{
    auto veri = Data::os().seferbilgisi().tumunuBul([](std::shared_ptr<SeferBilgisi>) {return true;});
    SeferBilgisiListeFormu *form = new SeferBilgisiListeFormu(Data::os().seferbilgisi());

    form->setListe(veri);

    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);

    form->show();
}

QAction *SeferBilgisiListesiIslemi::islem()
{
    return _islem;
}
