#include "Zwierze.h"

Zwierze::Zwierze(int glod, int wartosc) : glod(glod), wartosc(wartosc)
{}

int Zwierze::dajWartosc() const
{
  return wartosc;
}

int Zwierze::dajGlod() const
{
  return glod;
}

double Zwierze::podajCene() const
{
  return wartosc * 0.8;
}
