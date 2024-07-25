#ifndef SEYAHATBILGISIVERIGIRISFORMU_H
#define SEYAHATBILGISIVERIGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include <veri/VeriSiniflari/seyahatbilgisi.h>

namespace Ui {
class seyahatbilgisiverigirisformu;
}

class SeyahatBilgisiVeriGirisFormu : public QWidget, public TemelVeriGirisi<SeyahatBilgisiptr>
{
    Q_OBJECT

public:
    explicit SeyahatBilgisiVeriGirisFormu(QWidget *parent = nullptr);
    ~SeyahatBilgisiVeriGirisFormu();

private:
    Ui::seyahatbilgisiverigirisformu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();
};

#endif // SEYAHATBILGISIVERIGIRISFORMU_H
