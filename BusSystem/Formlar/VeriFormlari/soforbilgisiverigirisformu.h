#ifndef SOFORBILGISIVERIGIRISFORMU_H
#define SOFORBILGISIVERIGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include <veri/VeriSiniflari/soforbilgisi.h>

namespace Ui {
class SoforBilgisiVeriGirisFormu;
}

class SoforBilgisiVeriGirisFormu : public QWidget, public TemelVeriGirisi<SoforBilgisiptr>
{
    Q_OBJECT

public:
    explicit SoforBilgisiVeriGirisFormu(QWidget *parent = nullptr);
    ~SoforBilgisiVeriGirisFormu();

private:
    Ui::SoforBilgisiVeriGirisFormu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();
};

#endif // SOFORBILGISIVERIGIRISFORMU_H
