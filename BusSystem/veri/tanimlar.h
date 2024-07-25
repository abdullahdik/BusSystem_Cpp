#ifndef TANIMLAR_H
#define TANIMLAR_H



#include <QString>
#include <QDateTime>
#include <memory>
#include <QList>

typedef QString Metin;
typedef int Tamsayi;
typedef enum { Kadin = 1, Erkek = 2} Cinsiyet;
typedef QDate Tarh;
typedef QTime Saat;
typedef QDateTime TarhSaat;

class IsletmeBilgisi;
class OtobusBilgisi;
class SeferBilgisi;
class YolcuBilgisi;
class SeyahatBilgisi;
class SoforBilgisi;
class InsanBilgisi;

typedef std::shared_ptr <IsletmeBilgisi> IsletmeBilgisiptr;
typedef std::shared_ptr <OtobusBilgisi> OtobusBilgisiptr;
typedef std::shared_ptr <SeferBilgisi> SeferBilgisiptr;
typedef std::shared_ptr <YolcuBilgisi> YolcuBilgisiptr;
typedef std::shared_ptr <SeyahatBilgisi> SeyahatBilgisiptr;
typedef std::shared_ptr <SoforBilgisi> SoforBilgisiptr;
typedef std::shared_ptr <InsanBilgisi> InsanBilgisiptr;

typedef QList<IsletmeBilgisiptr> IsletmeBilgisiListesi;
typedef QList<OtobusBilgisiptr> OtobusBilgisiListesi;
typedef QList<SeferBilgisiptr> SeferBilgisiListesi;
typedef QList<YolcuBilgisiptr> YolcuBilgisiListesi;
typedef QList<SeyahatBilgisiptr> SeyahatBilgisiListesi;
typedef QList<SoforBilgisiptr> SoforBilgisiListesi;
typedef QList<InsanBilgisiptr> InsanBilgisiListsi;


class IsletmeBilgisiDeposu;
class OtobusBilgisiDeposu;
class SeferBilgisiDeposu;
class YolcuBilgisiDeposu;
class SeyahatBilgisiDeposu;
class SoforBilgisiDeposu;
class InsanBilgisiDeposu;

#endif // TANIMLAR_H
