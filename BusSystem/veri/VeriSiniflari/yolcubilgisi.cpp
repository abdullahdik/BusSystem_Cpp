#include "yolcubilgisi.h"

YolcuBilgisi::YolcuBilgisi(QObject *parent)
    : InsanBilgisi{parent}
{

}

Tamsayi YolcuBilgisi::KoltukNo() const
{
    return _KoltukNo;
}

void YolcuBilgisi::setKoltukNo(Tamsayi newKoltukNo)
{
    if (_KoltukNo == newKoltukNo)
        return;
    _KoltukNo = newKoltukNo;
    emit KoltukNoChanged(_KoltukNo);
}

const Metin &YolcuBilgisi::TelefonNo() const
{
    return _TelefonNo;
}

void YolcuBilgisi::setTelefonNo(const Metin &newTelefonNo)
{
    if (_TelefonNo == newTelefonNo)
        return;
    _TelefonNo = newTelefonNo;
    emit TelefonNoChanged(_TelefonNo);
}

const Metin &YolcuBilgisi::Uyruk() const
{
    return _Uyruk;
}

void YolcuBilgisi::setUyruk(const Metin &newUyruk)
{
    if (_Uyruk == newUyruk)
        return;
    _Uyruk = newUyruk;
    emit UyrukChanged(_Uyruk);
}

const Metin &YolcuBilgisi::BiletKodu() const
{
    return _BiletKodu;
}

void YolcuBilgisi::setBiletKodu(const Metin &newBiletKodu)
{
    if (_BiletKodu == newBiletKodu)
        return;
    _BiletKodu = newBiletKodu;
    emit BiletKoduChanged(_BiletKodu);
}

Tamsayi YolcuBilgisi::YolcuId() const
{
    return _YolcuId;
}

void YolcuBilgisi::setYolcuId(Tamsayi newYolcuId)
{
    if (_YolcuId == newYolcuId)
        return;
    _YolcuId = newYolcuId;
    emit YolcuIdChanged(_YolcuId);
}

Tamsayi YolcuBilgisi::SeyahatId() const
{
    return _SeyahatId;
}

void YolcuBilgisi::setSeyahatId(Tamsayi newSeyahatId)
{
    if (_SeyahatId == newSeyahatId)
        return;
    _SeyahatId = newSeyahatId;
    emit SeyahatIdChanged(_SeyahatId);
}

const QDateTime &YolcuBilgisi::Rezervasyon() const
{
    return _Rezervasyon;
}

void YolcuBilgisi::setRezervasyon(const QDateTime &newRezervasyon)
{
    if (_Rezervasyon == newRezervasyon)
        return;
    _Rezervasyon = newRezervasyon;
    emit RezervasyonChanged(_Rezervasyon);
}

QDataStream &operator<<(QDataStream &stream, const YolcuBilgisi &veri){
    stream << veri._BiletKodu;
    stream << veri._KoltukNo;
    stream << veri._SeyahatId;
    stream << veri._TelefonNo;
    stream << veri._Uyruk;
    stream << veri._YolcuId;
    stream << veri._Rezervasyon;
    stream << veri._silindiMi;
    stream << veri._id;
    stream << veri._Ad;
    stream << veri._Soyad;
    stream << veri._HesKodu;
    stream << veri._TCKimlikNo;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, YolcuBilgisi &veri){
    stream >> veri._BiletKodu;
    stream >> veri._KoltukNo;
    stream >> veri._SeyahatId;
    stream >> veri._TelefonNo;
    stream >> veri._Uyruk;
    stream >> veri._YolcuId;
    stream >> veri._Rezervasyon;
    stream >> veri._silindiMi;
    stream >> veri._id;
    stream >> veri._Ad;
    stream >> veri._Soyad;
    stream >> veri._HesKodu;
    stream >> veri._TCKimlikNo;
    return stream;
}
