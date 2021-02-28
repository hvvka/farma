#ifndef FARMA_SWINKA_H
#define FARMA_SWINKA_H

#include "Zwierze.h"

class Swinka : public Zwierze
{
public:
    static const int KOSZT = 10;
    static const int GLOD = 1;

    Swinka();

protected:
    int czasRozrodu{2}; // w turach
};

#endif // FARMA_SWINKA_H
