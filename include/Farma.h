#ifndef FARMA_FARMA_H
#define FARMA_FARMA_H

#include "Swinka.h"
#include "Piesek.h"
#include "Zwierze.h"
#include "Wilk.h"
#include <vector>
#include <optional>

using namespace std;

class Farma
{
public:
    Farma();

    ~Farma();

    void sprzedajSwinie(unsigned int ile);

    void rozmnazajSwinie();

    void kupSwinie(unsigned int ile);

    void kupKarme(unsigned int k);

    unsigned int ileSwinekPozaFarma();

    void kupPsa();

    void ulepszPsa();

    int dajAtakPsa();

    int dajGlodAzora();

    void wywolajWilkaZLasu();

    void wyswietlStanGry();

    unsigned int policzPunkty();

    bool odejmijKarme(unsigned int ile);

    void dodajKieszonkoweOdMamy();

private:
    vector<Swinka> tablicaSwin;
    std::optional<Piesek> piesObronny;
    Wilk wilczek;
    unsigned int karma;
    unsigned int pieniadz;
    unsigned int pojemnoscFarmy;
};

#endif //FARMA_FARMA_H
