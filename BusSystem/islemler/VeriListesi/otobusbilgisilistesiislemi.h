#ifndef OTOBUSBILGISILISTESIISLEMI_H
#define OTOBUSBILGISILISTESIISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class OtobusBilgisiListesiIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit OtobusBilgisiListesiIslemi(QObject *parent = nullptr);

signals:

private:
    QAction *_islem;


    // TemelKullaniciIslemleri interface
public:
    void main() override;

public slots:
    QAction *islem() override;
};

#endif // OTOBUSBILGISILISTESIISLEMI_H
