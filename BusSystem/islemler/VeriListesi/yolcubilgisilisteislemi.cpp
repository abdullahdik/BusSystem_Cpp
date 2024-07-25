#include "yolcubilgisilisteislemi.h"
#include <veri/data.h>
#include <Formlar/VeriListesi/yolcubilgisilistesiformu.h>

YolcuBilgisiListeIslemi::YolcuBilgisiListeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Yolcu Listesi Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Resimler/yolcu.png"));
    _islem->setShortcut(QKeySequence("f"));
    connect(_islem, &QAction::triggered,this, &YolcuBilgisiListeIslemi::main);
}


void YolcuBilgisiListeIslemi::main()
{
    auto veri = Data::os().yolcubilgisi().tumunuBul([](std::shared_ptr<YolcuBilgisi>) {return true;});
    YolcuBilgisiListesiFormu *form = new YolcuBilgisiListesiFormu();

    form->setListe(veri);

    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);

    form->show();
}

QAction *YolcuBilgisiListeIslemi::islem()
{
    return _islem;
}
