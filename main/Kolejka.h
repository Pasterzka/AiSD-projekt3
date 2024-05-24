#pragma once

class Kolejka {
private:
    int* dane;
    int przod;
    int tyl;
    int rozmiar;
    int pojemnosc;
public:
    Kolejka(int maxPojemnosc);
    ~Kolejka();
    void dodaj(int wartosc);
    int zdjemij();
    bool czyPusta();

};