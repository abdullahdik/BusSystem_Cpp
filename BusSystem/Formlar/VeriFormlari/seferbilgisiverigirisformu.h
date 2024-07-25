#ifndef SEFERBILGISIVERIGIRISFORMU_H
#define SEFERBILGISIVERIGIRISFORMU_H

#include <QWidget>
#include <veri/VeriSiniflari/seferbilgisi.h>
#include "TemelVeriGirisi.h"

namespace Ui {
class seferbilgisiverigirisformu;
}

class SeferBilgisiVeriGirisFormu : public QWidget, public TemelVeriGirisi<SeferBilgisiptr>
{
    Q_OBJECT

public:
    explicit SeferBilgisiVeriGirisFormu(QWidget *parent = nullptr);
    ~SeferBilgisiVeriGirisFormu();

private:
    Ui::seferbilgisiverigirisformu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();
};

#endif // SEFERBILGISIVERIGIRISFORMU_H
