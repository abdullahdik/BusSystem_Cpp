#ifndef OTOBUSBILGISIVERIGIRISFORMU_H
#define OTOBUSBILGISIVERIGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include <veri/VeriSiniflari/otobusbilgisi.h>

namespace Ui {
class OtobusBilgisiVeriGirisFormu;
}

class OtobusBilgisiVeriGirisFormu : public QWidget, public TemelVeriGirisi<OtobusBilgisiptr>
{
    Q_OBJECT

public:
    explicit OtobusBilgisiVeriGirisFormu(QWidget *parent = nullptr);
    ~OtobusBilgisiVeriGirisFormu();

private:
    Ui::OtobusBilgisiVeriGirisFormu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();
};

#endif // OTOBUSBILGISIVERIGIRISFORMU_H
