#include "seferbilgisilisteformu.h"
#include "ui_seferbilgisilisteformu.h"
#include <QString>
#include <QTableWidgetItem>
#include <veri/VeriSiniflari/seferbilgisi.h>
#include <veri/VeriDepolari/seferbilgisideposu.h>

SeferBilgisiListeFormu::SeferBilgisiListeFormu(SeferBilgisiDeposu &depo,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeferBilgisiListeFormu), _depo(depo)
{
    ui->setupUi(this);
}

SeferBilgisiListeFormu::~SeferBilgisiListeFormu()
{
    delete ui;
}

const SeferBilgisiListesi &SeferBilgisiListeFormu::liste() const
{
    return _liste;
}

void SeferBilgisiListeFormu::setListe(const SeferBilgisiListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void SeferBilgisiListeFormu::ekranGuncelle()
{
    ui->tblSeferBilgisiListesi->clear();
    ui->tblSeferBilgisiListesi->setColumnCount(6);
    QStringList Basliklar;
    Basliklar << tr("Başlangıç Saati") << tr("Bitiş Saati") << tr("Sefer No") << tr("Hatlar") << tr("Tarife") << tr("Sefer Kodu");

    ui->tblSeferBilgisiListesi->setHorizontalHeaderLabels(Basliklar);
    ui->tblSeferBilgisiListesi->setRowCount(_liste.size());
    for (int i = 0; i < _liste.size(); i++ )  {
        const auto &nesne_i = _liste[i];
        QTableWidgetItem *hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->BaslangicSaati().toString());
        ui->tblSeferBilgisiListesi->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->BitisSaati().toString());
        ui->tblSeferBilgisiListesi->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(tr("%1").arg(nesne_i->SeferNo()));
        ui->tblSeferBilgisiListesi->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Hatlar());
        ui->tblSeferBilgisiListesi->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Tarife());
        ui->tblSeferBilgisiListesi->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->SeferKodu());
        ui->tblSeferBilgisiListesi->setItem(i, 5, hucre);


    }
}

const QString &SeferBilgisiFiltrelemeFonksiyonu::alanAdi() const
{
    return _alanAdi;
}

void SeferBilgisiFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}
SeferBilgisiFiltrelemeFonksiyonu::FiltrelemeTuru
SeferBilgisiFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void SeferBilgisiFiltrelemeFonksiyonu::setFiltre(const FiltrelemeTuru &newFiltre)
{
    _filtre = newFiltre;
}

const QString &SeferBilgisiFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void SeferBilgisiFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}

bool SeferBilgisiFiltrelemeFonksiyonu::operator()(SeferBilgisiptr data)
{


    if(_alanAdi == "Tumu"){

    }
    QString deger;

    if (_alanAdi == "SeferNo") {
         deger = QString::number(data->SeferNo());
    }

    if (_alanAdi == "Hatlar") {
         deger = data->Hatlar();
    }

    if (_alanAdi == "SeferKodu") {
         deger = data->SeferKodu();
    }

    if (_filtre == FiltreIleBaslayan) {
        auto sonuc = deger.toLower().startsWith(_arananDeger.toLower());
        return sonuc;

    }

    if (_filtre == FiltreIleBiten){
        auto sonuc = deger.toLower().endsWith(_arananDeger.toLower());
        return sonuc;
    }

    if (_filtre == FiltreIceren) {
        auto sonuc =deger.toLower().contains(_arananDeger.toLower());
        return sonuc;
    }
    return false;
}


void SeferBilgisiListeFormu::on_pbArama_clicked()
{
    SeferBilgisiFiltrelemeFonksiyonu f;


    if(ui->rbSeferNo->isChecked()){
        f.setAlanAdi("Hatlar");
    }

    if(ui->rbTarife->isChecked()){
        f.setAlanAdi("Tarife");
    }

    if(ui->rbSeferKodu->isChecked()){
        f.setAlanAdi("SeferKodu");
    }


    if (ui->rbIceren->isChecked()){
        f.setFiltre(SeferBilgisiFiltrelemeFonksiyonu::FiltreIceren);
    }
    if(ui->rbIleBaslayan->isChecked()){
        f.setFiltre(SeferBilgisiFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }
    if(ui->rbIleBiten->isChecked()){
        f.setFiltre(SeferBilgisiFiltrelemeFonksiyonu::FiltreIleBiten);
    }

    f.setArananDeger(ui->leArama->text());

    auto liste = _depo.tumunuBul(f);
    setListe(liste);

}

