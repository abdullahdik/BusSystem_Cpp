#include "isletmebilgisiguncellemeislemi.h"
#include <Formlar/VeriFormlari/isletmebilgisiverigirisformu.h>


IsletmeBilgisiGuncellemeIslemi::IsletmeBilgisiGuncellemeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();

    connect(_islem, &QAction::triggered, this, &IsletmeBilgisiGuncellemeIslemi::main);
}

const IsletmeBilgisiptr &IsletmeBilgisiGuncellemeIslemi::veri() const
{
    return _veri;
}

void IsletmeBilgisiGuncellemeIslemi::setVeri(const IsletmeBilgisiptr &newVeri)
{
    _veri = newVeri;
}

void IsletmeBilgisiGuncellemeIslemi::depoGuncelle()
{
    IsletmeSistemiVeriGirisFormu *frmx = dynamic_cast<IsletmeSistemiVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    frmx->close();
    emit islemTamamlandi();
}

void IsletmeBilgisiGuncellemeIslemi::main()
{
    IsletmeSistemiVeriGirisFormu *form = new IsletmeSistemiVeriGirisFormu();
    connect(form, &IsletmeSistemiVeriGirisFormu::veriKaydet, this, &IsletmeBilgisiGuncellemeIslemi::depoGuncelle);
    form->setVeri(_veri);

    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);

    form->baslikAta("İşletme Bilgisi Güncelle");
    form->show();

}

QAction *IsletmeBilgisiGuncellemeIslemi::islem()
{
    return _islem;
}
