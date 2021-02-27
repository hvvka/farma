#include "Gracz.h"
#include <iostream>
#include <Wiadomosci.h>

using namespace std;

Gracz::Gracz() : licznikTur(0), imie("bezimienny")
{
  cout << "Witaj w grze Farma!\n";
}

void Gracz::ustawImie()
{
  cout << ">> Podaj imie: ";
  cin >> imie;
}

void Gracz::handluj()
{
  cout << "\n***TURA " << licznikTur + 1 << "***" << endl;
  farma.wyswietlStanGry();
  bool czyZakonczonoTure = true;
  while (czyZakonczonoTure)
  {
    if (!farma.czyJestPies())
    {
      cout
              << "Co chcesz zrobić?\n1. Kupic swinki ($10).\n2. Kupic pieska ($2).\n3. Sprzedac swinki.\n4. Kupic karme ($1).\n5. Zakonczyc ture.\n";
    } else
    {
      cout
              << "Co chcesz zrobić?\n1. Kupic swinki ($10).\n2. Ulepszyc pieska.\n3. Sprzedac swinki.\n4. Kupic karme ($1).\n5. Zakonczyc ture.\n";
    }

    int wybor = Wiadomosci::pobierzLiczbeOdUzytkownika();
    switch (wybor)
    {
      case 1:
      {
        cout << ">> Ile chcesz kupic swinek? ";
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
          cout << ">> Czy chcesz wyslac Azora na trening? [t/n] ";
          char czyTreningAzora;
          cin >> czyTreningAzora;
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
        cout << ">> Ile chcesz sprzedac swinek? ";
        int liczbaSwinekNaSprzedaz = Wiadomosci::pobierzLiczbeOdUzytkownika();
        farma.sprzedajSwinie(liczbaSwinekNaSprzedaz);
        farma.wyswietlStanGry();
        break;
      }

      case 4:
      {
        cout << ">> Ile chcesz kupic karmy? ";
        int liczbaKarmyDoZakupu = Wiadomosci::pobierzLiczbeOdUzytkownika();
        farma.kupKarme(liczbaKarmyDoZakupu, 1);
        farma.wyswietlStanGry();
        break;
      }

      case 5:
      {
        czyZakonczonoTure = false;
        break;
      }

      default:
      {
        cout << "Podano nieprawidlowa opcje." << endl;
        break;
      }
    }
  }
}

bool Gracz::nowaTura()
{
  cout << ">> Czy koniec tury? [t/n] ";
  char odp;
  cin >> odp;
  if (odp != 't')
  {
    return false;
  }
  licznikTur++;
  if (licznikTur == LICZBA_TUR) // czyKoniec calej gry
  {
    farma.wyswietlStanGry();
    Gracz::koniec = true;
    cout << "\nKoniec gry.\nWygrana!\n" << "Zagrano " << licznikTur << " tur." << endl;
    cout << endl << imie << " z wynikiem " << farma.policzPunkty() << " punktow." << endl;
  } else                // kolejna tura
  {
    farma.rozmnazajSwinie();
    farma.wywolajWilkaZLasu();
    farma.dodajKieszonkoweOdMamy();
    unsigned int szynkiPozaFarma = farma.ileSwinekPozaFarma();
    // odejmowanie karmy
    if (szynkiPozaFarma >= 0) // >=, bo moze byc jeszcze piesek poza farma
    {
      if (farma.nakarmZwierzeta(szynkiPozaFarma * Swinka::GLOD + farma.dajGlodAzora()))
      {
        farma.wyswietlStanGry();
        Gracz::koniec = true;
        cout << endl << "Koniec gry." << endl << "Porazka!" << endl << "Zagrano " << licznikTur << " tur.\n";
        cout << endl << imie << " z wynikiem " << farma.policzPunkty() << " punktow.\n";
      }
    }
  }
  return true;
}

bool Gracz::czyKoniec() const
{
  return koniec;
}
