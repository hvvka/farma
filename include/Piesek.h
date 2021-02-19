#ifndef FARMA_PIESEK_H
#define FARMA_PIESEK_H

#include "Zwierze.h"

class Piesek : public Zwierze
{
public:
    Piesek();

    void trenuj();

    unsigned int dajLvl() const;

    unsigned int dajAtak() const;

private:
    unsigned int silaAtaku{4};
    unsigned int lvl{1};
};

#endif // FARMA_PIESEK_H
