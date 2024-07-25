#include "seferbilgisi.h"

SeferBilgisi::SeferBilgisi(QObject *parent)
    : TemelVeriSinifi{parent}
{

}

Tamsayi SeferBilgisi::SeferNo() const
{
    return _SeferNo;
}

void SeferBilgisi::setSeferNo(Tamsayi newSeferNo)
{
    if (_SeferNo == newSeferNo)
        return;
    _SeferNo = newSeferNo;
    emit SeferNoChanged(_SeferNo);
}

const Metin &SeferBilgisi::Hatlar() const
{
    return _Hatlar;
}

void SeferBilgisi::setHatlar(const Metin &newHatlar)
{
    if (_Hatlar == newHatlar)
        return;
    _Hatlar = newHatlar;
    emit HatlarChanged(_Hatlar);
}

const Metin &SeferBilgisi::Tarife() const
{
    return _Tarife;
}

void SeferBilgisi::setTarife(const Metin &newTarife)
{
    if (_Tarife == newTarife)
        return;
    _Tarife = newTarife;
    emit TarifeChanged(_Tarife);
}

const Metin &SeferBilgisi::SeferKodu() const
{
    return _SeferKodu;
}

void SeferBilgisi::setSeferKodu(const Metin &newSeferKodu)
{
    if (_SeferKodu == newSeferKodu)
        return;
    _SeferKodu = newSeferKodu;
    emit SeferKoduChanged(_SeferKodu);
}

Tamsayi SeferBilgisi::SeferId() const
{
    return _SeferId;
}

void SeferBilgisi::setSeferId(Tamsayi newSeferId)
{
    if (_SeferId == newSeferId)
        return;
    _SeferId = newSeferId;
    emit SeferIdChanged(_SeferId);
}

Tamsayi SeferBilgisi::YolcuId() const
{
    return _YolcuId;
}

void SeferBilgisi::setYolcuId(Tamsayi newYolcuId)
{
    if (_YolcuId == newYolcuId)
        return;
    _YolcuId = newYolcuId;
    emit YolcuIdChanged(_YolcuId);
}

Tamsayi SeferBilgisi::SoforId() const
{
    return _SoforId;
}

void SeferBilgisi::setSoforId(Tamsayi newSoforId)
{
    if (_SoforId == newSoforId)
        return;
    _SoforId = newSoforId;
    emit SoforIdChanged(_SoforId);
}

Tamsayi SeferBilgisi::IsletmeId() const
{
    return _IsletmeId;
}

void SeferBilgisi::setIsletmeId(Tamsayi newIsletmeId)
{
    if (_IsletmeId == newIsletmeId)
        return;
    _IsletmeId = newIsletmeId;
    emit IsletmeIdChanged(_IsletmeId);
}

Tamsayi SeferBilgisi::SeyahatId() const
{
    return _SeyahatId;
}

void SeferBilgisi::setSeyahatId(Tamsayi newSeyahatId)
{
    if (_SeyahatId == newSeyahatId)
        return;
    _SeyahatId = newSeyahatId;
    emit SeyahatIdChanged(_SeyahatId);
}

const TarhSaat &SeferBilgisi::BitisSaati() const
{
    return _BitisSaati;
}

void SeferBilgisi::setBitisSaati(const TarhSaat &newBitisSaati)
{
    if (_BitisSaati == newBitisSaati)
        return;
    _BitisSaati = newBitisSaati;
    emit BitisSaatiChanged(_BitisSaati);
}

const TarhSaat &SeferBilgisi::BaslangicSaati() const
{
    return _BaslangicSaati;
}

void SeferBilgisi::setBaslangicSaati(const TarhSaat &newBaslangicSaati)
{
    if (_BaslangicSaati == newBaslangicSaati)
        return;
    _BaslangicSaati = newBaslangicSaati;
    emit BaslangicSaatiChanged(_BaslangicSaati);
}
QDataStream &operator<<(QDataStream &stream, const SeferBilgisi &veri){
    stream << veri._BaslangicSaati;
    stream << veri._BitisSaati;
    stream << veri._Hatlar;
    stream << veri._IsletmeId;
    stream << veri._SeferId;
    stream << veri._SeferKodu;
    stream << veri._SeferNo;
    stream << veri._SeyahatId;
    stream << veri._SoforId;
    stream << veri._Tarife;
    stream << veri._YolcuId;
    stream << veri._silindiMi;
    stream << veri._id;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, SeferBilgisi &veri){
    stream >> veri._BaslangicSaati;
    stream >> veri._BitisSaati;
    stream >> veri._Hatlar;
    stream >> veri._IsletmeId;
    stream >> veri._SeferId;
    stream >> veri._SeferKodu;
    stream >> veri._SeferNo;
    stream >> veri._SeyahatId;
    stream >> veri._SoforId;
    stream >> veri._Tarife;
    stream >> veri._YolcuId;
    stream >> veri._silindiMi;
    stream >> veri._id;
    return stream;
}
