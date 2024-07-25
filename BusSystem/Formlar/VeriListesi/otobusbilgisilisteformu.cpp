#include "otobusbilgisilisteformu.h"
#include "ui_otobusbilgisilisteformu.h"
#include <QString>
#include <QTableWidgetItem>
#include <veri/VeriSiniflari/otobusbilgisi.h>
#include <veri/VeriDepolari/otobusbilgisideposu.h>

OtobusBilgisiListeFormu::OtobusBilgisiListeFormu(OtobusBilgisiDeposu &depo,QWidget *parent) :
    QWidget(parent), ui(new Ui::OtobusBilgisiListeFormu), _depo(depo)
{
    ui->setupUi(this);
}

OtobusBilgisiListeFormu::~OtobusBilgisiListeFormu()
{
    delete ui;
}

const OtobusBilgisiListesi &OtobusBilgisiListeFormu::liste() const
{
    return _liste;
}

void OtobusBilgisiListeFormu::setListe(const OtobusBilgisiListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void OtobusBilgisiListeFormu::ekranGuncelle()
{
    ui->tblOtobusBilgisiListesi->clear();
    ui->tblOtobusBilgisiListesi->setColumnCount(5);
    QStringList Basliklar;
    Basliklar << tr("Plaka") << tr("Koltuk Sayısı") << tr("Ruhsat") << tr("Renk") << tr("Muayene Tarihi");

    ui->tblOtobusBilgisiListesi->setHorizontalHeaderLabels(Basliklar);
    ui->tblOtobusBilgisiListesi->setRowCount(_liste.size());
    for (int i = 0; i < _liste.size(); i++) {
        const auto &nesne_i = _liste[i];
        QTableWidgetItem *hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Plaka());
        ui->tblOtobusBilgisiListesi->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->KoltukSayisi());
        ui->tblOtobusBilgisiListesi->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Ruhsat());
        ui->tblOtobusBilgisiListesi->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Renk());
        ui->tblOtobusBilgisiListesi->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->MuayeneTarih().toString());
        ui->tblOtobusBilgisiListesi->setItem(i, 4, hucre);

    }

}




const QString &OtobusBilgisiFiltrelemeFonksiyonu::alanAdi() const
{
    return _alanAdi;
}

void OtobusBilgisiFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}

OtobusBilgisiFiltrelemeFonksiyonu::FiltrelemeTuru
OtobusBilgisiFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void OtobusBilgisiFiltrelemeFonksiyonu::setFiltre(FiltrelemeTuru newFiltre)
{
    _filtre = newFiltre;
}

const QString &OtobusBilgisiFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void OtobusBilgisiFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}

bool OtobusBilgisiFiltrelemeFonksiyonu::operator()(OtobusBilgisiptr data)
{



    if (_alanAdi == "Tumu"){

    }
    QString  deger;

    if (_alanAdi == "Plaka"){
        deger = data->Plaka();
    }

    if (_alanAdi == "KoltukSayisi"){
        deger = data->KoltukSayisi();
    }

    if (_alanAdi == "Ruhsat"){
        deger = data->Ruhsat();
    }


    if (_alanAdi == "Renk"){
        deger = data->Renk();
    }

    if (_filtre == FiltreIleBaslayan){
        auto sonuc = deger.toLower().startsWith(_arananDeger.toLower());
        return sonuc;
    }

    if (_filtre == FiltreIleBiten){
        auto sonuc = deger.toLower().endsWith(_arananDeger.toLower());
        return sonuc;
    }

    if (_filtre == FiltreIceren) {
        auto sonuc = deger.toLower().contains(_arananDeger.toLower());
        return sonuc;
    }
   return false;
}



void OtobusBilgisiListeFormu::on_pbArama_clicked()
{
    OtobusBilgisiFiltrelemeFonksiyonu f;

    if(ui->rbKoltukSayisi->isChecked()) {
        f.setAlanAdi("KoltukSayisi");
    }

    if(ui->rbPlaka->isChecked()) {
        f.setAlanAdi("Plaka");
    }

    if(ui->rbRenk->isChecked()) {
        f.setAlanAdi("Renk");
    }

    if(ui->rbRuhsat->isChecked()) {
        f.setAlanAdi("Ruhsat");
    }

    if(ui->rbTumu->isChecked()) {
        f.setAlanAdi(("Tumu"));
    }

    if (ui->rbIceren->isChecked()){
        f.setFiltre(OtobusBilgisiFiltrelemeFonksiyonu::FiltreIceren);
    }
    if(ui->rbIleBaslayan->isChecked()){
        f.setFiltre(OtobusBilgisiFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }
    if(ui->rbIleBiten->isChecked()){
        f.setFiltre(OtobusBilgisiFiltrelemeFonksiyonu::FiltreIleBiten);
    }

    f.setArananDeger(ui->leArama->text());

    auto liste = _depo.tumunuBul(f);
    setListe(liste);
}

