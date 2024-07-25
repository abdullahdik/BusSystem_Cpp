#include "isletmebilgisideposu.h"

IsletmeBilgisiDeposu::IsletmeBilgisiDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<IsletmeBilgisi>{} {}

QDataStream &operator<<(QDataStream &stream, const IsletmeBilgisiDeposu &veri){
    stream << veri._sonId;
    stream << veri._veriler;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, IsletmeBilgisiDeposu &veri){
    stream >> veri._sonId;
    stream >> veri._veriler;
    return stream;
}
