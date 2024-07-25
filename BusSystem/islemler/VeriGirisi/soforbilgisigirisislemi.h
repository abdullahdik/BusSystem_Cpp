#ifndef SOFORBILGISIGIRISISLEMI_H
#define SOFORBILGISIGIRISISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class SoforBilgisiGirisIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit SoforBilgisiGirisIslemi(QObject *parent = nullptr);

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

#endif // SOFORBILGISIGIRISISLEMI_H
