#ifndef ISLETMEBILGISIGUNCELLEMEISLEMI_H
#define ISLETMEBILGISIGUNCELLEMEISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>
#include <veri/tanimlar.h>

class IsletmeBilgisiGuncellemeIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit IsletmeBilgisiGuncellemeIslemi(QObject *parent = nullptr);

signals:
    void islemTamamlandi();

private:
    QAction *_islem;
    IsletmeBilgisiptr _veri;


    // TemelKullaniciIslemleri interface
public:

    QAction *islem() override;

    const IsletmeBilgisiptr &veri() const;


public slots:
    void main() override;

     void setVeri(const IsletmeBilgisiptr &newVeri);

     void depoGuncelle();
};

#endif // ISLETMEBILGISIGUNCELLEMEISLEMI_H
