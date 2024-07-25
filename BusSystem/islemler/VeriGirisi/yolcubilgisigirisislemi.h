#ifndef YOLCUBILGISIGIRISISLEMI_H
#define YOLCUBILGISIGIRISISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class YolcuBilgisiGirisIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit YolcuBilgisiGirisIslemi(QObject *parent = nullptr);

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

#endif // YOLCUBILGISIGIRISISLEMI_H
