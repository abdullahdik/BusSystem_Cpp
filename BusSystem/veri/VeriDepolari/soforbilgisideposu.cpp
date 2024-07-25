#include "soforbilgisideposu.h"

SoforBilgisiDeposu::SoforBilgisiDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<SoforBilgisi>{}{}
QDataStream &operator<<(QDataStream &stream, const SoforBilgisiDeposu &veri){
    stream << veri._sonId;
    stream << veri._veriler;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, SoforBilgisiDeposu &veri){
    stream >> veri._sonId;
    stream >> veri._veriler;
    return stream;
}
