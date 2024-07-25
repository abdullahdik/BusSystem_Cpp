#ifndef SEYAHATBILGISILISTEISLEMI_H
#define SEYAHATBILGISILISTEISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class SeyahatBilgisiListeIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit SeyahatBilgisiListeIslemi(QObject *parent = nullptr);

signals:

private:
    QAction *_islem;


    // TemelKullaniciIslemleri interface
public:
    void main() override;

public slots:
    QAction *islem() override;
};

#endif // SEYAHATBILGISILISTEISLEMI_H
