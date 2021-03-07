#ifndef FARMA_FARMA_H
#define FARMA_FARMA_H

#include "Swinka.h"
#include "Piesek.h"
#include "Zwierze.h"
#include "Wilk.h"
#include <vector>
#include <optional>

class Farma
{
public:
    static const int WYSOKOSC_KIESZONKOWEGO = 10;
    static const int KOSZT_KARMY = 1;

    Farma();

    void sprzedajSwinie(unsigned int ile);

    void rozmnazajSwinie();

    void kupSwinie(unsigned int ile);

    unsigned int kupKarme(unsigned int liczbaZamowionejKarmy, unsigned int kurs);

    unsigned int ileSwinekPozaFarma();

    void wywolajWilkaZLasu();

    void wyswietlStanGry();

    unsigned int policzPunkty();

    bool nakarmZwierzeta(unsigned int liczbaPotrzebnejKarmy);

    void dodajKieszonkoweOdMamy();

    void kupPsa();

    void ulepszPsa();

    unsigned int obliczKosztTreninguAzora();

    unsigned int dajSileAtakuPsa();

    unsigned int dajGlodAzora();

    bool czyJestPies() const;

private:
    std::vector <Swinka> tablicaSwin;
    std::optional <Piesek> piesObronny;
    Wilk wilczek;
    unsigned int karma;
    unsigned int pieniadz;
    unsigned int pojemnoscFarmy;
};

#endif //FARMA_FARMA_H
