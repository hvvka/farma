#ifndef FARMA_GRACZ_H
#define FARMA_GRACZ_H

#include <string>
#include "Farma.h"

class Gracz
{
public:
    static const int LICZBA_TUR = 5;

    Gracz();

    void ustawImie();

    bool nowaTura();

    void handluj();

    bool czyKoniec() const;

private:
    int licznikTur;
    std::string imie;
    bool koniec{false};
    Farma farma;
};

#endif // FARMA_GRACZ_H
