#ifndef SEFERBILGISIDEPOSU_H
#define SEFERBILGISIDEPOSU_H

#include <QObject>
#include "temelverideposu.h"
#include <veri/VeriSiniflari/seferbilgisi.h>

class SeferBilgisiDeposu : public QObject, public TemelVeriDeposu<SeferBilgisi>
{
    Q_OBJECT
public:
    explicit SeferBilgisiDeposu(QObject *parent = nullptr);

signals:
private:
friend    QDataStream &operator<<(QDataStream &stream, const SeferBilgisiDeposu &veri);
friend    QDataStream &operator>>(QDataStream &stream, SeferBilgisiDeposu &veri);
};

#endif // SEFERBILGISIDEPOSU_H
QDataStream &operator<<(QDataStream &stream, const SeferBilgisiDeposu &veri);
QDataStream &operator>>(QDataStream &stream, SeferBilgisiDeposu &veri);
