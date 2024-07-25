#ifndef YOLCUBILGISIVERIGIRISFORMU_H
#define YOLCUBILGISIVERIGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include <veri/VeriSiniflari/yolcubilgisi.h>

namespace Ui {
class yolcubilgisiverigirisformu;
}

class YolcuBilgisiVeriGirisFormu : public QWidget, public TemelVeriGirisi<YolcuBilgisiptr>
{
    Q_OBJECT

public:
    explicit YolcuBilgisiVeriGirisFormu(QWidget *parent = nullptr);
    ~YolcuBilgisiVeriGirisFormu();

private:
    Ui::yolcubilgisiverigirisformu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();
};

#endif // YOLCUBILGISIVERIGIRISFORMU_H
