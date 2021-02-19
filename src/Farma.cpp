#include "Farma.h"
#include <iostream>

Farma::Farma() : karma(0), pieniadz(30), pojemnoscFarmy(10)
{}

Farma::~Farma() //wywolanie destruktorow obiektow dziedziczacych chyba nastepuje automatycznie - sprawdzic
{
  tablicaSwin.clear();
  piesObronny = std::nullopt;
  wilczek.~Wilk();
}

void Farma::sprzedajSwinie(int ile)      //sprzedanie Swinki
{
  for (int i = 0; !tablicaSwin.empty() && i < ile; i++)
  {
    //tablicaSwin.erase(tablicaSwin.end() - 1);
    tablicaSwin.pop_back();
    pieniadz += 10;
    if (tablicaSwin.empty() && ile > i)
      cout << "Podales zbyt duza liczbe. Nie masz juz zadnej Swinki w zagrodzie.\n";
  }
/*
    int i = 0;
    vector <Swinka>::iterator it_tablicaSwin = tablicaSwin.begin();
    while(it_tablicaSwin != tablicaSwin.end() && i < ile)
    {
        tablicaSwin.erase(it_tablicaSwin++);
        pieniadz += 4;
        i++;
    }

    if (tablicaSwin.empty() && ile > i)
        cout << "Podales za duza liczbe. Nie masz juz zadnej Swinki w zagrodzie.\n";
*/
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

void Farma::kupSwinie(int ile)
{
  for (int i = 0; i < ile; i++)
  {
    if (pieniadz < 10)
    {
      int tmp = ile - i;
      if (tmp == 1)
      {
        cout << "Nie masz pieniedzy, zeby kupic kolejna " << tmp << " swinke.\n";
      } else if (tmp < 5)
      {
        cout << "Nie masz pieniedzy, zeby kupic kolejne " << tmp << " swinki.\n";
      } else
      {
        cout << "Nie masz pieniedzy, zeby kupic kolejne " << tmp << " swinek.\n";
      }

      break;
    } else
    {
      Swinka s;
      tablicaSwin.push_back(s);
      pieniadz -= 10;
    }
  }
}

void Farma::kupPsa()
{
  if (pieniadz >= 2)
  {
    piesObronny = std::optional<Piesek>{Piesek()};
    pieniadz -= 2;
  } else
    cout << "Nie stac cie na Azora." << endl;
}

void Farma::ulepszPsa()
{
  if (piesObronny.__get().dajLvl() < 6 && piesObronny.__get().dajWartosc() + 2 <= pieniadz)
  {
    piesObronny.__get().trenuj();
    pieniadz -= piesObronny.__get().dajWartosc();
  } else if (piesObronny.__get().dajLvl() == 6)
  {
    cout << "\nTwoj Azor juz osiagnal najwyzszy stopien rozwoju.\n";
  } else
  {
    cout << "Treningi Azora są zbyt kosztowne dla ciebie w tej chwili.\n";
  }
}

void Farma::wyswietlStanGry()
{
  cout << endl << "OTO TWOJA FARMA:" << endl;
  cout << endl << "\tZWIERZETA NA FARMIE" << endl;
  cout << "\tLiczba Swinek: " << tablicaSwin.size() << endl;
  if (int(tablicaSwin.size() - pojemnoscFarmy) >= 0 && piesObronny.__get().dajWartosc() != 0)
  {
    cout << "\tW tym liczba swinek poza farma: " << tablicaSwin.size() - pojemnoscFarmy + 1 << endl;
  }
  if (int(tablicaSwin.size() - pojemnoscFarmy) > 0 && piesObronny.__get().dajWartosc() == 0)
  {
    cout << "\tW tym liczba swinek poza farma: " << tablicaSwin.size() - pojemnoscFarmy << endl;
  }
  if (piesObronny.__get().dajWartosc())
  {
    cout << endl << "\tPies Azor" << endl;
    cout << "\tLevel: " << piesObronny.__get().dajLvl() << endl;
    cout << "\tSila ataku: " << piesObronny.__get().dajAtak() << endl;
    cout << "\tGlod: " << piesObronny.__get().dajGlod() << endl;
    cout << "\tWartosc: " << piesObronny.__get().dajWartosc() << endl;
  }

  cout << endl << "\tZASOBY" << endl;
  cout << "\tPieniadze: $" << pieniadz << endl;
  cout << "\tKarma: " << karma << endl;

}

void Farma::kupKarme(int k) // 4 karmy kosztuje 1 pieniadz
{
  k = k / 4;  //mozna kupic tylko wielokrotnosci 4 karmy

  for (int i = 0; (i < k && pieniadz > 0); i++)
  {
    karma += 4;
    pieniadz--;
  }
}

void Farma::wywolajWilkaZLasu()
{
  if (wilczek.atakuj())
  {
    cout << "\nZostales zaataowany przez wilka!";
    int atakWilka = wilczek.dajAtak();
    if (atakWilka >= piesObronny.__get().dajAtak())
    {
      int i;
      //kazdy punkt ataku wilka zjada jedna swinke
      for (i = 0; (i < atakWilka && !tablicaSwin.empty()); i++)
        tablicaSwin.pop_back();

      cout << "\nStraciles " << i << " swinek.";
      piesObronny = std::nullopt;
      cout << "\nStraciles Azora. [*]";
    } else
      cout << "\nAzor pokonal wilka!";
  }

}


unsigned int Farma::policzPunkty()
{
  return 10 * tablicaSwin.size() + pieniadz;
}

int Farma::dajAtakPsa()
{
  return piesObronny.__get().dajAtak();
}

int Farma::dajGlodAzora()
{
  return piesObronny.__get().dajGlod();
}

int Farma::dajGlodSwinek()
{
  return tablicaSwin[0].nakarm();
}

unsigned int Farma::ileSwinekPozaFarma()
{
  return tablicaSwin.size() - pojemnoscFarmy;
}

bool Farma::odejmijKarme(int ile)
{
  if (ile > karma)
  {
    int nadmiar = ile - karma;
    if (pieniadz < nadmiar)
    {
      cout
              << "\nMiales za malo karmy na wykarmienie swinek i jednoczesnie za malo pieniedzy na kupno karmy po gorszym kursie.\nZOSTALES BANKRUTEM.\n";
      return true;
    }
    pieniadz -= nadmiar; //karne odejmowanie pieniedzy, za brak karmy, karma 4x drozsza niz normlanie

    cout << "\nAby wyzywic swinki zostala naliczona karna karma, ktora kosztowala $" << nadmiar << "." << endl;
    ile -= nadmiar;

  }
  karma -= ile;

  return false;

}

void Farma::dodajKieszonkoweOdMamy()
{
  pieniadz += 10;
  cout << "\nMama wysyla przelew na $10.\n";
}



