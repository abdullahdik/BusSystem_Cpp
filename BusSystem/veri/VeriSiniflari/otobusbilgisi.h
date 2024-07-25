#ifndef OTOBUSBILGISI_H
#define OTOBUSBILGISI_H

#include "temelverisinifi.h"

class OtobusBilgisi : public TemelVeriSinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Tarh MuayeneTarih READ MuayeneTarih WRITE setMuayeneTarih NOTIFY MuayeneTarihChanged)
    Q_PROPERTY(Metin Plaka READ Plaka WRITE setPlaka NOTIFY PlakaChanged)
    Q_PROPERTY(Metin KoltukSayisi READ KoltukSayisi WRITE setKoltukSayisi NOTIFY KoltukSayisiChanged)
    Q_PROPERTY(Metin Ruhsat READ Ruhsat WRITE setRuhsat NOTIFY RuhsatChanged)
    Q_PROPERTY(Metin Renk READ Renk WRITE setRenk NOTIFY RenkChanged)
    Q_PROPERTY(Tamsayi OtobusId READ OtobusId WRITE setOtobusId NOTIFY OtobusIdChanged)
    Q_PROPERTY(Tamsayi SoforId READ SoforId WRITE setSoforId NOTIFY SoforIdChanged)
    Q_PROPERTY(Tamsayi SeyahatId READ SeyahatId WRITE setSeyahatId NOTIFY SeyahatIdChanged)
    Q_PROPERTY(Tamsayi IsletmeId READ IsletmeId WRITE setIsletmeId NOTIFY IsletmeIdChanged)
    Q_PROPERTY(Tamsayi SeferId READ SeferId WRITE setSeferId NOTIFY SeferIdChanged)

    explicit OtobusBilgisi(QObject *parent = nullptr);

    const Metin &Plaka() const;


    const Metin &KoltukSayisi() const;


    const Metin &Ruhsat() const;


    const Metin &MuayeneTarihi() const;


    const Metin &Renk() const;


    Tamsayi OtobusId() const;


    Tamsayi SoforId() const;


    Tamsayi SeyahatId() const;


    Tamsayi IsletmeId() const;


    Tamsayi SeferId() const;   

    const Tarh &MuayeneTarih() const;


public slots:
    void setMuayeneTarih(const Tarh &newMuayeneTarih);

    void setPlaka(const Metin &newPlaka);

    void setKoltukSayisi(const Metin &newKoltukSayisi);

    void setRuhsat(const Metin &newRuhsat);

    void setRenk(const Metin &newRenk);

    void setOtobusId(Tamsayi newOtobusId);

    void setSoforId(Tamsayi newSoforId);

    void setSeyahatId(Tamsayi newSeyahatId);

    void setIsletmeId(Tamsayi newIsletmeId);

    void setSeferId(Tamsayi newSeferId);

signals:
    void PlakaChanged(const Metin &newPlaka);

    void KoltukSayisiChanged(const Metin &newKoltukSayisi);

    void RuhsatChanged(const Metin &newRuhsat);

    void RenkChanged(const Metin &newRenk);

    void OtobusIdChanged(Tamsayi newOtobusId);

    void SoforIdChanged(Tamsayi newSoforId);

    void SeyahatIdChanged(Tamsayi newSeyahatId);

    void IsletmeIdChanged(Tamsayi newIsletmeId);

    void SeferIdChanged(Tamsayi newSeferId);

    void MuayeneTarihChanged(const Tarh &newMuayeneTarih);

private:
    Metin _Plaka;
    Metin _KoltukSayisi;
    Metin _Ruhsat;
    Metin _Renk;
    Tamsayi _OtobusId;
    Tamsayi _SoforId;
    Tamsayi _SeyahatId;
    Tamsayi _IsletmeId;
    Tamsayi _SeferId;
    Tarh _MuayeneTarih;

   friend QDataStream &operator<<(QDataStream &stream, const OtobusBilgisi &veri);
   friend QDataStream &operator>>(QDataStream &stream, OtobusBilgisi &veri);
};

QDataStream &operator<<(QDataStream &stream, const OtobusBilgisi &veri);
QDataStream &operator>>(QDataStream &stream, OtobusBilgisi &veri);

#endif // OTOBUSBILGISI_H
