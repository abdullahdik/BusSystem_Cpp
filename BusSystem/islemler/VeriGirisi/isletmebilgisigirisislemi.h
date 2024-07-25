#ifndef ISLETMEBILGISIGIRISISLEMI_H
#define ISLETMEBILGISIGIRISISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class IsletmeBilgisiGirisIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit IsletmeBilgisiGirisIslemi(QObject *parent = nullptr);

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

#endif // ISLETMEBILGISIGIRISISLEMI_H
