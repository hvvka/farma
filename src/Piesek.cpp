#include "Piesek.h"

Piesek::Piesek() : Zwierze(2, 2)
{}

void Piesek::trenuj()
{
  glod++;
  wartosc += 2;
  silaAtaku++;
  lvl++;
}

unsigned int Piesek::dajLvl() const
{
  return lvl;
}

unsigned int Piesek::dajSileAtaku() const
{
  return silaAtaku;
}

unsigned int Piesek::dajCeneTreninguAzora() const
{
  return wartosc + 2;
}
