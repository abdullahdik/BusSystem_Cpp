#ifndef OTOBUSBILGISIGIRISISLEMI_H
#define OTOBUSBILGISIGIRISISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class OtobusBilgisiGirisIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit OtobusBilgisiGirisIslemi(QObject *parent = nullptr);

signals:


    // TemelKullaniciIslemleri interface
public:

    QAction *islem() override;

public slots:

    void main() override;
    void depoEkle();

private:

    QAction *_islem;

};

#endif // OTOBUSBILGISIGIRISISLEMI_H
