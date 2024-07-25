#ifndef SEYAHATBILGISIDEPOSU_H
#define SEYAHATBILGISIDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <veri/VeriSiniflari/seyahatbilgisi.h>

class SeyahatBilgisiDeposu : public QObject, public TemelVeriDeposu<SeyahatBilgisi>
{
    Q_OBJECT
public:
    explicit SeyahatBilgisiDeposu(QObject *parent = nullptr);

signals:

private:
friend QDataStream &operator<<(QDataStream &stream, const SeyahatBilgisiDeposu &veri);
friend QDataStream &operator>>(QDataStream &stream, SeyahatBilgisiDeposu &veri);
};

#endif // SEYAHATBILGISIDEPOSU_H
QDataStream &operator<<(QDataStream &stream, const SeyahatBilgisiDeposu &veri);
QDataStream &operator>>(QDataStream &stream, SeyahatBilgisiDeposu &veri);
