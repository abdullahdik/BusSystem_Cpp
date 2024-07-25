#ifndef ISLEMDEPOSU_H
#define ISLEMDEPOSU_H

#include <QObject>
#include <QList>
#include "TemelKullaniciIslemleri.h"
#include <memory>


class IslemDeposu : public QObject
{
    Q_OBJECT
public:
    static IslemDeposu &os();

    typedef enum { IsletmeBilgisiVeriGirisFormu = 0, OtobusBilgisiVeriGirisFormu = 1,  SeferBilgisiVeriGirisFormu = 2,
                   YolcuBilgisiVeriGirisFormu = 3,   SeyahatBilgisiVeriGirisFormu = 4, SoforBilgisiVeriGirisFormu = 5,
                   IsletmeBilgisiListesiIslemi =6,   OtobusBilgisiListeIslemi = 7,     SeferBilgsiListeIslemi = 8,
                   SeyahatBilgisiListesiIslemi = 9,  YolcuBilgisiListesiIslemi = 10,   SoforBilgisiListesiIslemi =11,
                   IslemIsletmeBilgisiSilme = 12,    IslemIsletmeBilgisiGuncelleme = 13 }  IslemSirasi ;

    QAction *getAction(IslemSirasi x);
    void calistir(IslemSirasi y );
    std::shared_ptr<TemelKullaniciIslemleri> getIslem(IslemSirasi z);

private:

    QList<std::shared_ptr<TemelKullaniciIslemleri>> _islemler ;
    explicit IslemDeposu(QObject *parent = nullptr);

signals:

};

#endif // ISLEMDEPOSU_H
