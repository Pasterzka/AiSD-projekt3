#pragma once

#include <iostream>

class Graf {
private:
    long long iloscWierzcholkow;
    int* stopienWierzcholkow;
    int** GRAF;
    bool* odwiedzony;

    //dfs
    void DFS(long long v);

    // sortowanie
    void swap(int* a, int* b);
    int partition(int arr[], int low, int high);
    void merge(int arr[], int left, int mid, int right);
public:
    // tworzenie grafu
    Graf();
    //~Graf();

    //quick sort
    void quickSort(int arr[], int low, int high);
    void mergeSort(int arr[], int left, int right);

    // 1 -> ci¹g stopniowy wierzcho³ków
    void kolejnoscWierzcholkow();

    // 2 -> liczba sk³adowych spójnoœci
    int liczbaSkladowychSpojnosci();

    // 3 -> czy dwudzielny
    bool czyDwudzielny();

    // 5 -> czy planarny
    bool czyPlanarny();

    // 8 -> liczba dope³nienia krawêdzi grafu 
    long long liczbaKrawedziDopelnienGrafu();
};
