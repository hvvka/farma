#include "Wilk.h"
#include <ctime>
#include <cstdlib>

Wilk::Wilk() : silaAtaku(0)
{}

bool Wilk::atakuj()
{
  srand((unsigned) time(nullptr));
  silaAtaku = rand() % 8 + 1;
  return rand() % 2;
}

int Wilk::dajAtak() const
{
  return silaAtaku;
}

Wilk::~Wilk()
{
  silaAtaku = 0;
}
