#include "yolcubilgisilistesiformu.h"
#include "ui_yolcubilgisilistesiformu.h"
#include <QString>
#include <QTableWidgetItem>
#include <veri/VeriSiniflari/yolcubilgisi.h>

YolcuBilgisiListesiFormu::YolcuBilgisiListesiFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YolcuBilgisiListesiFormu)
{
    ui->setupUi(this);
}

YolcuBilgisiListesiFormu::~YolcuBilgisiListesiFormu()
{
    delete ui;
}

const YolcuBilgisiListesi &YolcuBilgisiListesiFormu::liste() const
{
    return _liste;
}

void YolcuBilgisiListesiFormu::setListe(const YolcuBilgisiListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void YolcuBilgisiListesiFormu::ekranGuncelle()
{
    ui->tblYolcuBilgisiListesi->clear();
    ui->tblYolcuBilgisiListesi->setColumnCount(10);
    QStringList Basliklar;
    Basliklar << tr("Adı") << tr("Soyadı") << tr("TCKimlik No") << tr("Telefon no") << tr("Hes Kodu") << tr("Cinsiyet") << tr("Uyruk") << tr("Koltuk No") << tr("Bilet Kodu0") << tr("Rezervasyon");

    ui->tblYolcuBilgisiListesi->setHorizontalHeaderLabels(Basliklar);
    ui->tblYolcuBilgisiListesi->setRowCount(_liste.size());
    for ( int i = 0; i < _liste.size(); i++) {
        const auto &nesne_i = _liste[i];
        QTableWidgetItem *hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Ad());
        ui->tblYolcuBilgisiListesi->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Soyad());
        ui->tblYolcuBilgisiListesi->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->TCKimlikNo());
        ui->tblYolcuBilgisiListesi->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->TelefonNo());
        ui->tblYolcuBilgisiListesi->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->HesKodu());
        ui->tblYolcuBilgisiListesi->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem;
        if(nesne_i->Cinsiyt()==Erkek) {
            hucre->setText("Erkek");
        } else {
            hucre->setText("Kadın");
        }
        ui->tblYolcuBilgisiListesi->setItem(i, 5, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Uyruk());
        ui->tblYolcuBilgisiListesi->setItem(i, 6, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(tr("%1").arg(nesne_i->KoltukNo()));
        ui->tblYolcuBilgisiListesi->setItem(i, 7, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->BiletKodu());
        ui->tblYolcuBilgisiListesi->setItem(i, 8, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Rezervasyon().toString());
        ui->tblYolcuBilgisiListesi->setItem(i, 9, hucre);




    }
}
