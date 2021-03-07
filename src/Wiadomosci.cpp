#include <iostream>
#include <sstream>
#include <Swinka.h>
#include <Piesek.h>
#include <Farma.h>
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

std::string Wiadomosci::wybierzAkcje(bool czyJestPies, unsigned int cenaTreninguAzora)
{
  std::stringstream menuAkcji;
  menuAkcji << "Co chcesz zrobić?" << std::endl;
  menuAkcji << "1. Kupic swinki (-$" << Swinka::KOSZT << ")." << std::endl;
  if (!czyJestPies)
  {
    menuAkcji << "2. Kupic pieska (-$" << Piesek::CENA_KUPNA << ")." << std::endl;
  } else
  {
    menuAkcji << "2. Ulepszyc pieska (-$" << cenaTreninguAzora << ")." << std::endl;
  }
  menuAkcji << "3. Sprzedac swinki (+$" << Swinka::KOSZT << ")." << std::endl;
  menuAkcji << "4. Kupic karme (-$" << Farma::KOSZT_KARMY << ")." << std::endl;
  menuAkcji << "5. Zakonczyc ture." << std::endl;
  return menuAkcji.str();
}
