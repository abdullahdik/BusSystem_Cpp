#include "yolcubilgisideposu.h"

YolcuBilgisiDeposu::YolcuBilgisiDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<YolcuBilgisi>{}{}
QDataStream &operator<<(QDataStream &stream, const YolcuBilgisiDeposu &veri){
    stream << veri._sonId;
    stream << veri._veriler;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, YolcuBilgisiDeposu &veri){
    stream >> veri._sonId;
    stream >> veri._veriler;
    return stream;
}
