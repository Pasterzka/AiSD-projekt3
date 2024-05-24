#include "Kolejka.h"

Kolejka::Kolejka(int maxPojemnosc)
{
    pojemnosc = maxPojemnosc;
    dane = new int[pojemnosc];
    przod = 0;
    tyl = -1;
    rozmiar = 0;
}

Kolejka::~Kolejka()
{
    delete[] dane;
}

void Kolejka::dodaj(int wartosc)
{
    if (rozmiar == pojemnosc) return; // kolejka pe³na
    tyl = (tyl + 1) % pojemnosc;
    dane[tyl] = wartosc;
    rozmiar++;
}

int Kolejka::zdjemij()
{
    if (rozmiar == 0) return -1; // kolejka pusta
    int wartosc = dane[przod];
    przod = (przod + 1) % pojemnosc;
    rozmiar--;
    return wartosc;
}

bool Kolejka::czyPusta()
{
    return (rozmiar == 0);
}
