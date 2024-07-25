#include "seyahatbilgisi.h"

SeyahatBilgisi::SeyahatBilgisi(QObject *parent)
    : TemelVeriSinifi{parent}
{

}

Tamsayi SeyahatBilgisi::PeronNo() const
{
    return _PeronNo;
}

void SeyahatBilgisi::setPeronNo(Tamsayi newPeronNo)
{
    if (_PeronNo == newPeronNo)
        return;
    _PeronNo = newPeronNo;
    emit PeronNoChanged(_PeronNo);
}

const TarhSaat &SeyahatBilgisi::TarihSaat() const
{
    return _TarihSaat;
}

void SeyahatBilgisi::setTarihSaat(const TarhSaat &newTarihSaat)
{
    if (_TarihSaat == newTarihSaat)
        return;
    _TarihSaat = newTarihSaat;
    emit TarihSaatChanged(_TarihSaat);
}

const Metin &SeyahatBilgisi::Ikram() const
{
    return _Ikram;
}

void SeyahatBilgisi::setIkram(const Metin &newIkram)
{
    if (_Ikram == newIkram)
        return;
    _Ikram = newIkram;
    emit IkramChanged(_Ikram);
}

const Metin &SeyahatBilgisi::Tesis() const
{
    return _Tesis;
}

void SeyahatBilgisi::setTesis(const Metin &newTesis)
{
    if (_Tesis == newTesis)
        return;
    _Tesis = newTesis;
    emit TesisChanged(_Tesis);
}

Tamsayi SeyahatBilgisi::SeyahatId() const
{
    return _SeyahatId;
}

void SeyahatBilgisi::setSeyahatId(Tamsayi newSeyahatId)
{
    if (_SeyahatId == newSeyahatId)
        return;
    _SeyahatId = newSeyahatId;
    emit SeyahatIdChanged(_SeyahatId);
}

Tamsayi SeyahatBilgisi::SoforId() const
{
    return _SoforId;
}

void SeyahatBilgisi::setSoforId(Tamsayi newSoforId)
{
    if (_SoforId == newSoforId)
        return;
    _SoforId = newSoforId;
    emit SoforIdChanged(_SoforId);
}

Tamsayi SeyahatBilgisi::IsletmeId() const
{
    return _IsletmeId;
}

void SeyahatBilgisi::setIsletmeId(Tamsayi newIsletmeId)
{
    if (_IsletmeId == newIsletmeId)
        return;
    _IsletmeId = newIsletmeId;
    emit IsletmeIdChanged(_IsletmeId);
}

Tamsayi SeyahatBilgisi::SeferId() const
{
    return _SeferId;
}

void SeyahatBilgisi::setSeferId(Tamsayi newSeferId)
{
    if (_SeferId == newSeferId)
        return;
    _SeferId = newSeferId;
    emit SeferIdChanged(_SeferId);
}
QDataStream &operator<<(QDataStream &stream, const SeyahatBilgisi &veri){
    stream << veri._Ikram;
    stream << veri._IsletmeId;
    stream << veri._PeronNo;
    stream << veri._SeferId;
    stream << veri._SeyahatId;
    stream << veri._SoforId;
    stream << veri._TarihSaat;
    stream << veri._Tesis;
    stream << veri._silindiMi;
    stream << veri._id;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, SeyahatBilgisi &veri){
    stream >> veri._Ikram;
    stream >> veri._IsletmeId;
    stream >> veri._PeronNo;
    stream >> veri._SeferId;
    stream >> veri._SeyahatId;
    stream >> veri._SoforId;
    stream >> veri._TarihSaat;
    stream >> veri._Tesis;
    stream >> veri._silindiMi;
    stream >> veri._id;
    return stream;
}
