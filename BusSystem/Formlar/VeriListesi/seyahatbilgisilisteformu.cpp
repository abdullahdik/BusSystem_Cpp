#include "seyahatbilgisilisteformu.h"
#include "ui_seyahatbilgisilisteformu.h"
#include <QString>
#include <QTableWidgetItem>
#include <veri/VeriSiniflari/seyahatbilgisi.h>

SeyahatBilgisiListeFormu::SeyahatBilgisiListeFormu(SeyahatBilgisiDeposu &depo,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeyahatBilgisiListeFormu), _depo(depo)
{
    ui->setupUi(this);
}

SeyahatBilgisiListeFormu::~SeyahatBilgisiListeFormu()
{
    delete ui;
}

const SeyahatBilgisiListesi &SeyahatBilgisiListeFormu::liste() const
{
    return _liste;
}

void SeyahatBilgisiListeFormu::setListe(const SeyahatBilgisiListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void SeyahatBilgisiListeFormu::ekranGuncelle()
{
     ui->tblSeyahatBlgisiListesi->clear();
     ui->tblSeyahatBlgisiListesi->setColumnCount(4);
     QStringList Basliklar;
     Basliklar << tr("Peron No") << tr("Tarih/Saat") << tr("İkram") << tr("Tesis");

     ui->tblSeyahatBlgisiListesi->setHorizontalHeaderLabels(Basliklar);
     ui->tblSeyahatBlgisiListesi->setRowCount(_liste.size());
     for (int i = 0; i < _liste.size(); i++ ) {
         const auto &nesne_i = _liste[i];
         QTableWidgetItem *hucre = new QTableWidgetItem;
         hucre->setText(tr("%1").arg(nesne_i->PeronNo()));
         ui->tblSeyahatBlgisiListesi->setItem(i, 0, hucre);

         hucre = new QTableWidgetItem;
         hucre->setText(nesne_i->TarihSaat().toString());
         ui->tblSeyahatBlgisiListesi->setItem(i, 1, hucre);

         hucre = new QTableWidgetItem;
         hucre->setText(nesne_i->Ikram());
         ui->tblSeyahatBlgisiListesi->setItem(i, 2, hucre);

         hucre = new QTableWidgetItem;
         hucre->setText(nesne_i->Tesis());
         ui->tblSeyahatBlgisiListesi->setItem(i, 3, hucre);
     }
}


