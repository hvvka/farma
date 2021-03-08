#include "Gracz.h"
#include <iostream>
#include <Wiadomosci.h>

Gracz::Gracz() : licznikTur(0), imie("bezimienny")
{
  std::cout << "Witaj w grze Farma!" << std::endl;
}

void Gracz::ustawImie()
{
  std::cout << ">> Podaj imie: ";
  std::cin >> imie;
}

void Gracz::handluj()
{
  std::cout << std::endl;
  printf("\033[1;96m*** TURA %d ***\033[0m\n", licznikTur + 1);
  farma.wyswietlStanGry();
  bool czyTuraTrwa = true;
  while (czyTuraTrwa)
  {
    std::cout << Wiadomosci::wybierzAkcje(farma.czyJestPies(), farma.obliczKosztTreninguAzora());
    int wybor = Wiadomosci::pobierzLiczbeOdUzytkownika();
    switch (wybor)
    {
      case 1:
      {
        std::cout << ">> Ile chcesz kupic swinek? ";
        int liczbaSwinekDoKupienia = Wiadomosci::pobierzLiczbeOdUzytkownika();
        farma.kupSwinie(liczbaSwinekDoKupienia);
        farma.wyswietlStanGry();
        break;
      }

      case 2:
      {
        if (!farma.czyJestPies())
        {
          farma.kupPsa();
        } else
        {
          farma.ulepszPsa();
        }
        farma.wyswietlStanGry();
        break;
      }

      case 3:
      {
        std::cout << ">> Ile chcesz sprzedac swinek? ";
        int liczbaSwinekNaSprzedaz = Wiadomosci::pobierzLiczbeOdUzytkownika();
        farma.sprzedajSwinie(liczbaSwinekNaSprzedaz);
        farma.wyswietlStanGry();
        break;
      }

      case 4:
      {
        std::cout << ">> Ile chcesz kupic karmy? ";
        int liczbaKarmyDoZakupu = Wiadomosci::pobierzLiczbeOdUzytkownika();
        farma.kupKarme(liczbaKarmyDoZakupu, 1);
        farma.wyswietlStanGry();
        break;
      }

      case 5:
      {
        czyTuraTrwa = false;
        break;
      }

      default:
      {
        std::cout << "Podano nieprawidlowa opcje." << std::endl;
        break;
      }
    }
  }
}

bool Gracz::nowaTura()
{
  std::cout << ">> Czy koniec tury? [t/n] ";
  char odp;
  std::cin >> odp;
  if (odp != 't')
  {
    return false;
  }
  if (++licznikTur == LICZBA_TUR) // czyKoniec calej gry
  {
    farma.wyswietlStanGry();
    Gracz::koniec = true;
    std::cout << "Koniec gry." << std::endl << "Wygrana!" << std::endl << "Zagrano " << licznikTur << " tur."
              << std::endl;
    std::cout << imie << " konczy z wynikiem " << farma.policzPunkty() << " punktow." << std::endl;
    printf("\033[1;95m%s\033[0m\n", Wiadomosci::asciiSwinka().c_str());
  } else // kolejna tura
  {
    farma.rozmnazajSwinie();
    farma.wywolajWilkaZLasu();
    farma.dodajKieszonkoweOdMamy();
    unsigned int szynkiPozaFarma = farma.ileSwinekPozaFarma();
    unsigned int glodZwierzat = szynkiPozaFarma * Swinka::GLOD + farma.dajGlodAzora();
    if (!farma.nakarmZwierzeta(glodZwierzat))
    {
      farma.wyswietlStanGry();
      Gracz::koniec = true;
      std::cout << "Koniec gry." << std::endl << "Porazka!" << std::endl << "Zagrano " << licznikTur << " tur."
                << std::endl;
      std::cout << imie << " z wynikiem " << farma.policzPunkty() << " punktow." << std::endl;
    }
  }
  return true;
}

bool Gracz::czyKoniec() const
{
  return koniec;
}
