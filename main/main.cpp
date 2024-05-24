#include <iostream>

#include "Graf.h"

int main()
{

	//wcztytanie liczby grafów
	int liczbaGrafow;
	std::cin >> liczbaGrafow;

	//pętla dla wszystkich grafów
	for (int i = 0; i < liczbaGrafow; i++) {
		//stworzenie grafu
		Graf* graf = new Graf();
		graf->kolejnoscWierzcholkow();
		std::cout << graf->liczbaSkladowychSpojnosci() << "\n";
		if (graf->czyDwudzielny())
		{
			std::cout << "T\n";
		}
		else {
			std::cout << "F\n";
		}
		for (int j = 0; j < 6; j++)
		{
			std::cout << "?\n";
		}
		std::cout << graf->liczbaKrawedziDopelnienGrafu() << "\n";
	}


	return 0;
}