#ifndef ISLETMEBILGISIVERIGIRISFORMU_H
#define ISLETMEBILGISIVERIGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include <veri/VeriSiniflari/isletmebilgisi.h>

namespace Ui {
class IsletmeBilgisiVeriGirisFormu;
}

class IsletmeSistemiVeriGirisFormu : public QWidget, public TemelVeriGirisi<IsletmeBilgisiptr>
{
    Q_OBJECT

public:
    explicit IsletmeSistemiVeriGirisFormu(QWidget *parent = nullptr);
    ~IsletmeSistemiVeriGirisFormu();

private:
    Ui::IsletmeBilgisiVeriGirisFormu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
    void baslikAta(QString baslik);
signals:
    void veriKaydet();
};

#endif // ISLETMEBILGISIVERIGIRISFORMU_H
