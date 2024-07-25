#include "seyahatbilgisideposu.h"

SeyahatBilgisiDeposu::SeyahatBilgisiDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<SeyahatBilgisi>{}{}
QDataStream &operator<<(QDataStream &stream, const SeyahatBilgisiDeposu &veri){
    stream << veri._sonId;
    stream << veri._veriler;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, SeyahatBilgisiDeposu &veri){
    stream >> veri._sonId;
    stream >> veri._veriler;
    return stream;
}
