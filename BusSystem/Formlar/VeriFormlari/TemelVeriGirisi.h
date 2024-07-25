#ifndef TEMELVERIGIRISI_H
#define TEMELVERIGIRISI_H

#include <veri/tanimlar.h>

template <class ptr >
class TemelVeriGirisi{
protected:
    ptr _veri;

public:
    ptr veri() {
        veriGuncelle();
        return _veri;
    }

    void setVeri(ptr k) {
        _veri = k;
        ekranGuncelle();
    }

    virtual void ekranGuncelle() = 0;

    virtual void veriGuncelle() = 0;

};


#endif // TEMELVERIGIRISI_H
