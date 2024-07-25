#include "seferbilgisideposu.h"

SeferBilgisiDeposu::SeferBilgisiDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<SeferBilgisi>{}{}
QDataStream &operator<<(QDataStream &stream, const SeferBilgisiDeposu &veri){
    stream << veri._sonId;
    stream << veri._veriler;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, SeferBilgisiDeposu &veri){
    stream >> veri._sonId;
    stream >> veri._veriler;
    return stream;
}
