#include "Wiadomosci.h"

std::string Wiadomosci::brakFunduszyNaSwinie(unsigned int liczbaSwin)
{
  if (liczbaSwin == 1)
  {
    return "Nie masz pieniedzy, zeby kupic kolejna " + std::to_string(liczbaSwin) + " swinke.\n";
  } else if (liczbaSwin <= 4)
  {
    return "Nie masz pieniedzy, zeby kupic kolejne " + std::to_string(liczbaSwin) + " swinki.\n";
  } else
  {
    return "Nie masz pieniedzy, zeby kupic kolejne " + std::to_string(liczbaSwin) + " swinek.\n";
  }
}

std::string Wiadomosci::zakupionoSwinie(unsigned int ile)
{
  if (ile == 1)
  {
    return "Zakupiono " + std::to_string(ile) + " swinke.\n";
  } else if (ile <= 4)
  {
    return "Zakupiono " + std::to_string(ile) + " swinki.\n";
  } else
  {
    return "Zakupiono " + std::to_string(ile) + " swinek.\n";
  }
}
