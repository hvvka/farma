#include "Farma.h"
#include <Wiadomosci.h>
#include <iostream>

Farma::Farma() : karma(0), pieniadz(30), pojemnoscFarmy(5)
{}

void Farma::sprzedajSwinie(unsigned int ile)
{
  if (tablicaSwin.size() < ile)
  {
    std::cout << "Podales zbyt duza liczbe. Sprzedano " << tablicaSwin.size()
              << " swinek.\n";
  }
  for (unsigned int i = 0; !tablicaSwin.empty() && i < ile; i++)
  {
    tablicaSwin.pop_back();
    pieniadz += Swinka::KOSZT;
  }
}

void Farma::rozmnazajSwinie()
{
  unsigned int liczbaSwinWNowymMiocie = tablicaSwin.size() / 2;
  for (unsigned int i = 0; i < liczbaSwinWNowymMiocie; i++)
  {
    Swinka s;
    tablicaSwin.push_back(s);
  }
  std::cout << Wiadomosci::urodzonoSwinie(liczbaSwinWNowymMiocie);
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

  std::cout << Wiadomosci::zakupionoSwinie(mozliwosciNabywcze) << std::endl;
  if (roznicaZamowienia > 0)
  {
    std::cout << Wiadomosci::brakFunduszyNaSwinie(roznicaZamowienia);
  }
}

void Farma::kupPsa()
{
  if (pieniadz >= Piesek::CENA_KUPNA)
  {
    piesObronny = std::optional < Piesek > {Piesek()};
    pieniadz -= Piesek::CENA_KUPNA;
  } else
  {
    std::cout << "Nie stac cie na Azora." << std::endl;
  }
}

void Farma::ulepszPsa()
{
  if (piesObronny->dajLvl() >= Piesek::MAX_LVL)
  {
    std::cout << "Twoj Azor osiagnal juz najwyzszy stopien rozwoju." << std::endl;
  } else if (piesObronny->dajCeneTreninguAzora() > pieniadz)
  {
    std::cout << "Treningi Azora są dla ciebie zbyt kosztowne w tej chwili." << std::endl;
  } else
  {
    pieniadz -= piesObronny->dajCeneTreninguAzora();
    piesObronny->trenuj();
  }
}

void Farma::wyswietlStanGry()
{
  std::cout << std::endl;
  std::cout << "OTO TWOJA FARMA:" << std::endl << std::endl;
  std::cout << "\tZWIERZETA NA FARMIE" << std::endl;
  std::cout << "\tLiczba swinek: " << tablicaSwin.size() - ileSwinekPozaFarma() << std::endl;
  if (ileSwinekPozaFarma() > 0)
  {
    std::cout << "\tZWIERZETA POZA FARMA" << std::endl;
    std::cout << "\tLiczba swinek: " << ileSwinekPozaFarma() << std::endl;
    std::cout << "\tGlod: " << Swinka::GLOD * ileSwinekPozaFarma() << std::endl;
  }
  if (czyJestPies())
  {
    std::cout << std::endl;
    std::cout << "\tPIES AZOR" << std::endl;
    std::cout << "\tLevel: " << piesObronny->dajLvl() << std::endl;
    std::cout << "\tSila ataku: " << piesObronny->dajSileAtaku() << std::endl;
    std::cout << "\tGlod: " << piesObronny->dajGlod() << std::endl;
    std::cout << "\tWartosc: " << piesObronny->dajWartosc() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "\tZASOBY" << std::endl;
  std::cout << "\tPieniadze: $" << pieniadz << std::endl;
  std::cout << "\tKarma: " << karma << std::endl;
  std::cout << std::endl;
}

void Farma::wywolajWilkaZLasu()
{
  if (!wilczek.czyAtakuje())
  {
    return;
  }

  std::cout << "Zostales zaatakowany przez wilka!" << std::endl;
  unsigned int silaAtakuWilka = wilczek.dajSileAtaku();
  if (dajSileAtakuPsa() >= silaAtakuWilka)
  {
    std::cout << "Azor pokonal wilka!" << std::endl;
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

    std::cout << Wiadomosci::stracilesSwinie(liczbaStraconychSwinek);
    if (czyJestPies())
    {
      piesObronny = std::nullopt;
      std::cout << "Straciles Azora. [*]" << std::endl;
    }
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

bool Farma::nakarmZwierzeta(unsigned int liczbaPotrzebnejKarmy)
{
  if (liczbaPotrzebnejKarmy > karma)
  {

    unsigned int kosztDokupionejKarmy = kupKarme(liczbaPotrzebnejKarmy - karma, 2);
    std::cout << "Aby wyzywic zwierzeta zakupiona zostala karna karma (kurs x2), ktora kosztowala $"
              << kosztDokupionejKarmy << "." << std::endl;
    if (kosztDokupionejKarmy > pieniadz)
    {
      return false;
    }
  }
  karma -= liczbaPotrzebnejKarmy;
  return true;
}

unsigned int Farma::kupKarme(unsigned int liczbaZamowionejKarmy, unsigned int kurs)
{
  unsigned int kosztZamowionejKarmy = liczbaZamowionejKarmy * KOSZT_KARMY * kurs;
  if (kosztZamowionejKarmy > pieniadz)
  {
    std::cout << "Nie masz wystarczajaych funduszy na zakup karmy." << std::endl;
  } else
  {
    pieniadz -= kosztZamowionejKarmy;
    karma += liczbaZamowionejKarmy;
  }
  return kosztZamowionejKarmy;
}

void Farma::dodajKieszonkoweOdMamy()
{
  pieniadz += WYSOKOSC_KIESZONKOWEGO;
  std::cout << "Mama wysyla przelew na $10." << std::endl;
}

unsigned int Farma::obliczKosztTreninguAzora()
{
  return piesObronny->dajCeneTreninguAzora();
}
