#include "Pracownik.h"
#include <string.h>
#include <iostream>

using namespace std;

Pracownik::Pracownik() : m_pNastepny(nullptr)
{
}


Pracownik::~Pracownik()
{
}

const char * Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char * Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char * nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char * nowe_nazwisko) 
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	cout << '\t';
	m_Nazwisko.Wypisz();
	cout << '\t';
	m_DataUrodzenia.Wypisz();
	cout << '\n';
}

void Pracownik::Wpisz()
{
	cout << "Wprowadzanie danych pracownika" << endl;
	cout << "Podaj imie pracownika: ";
	m_Imie.Wpisz();
	cout << "Nazwisko: ";
	m_Nazwisko.Wpisz();
	cout << "Data urodzenia!" << endl;
	m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char * por_imie) const
{
	int r = _stricoll(m_Imie.Zwroc(), por_imie);
	return r;
}

int Pracownik::SprawdzNazwisko(const char * por_nazwisko) const
{
	int r = _stricoll(m_Nazwisko.Zwroc(), por_nazwisko);
	return r;
}

int Pracownik::Porownaj(const Pracownik & wzorzec) const
{
	if ((SprawdzNazwisko(wzorzec.m_Nazwisko.Zwroc()) == 0) && (SprawdzImie(wzorzec.m_Imie.Zwroc()) == 0))
		return m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);
	else if ((SprawdzNazwisko(wzorzec.m_Nazwisko.Zwroc()) == 0))
		return SprawdzImie(wzorzec.m_Imie.Zwroc());
	else return SprawdzNazwisko(wzorzec.m_Nazwisko.Zwroc());
}

