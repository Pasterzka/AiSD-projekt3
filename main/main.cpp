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
		for (int j = 0; j < 8; j++)
		{
			std::cout << "?\n";
		}
	}


	return 0;
}