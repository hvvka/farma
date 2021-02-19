#include "Piesek.h"

Piesek::Piesek() : Zwierze(2, 2), silaAtaku(4), lvl(1)
{}

Piesek::~Piesek()
{
  silaAtaku = 0;
  glod = 0;
  wartosc = 0;
  lvl = 0;
}

void Piesek::trenuj()
{
  wartosc += 2;
  silaAtaku++;
  lvl++;
}

int Piesek::dajLvl() const
{
  return lvl;
}

int Piesek::dajAtak() const
{
  return silaAtaku;
}