#ifndef SOFORBILGISI_H
#define SOFORBILGISI_H

#include "insanbilgisi.h"
#include "temelverisinifi.h"

class SoforBilgisi : public InsanBilgisi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin EhliyetSinifi READ EhliyetSinifi WRITE setEhliyetSinifi NOTIFY EhliyetSinifiChanged)
    Q_PROPERTY(Metin Tecrubesi READ Tecrubesi WRITE setTecrubesi NOTIFY TecrubesiChanged)
    Q_PROPERTY(Tamsayi SoforId READ SoforId WRITE setSoforId NOTIFY SoforIdChanged)
    Q_PROPERTY(Tamsayi IsletmeId READ IsletmeId WRITE setIsletmeId NOTIFY IsletmeIdChanged)

    explicit SoforBilgisi(QObject *parent = nullptr);

    const Metin &EhliyetSinifi() const;

    const Metin &Tecrubesi() const;

    Tamsayi SoforId() const;

    Tamsayi IsletmeId() const;

public slots:
    void setEhliyetSinifi(const Metin &newEhliyetSinifi);

    void setTecrubesi(const Metin &newTecrubesi);

    void setSoforId(Tamsayi newSoforId);

    void setIsletmeId(Tamsayi newIsletmeId);

signals:
    void EhliyetSinifiChanged(const Metin &newEhliyetSinifi);

    void TecrubesiChanged(const Metin &newTecrubesi);

    void SoforIdChanged(Tamsayi newSoforId);

    void IsletmeIdChanged(Tamsayi newIsletmeId);

protected:
    Metin   _EhliyetSinifi;
    Metin   _Tecrubesi;
    Tamsayi _SoforId;
    Tamsayi _IsletmeId;

   friend QDataStream &operator<<(QDataStream &stream, const SoforBilgisi &veri);
   friend QDataStream &operator>>(QDataStream &stream, SoforBilgisi &veri);
};

QDataStream &operator<<(QDataStream &stream, const SoforBilgisi &veri);
QDataStream &operator>>(QDataStream &stream, SoforBilgisi &veri);

#endif // SOFORBILGISI_H
