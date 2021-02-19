#ifndef FARMA_GRA_H
#define FARMA_GRA_H

#include "Gracz.h"

class Gra final
{
public:
    Gra();

    ~Gra();

    void start();

private:
    bool running;
    Gracz gracz;
};

#endif // FARMA_GRA_H
