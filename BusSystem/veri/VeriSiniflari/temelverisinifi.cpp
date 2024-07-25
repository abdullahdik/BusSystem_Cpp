#include "temelverisinifi.h"

TemelVeriSinifi::TemelVeriSinifi(QObject *parent)
    : QObject{parent}
{

}

Tamsayi TemelVeriSinifi::id() const
{
    return _id;
}

void TemelVeriSinifi::setId(Tamsayi newId)
{
    if (_id == newId)
        return;
    _id = newId;
    emit idChanged(_id);
}

bool TemelVeriSinifi::silindiMi() const
{
    return _silindiMi;
}

void TemelVeriSinifi::setSilindiMi(bool newSilindiMi)
{
    if (_silindiMi == newSilindiMi)
        return;
    _silindiMi = newSilindiMi;
    emit silindiMiChanged(_silindiMi);
}
