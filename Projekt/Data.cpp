#include "Data.h"
#include <iostream>

using namespace std;

Data::Data(): m_nDzien(1)
	, m_nMiesiac(1)
	, m_nRok(2000)
{
}


Data::~Data()
{
}


void Data::Ustaw(int d, int m, int r)
{
	Data::m_nDzien = d;
	Data::m_nMiesiac = m;
	Data::m_nRok = r;
	Koryguj();
}

int Data::Dzien() const
{
	return Data::m_nDzien;
}

int Data::Miesiac() const
{
	return Data::m_nMiesiac;
}

int Data::Rok() const
{
	return Data::m_nRok;
}

void Data::Wypisz() const
{
	cout << m_nDzien << " - " << m_nMiesiac << " - " << m_nRok << endl;
}

void Data::Wpisz()
{
	int d, m, r; 
	cout << "Wprowadzenie nowej daty \nDzien: ";
	cin >> d;
	cout << "\nMiesiac: ";
	cin >> m;
	cout << "\nRok: ";
	cin >> r;

	Ustaw(d, m, r);
}

int Data::Porownaj(const Data & wzor) const // zwraca 1 jeœli wzór jest m³odszy 
{
	if (m_nRok == wzor.m_nRok && m_nMiesiac == wzor.m_nMiesiac && m_nDzien == wzor.m_nDzien) return 0;
	
	if (m_nRok == wzor.m_nRok && m_nMiesiac == wzor.m_nMiesiac)
	{
		if (wzor.m_nDzien < m_nDzien) return 1;
		if (wzor.m_nDzien > m_nDzien) return -1;
	}
	if (m_nRok == wzor.m_nRok)
	{
		if (wzor.m_nMiesiac < m_nMiesiac) return 1;
		if (wzor.m_nMiesiac > m_nMiesiac) return -1;
	}
	if (wzor.m_nRok < m_nRok) return 1;
	if (wzor.m_nRok > m_nRok) return -1;
	
	return 0;
}

void Data::Koryguj()
{
	switch (Data::m_nMiesiac)
	{
	case 1:

		if (Data::m_nDzien > 31)
			m_nDzien = 31;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;
		break;

	case 2:
		if ((Data::m_nRok % 4 == 0) && (Data::m_nRok % 100 != 0) || (Data::m_nRok % 400 == 0)) 
		{
			if (Data::m_nDzien > 29)
				m_nDzien = 29;
		}
		else
		{
			if (Data::m_nDzien > 28)
				m_nDzien = 28;
		}


		if (Data::m_nDzien < 1)
			m_nDzien = 1;
		break;
	case 3:

		if (Data::m_nDzien > 31)
			m_nDzien = 31;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;

		break;
	case 4:
	{
		if (Data::m_nDzien > 30)
			m_nDzien = 30;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;
	}
	break;
	case 5:
	{
		if (Data::m_nDzien > 31)
			m_nDzien = 31;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;
	}
	break;
	case 6:
	{
		if (Data::m_nDzien > 30)
			m_nDzien = 30;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;
	}
	break;
	case 7:
	{
		if (Data::m_nDzien > 31)
			m_nDzien = 31;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;
	}
	break;
	case 8:
	{
		if (Data::m_nDzien > 31)
			m_nDzien = 31;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;
	}
	break;
	case 9:
	{
		if (Data::m_nDzien > 30)
			m_nDzien = 30;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;
	}
	break;
	case 10:
	{
		if (Data::m_nDzien > 31)
			m_nDzien = 31;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;
	}
	break;
	case 11:
	{
		if (Data::m_nDzien > 30)
			m_nDzien = 30;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;
	}
	break;
	case 12:
	{
		if (Data::m_nDzien > 31)
			m_nDzien = 31;
		if (Data::m_nDzien < 1)
			m_nDzien = 1;
	}
	default:
		if (Data::m_nMiesiac > 12) Data::m_nMiesiac = 12;
		if (Data::m_nMiesiac < 1)  Data::m_nMiesiac = 1;
			
		Data::m_nDzien = 1;

	}
}

