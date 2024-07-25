#ifndef TUMKULLANICIISLEMLERI_H
#define TUMKULLANICIISLEMLERI_H

#include "TemelKullaniciIslemleri.h"
#include <QList>
#include <QObject>
#include <memory.h>

class TumKullaniciIslemleri : public QObject
{
    Q_OBJECT
public:
   static TumKullaniciIslemleri &os();
   void islemCalistir(int sira_no);

   QAction *islem(int sira_no);

signals:

private:
  explicit TumKullaniciIslemleri(QObject *parent = nullptr);
   QList<std::shared_ptr<TemelKullaniciIslemleri>> _islemler;
};

#endif // TUMKULLANICIISLEMLERI_H
