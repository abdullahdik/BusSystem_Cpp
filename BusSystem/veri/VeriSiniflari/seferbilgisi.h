#ifndef SEFERBILGISI_H
#define SEFERBILGISI_H

#include "temelverisinifi.h"


class SeferBilgisi : public TemelVeriSinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(TarhSaat BaslangicSaati READ BaslangicSaati WRITE setBaslangicSaati NOTIFY BaslangicSaatiChanged)
    Q_PROPERTY(TarhSaat BitisSaati READ BitisSaati WRITE setBitisSaati NOTIFY BitisSaatiChanged)
    Q_PROPERTY(Tamsayi SeferNo READ SeferNo WRITE setSeferNo NOTIFY SeferNoChanged)
    Q_PROPERTY(Metin Hatlar READ Hatlar WRITE setHatlar NOTIFY HatlarChanged)
    Q_PROPERTY(Metin Tarife READ Tarife WRITE setTarife NOTIFY TarifeChanged)
    Q_PROPERTY(Metin SeferKodu READ SeferKodu WRITE setSeferKodu NOTIFY SeferKoduChanged)
    Q_PROPERTY(Tamsayi SeferId READ SeferId WRITE setSeferId NOTIFY SeferIdChanged)
    Q_PROPERTY(Tamsayi YolcuId READ YolcuId WRITE setYolcuId NOTIFY YolcuIdChanged)
    Q_PROPERTY(Tamsayi SoforId READ SoforId WRITE setSoforId NOTIFY SoforIdChanged)
    Q_PROPERTY(Tamsayi IsletmeId READ IsletmeId WRITE setIsletmeId NOTIFY IsletmeIdChanged)
    Q_PROPERTY(Tamsayi SeyahatId READ SeyahatId WRITE setSeyahatId NOTIFY SeyahatIdChanged)

    explicit SeferBilgisi(QObject *parent = nullptr);

    Tamsayi SeferNo() const;


    const Metin &Hatlar() const;


    const Metin &Tarife() const;


    const Metin &SeferKodu() const;


    Tamsayi SeferId() const;


    Tamsayi YolcuId() const;


    Tamsayi SoforId() const;


    Tamsayi IsletmeId() const;


    Tamsayi SeyahatId() const;


    const TarhSaat &BaslangicSaati() const;


    const TarhSaat &BitisSaati() const;


public slots:


    void setSeferNo(Tamsayi newSeferNo);

    void setHatlar(const Metin &newHatlar);

    void setTarife(const Metin &newTarife);

    void setSeferKodu(const Metin &newSeferKodu);

    void setSeferId(Tamsayi newSeferId);

    void setYolcuId(Tamsayi newYolcuId);

    void setSoforId(Tamsayi newSoforId);

    void setIsletmeId(Tamsayi newIsletmeId);

    void setSeyahatId(Tamsayi newSeyahatId);

    void setBaslangicSaati(const TarhSaat &newBaslangicSaati);

    void setBitisSaati(const TarhSaat &newBitisSaati);

signals:


    void SeferNoChanged(Tamsayi newSeferNo);

    void HatlarChanged(const Metin &newHatlar);

    void TarifeChanged(const Metin &newTarife);

    void SeferKoduChanged(const Metin &newSeferKodu);

    void SeferIdChanged(Tamsayi newSeferId);

    void YolcuIdChanged(Tamsayi newYolcuId);

    void SoforIdChanged(Tamsayi newSoforId);

    void IsletmeIdChanged(Tamsayi newIsletmeId);

    void SeyahatIdChanged(Tamsayi newSeyahatId);

    void BaslangicSaatiChanged(const TarhSaat &newBaslangicSaati);

    void BitisSaatiChanged(const TarhSaat &newBitisSaati);

private:
    TarhSaat  _BaslangicSaati;
    TarhSaat  _BitisSaati;
    Tamsayi   _SeferNo;
    Metin     _Hatlar;
    Metin     _Tarife;
    Metin     _SeferKodu;
    Tamsayi   _SeferId;
    Tamsayi   _YolcuId;
    Tamsayi   _SoforId;
    Tamsayi   _IsletmeId;
    Tamsayi   _SeyahatId;

friend QDataStream &operator<<(QDataStream &stream, const SeferBilgisi &veri);
friend QDataStream &operator>>(QDataStream &stream, SeferBilgisi &veri);
};

QDataStream &operator<<(QDataStream &stream, const SeferBilgisi &veri);
QDataStream &operator>>(QDataStream &stream, SeferBilgisi &veri);

#endif // SEFERBILGISI_H
