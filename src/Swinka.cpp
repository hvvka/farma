#include "Swinka.h"

Swinka::Swinka() : Zwierze(GLOD, KOSZT), czasRozrodu(2)
{}

int Swinka::nakarm()
{
  return glod;
}

Swinka::~Swinka() = default;