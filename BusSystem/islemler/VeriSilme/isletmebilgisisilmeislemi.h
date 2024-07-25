#ifndef ISLETMEBILGISISILMEISLEMI_H
#define ISLETMEBILGISISILMEISLEMI_H

#include <QObject>
#include <islemler/TemelKullaniciIslemleri.h>
#include <veri/tanimlar.h>

class IsletmeBilgisiSilmeIslemi : public QObject , public TemelKullaniciIslemleri
{
    Q_OBJECT
public:
    explicit IsletmeBilgisiSilmeIslemi(QObject *parent = nullptr);

    QAction *islem();

    const IsletmeBilgisiptr &veri() const;
    void setVeri(const IsletmeBilgisiptr &newVeri);

public slots:
    void main () ;
signals:

private:
    QAction *_islem;
    IsletmeBilgisiptr _veri;
};

#endif // ISLETMEBILGISISILMEISLEMI_H
