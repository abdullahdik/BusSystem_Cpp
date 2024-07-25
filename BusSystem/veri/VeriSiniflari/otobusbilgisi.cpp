#include "otobusbilgisi.h"

OtobusBilgisi::OtobusBilgisi(QObject *parent)
    : TemelVeriSinifi{parent}
{

}

const Metin &OtobusBilgisi::Plaka() const
{
    return _Plaka;
}

void OtobusBilgisi::setPlaka(const Metin &newPlaka)
{
    if (_Plaka == newPlaka)
        return;
    _Plaka = newPlaka;
    emit PlakaChanged(_Plaka);
}

const Metin &OtobusBilgisi::KoltukSayisi() const
{
    return _KoltukSayisi;
}

void OtobusBilgisi::setKoltukSayisi(const Metin &newKoltukSayisi)
{
    if (_KoltukSayisi == newKoltukSayisi)
        return;
    _KoltukSayisi = newKoltukSayisi;
    emit KoltukSayisiChanged(_KoltukSayisi);
}

const Metin &OtobusBilgisi::Ruhsat() const
{
    return _Ruhsat;
}

void OtobusBilgisi::setRuhsat(const Metin &newRuhsat)
{
    if (_Ruhsat == newRuhsat)
        return;
    _Ruhsat = newRuhsat;
    emit RuhsatChanged(_Ruhsat);
}

const Metin &OtobusBilgisi::Renk() const
{
    return _Renk;
}

void OtobusBilgisi::setRenk(const Metin &newRenk)
{
    if (_Renk == newRenk)
        return;
    _Renk = newRenk;
    emit RenkChanged(_Renk);
}

Tamsayi OtobusBilgisi::OtobusId() const
{
    return _OtobusId;
}

void OtobusBilgisi::setOtobusId(Tamsayi newOtobusId)
{
    if (_OtobusId == newOtobusId)
        return;
    _OtobusId = newOtobusId;
    emit OtobusIdChanged(_OtobusId);
}

Tamsayi OtobusBilgisi::SoforId() const
{
    return _SoforId;
}

void OtobusBilgisi::setSoforId(Tamsayi newSoforId)
{
    if (_SoforId == newSoforId)
        return;
    _SoforId = newSoforId;
    emit SoforIdChanged(_SoforId);
}

Tamsayi OtobusBilgisi::SeyahatId() const
{
    return _SeyahatId;
}

void OtobusBilgisi::setSeyahatId(Tamsayi newSeyahatId)
{
    if (_SeyahatId == newSeyahatId)
        return;
    _SeyahatId = newSeyahatId;
    emit SeyahatIdChanged(_SeyahatId);
}

Tamsayi OtobusBilgisi::IsletmeId() const
{
    return _IsletmeId;
}

void OtobusBilgisi::setIsletmeId(Tamsayi newIsletmeId)
{
    if (_IsletmeId == newIsletmeId)
        return;
    _IsletmeId = newIsletmeId;
    emit IsletmeIdChanged(_IsletmeId);
}

Tamsayi OtobusBilgisi::SeferId() const
{
    return _SeferId;
}

void OtobusBilgisi::setSeferId(Tamsayi newSeferId)
{
    if (_SeferId == newSeferId)
        return;
    _SeferId = newSeferId;
    emit SeferIdChanged(_SeferId);
}

const Tarh &OtobusBilgisi::MuayeneTarih() const
{
    return _MuayeneTarih;
}

void OtobusBilgisi::setMuayeneTarih(const Tarh &newMuayeneTarih)
{
    if (_MuayeneTarih == newMuayeneTarih)
        return;
    _MuayeneTarih = newMuayeneTarih;
    emit MuayeneTarihChanged(_MuayeneTarih);
}
QDataStream &operator<<(QDataStream &stream, const OtobusBilgisi &veri){
    stream << veri._IsletmeId;
    stream << veri._KoltukSayisi;
    stream << veri._MuayeneTarih;
    stream << veri._OtobusId;
    stream << veri._Plaka;
    stream << veri._Renk;
    stream << veri._Ruhsat;
    stream << veri._SeferId;
    stream << veri._SeyahatId;
    stream << veri._SoforId;
    stream << veri._silindiMi;
    stream << veri._id;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, OtobusBilgisi &veri){
    stream >> veri._IsletmeId;
    stream >> veri._KoltukSayisi;
    stream >> veri._MuayeneTarih;
    stream >> veri._OtobusId;
    stream >> veri._Plaka;
    stream >> veri._Renk;
    stream >> veri._Ruhsat;
    stream >> veri._SeferId;
    stream >> veri._SeyahatId;
    stream >> veri._SoforId;
    stream >> veri._silindiMi;
    stream >> veri._id;
    return stream;
}
