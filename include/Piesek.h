#ifndef FARMA_PIESEK_H
#define FARMA_PIESEK_H

#include "Zwierze.h"

class Piesek : public Zwierze
{
public:
    void trenuj();

    int dajLvl() const;

    int dajAtak() const;

    Piesek();

    ~Piesek();

private:
    int silaAtaku;
    int lvl;
};

#endif // FARMA_PIESEK_H
