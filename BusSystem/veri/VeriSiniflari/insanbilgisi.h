#ifndef INSANBILGISI_H
#define INSANBILGISI_H

#include <QObject>
#include "temelverisinifi.h"

class InsanBilgisi : public TemelVeriSinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin Ad READ Ad WRITE setAd NOTIFY AdChanged)
    Q_PROPERTY(Metin Soyad READ Soyad WRITE setSoyad NOTIFY SoyadChanged)
    Q_PROPERTY(Metin TCKimlikNo READ TCKimlikNo WRITE setTCKimlikNo NOTIFY TCKimlikNoChanged)
    Q_PROPERTY(Metin HesKodu READ HesKodu WRITE setHesKodu NOTIFY HesKoduChanged)
    Q_PROPERTY(Metin TelefonNo READ TelefonNo WRITE setTelefonNo NOTIFY TelefonNoChanged)
    Q_PROPERTY(Cinsiyet Cinsiyt READ Cinsiyt WRITE setCinsiyt NOTIFY CinsiytChanged)
    explicit InsanBilgisi(QObject *parent = nullptr);

    const Metin &Ad() const;
    void setAd(const Metin &newAd);

    const Metin &Soyad() const;
    void setSoyad(const Metin &newSoyad);

    const Metin &TCKimlikNo() const;
    void setTCKimlikNo(const Metin &newTCKimlikNo);

    const Metin &HesKodu() const;
    void setHesKodu(const Metin &newHesKodu);

    const Metin &TelefonNo() const;
    void setTelefonNo(const Metin &newTelefonNo);

    Cinsiyet Cinsiyt() const;
    void setCinsiyt(Cinsiyet newCinsiyt);
public slots:

signals:
    void AdChanged(const Metin &newAd);

    void SoyadChanged(const Metin &newSoyad);

    void TCKimlikNoChanged(const Metin &newTCKimlikNo);

    void HesKoduChanged(const Metin &newHesKodu);

    void TelefonNoChanged(const Metin &newTelefonNo);

    void CinsiytChanged(Cinsiyet newCinsiyt);

protected:
    Metin _Ad;
    Metin _Soyad;
    Metin _TCKimlikNo;
    Metin _HesKodu;
    Metin _TelefonNo;
    Cinsiyet _Cinsiyt;

};


#endif // INSANBILGISI_H
