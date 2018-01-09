#pragma once
#include "Pracownik.h"
class ListaPracownikow
{
public:
	ListaPracownikow(); //inicjuje odpowiednie pola sk³adowe
	~ListaPracownikow(); //usuwa wszystkich pracowników z lisy 
private:
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;
public:
	void Dodaj(const Pracownik & p);
	void Usun(const Pracownik & wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;

};

