#ifndef SEYAHATBILGISILISTEFORMU_H
#define SEYAHATBILGISILISTEFORMU_H

#include <QWidget>
#include <veri/data.h>

namespace Ui {
class SeyahatBilgisiListeFormu;
}

class SeyahatBilgisiFiltrelemeFonksiyonu {
public:
    typedef enum {
        FiltreIleBaslayan = 1,
        FiltreIleBiten = 2,
        FiltreIceren = 4,
    } FiltrelemeTuru;
};

class SeyahatBilgisiListeFormu : public QWidget
{
    Q_OBJECT

public:
    explicit SeyahatBilgisiListeFormu(SeyahatBilgisiDeposu &depo,QWidget *parent = nullptr);
    ~SeyahatBilgisiListeFormu();

    const SeyahatBilgisiListesi &liste() const;

public slots:
    void setListe(const SeyahatBilgisiListesi &newListe);

private:
    Ui::SeyahatBilgisiListeFormu *ui;
    SeyahatBilgisiListesi _liste;
    SeyahatBilgisiDeposu &_depo;

    void ekranGuncelle();
};

#endif // SEYAHATBILGISILISTEFORMU_H
