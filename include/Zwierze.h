#ifndef FARMA_ZWIERZE_H
#define FARMA_ZWIERZE_H

class Zwierze
{
public:
    Zwierze(int glod, int wartosc);

    int dajGlod() const;

    int dajWartosc() const;

    double podajCene() const;

protected:
    int glod{0};
    int wartosc{0};
};

#endif /* Zwierze_h */
