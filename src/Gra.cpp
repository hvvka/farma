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
    gracz.handluj();
  } while (gracz.nowaTura());
}

Gra::~Gra()
{
  running = false;
}


