#ifndef SOFORBILGISILISTEFORMU_H
#define SOFORBILGISILISTEFORMU_H

#include <QWidget>
#include <veri/data.h>

namespace Ui {
class SoforBilgisiListeFormu;
}

class SoforBilgisiListeFormu : public QWidget
{
    Q_OBJECT

public:
    explicit SoforBilgisiListeFormu(QWidget *parent = nullptr);
    ~SoforBilgisiListeFormu();

    const SoforBilgisiListesi &liste() const;

public slots:

    void setListe(const SoforBilgisiListesi &newListe);

private:
    Ui::SoforBilgisiListeFormu *ui;
    SoforBilgisiListesi _liste;

    void ekranGuncelle();
};

#endif // SOFORBILGISILISTEFORMU_H
