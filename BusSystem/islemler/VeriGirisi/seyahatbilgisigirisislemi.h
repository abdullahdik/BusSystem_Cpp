#ifndef SEYAHATBILGISIGIRISISLEMI_H
#define SEYAHATBILGISIGIRISISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class SeyahatBilgisiGirisIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit SeyahatBilgisiGirisIslemi(QObject *parent = nullptr);

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

#endif // SEYAHATBILGISIGIRISISLEMI_H
