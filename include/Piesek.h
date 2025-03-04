#ifndef FARMA_PIESEK_H
#define FARMA_PIESEK_H

#include "Zwierze.h"
#include "Wilk.h"

class Piesek : public Zwierze, public Wilk
{
public:
    static const int CENA_KUPNA = 2;
    static const int MAX_LVL = 6;

    Piesek();

    void trenuj();

    unsigned int dajLvl() const;

    unsigned int dajCeneTreninguAzora() const;

private:
    static const int CENA_TRENINGU = 2;
    unsigned int lvl{1};
};

#endif // FARMA_PIESEK_H
