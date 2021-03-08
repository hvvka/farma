#ifndef FARMA_ZWIERZE_H
#define FARMA_ZWIERZE_H

class Zwierze
{
public:
    Zwierze(int glod, int wartosc);

    unsigned int dajGlod() const;

    unsigned int dajWartosc() const;

protected:
    unsigned int glod{0};
    unsigned int wartosc{0};
};

#endif /* Zwierze_h */
