#ifndef YOLCUBILGISIDEPOSU_H
#define YOLCUBILGISIDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <veri/VeriSiniflari/yolcubilgisi.h>

class YolcuBilgisiDeposu : public QObject, public TemelVeriDeposu<YolcuBilgisi>
{
    Q_OBJECT
public:
    explicit YolcuBilgisiDeposu(QObject *parent = nullptr);

signals:

private:
friend  QDataStream &operator<<(QDataStream &stream, const YolcuBilgisiDeposu &veri);
friend  QDataStream &operator>>(QDataStream &stream, YolcuBilgisiDeposu &veri);
};

#endif // YOLCUBILGISIDEPOSU_H
QDataStream &operator<<(QDataStream &stream, const SeyahatBilgisiDeposu &veri);
QDataStream &operator>>(QDataStream &stream, SeyahatBilgisiDeposu &veri);
