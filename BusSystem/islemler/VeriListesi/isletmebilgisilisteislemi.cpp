#include "isletmebilgisilisteislemi.h"
#include <veri/data.h>
#include <Formlar/VeriListesi/isletmebilgisilisteformu.h>

IsletmeBilgisiListeIslemi::IsletmeBilgisiListeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("İşletme Listesi Giriş"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/isletme.png"));
    _islem->setShortcut(QKeySequence("a"));
    connect(_islem, &QAction::triggered, this, &IsletmeBilgisiListeIslemi::main);
}


void IsletmeBilgisiListeIslemi::main()
{
    auto veri = Data::os().isletmebilgisi().tumunuBul([](std::shared_ptr<IsletmeBilgisi>) {return true;});
    IsletmeBilgisiListeFormu *form = new IsletmeBilgisiListeFormu(Data::os().isletmebilgisi());

    form->setListe(veri);

    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);

    form->show();
}

QAction *IsletmeBilgisiListeIslemi::islem()
{
    return _islem;
}
