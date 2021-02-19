#include "Zwierze.h"

Zwierze::Zwierze(int glod, int wartosc) : glod(glod), wartosc(wartosc)
{}

unsigned int Zwierze::dajWartosc() const
{
  return wartosc;
}

unsigned int Zwierze::dajGlod() const
{
  return glod;
}

double Zwierze::podajCene() const
{
  return wartosc * 0.8;
}
