#include "insanbilgisi.h"

InsanBilgisi::InsanBilgisi(QObject *parent)
    : TemelVeriSinifi(parent)
{

}

const Metin &InsanBilgisi::Ad() const
{
    return _Ad;
}

void InsanBilgisi::setAd(const Metin &newAd)
{
    if (_Ad == newAd)
        return;
    _Ad = newAd;
    emit AdChanged(_Ad);
}

const Metin &InsanBilgisi::Soyad() const
{
    return _Soyad;
}

void InsanBilgisi::setSoyad(const Metin &newSoyad)
{
    if (_Soyad == newSoyad)
        return;
    _Soyad = newSoyad;
    emit SoyadChanged(_Soyad);
}

const Metin &InsanBilgisi::TCKimlikNo() const
{
    return _TCKimlikNo;
}

void InsanBilgisi::setTCKimlikNo(const Metin &newTCKimlikNo)
{
    if (_TCKimlikNo == newTCKimlikNo)
        return;
    _TCKimlikNo = newTCKimlikNo;
    emit TCKimlikNoChanged(_TCKimlikNo);
}

const Metin &InsanBilgisi::HesKodu() const
{
    return _HesKodu;
}

void InsanBilgisi::setHesKodu(const Metin &newHesKodu)
{
    if (_HesKodu == newHesKodu)
        return;
    _HesKodu = newHesKodu;
    emit HesKoduChanged(_HesKodu);
}

const Metin &InsanBilgisi::TelefonNo() const
{
    return _TelefonNo;
}

void InsanBilgisi::setTelefonNo(const Metin &newTelefonNo)
{
    if (_TelefonNo == newTelefonNo)
        return;
    _TelefonNo = newTelefonNo;
    emit TelefonNoChanged(_TelefonNo);
}

Cinsiyet InsanBilgisi::Cinsiyt() const
{
    return _Cinsiyt;
}

void InsanBilgisi::setCinsiyt(Cinsiyet newCinsiyt)
{
    if (_Cinsiyt == newCinsiyt)
        return;
    _Cinsiyt = newCinsiyt;
    emit CinsiytChanged(_Cinsiyt);
}


