#ifndef SOFORBILGISIDEPOSU_H
#define SOFORBILGISIDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <veri/VeriSiniflari/soforbilgisi.h>

class SoforBilgisiDeposu : public QObject, public TemelVeriDeposu<SoforBilgisi>
{
    Q_OBJECT
public:
    explicit SoforBilgisiDeposu(QObject *parent = nullptr);

signals:

private:
friend  QDataStream &operator<<(QDataStream &stream, const SoforBilgisiDeposu &veri);
friend  QDataStream &operator>>(QDataStream &stream, SoforBilgisiDeposu &veri);
};

#endif // SOFORBILGISIDEPOSU_H
QDataStream &operator<<(QDataStream &stream, const SoforBilgisiDeposu &veri);
QDataStream &operator>>(QDataStream &stream, SoforBilgisiDeposu &veri);
