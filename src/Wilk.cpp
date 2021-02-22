#include "Wilk.h"
#include <ctime>
#include <cstdlib>

bool Wilk::czyAtakuje()
{
  srand((unsigned) time(nullptr));
  silaAtaku = rand() % 8 + 1;
  return rand() % 2;
}

int Wilk::dajSileAtaku() const
{
  return silaAtaku;
}
