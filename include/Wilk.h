#ifndef FARMA_WILK_H
#define FARMA_WILK_H

class Wilk
{
public:
    bool czyAtakuje();

    int dajSileAtaku() const;

protected:
    int silaAtaku{4};
};

#endif // FARMA_WILK_H
