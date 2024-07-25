#include "isletmebilgisisilmeislemi.h"
#include <veri/data.h>
#include <QMessageBox>
#include <veri/VeriSiniflari/isletmebilgisi.h>

IsletmeBilgisiSilmeIslemi::IsletmeBilgisiSilmeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    connect(_islem, &QAction::triggered, this, &IsletmeBilgisiSilmeIslemi::main);
}

QAction *IsletmeBilgisiSilmeIslemi::islem(){ return _islem; }

void IsletmeBilgisiSilmeIslemi::main()
{
    auto cevap = QMessageBox::question(nullptr,
                tr("İşletme Bilgisi Silme Onayı"),
                tr("%1 isimli işletme bilgisini silmek istediğine emin misiniz?")
                  .arg(_veri->IsletmeAdi()));


    if ( cevap == QMessageBox::Yes) {
        Data::os().isletmebilgisi().nesneSil(_veri);
    }
}
const IsletmeBilgisiptr &IsletmeBilgisiSilmeIslemi::veri() const
{
    return _veri;
}

void IsletmeBilgisiSilmeIslemi::setVeri(const IsletmeBilgisiptr &newVeri)
{
    _veri = newVeri;
}


