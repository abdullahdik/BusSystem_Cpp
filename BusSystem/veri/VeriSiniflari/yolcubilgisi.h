#ifndef YOLCUBILGISI_H
#define YOLCUBILGISI_H

#include "insanbilgisi.h"

class YolcuBilgisi : public InsanBilgisi
{
    Q_OBJECT
public:
    Q_PROPERTY(Tamsayi KoltukNo READ KoltukNo WRITE setKoltukNo NOTIFY KoltukNoChanged)
    Q_PROPERTY(Metin TelefonNo READ TelefonNo WRITE setTelefonNo NOTIFY TelefonNoChanged)
    Q_PROPERTY(Metin Uyruk READ Uyruk WRITE setUyruk NOTIFY UyrukChanged)
    Q_PROPERTY(Metin BiletKodu READ BiletKodu WRITE setBiletKodu NOTIFY BiletKoduChanged)
    Q_PROPERTY(QDateTime Rezervasyon READ Rezervasyon WRITE setRezervasyon NOTIFY RezervasyonChanged)
    Q_PROPERTY(Tamsayi YolcuId READ YolcuId WRITE setYolcuId NOTIFY YolcuIdChanged)
    Q_PROPERTY(Tamsayi SeyahatId READ SeyahatId WRITE setSeyahatId NOTIFY SeyahatIdChanged)

    explicit YolcuBilgisi(QObject *parent = nullptr);

    Tamsayi KoltukNo() const;

    const Metin &TelefonNo() const;

    const Metin &Uyruk() const;

    const Metin &BiletKodu() const;

    Tamsayi YolcuId() const;

    Tamsayi SeyahatId() const;

    const QDateTime &Rezervasyon() const;


public slots:
    void setKoltukNo(Tamsayi newKoltukNo);

    void setTelefonNo(const Metin &newTelefonNo);

    void setUyruk(const Metin &newUyruk);

    void setBiletKodu(const Metin &newBiletKodu);

    void setYolcuId(Tamsayi newYolcuId);

    void setSeyahatId(Tamsayi newSeyahatId);

    void setRezervasyon(const QDateTime &newRezervasyon);

signals:
    void KoltukNoChanged(Tamsayi newKoltukNo);

    void TelefonNoChanged(const Metin &newTelefonNo);

    void UyrukChanged(const Metin &newUyruk);

    void BiletKoduChanged(const Metin &newBiletKodu);

    void YolcuIdChanged(Tamsayi newYolcuId);

    void SeyahatIdChanged(Tamsayi newSeyahatId);

    void RezervasyonChanged(const QDateTime &newRezervasyon);

protected:
   Tamsayi   _KoltukNo;
   Metin     _TelefonNo;
   Metin     _Uyruk;
   Metin     _BiletKodu;
   QDateTime _Rezervasyon;
   Tamsayi   _YolcuId;
   Tamsayi   _SeyahatId;

  friend QDataStream &operator<<(QDataStream &stream, const YolcuBilgisi &veri);
  friend QDataStream &operator>>(QDataStream &stream, YolcuBilgisi &veri);

};
QDataStream &operator<<(QDataStream &stream, const YolcuBilgisi &veri);
QDataStream &operator>>(QDataStream &stream, YolcuBilgisi &veri);

#endif // YOLCUBILGISI_H
