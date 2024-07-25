#include "soforbilgisi.h"

SoforBilgisi::SoforBilgisi(QObject *parent)
    : InsanBilgisi{parent}
{

}

const Metin &SoforBilgisi::EhliyetSinifi() const
{
    return _EhliyetSinifi;
}

void SoforBilgisi::setEhliyetSinifi(const Metin &newEhliyetSinifi)
{
    if (_EhliyetSinifi == newEhliyetSinifi)
        return;
    _EhliyetSinifi = newEhliyetSinifi;
    emit EhliyetSinifiChanged(_EhliyetSinifi);
}

const Metin &SoforBilgisi::Tecrubesi() const
{
    return _Tecrubesi;
}

void SoforBilgisi::setTecrubesi(const Metin &newTecrubesi)
{
    if (_Tecrubesi == newTecrubesi)
        return;
    _Tecrubesi = newTecrubesi;
    emit TecrubesiChanged(_Tecrubesi);
}

Tamsayi SoforBilgisi::SoforId() const
{
    return _SoforId;
}

void SoforBilgisi::setSoforId(Tamsayi newSoforId)
{
    if (_SoforId == newSoforId)
        return;
    _SoforId = newSoforId;
    emit SoforIdChanged(_SoforId);
}

Tamsayi SoforBilgisi::IsletmeId() const
{
    return _IsletmeId;
}

void SoforBilgisi::setIsletmeId(Tamsayi newIsletmeId)
{
    if (_IsletmeId == newIsletmeId)
        return;
    _IsletmeId = newIsletmeId;
    emit IsletmeIdChanged(_IsletmeId);
}

QDataStream &operator<<(QDataStream &stream, const SoforBilgisi &veri){
    stream << veri._EhliyetSinifi;
    stream << veri._IsletmeId;
    stream << veri._SoforId;
    stream << veri._Tecrubesi;
    stream << veri._silindiMi;
    stream << veri._id;
    stream << veri._Ad;
    stream << veri._Soyad;
    stream << veri._HesKodu;
    stream << veri._TCKimlikNo;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, SoforBilgisi &veri){
    stream >> veri._EhliyetSinifi;
    stream >> veri._IsletmeId;
    stream >> veri._SoforId;
    stream >> veri._Tecrubesi;
    stream >> veri._silindiMi;
    stream >> veri._id;
    stream >> veri._Ad;
    stream >> veri._Soyad;
    stream >> veri._HesKodu;
    stream >> veri._TCKimlikNo;
    return stream;
}
