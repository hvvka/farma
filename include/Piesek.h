#ifndef FARMA_PIESEK_H
#define FARMA_PIESEK_H

#include "Zwierze.h"

class Piesek : public Zwierze
{
public:
    static const int CENA_KUPNA = 10;
    static const int MAX_LVL = 6;

    Piesek();

    void trenuj();

    unsigned int dajLvl() const;

    unsigned int dajSileAtaku() const;

    unsigned int dajCeneTreninguAzora() const;

private:
    unsigned int silaAtaku{4};
    unsigned int lvl{1};
};

#endif // FARMA_PIESEK_H
