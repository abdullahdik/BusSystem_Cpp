#ifndef SEFERBILGISILISTESIISLEMI_H
#define SEFERBILGISILISTESIISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>

class SeferBilgisiListesiIslemi : public QObject, public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit SeferBilgisiListesiIslemi(QObject *parent = nullptr);

signals:

private:

    QAction *_islem;

    // TemelKullaniciIslemleri interface
public:

    void main() override;

public slots:

    QAction *islem() override;
};

#endif // SEFERBILGISILISTESIISLEMI_H
