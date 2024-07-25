#include "otobusbilgisideposu.h"

OtobusBilgisiDeposu::OtobusBilgisiDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<OtobusBilgisi>{} {}

QDataStream &operator<<(QDataStream &stream, const OtobusBilgisiDeposu &veri){
    stream << veri._sonId;
    stream << veri._veriler;
    return stream;
}


QDataStream &operator>>(QDataStream &stream, OtobusBilgisiDeposu &veri){
    stream >> veri._sonId;
    stream >> veri._veriler;
    return stream;
}
