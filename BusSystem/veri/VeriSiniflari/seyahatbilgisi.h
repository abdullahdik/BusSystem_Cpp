#ifndef SEYAHATBILGISI_H
#define SEYAHATBILGISI_H

#include "temelverisinifi.h"

class SeyahatBilgisi : public TemelVeriSinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Tamsayi PeronNo READ PeronNo WRITE setPeronNo NOTIFY PeronNoChanged)
    Q_PROPERTY(TarhSaat TarihSaat READ TarihSaat WRITE setTarihSaat NOTIFY TarihSaatChanged)
    Q_PROPERTY(Metin Ikram READ Ikram WRITE setIkram NOTIFY IkramChanged)
    Q_PROPERTY(Metin Tesis READ Tesis WRITE setTesis NOTIFY TesisChanged)
    Q_PROPERTY(Tamsayi SeyahatId READ SeyahatId WRITE setSeyahatId NOTIFY SeyahatIdChanged)
    Q_PROPERTY(Tamsayi SoforId READ SoforId WRITE setSoforId NOTIFY SoforIdChanged)
    Q_PROPERTY(Tamsayi IsletmeId READ IsletmeId WRITE setIsletmeId NOTIFY IsletmeIdChanged)
    Q_PROPERTY(Tamsayi SeferId READ SeferId WRITE setSeferId NOTIFY SeferIdChanged)

    explicit SeyahatBilgisi(QObject *parent = nullptr);

    Tamsayi PeronNo() const;

    const TarhSaat &TarihSaat() const;

    const Metin &Ikram() const;

    const Metin &Tesis() const;

    Tamsayi SeyahatId() const;

    Tamsayi SoforId() const;

    Tamsayi IsletmeId() const;

    Tamsayi SeferId() const;

public slots:
    void setPeronNo(Tamsayi newPeronNo);

    void setTarihSaat(const TarhSaat &newTarihSaat);

    void setIkram(const Metin &newIkram);

    void setTesis(const Metin &newTesis);

    void setSeyahatId(Tamsayi newSeyahatId);

    void setSoforId(Tamsayi newSoforId);

    void setIsletmeId(Tamsayi newIsletmeId);

    void setSeferId(Tamsayi newSeferId);

signals:
    void PeronNoChanged(Tamsayi newPeronNo);

    void TarihSaatChanged(const TarhSaat &newTarihSaat);

    void IkramChanged(const Metin &newIkram);

    void TesisChanged(const Metin &newTesis);

    void SeyahatIdChanged(Tamsayi newSeyahatId);

    void SoforIdChanged(Tamsayi newSoforId);

    void IsletmeIdChanged(Tamsayi newIsletmeId);

    void SeferIdChanged(Tamsayi newSeferId);

private:
    Tamsayi   _PeronNo;
    TarhSaat _TarihSaat;
    Metin     _Ikram;
    Metin     _Tesis;
    Tamsayi   _SeyahatId;
    Tamsayi   _SoforId;
    Tamsayi   _IsletmeId;
    Tamsayi   _SeferId;

friend QDataStream &operator<<(QDataStream &stream, const SeyahatBilgisi &veri);
friend QDataStream &operator>>(QDataStream &stream, SeyahatBilgisi &veri);

};
QDataStream &operator<<(QDataStream &stream, const SeyahatBilgisi &veri);
QDataStream &operator>>(QDataStream &stream, SeyahatBilgisi &veri);

#endif // SEYAHATBILGISI_H
