#include <iostream>
#include "Wiadomosci.h"

std::string Wiadomosci::brakFunduszyNaSwinie(unsigned int liczbaSwin)
{
  if (liczbaSwin == 1)
  {
    return "Nie masz pieniedzy, zeby kupic kolejna " + std::to_string(liczbaSwin) + " swinke.";
  } else if (liczbaSwin <= 4)
  {
    return "Nie masz pieniedzy, zeby kupic kolejne " + std::to_string(liczbaSwin) + " swinki.";
  } else
  {
    return "Nie masz pieniedzy, zeby kupic kolejne " + std::to_string(liczbaSwin) + " swinek.";
  }
}

std::string Wiadomosci::zakupionoSwinie(unsigned int ile)
{
  if (ile == 1)
  {
    return "Zakupiono " + std::to_string(ile) + " swinke.";
  } else if (ile <= 4)
  {
    return "Zakupiono " + std::to_string(ile) + " swinki.";
  } else
  {
    return "Zakupiono " + std::to_string(ile) + " swinek.";
  }
}

int Wiadomosci::pobierzLiczbeOdUzytkownika()
{
  int liczba;
  while (!(std::cin >> liczba))
  {
    std::cout << "Niepoprawna liczba. Wprowadz dane ponownie." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return liczba;
}

