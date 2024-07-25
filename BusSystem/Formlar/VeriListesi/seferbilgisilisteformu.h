#ifndef SEFERBILGISILISTEFORMU_H
#define SEFERBILGISILISTEFORMU_H

#include <QWidget>
#include <veri/data.h>
#include <veri/VeriDepolari/seferbilgisideposu.h>

namespace Ui {
class SeferBilgisiListeFormu;
}

class SeferBilgisiFiltrelemeFonksiyonu{
public:
    typedef enum {

        FiltreIleBaslayan = 1,
        FiltreIleBiten = 2,
        FiltreIceren = 4,

    }FiltrelemeTuru;

    const QString &alanAdi() const;
    void setAlanAdi(const QString &newAlanAdi);

    FiltrelemeTuru filtre() const;
    void setFiltre(const FiltrelemeTuru &newFiltre);

    const QString &arananDeger() const;
    void setArananDeger(const QString &newArananDeger);

    bool operator()(SeferBilgisiptr data);

private:
    QString _alanAdi;
    FiltrelemeTuru _filtre;
    QString _arananDeger;
};

class SeferBilgisiListeFormu : public QWidget
{
    Q_OBJECT

public:
    explicit SeferBilgisiListeFormu(SeferBilgisiDeposu &depo,QWidget *parent = nullptr);
    ~SeferBilgisiListeFormu();

    const SeferBilgisiListesi &liste() const;
    void setListe(const SeferBilgisiListesi &newListe);


private slots:

    void on_pbArama_clicked();

private:
    Ui::SeferBilgisiListeFormu *ui;
    SeferBilgisiListesi _liste;
    SeferBilgisiDeposu &_depo;

    void ekranGuncelle();

};

#endif // SEFERBILGISILISTEFORMU_H
