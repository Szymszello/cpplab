#include "Napis.h"
#include <iostream>
#include <string.h>

using namespace std;
Napis::Napis()
{
}


Napis::~Napis()
{
}

const char * Napis::Zwroc() const
{
	return Napis::m_pszNapis;
}

void Napis::Ustaw(const char * nowy_napis)
{
	strcpy_s(Napis::m_pszNapis, nowy_napis);
}

void Napis::Wypisz() const
{
	cout << Napis::m_pszNapis << endl;
}

void Napis::Wpisz()
{
	cin >> Napis::m_pszNapis;
}

int Napis::SprawdzNapis(const char * por_napis) const
{
	int r = _stricoll(Napis::m_pszNapis, por_napis);
	return r;
}
