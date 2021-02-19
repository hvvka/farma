#ifndef FARMA_SWINKA_H
#define FARMA_SWINKA_H

#include "Zwierze.h"

class Swinka : public Zwierze
{
public:
    static const int KOSZT = 10;
    static const int GLOD = 4;

    int nakarm();

    Swinka();

    ~Swinka();

protected:
    int czasRozrodu; // w turach
};

#endif // FARMA_SWINKA_H
