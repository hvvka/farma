#ifndef FARMA_GRACZ_H
#define FARMA_GRACZ_H

#include <string>
#include "Farma.h"

class Gracz
{
public:
    Gracz();

    void ustawImie();

    bool nowaTura();

    void handluj();

    bool koniec();

private:
    int licznikTur;
    std::string imie;
    bool czyKoniec;
    Farma farma;
};

#endif // FARMA_GRACZ_H
