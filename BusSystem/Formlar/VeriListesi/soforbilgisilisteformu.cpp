#include "soforbilgisilisteformu.h"
#include "ui_soforbilgisilisteformu.h"
#include <QString>
#include <QTableWidgetItem>
#include <veri/VeriSiniflari/soforbilgisi.h>

SoforBilgisiListeFormu::SoforBilgisiListeFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SoforBilgisiListeFormu)
{
    ui->setupUi(this);
}

SoforBilgisiListeFormu::~SoforBilgisiListeFormu()
{
    delete ui;
}

const SoforBilgisiListesi &SoforBilgisiListeFormu::liste() const
{
    return _liste;
}

void SoforBilgisiListeFormu::setListe(const SoforBilgisiListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void SoforBilgisiListeFormu::ekranGuncelle()
{
    ui->tblSoforBilgisiListesi->clear();
    ui->tblSoforBilgisiListesi->setColumnCount(7);
    QStringList Basliklar;
    Basliklar << tr("Adı") << tr("Soyadı") << tr("TCKimlik No") << tr("HES Kodu") << tr("Cinsiyet") << tr("Ehliyet Sınıfı") << tr("Tecrübesi");

    ui->tblSoforBilgisiListesi->setHorizontalHeaderLabels(Basliklar);
    ui->tblSoforBilgisiListesi->setRowCount(_liste.size());
    for ( int i = 0; i < _liste.size(); i++) {
        const auto &nesne_i = _liste[i];
        QTableWidgetItem *hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Ad());
        ui->tblSoforBilgisiListesi->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Soyad());
        ui->tblSoforBilgisiListesi->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->TCKimlikNo());
        ui->tblSoforBilgisiListesi->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->HesKodu());
        ui->tblSoforBilgisiListesi->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem;
        if(nesne_i->Cinsiyt()==Erkek) {
            hucre->setText("Erkek");
        } else {
            hucre->setText("Kadın");
        }
        ui->tblSoforBilgisiListesi->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->EhliyetSinifi());
        ui->tblSoforBilgisiListesi->setItem(i, 5, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Tecrubesi());
        ui->tblSoforBilgisiListesi->setItem(i, 6, hucre);


    }
}
