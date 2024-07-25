#ifndef YOLCUBILGISILISTEISLEMI_H
#define YOLCUBILGISILISTEISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class YolcuBilgisiListeIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit YolcuBilgisiListeIslemi(QObject *parent = nullptr);

signals:

private:
    QAction *_islem;



    // TemelKullaniciIslemleri interface
public:
    void main() override;

public slots:
    QAction *islem() override;
};

#endif // YOLCUBILGISILISTEISLEMI_H
