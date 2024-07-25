#include "isletmebilgisilisteformu.h"
#include "ui_isletmebilgisilisteformu.h"
#include <QStringList>
#include <QTableWidgetItem>
#include <veri/VeriSiniflari/isletmebilgisi.h>
#include <veri/VeriDepolari/isletmebilgisideposu.h>
#include <islemler/islemdeposu.h>
#include <islemler/VeriSilme/isletmebilgisisilmeislemi.h>
#include <islemler/VeriGuncelle/isletmebilgisiguncellemeislemi.h>
#include <islemler/islemdeposu.h>

IsletmeBilgisiListeFormu::IsletmeBilgisiListeFormu(IsletmeBilgisiDeposu &depo ,QWidget *parent) :
    QWidget(parent), ui(new Ui::IsletmeBilgisiListeFormu), _depo(depo)
{
    ui->setupUi(this);

    auto islem1 = IslemDeposu::os().getIslem(IslemDeposu::IslemIsletmeBilgisiGuncelleme);
    auto islem2 = std::dynamic_pointer_cast<IsletmeBilgisiGuncellemeIslemi>(islem1);
    connect(islem2.get(), &IsletmeBilgisiGuncellemeIslemi::islemTamamlandi, ui->pbArama, &QPushButton::click);

}

IsletmeBilgisiListeFormu::~IsletmeBilgisiListeFormu()
{
    delete ui;
}

const IsletmeBilgisiListesi &IsletmeBilgisiListeFormu::liste() const
{
    return _liste;
}

void IsletmeBilgisiListeFormu::setListe(const IsletmeBilgisiListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void IsletmeBilgisiListeFormu::ekranGuncelle()
{
    ui->tblIsletmeBilgisiListesi->clear();
    ui->tblIsletmeBilgisiListesi->setColumnCount(6);
    QStringList Basliklar;
    Basliklar << tr("İşletme Adı") << tr("Vergi No") << tr("Konum") << tr("Sicil No") << tr("Güncelle") << tr("Veri Sil") ;

    ui->tblIsletmeBilgisiListesi->setHorizontalHeaderLabels(Basliklar);
    ui->tblIsletmeBilgisiListesi->setRowCount(_liste.size());
    for (int i = 0; i < _liste.size(); i++) {
        const auto &nesne_i = _liste[i];
        QTableWidgetItem *hucre = new QTableWidgetItem;        
        hucre->setText(nesne_i->IsletmeAdi());
        ui->tblIsletmeBilgisiListesi->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->VergiNo());        
        ui->tblIsletmeBilgisiListesi->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Konum());
        ui->tblIsletmeBilgisiListesi->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(tr("%1").arg(nesne_i->SicilNo()));
        ui->tblIsletmeBilgisiListesi->setItem(i, 3, hucre);

        auto gui= ui;
        auto guncellemeButonu = new QPushButton();
        guncellemeButonu->setText("Güncelle");
        connect(guncellemeButonu, &QPushButton::clicked,[nesne_i, gui](){
            auto islem1 = IslemDeposu::os().getIslem(IslemDeposu::IslemIsletmeBilgisiGuncelleme);
            auto islem2 = std::dynamic_pointer_cast<IsletmeBilgisiGuncellemeIslemi>(islem1);
            islem2->setVeri(nesne_i);
            islem2->main();

        });
        ui->tblIsletmeBilgisiListesi->setCellWidget(i, 4, guncellemeButonu);
       auto silmeButonu = new  QPushButton();
        silmeButonu->setText("Sil");
        /*connect(silmeButonu, &QPushButton::clicked, IslemDeposu::os().getAction(IslemIsletmeBilgisiSilme),
                &QAction::trigger);*/


        connect(silmeButonu, &QPushButton::clicked,[nesne_i, gui](){
          auto islem1 =  IslemDeposu::os().getIslem(IslemDeposu::IslemIsletmeBilgisiSilme);
          auto islem2 = std::dynamic_pointer_cast<IsletmeBilgisiSilmeIslemi>(islem1);
          islem2->setVeri(nesne_i);
          islem2->main();
          gui->pbArama->click();
        });

        ui->tblIsletmeBilgisiListesi->setCellWidget(i, 5, silmeButonu);
    }
}

const QString &IsletmeBilgisiFiltrelemeFonksiyonu::alanAdi() const {

    return _alanAdi;
}

void IsletmeBilgisiFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}

IsletmeBilgisiFiltrelemeFonksiyonu::FiltrelemeTuru
IsletmeBilgisiFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void IsletmeBilgisiFiltrelemeFonksiyonu::setFiltre(FiltrelemeTuru newFiltre)
{
    _filtre = newFiltre;
}

const QString &IsletmeBilgisiFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void IsletmeBilgisiFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}

bool IsletmeBilgisiFiltrelemeFonksiyonu::operator()(IsletmeBilgisiptr data)

{


    if (_alanAdi == "Tumu"){

    }
    QString deger;

    if (_alanAdi == "IsletmeAdi") {
     deger = data->IsletmeAdi();

    }

    if (_alanAdi == "SicilNo" ) {
     deger = QString::number(data->SicilNo());

    }

    if (_alanAdi == "VergiNo") {
     deger = data->VergiNo();
    }

    if (_alanAdi == "Konum") {
    deger = data->Konum();
    }


    if (_filtre == FiltreIleBaslayan) {
        auto sonuc = deger.toLower().startsWith(_arananDeger.toLower());
        return sonuc;
    }

    if (_filtre == FiltreIleBiten) {
        auto sonuc = deger.toLower().endsWith(_arananDeger.toLower());
        return sonuc;
    }

    if (_filtre == FiltreIceren) {
        auto sonuc = deger.toLower().contains(_arananDeger.toLower());
        return sonuc;
    }
    return false;
}

void IsletmeBilgisiListeFormu::on_pbArama_clicked()
{
    IsletmeBilgisiFiltrelemeFonksiyonu f;

    if(ui->rbIsletmeAdi->isChecked()) {
        f.setAlanAdi("IsletmeAdi");
    }
    if(ui->rbSicilNo->isChecked()){
        f.setAlanAdi("SicilNo");
    }
    if(ui->rbVergiNo->isChecked()){
        f.setAlanAdi("VergiNo");
    }
    if(ui->rbKonum->isChecked()){
        f.setAlanAdi("Konum");
    }

    if (ui->rbIceren->isChecked()){
        f.setFiltre(IsletmeBilgisiFiltrelemeFonksiyonu::FiltreIceren);
    }
    if(ui->rbIleBaslayan->isChecked()){
        f.setFiltre(IsletmeBilgisiFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }
    if(ui->rbIleBiten->isChecked()){
        f.setFiltre(IsletmeBilgisiFiltrelemeFonksiyonu::FiltreIleBiten);
    }

    f.setArananDeger(ui->leArama->text());

    auto liste = _depo.tumunuBul(f);
    setListe(liste);


}


