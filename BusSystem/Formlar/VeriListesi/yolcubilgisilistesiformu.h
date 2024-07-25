#ifndef YOLCUBILGISILISTESIFORMU_H
#define YOLCUBILGISILISTESIFORMU_H

#include <QWidget>
#include <veri/data.h>

namespace Ui {
class YolcuBilgisiListesiFormu;
}

class YolcuBilgisiListesiFormu : public QWidget
{
    Q_OBJECT

public:
    explicit YolcuBilgisiListesiFormu(QWidget *parent = nullptr);
    ~YolcuBilgisiListesiFormu();

    const YolcuBilgisiListesi &liste() const;

public slots:

    void setListe(const YolcuBilgisiListesi &newListe);

private:
    Ui::YolcuBilgisiListesiFormu *ui;
    YolcuBilgisiListesi _liste;

    void ekranGuncelle();
};

#endif // YOLCUBILGISILISTESIFORMU_H
