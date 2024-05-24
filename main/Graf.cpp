#include "Graf.h"
#include <iostream>

// konstruktor grafu
Graf::Graf() {
    std::cin >> iloscWierzcholkow;
    int pomIloscWierzcholkow = (int)iloscWierzcholkow;
    GRAF = new int* [pomIloscWierzcholkow];
    stopienWierzcholkow = new int[pomIloscWierzcholkow];
    odwiedzony = new bool[pomIloscWierzcholkow];

    for (int i = 0; i < iloscWierzcholkow; i++)
    {
        int stopienWiwerzcholka;
        std::cin >> stopienWiwerzcholka;
        GRAF[i] = new int[stopienWiwerzcholka];
        stopienWierzcholkow[i] = stopienWiwerzcholka;
        odwiedzony[i] = false;
        for (int k = 0; k < stopienWiwerzcholka; k++)
        {
            std::cin >> GRAF[i][k];
        }
    }
}



// zamiana elementów
void Graf::swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// na lewo elementy wiêksze od pivota, na prawo mniejsze
int Graf::partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // indeks mniejszego elementu

    for (int j = low; j < high; j++) {
        // Jeœli bie¿¹cy element jest wiêkszy
        if (arr[j] > pivot) {
            i++; // zwiêksz indeks mniejszego elementu
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Graf::merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tworzenie tymczasowych tablic L[] i R[]
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Scalanie tablic tymczasowych z powrotem do arr[left..right] w kolejnoœci malej¹cej
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) { // Zmieniony warunek na >=
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozosta³ych elementów tablicy L[], jeœli istniej¹
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Kopiowanie pozosta³ych elementów tablicy R[], jeœli istniej¹
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Funkcja implementuj¹ca QuickSort
void Graf::quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi to indeks partycji, arr[pi] jest teraz na w³aœciwym miejscu
        int pi = partition(arr, low, high);

        // Osobno sortuj elementy przed i za partycj¹
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Graf::mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        // Obliczanie œrodka
        int mid = left + (right - left) / 2;

        // Sortowanie pierwszej i drugiej po³owy
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Scalanie posortowanych po³ówek
        merge(arr, left, mid, right);
    }
}

void Graf::kolejnoscWierzcholkow() {
    int pomIloscWierzcholkow = int(iloscWierzcholkow);
    int* pomStopienWierzcholkow = new int[pomIloscWierzcholkow];
    for (int i = 0; i < pomIloscWierzcholkow; i++)
    {
        pomStopienWierzcholkow[i] = stopienWierzcholkow[i];
    }

    mergeSort(pomStopienWierzcholkow, 0, pomIloscWierzcholkow - 1);

    for (int i = 0; i < pomIloscWierzcholkow; i++) {
        std::cout << pomStopienWierzcholkow[i] << " ";
    }
    std::cout << "\n";
}

//DFS
void Graf::DFS(long long v)
{
    odwiedzony[v] = true;
    for (long long i = 0; i < stopienWierzcholkow[v]; i++)
    {
        long long x = GRAF[v][i] - 1;
        if (!odwiedzony[x])
        {
            DFS(x);
        }
    }
}

int Graf::liczbaSkladowychSpojnosci()
{
    int liczba = 0;
    for (int i = 0; i < iloscWierzcholkow; i++) {
        if (!odwiedzony[i]) {
            DFS(i);
            liczba++;
        }
    }
    return liczba;
}

