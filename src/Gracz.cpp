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
  std::cout << "***TURA " << licznikTur + 1 << "***" << std::endl;
  farma.wyswietlStanGry();
  bool czyTuraTrwa = true;
  while (czyTuraTrwa)
  {
    std::cout << "Co chcesz zrobić?" << std::endl;
    std::cout << "1. Kupic swinki (-$" << Swinka::KOSZT << ")." << std::endl;
    if (!farma.czyJestPies())
    {
      std::cout << "2. Kupic pieska (-$" << Piesek::CENA_KUPNA << ")." << std::endl;
    } else
    {
      std::cout << "2. Ulepszyc pieska (-$" << farma.obliczKosztTreninguAzora() << ")." << std::endl;
    }
    std::cout << "3. Sprzedac swinki (+$" << Swinka::KOSZT << ")." << std::endl;
    std::cout << "4. Kupic karme (-$" << Farma::KOSZT_KARMY << ")." << std::endl;
    std::cout << "5. Zakonczyc ture." << std::endl;

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
          std::cout << ">> Czy chcesz wyslac Azora na trening? [t/n] ";
          char czyTreningAzora;
          std::cin >> czyTreningAzora;
          if (czyTreningAzora == 't')
          {
            farma.ulepszPsa();
          }
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
  if (licznikTur++ == LICZBA_TUR) // czyKoniec calej gry
  {
    farma.wyswietlStanGry();
    Gracz::koniec = true;
    std::cout << "Koniec gry." << std::endl << "Wygrana!" << std::endl << "Zagrano " << licznikTur << " tur."
              << std::endl;
    std::cout << imie << " z wynikiem " << farma.policzPunkty() << " punktow." << std::endl;
  } else                // kolejna tura
  {
    farma.rozmnazajSwinie();
    farma.wywolajWilkaZLasu();
    farma.dodajKieszonkoweOdMamy();
    unsigned int szynkiPozaFarma = farma.ileSwinekPozaFarma();
    // odejmowanie karmy
    if (szynkiPozaFarma > 0 || farma.czyJestPies()) // >=, bo moze byc jeszcze piesek poza farma
    {
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
  }
  return true;
}

bool Gracz::czyKoniec() const
{
  return koniec;
}
