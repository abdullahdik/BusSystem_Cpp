#include "soforbilgisilisteislemi.h"
#include <veri/data.h>
#include <Formlar/VeriListesi/soforbilgisilisteformu.h>

SoforBilgisiListeIslemi::SoforBilgisiListeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Şoför Listesi Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/sofor.png"));
    _islem->setShortcut(QKeySequence("h"));
    connect(_islem, &QAction::triggered,this, &SoforBilgisiListeIslemi::main);
}


void SoforBilgisiListeIslemi::main()
{
    auto veri = Data::os().soforbilgisi().tumunuBul([](std::shared_ptr<SoforBilgisi>) {return true;});
    SoforBilgisiListeFormu *form = new SoforBilgisiListeFormu();

    form->setListe(veri);

    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);

    form->show();
}

QAction *SoforBilgisiListeIslemi::islem()
{
    return _islem;
}
