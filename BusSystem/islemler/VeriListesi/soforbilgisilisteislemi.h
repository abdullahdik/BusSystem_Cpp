#ifndef SOFORBILGISILISTEISLEMI_H
#define SOFORBILGISILISTEISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class SoforBilgisiListeIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit SoforBilgisiListeIslemi(QObject *parent = nullptr);


signals:

private:
    QAction *_islem;

    // TemelKullaniciIslemleri interface
public:
    void main() override;

public slots:
    QAction *islem() override;
};

#endif // SOFORBILGISILISTEISLEMI_H
