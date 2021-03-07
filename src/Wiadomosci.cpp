#include <iostream>
#include <sstream>
#include <Swinka.h>
#include <Piesek.h>
#include <Farma.h>
#include "Wiadomosci.h"

std::string Wiadomosci::brakFunduszyNaSwinie(unsigned int liczbaSwin)
{
  return "Nie masz wystarczajaco pieniedzy, zeby kupic " + std::to_string(liczbaSwin) + " " + odmienSwinie(liczbaSwin);
}

std::string Wiadomosci::zakupionoSwinie(unsigned int ile)
{
  return "Zakupiono " + std::to_string(ile) + " " + odmienSwinie(ile);
}

std::string Wiadomosci::odmienSwinie(unsigned int ile)
{
  if (ile == 1)
  {
    return "swinke.";
  } else if (ile <= 4)
  {
    return "swinki.";
  }
  return "swinek.";
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

std::string Wiadomosci::asciiSwinka()
{
  return "         ___\n"
         "         ',_`\"\"\\        .---,\n"
         "            \\   :-\"\"``/`    |\n"
         "             `;'     //`\\   /\n"
         "             /   __     |   ('.\n"
         "            |_ ./O)\\     \\  `) \\\n"
         "           _/-.    `      `\"`  |`-.\n"
         "       .-=; `                  /   `-.\n"
         "      /o o \\   ,_,           .        '.\n"
         "      L._._;_.-'           .            `'-.\n"
         "        `'-.`             '                 `'-.\n"
         "            `.         '                        `-._\n"
         "              '-._. -'                              '.\n"
         "                 \\                                    `\\\n"
         "                  |                                     \\\n"
         "                  |    |                                 ;   _.\n"
         "                  \\    |           |                     |-.((\n"
         "                   ;.  \\           /    /                |-.`\\)\n"
         "                   | '. ;         /    |                 |(_) )\n"
         "                   |   \\ \\       /`    |                 ;'--'\n"
         "                    \\   '.\\    /`      |                /\n"
         "                     |   /`|  ;        \\               /\n"
         "                     |  |  |  |-._      '.           .'\n"
         "                     /  |  |  |__.`'---\"_;'-.     .-'\n"
         "                    //__/  /  |    .-'``     _.-'`\n"
         "                          //__/   //___.--''`";
}

std::string Wiadomosci::urodzonoSwinie(unsigned int ile)
{
  return "Urodzono " + std::to_string(ile) + " " + odmienSwinie(ile) + "\n";
}
