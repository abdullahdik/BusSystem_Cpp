#ifndef OTOBUSBILGISILISTEFORMU_H
#define OTOBUSBILGISILISTEFORMU_H

#include <QWidget>
#include <veri/tanimlar.h>
#include <veri/VeriDepolari/otobusbilgisideposu.h>

namespace Ui {
class OtobusBilgisiListeFormu;
}

class OtobusBilgisiFiltrelemeFonksiyonu {
public:
    typedef enum{


    FiltreIleBaslayan = 1,
    FiltreIleBiten = 2,
    FiltreIceren = 4,
    } FiltrelemeTuru;


    const QString &alanAdi() const;
    void setAlanAdi(const QString &newAlanAdi);

    FiltrelemeTuru filtre() const;
    void setFiltre(FiltrelemeTuru newFiltre);

    const QString &arananDeger() const;
    void setArananDeger(const QString &newArananDeger);

    bool operator()(OtobusBilgisiptr data);


private:
    QString _alanAdi;
    FiltrelemeTuru _filtre;
    QString _arananDeger;

};

class OtobusBilgisiListeFormu : public QWidget
{
    Q_OBJECT

public:
    explicit OtobusBilgisiListeFormu(OtobusBilgisiDeposu &depo,QWidget *parent = nullptr);
    ~OtobusBilgisiListeFormu();

    const OtobusBilgisiListesi &liste() const;
    void setListe(const OtobusBilgisiListesi &newListe);

private slots:
    void on_pbArama_clicked();

private:
    Ui::OtobusBilgisiListeFormu *ui;
    OtobusBilgisiListesi _liste;
    OtobusBilgisiDeposu &_depo;

    void ekranGuncelle();

};

#endif // OTOBUSBILGISILISTEFORMU_H
