#include "isletmebilgisi.h"

IsletmeBilgisi::IsletmeBilgisi(QObject *parent)
    : TemelVeriSinifi{parent}
{

}

const Metin &IsletmeBilgisi::IsletmeAdi() const
{
    return _IsletmeAdi;
}

void IsletmeBilgisi::setIsletmeAdi(const Metin &newIsletmeAdi)
{
    if (_IsletmeAdi == newIsletmeAdi)
        return;
    _IsletmeAdi = newIsletmeAdi;
    emit IsletmeAdiChanged(_IsletmeAdi);
}

const Metin &IsletmeBilgisi::VergiNo() const
{
    return _VergiNo;
}

void IsletmeBilgisi::setVergiNo(const Metin &newVergiNo)
{
    if (_VergiNo == newVergiNo)
        return;
    _VergiNo = newVergiNo;
    emit VergiNoChanged(_VergiNo);
}

const Metin &IsletmeBilgisi::Konum() const
{
    return _Konum;
}

void IsletmeBilgisi::setKonum(const Metin &newKonum)
{
    if (_Konum == newKonum)
        return;
    _Konum = newKonum;
    emit KonumChanged(_Konum);
}

Tamsayi IsletmeBilgisi::IsletmeId() const
{
    return _IsletmeId;
}

void IsletmeBilgisi::setIsletmeId(Tamsayi newIsletmeId)
{
    if (_IsletmeId == newIsletmeId)
        return;
    _IsletmeId = newIsletmeId;
    emit IsletmeIdChanged(_IsletmeId);
}

Tamsayi IsletmeBilgisi::SicilNo() const
{
    return _SicilNo;
}

void IsletmeBilgisi::setSicilNo(Tamsayi newSicilNo)
{
    if (_SicilNo == newSicilNo)
        return;
    _SicilNo = newSicilNo;
    emit SicilNoChanged(_SicilNo);
}

QDataStream &operator<<(QDataStream &stream, const IsletmeBilgisi &veri){
    stream << veri._IsletmeAdi;
    stream << veri._Konum;
    stream << veri._SicilNo;
    stream << veri._VergiNo;
    stream << veri._IsletmeId;
    stream << veri._id;
    stream << veri._silindiMi;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, IsletmeBilgisi &veri){
    stream >> veri._IsletmeAdi;
    stream >> veri._Konum;
    stream >> veri._SicilNo;
    stream >> veri._VergiNo;
    stream >> veri._IsletmeId;
    stream >> veri._silindiMi;
    stream >> veri._id;
    return stream;
}
