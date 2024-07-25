#ifndef ISLETMEBILGISILISTEISLEMI_H
#define ISLETMEBILGISILISTEISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class IsletmeBilgisiListeIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit IsletmeBilgisiListeIslemi(QObject *parent = nullptr);

signals:

private:
    QAction *_islem;

    // TemelKullaniciIslemleri interface
public slots:
    void main() override;
public:
    QAction *islem() override;
};

#endif // ISLETMEBILGISILISTEISLEMI_H
