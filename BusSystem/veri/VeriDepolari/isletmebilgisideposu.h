#ifndef ISLETMEBILGISIDEPOSU_H
#define ISLETMEBILGISIDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <veri/VeriSiniflari/isletmebilgisi.h>

class IsletmeBilgisiDeposu : public QObject, public TemelVeriDeposu<IsletmeBilgisi>
{
    Q_OBJECT
public:
    explicit IsletmeBilgisiDeposu(QObject *parent = nullptr);

signals:

private:
friend  QDataStream &operator<<(QDataStream &stream, const IsletmeBilgisiDeposu &veri);
friend  QDataStream &operator>>(QDataStream &stream, IsletmeBilgisiDeposu &veri);

};
QDataStream &operator<<(QDataStream &stream, const IsletmeBilgisiDeposu &veri);
QDataStream &operator>>(QDataStream &stream, IsletmeBilgisiDeposu &veri);

#endif // ISLETMEBILGISIDEPOSU_H
