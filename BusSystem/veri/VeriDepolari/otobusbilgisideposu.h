#ifndef OTOBUSBILGISIDEPOSU_H
#define OTOBUSBILGISIDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <veri/VeriSiniflari/otobusbilgisi.h>

class OtobusBilgisiDeposu : public QObject, public  TemelVeriDeposu<OtobusBilgisi>
{
    Q_OBJECT
public:
    explicit OtobusBilgisiDeposu(QObject *parent = nullptr);

signals:

private:
friend  QDataStream &operator<<(QDataStream &stream, const OtobusBilgisiDeposu &veri);
friend  QDataStream &operator>>(QDataStream &stream, OtobusBilgisiDeposu &veri);
};
QDataStream &operator<<(QDataStream &stream, const OtobusBilgisiDeposu &veri);
QDataStream &operator>>(QDataStream &stream, OtobusBilgisiDeposu &veri);

#endif // OTOBUSBILGISIDEPOSU_H
