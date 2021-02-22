#ifndef FARMA_WILK_H
#define FARMA_WILK_H

class Wilk
{
public:
    bool czyAtakuje();

    int dajSileAtaku() const;

private:
    int silaAtaku{0};
};

#endif // FARMA_WILK_H
