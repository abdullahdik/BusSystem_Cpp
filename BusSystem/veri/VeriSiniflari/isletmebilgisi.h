#ifndef ISLETMEBILGISI_H
#define ISLETMEBILGISI_H

#include "temelverisinifi.h"

class IsletmeBilgisi : public TemelVeriSinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin IsletmeAdi READ IsletmeAdi WRITE setIsletmeAdi NOTIFY IsletmeAdiChanged)
    Q_PROPERTY(Metin VergiNo READ VergiNo WRITE setVergiNo NOTIFY VergiNoChanged)
    Q_PROPERTY(Metin Konum READ Konum WRITE setKonum NOTIFY KonumChanged)
    Q_PROPERTY(Tamsayi IsletmeId READ IsletmeId WRITE setIsletmeId NOTIFY IsletmeIdChanged)
    Q_PROPERTY(Tamsayi SicilNo READ SicilNo WRITE setSicilNo NOTIFY SicilNoChanged)

    explicit IsletmeBilgisi(QObject *parent = nullptr);

    const Metin &IsletmeAdi() const;    


    const Metin &VergiNo() const;


    const Metin &Konum() const;

    Tamsayi IsletmeId() const;


    Tamsayi SicilNo() const;
    ;

public slots:
    void setIsletmeAdi(const Metin &newIsletmeAdi);

    void setVergiNo(const Metin &newVergiNo);

    void setKonum(const Metin &newKonum);

    void setIsletmeId(Tamsayi newIsletmeId);

    void setSicilNo(Tamsayi newSicilNo);

signals:
    void IsletmeAdiChanged(const Metin &newIsletmeAdi);

    void VergiNoChanged(const Metin &newVergiNo);

    void KonumChanged(const Metin &newKonum);

    void IsletmeIdChanged(Tamsayi newIsletmeId);

    void SicilNoChanged(Tamsayi newSicilNo);

private:
    Metin _IsletmeAdi;
    Metin _VergiNo;
    Metin _Konum;
    Tamsayi _IsletmeId;
    Tamsayi _SicilNo;

   friend QDataStream &operator<<(QDataStream &stream, const IsletmeBilgisi &veri);
   friend QDataStream &operator>>(QDataStream &stream, IsletmeBilgisi &veri);

};

QDataStream &operator<<(QDataStream &stream, const IsletmeBilgisi &veri);
QDataStream &operator>>(QDataStream &stream, IsletmeBilgisi &veri);

#endif // ISLETMEBILGISI_H
