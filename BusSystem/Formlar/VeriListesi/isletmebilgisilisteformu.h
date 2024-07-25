#ifndef ISLETMEBILGISILISTEFORMU_H
#define ISLETMEBILGISILISTEFORMU_H

#include <QWidget>
#include <veri/tanimlar.h>

namespace Ui {
class IsletmeBilgisiListeFormu;
}

class IsletmeBilgisiFiltrelemeFonksiyonu {

public:
    typedef enum {
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

    bool operator()(IsletmeBilgisiptr data);
private:
    QString _alanAdi;
    FiltrelemeTuru _filtre;
    QString _arananDeger;


};

class IsletmeBilgisiListeFormu : public QWidget
{
    Q_OBJECT

public:
    explicit IsletmeBilgisiListeFormu(IsletmeBilgisiDeposu &depo, QWidget *parent = nullptr);
    ~IsletmeBilgisiListeFormu();

    const IsletmeBilgisiListesi &liste() const;

    void setListe(const IsletmeBilgisiListesi &newListe);

private slots:

    void on_pbArama_clicked();

private:
    Ui::IsletmeBilgisiListeFormu *ui;
    IsletmeBilgisiListesi _liste;
    IsletmeBilgisiDeposu &_depo; // eğer bu depo include edilmezse satırda depo başına * işaret koyulabilir//
    void ekranGuncelle();
};
#endif // ISLETMEBILGISILISTEFORMU_H
