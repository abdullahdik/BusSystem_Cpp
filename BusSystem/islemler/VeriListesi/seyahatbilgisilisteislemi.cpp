#include "seyahatbilgisilisteislemi.h"
#include <veri/data.h>
#include <Formlar/VeriListesi/seyahatbilgisilisteformu.h>

SeyahatBilgisiListeIslemi::SeyahatBilgisiListeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Seyahat Listesi Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/seyahat.png"));
    _islem->setShortcut(QKeySequence("g"));
    connect(_islem, &QAction::triggered,this, &SeyahatBilgisiListeIslemi::main);
}


void SeyahatBilgisiListeIslemi::main()
{
    auto veri = Data::os().seyahatbilgisi().tumunuBul([](std::shared_ptr<SeyahatBilgisi>) {return true;});
    SeyahatBilgisiListeFormu *form = new SeyahatBilgisiListeFormu(Data::os().seyahatbilgisi());

    form->setListe(veri);

    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);

    form->show();

}

QAction *SeyahatBilgisiListeIslemi::islem()
{
    return _islem;
}
