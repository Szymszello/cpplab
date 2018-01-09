#include <iostream>
#include <cstdlib>
#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "ListaPracownikow.h"
 
using namespace std;

int main()
{
	ListaPracownikow lista;
	Pracownik p;
	Napis imie, nazwisko;
	while (1)
	{
		system("cls");
		cout << "Co chcesz zrobic?!\n";
		cout << "1. Dodaj pracownika\n";
		cout << "2. Usun liste pracownikow\n";
		cout << "3. Wyswietl liste\n";
		cout << "4. Znajdz pracownika\n";

		char wybor = getchar();

		switch (wybor)
		{
		case '1':
			p.Wpisz();
			lista.Dodaj(p);
			break;
		case '2':
			lista.~ListaPracownikow();
			break;
		case '3':
			lista.WypiszPracownikow();
			break;
		case '4':
			cout << "Podaj imi� i nazwisko: ";
			imie.Wpisz();
			nazwisko.Wpisz();
			lista.Szukaj(imie.Zwroc(),nazwisko.Zwroc());
			break;
		default:
			break;
		}
	}
 
	/*TODO: 
		1. wprowad� nowego pracownika
		2. Usu� ca�� liste pracownikow
		3. wypisz ca�� list� pracownikow
		4. znajd� pracownika (na podst. imie, nazwisko, data ur.) 
	*/
}
