#ifndef SEFERBILGISIGIRISISLEMI_H
#define SEFERBILGISIGIRISISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class SeferBilgisiGirisIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit SeferBilgisiGirisIslemi(QObject *parent = nullptr);

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

#endif // SEFERBILGISIGIRISISLEMI_H
