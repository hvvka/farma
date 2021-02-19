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

    void sprzedajSwinie(int ile);

    void rozmnazajSwinie();

    void kupSwinie(int ile);

    void kupKarme(int k);

    unsigned int ileSwinekPozaFarma();

    void kupPsa();

    void ulepszPsa();

    int dajAtakPsa();

    int dajGlodAzora();

    int dajGlodSwinek();

    void wywolajWilkaZLasu();

    void wyswietlStanGry();

    unsigned int policzPunkty();

    bool odejmijKarme(int ile);

    void dodajKieszonkoweOdMamy();

private:
    vector<Swinka> tablicaSwin;
    std::optional<Piesek> piesObronny;
    Wilk wilczek;
    int karma;
    int pieniadz;
    int pojemnoscFarmy;
};

#endif //FARMA_FARMA_H
