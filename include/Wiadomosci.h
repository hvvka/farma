#ifndef FARMA_WIADOMOSCI_H
#define FARMA_WIADOMOSCI_H

#include <string>

namespace Wiadomosci
{
    std::string brakFunduszyNaSwinie(unsigned int liczbaSwin);

    std::string zakupionoSwinie(unsigned int ile);

    int pobierzLiczbeOdUzytkownika();

    std::string wybierzAkcje(bool czyJestPies, unsigned int cenaTreninguAzora);

    std::string odmienSwinie(unsigned int ile);

    std::string asciiSwinka();
}

#endif //FARMA_WIADOMOSCI_H
