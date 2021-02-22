#include "Gra.h"

Gra::Gra() : running{true}
{
  start();
}

void Gra::start()
{
  gracz.ustawImie();
  do
  {
    do
    {
      gracz.handluj();
    } while (!gracz.nowaTura());
    running = gracz.czyKoniec();
  } while (!running);
}

Gra::~Gra()
{
  running = false;
}


