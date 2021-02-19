#include "Gracz.h"
#include <iostream>

using namespace std;

Gracz::Gracz() : licznikTur(0), imie("bezimienny"), czyKoniec(false)
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
  char odp;
  int wybor = 0;
  bool koncz = true;
  while (koncz)
  {
    !farma.dajAtakPsa() ?
    cout
            << "\nCo chcesz zrobić?\n1. Kupic swinki ($10).\n2. Kupic pieska ($2).\n3. Sprzedac swinki.\n4. Kupic karme ($0.25).\n5. Zakonczyc ture.\n"
                        : cout
            << "\nCo chcesz zrobić?\n1. Kupic swinki ($10).\n2. Ulepszyc pieska.\n3. Sprzedac swinki.\n4. Kupic karme ($0.25).\n5. Zakonczyc ture.\n";

    while (!(cin >> wybor))
    {
      cout << "Podano nieprawidlowa opcje. Wybierz ponownie: ";
      cin.clear();
    }

    switch (wybor)
    {
      case 1:
        cout << ">> Ile chcesz kupic swinek? (koszt jednej to $10) ";
        int ile;
        while (!(cin >> ile))
        {
          cout << "Podano nieprawidlowe dane. Wprowadz ile chcesz kupic karmy ponownie: ";
          cin.clear();
        }
        farma.kupSwinie(ile);
        farma.wyswietlStanGry();
        break;

      case 2:
        if (!farma.dajAtakPsa())
        {
          farma.kupPsa();
          farma.wyswietlStanGry();
        } else
        {
          cout << ">> Czy chcesz wyslac Azora na trening? [t/n] ";
          odp = '\0';
          while (!(cin >> odp))
          {
            cout << "Podano nieprawidlowa opcje. Wprowadz dane jeszcze raz: ";
            cin.clear();
          }

          if (odp == 't')
          {
            farma.ulepszPsa();
          }

          farma.wyswietlStanGry();
        }
        break;

      case 3:
        cout << ">> Ile chcesz sprzedac swinek? ";
        int ileSprzedac;
        cin >> ileSprzedac;
        while (!(cin >> ileSprzedac))
        {
          cout << "Podano nieprawidlowa opcje. Wprowadz dane jeszcze raz: ";
          cin.clear();
        }
        farma.sprzedajSwinie(ileSprzedac);
        farma.wyswietlStanGry();
        break;

      case 4:
        cout << ">> Ile chcesz kupic karmy? (4 porcje kosztuja $1) ";
        int ileKupic;
        while (!(cin >> ileKupic))
        {
          cout << "Podano nieprawidlowe dane. Wprowadz ile chcesz kupic karmy ponownie: ";
          cin.clear();
        }
        farma.kupKarme(ileKupic);
        farma.wyswietlStanGry();
        break;

      case 5:
        koncz = false;
        break;

      default:
        cout << "Podano nieprawidlowa opcje.\n";
        break;
    }
  }

}

bool Gracz::nowaTura()
{
  bool czyKoniec = false;
  char odp = '\0';
  cout << "\n>> Czy koniec tury? [t/n] ";
  while (!(cin >> odp))
  {
    cout << "Podano nieprawidlowe dane. Wprowadz odpowiedz ponownie: ";
    cin.clear();
  }

  if (odp == 't')
  {
    czyKoniec = true;
    licznikTur++;
    if (licznikTur == 5) // koniec calej gry
    {
      farma.wyswietlStanGry();
      Gracz::czyKoniec = true;
      cout << "\nKoniec gry.\nWygrales/as!\n" << "Zagrano " << licznikTur + 1 << " tur.\n";
      farma.wyswietlStanGry();
      cout << endl << imie << " z wynikiem " << farma.policzPunkty() << " punktow.\n";

    } else                //kolejna tura
    {
      farma.rozmnazajSwinie();
      farma.wywolajWilkaZLasu();
      farma.dodajKieszonkoweOdMamy();
      unsigned int szynkiPozaFarma = farma.ileSwinekPozaFarma();
      //odejmowanie karmy
      if (szynkiPozaFarma >= 0) // >=, bo moze byc jeszcze piesek poza farma
      {
        if (farma.odejmijKarme(szynkiPozaFarma * Swinka::GLOD + farma.dajGlodAzora()))
        {
          farma.wyswietlStanGry();
          Gracz::czyKoniec = true;
          cout << "\nKoniec gry.\nPorazka!\n" << "Zagrano " << licznikTur + 1 << " tur.\n";
          cout << endl << imie << " z wynikiem " << farma.policzPunkty() << " punktow.\n";
        }
      }
    }
  }

  return czyKoniec;
}
