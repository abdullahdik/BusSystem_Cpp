#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QDataStream>
#include <veri/VeriDepolari/isletmebilgisideposu.h>
#include <veri/VeriDepolari/otobusbilgisideposu.h>
#include <veri/VeriDepolari/seferbilgisideposu.h>
#include <veri/VeriDepolari/seyahatbilgisideposu.h>
#include <veri/VeriDepolari/soforbilgisideposu.h>
#include <veri/VeriDepolari/yolcubilgisideposu.h>

class Data : public QObject
{
    Q_OBJECT
public:
    IsletmeBilgisiDeposu &isletmebilgisi() { return _isletmebilgisi ; }
    OtobusBilgisiDeposu &otobusbilgisi() { return _otobusbilgisi ; }
    SeferBilgisiDeposu &seferbilgisi() { return _seferbilgisi ; }
    SeyahatBilgisiDeposu &seyahatbilgisi() { return _seyahatbilgisi ; }
    SoforBilgisiDeposu &soforbilgisi() { return _soforbilgisi ; }
    YolcuBilgisiDeposu &yolcubilgisi() { return _yolcubilgisi ; }

    void kaydet();
    void yukle();
    ~Data();


    static Data &os() {
        static Data kg;
        return kg;
    }


signals:
private:
    explicit Data(QObject *parent = nullptr);
    IsletmeBilgisiDeposu _isletmebilgisi;
    OtobusBilgisiDeposu _otobusbilgisi;
    SeferBilgisiDeposu _seferbilgisi;
    SeyahatBilgisiDeposu _seyahatbilgisi;
    SoforBilgisiDeposu _soforbilgisi;
    YolcuBilgisiDeposu _yolcubilgisi;

    QString dosyaYolu();

   friend QDataStream &operator<<(QDataStream &stream, const Data &veri);
   friend QDataStream &operator>>(QDataStream &stream, Data &veri);

};

QDataStream &operator<<(QDataStream &stream, const Data &veri);
QDataStream &operator>>(QDataStream &stream, Data &veri);

#endif // DATA_H
