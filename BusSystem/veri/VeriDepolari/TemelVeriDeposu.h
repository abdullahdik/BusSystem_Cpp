#ifndef TEMELVERIDEPOSU_H
#define TEMELVERIDEPOSU_H

#include <veri/tanimlar.h>
#include <functional>

template <class XYZ > class TemelVeriDeposu {
public:
    typedef std::shared_ptr<XYZ> DataPtr;
    typedef QList<DataPtr> DataList;

    typedef std::function<bool(DataPtr)> FiltreFonksiyonu;

    TemelVeriDeposu() : _veriler{}, _sonId{0} {}

    DataPtr YeniNesne() { return std::make_shared<XYZ>(); }

    bool nesneEkle(DataPtr veri ) {
        for (const auto &kayitliVeri : _veriler) {
            if (veri->id() == kayitliVeri->id()) {
               return false;
            }
        }
        _sonId++;
        veri->setId(_sonId);
        veri->setSilindiMi(false);
        _veriler.append(veri);
        return true;
    }

    bool nesneSil(DataPtr silinecekVeri) {
        for (const auto &kayitliVeri : _veriler) {
            if (silinecekVeri->id() == kayitliVeri->id()) {
               kayitliVeri->setSilindiMi(true);
                return true;
            }
        };
        return false;
    }

    DataPtr ilkiniBul(FiltreFonksiyonu f) {
      for (auto i = _veriler.begin(); i != _veriler.end(); i++) {
          auto veri = *i;
          if (veri->silindiMi() == false && f(veri) == true) {
              return veri;
          }
      }
      return DataPtr(nullptr);
    }

    DataPtr sonuncuyuBul(FiltreFonksiyonu f) {
        for (auto i = _veriler.begin(); i != _veriler.rend(); i++) {
            auto veri = *i;
            if (veri->silindiMi() == false && f(veri) == true) {
                return veri;
            }
        }
        return DataPtr(nullptr);
    }

    DataList tumunuBul(FiltreFonksiyonu f) {
        DataList sonuc;
        for (auto i = _veriler.begin(); i != _veriler.end(); i++) {
            auto veri = *i;
            if (veri->silindiMi() == false && f(veri) == true) {
                sonuc.append(veri);
            }
        }
        return sonuc;
    }

protected:
    DataList _veriler;
    Tamsayi _sonId;

};
template <class XYZ >
QDataStream &operator<<(QDataStream &stream, const std::shared_ptr<XYZ> &veri){
    stream << *veri;
    return stream;
}
template <class XYZ >
QDataStream &operator>>(QDataStream &stream, std::shared_ptr<XYZ> &veri){
   veri = std::make_shared<XYZ>();
   stream >> *veri;
   return stream;
}


#endif // TEMELVERIDEPOSU_H
