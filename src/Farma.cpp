#include "Farma.h"
#include <Wiadomosci.h>
#include <iostream>

Farma::Farma() : karma(0), pieniadz(30), pojemnoscFarmy(10)
{}

void Farma::sprzedajSwinie(unsigned int ile)
{
  for (unsigned int i = 0; !tablicaSwin.empty() && i < ile; i++)
  {
    tablicaSwin.pop_back();
    pieniadz += Swinka::KOSZT;
    if (tablicaSwin.empty() && ile > i)
    {
      cout << "Podales zbyt duza liczbe. Nie masz juz zadnej Swinki w zagrodzie.\n";
    }
  }
}

void Farma::rozmnazajSwinie()
{
  unsigned int nowyMiot = tablicaSwin.size() / 2;
  for (unsigned int i = 0; i < nowyMiot; i++)
  {
    Swinka s;
    tablicaSwin.push_back(s);
  }

  if (nowyMiot == 1)
  {
    cout << "\nUrodzila sie " << nowyMiot << " swinka.";
  } else if (nowyMiot < 5 && nowyMiot != 0)
  {
    cout << "\nUrodzily sie " << nowyMiot << " swinki.";
  } else
  {
    cout << "\nUrodzilo sie " << nowyMiot << " swinek.";
  }
}

void Farma::kupSwinie(unsigned int ile)
{
  unsigned int mozliwosciNabywcze;
  unsigned int roznicaZamowienia = 0;
  if (ile * Swinka::KOSZT > pieniadz)
  {
    mozliwosciNabywcze = pieniadz / Swinka::KOSZT;
    roznicaZamowienia = ile - mozliwosciNabywcze;
  } else
  {
    mozliwosciNabywcze = ile;
  }

  for (unsigned int i = 0; i < mozliwosciNabywcze; i++)
  {
    Swinka s;
    tablicaSwin.emplace_back(s);
    pieniadz -= 10;
  }

  cout << Wiadomosci::zakupionoSwinie(mozliwosciNabywcze);
  if (roznicaZamowienia > 0)
  {
    cout << Wiadomosci::brakFunduszyNaSwinie(roznicaZamowienia);
  }
}

void Farma::kupPsa()
{
  if (pieniadz >= Piesek::CENA_KUPNA)
  {
    piesObronny = std::optional<Piesek>{Piesek()};
    pieniadz -= Piesek::CENA_KUPNA;
  } else
  {
    cout << "Nie stac cie na Azora." << endl;
  }
}

void Farma::ulepszPsa()
{
  if (piesObronny->dajLvl() >= Piesek::MAX_LVL)
  {
    cout << "Twoj Azor osiagnal juz najwyzszy stopien rozwoju.\n";
  } else if (piesObronny->dajCeneTreninguAzora() <= pieniadz)
  {
    cout << "Treningi Azora są dla ciebie zbyt kosztowne w tej chwili.\n";
  } else
  {
    piesObronny->trenuj();
    pieniadz -= piesObronny->dajCeneTreninguAzora();
  }
}

void Farma::wyswietlStanGry()
{
  cout << endl << "OTO TWOJA FARMA:" << endl;
  cout << endl << "\tZWIERZETA NA FARMIE" << endl;
  cout << "\tLiczba Swinek: " << tablicaSwin.size() << endl;
  if (int(tablicaSwin.size() - pojemnoscFarmy) >= 0 && piesObronny->dajWartosc() != 0)
  {
    cout << "\tW tym liczba swinek poza farma: " << tablicaSwin.size() - pojemnoscFarmy + 1 << endl;
  }
  if (int(tablicaSwin.size() - pojemnoscFarmy) > 0 && piesObronny->dajWartosc() == 0)
  {
    cout << "\tW tym liczba swinek poza farma: " << tablicaSwin.size() - pojemnoscFarmy << endl;
  }
  if (czyJestPies())
  {
    cout << endl << "\tPies Azor" << endl;
    cout << "\tLevel: " << piesObronny->dajLvl() << endl;
    cout << "\tSila ataku: " << piesObronny->dajSileAtaku() << endl;
    cout << "\tGlod: " << piesObronny->dajGlod() << endl;
    cout << "\tWartosc: " << piesObronny->dajWartosc() << endl;
  }

  cout << endl << "\tZASOBY" << endl;
  cout << "\tPieniadze: $" << pieniadz << endl;
  cout << "\tKarma: " << karma << endl;
  cout << endl;
}

void Farma::wywolajWilkaZLasu()
{
  if (!wilczek.czyAtakuje())
  {
    return;
  }

  cout << "Zostales zaataowany przez wilka!" << endl;
  unsigned int silaAtakuWilka = wilczek.dajSileAtaku();
  if (dajSileAtakuPsa() >= silaAtakuWilka)
  {
    cout << "Azor pokonal wilka!" << endl;
  } else
  {
    unsigned int liczbaStraconychSwinek;
    if (silaAtakuWilka >= tablicaSwin.size())
    {
      liczbaStraconychSwinek = tablicaSwin.size();
      tablicaSwin.clear();
    } else
    {
      liczbaStraconychSwinek = silaAtakuWilka;
      tablicaSwin.erase(tablicaSwin.begin(), tablicaSwin.begin() + silaAtakuWilka);
    }

    cout << "Straciles " << liczbaStraconychSwinek << " swinek." << endl;
    piesObronny = std::nullopt;
    cout << "Straciles Azora. [*]" << endl;
  }
}

unsigned int Farma::policzPunkty()
{
  return Swinka::KOSZT * tablicaSwin.size() + pieniadz;
}

unsigned int Farma::dajSileAtakuPsa()
{
  if (!czyJestPies())
  {
    return 0;
  }
  return piesObronny->dajSileAtaku();
}

unsigned int Farma::dajGlodAzora()
{
  if (!czyJestPies())
  {
    return 0;
  }
  return piesObronny->dajGlod();
}

bool Farma::czyJestPies() const
{ return piesObronny.has_value(); }

unsigned int Farma::ileSwinekPozaFarma()
{
  if (tablicaSwin.size() <= pojemnoscFarmy)
  {
    return 0;
  }
  return tablicaSwin.size() - pojemnoscFarmy;
}

bool Farma::nakarmZwierzeta(unsigned int liczbaJednostekPotrzebnejKarmy)
{
  karma -= liczbaJednostekPotrzebnejKarmy;
  if (karma < 0)
  {
    int kosztZakupionejKarmy = kupKarme(-karma, 2);
    cout << "Aby wyzywic swinki zostala naliczona karna karma, ktora kosztowala $" << kosztZakupionejKarmy << "."
         << endl;
    if (kosztZakupionejKarmy == 0)
    {
      return true;
    }
  }
  return false;
}

unsigned int Farma::kupKarme(unsigned int liczbaZamowionejKarmy, unsigned int kurs)
{
  unsigned int kosztZamowionejKarmy = liczbaZamowionejKarmy * KOSZT_KARMY * kurs;
  if (kosztZamowionejKarmy > pieniadz)
  {
    cout << "Nie masz wystarczajaych funduszy na zakup karmy." << endl;
    return 0;
  }
  pieniadz -= kosztZamowionejKarmy;
  karma += liczbaZamowionejKarmy;
  return kosztZamowionejKarmy;
}

void Farma::dodajKieszonkoweOdMamy()
{
  pieniadz += WYSOKOSC_KIESZONKOWEGO;
  cout << "Mama wysyla przelew na $10." << endl;
}



