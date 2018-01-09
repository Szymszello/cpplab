#include "ListaPracownikow.h"

#include <iostream>
 
using namespace std;

ListaPracownikow::ListaPracownikow() : m_nLiczbaPracownikow(0)
{
}


ListaPracownikow::~ListaPracownikow()
{
	m_pPoczatek = nullptr;
	m_nLiczbaPracownikow = 0;
	cout << "Poprawnie usunieto liste pracownikow!\n";
	system("pause");
}

void ListaPracownikow::Dodaj(const Pracownik & p)
{
	Pracownik *poprzedni = nullptr, *pom = nullptr;
	Pracownik kopia_p = p;
	if (m_nLiczbaPracownikow == 0)
	{
		m_pPoczatek = &kopia_p;
		cout << "Poprawnie dodano pracownika!\n";
	}
	else
	{
		pom = m_pPoczatek;
		//for (int i = 0; i < m_nLiczbaPracownikow; i++)
		while (pom != nullptr) 
		{
			if (pom->Porownaj(p) == 0)
			{
				cout << "Taki pracownik jest juz na liœcie!" << endl;
				break;
			}
			else
			{
				if (pom->Porownaj(p) > 0)		//pracownik podawany do funkcji (p) jest dalej alfabetycznie lub chronologicznie od aktualnego w iteracji.
				{
					if (pom->m_pNastepny == nullptr) //jeœli koniec listy
					{
						pom->m_pNastepny = &kopia_p;
						cout << "Poprawnie dodano pracownika!\n";
						break;						//koniec pêtli
					}
					poprzedni = pom;			//poprzednim pracownikiem staje siê ten "aktualny" 
					pom = pom->m_pNastepny;		//a aktualny bêdzie ten który jest nastêpny na liœcie
					continue;					//przejœcie do kolejnej iteracji 
				}
				if (pom->Porownaj(p) < 0)		//pierwszy pracownik napotkany w iteracji od którego pracownik (p) jest mniejszy dlatego przed niego dodajemy go w kolejkê  
				{
					if (poprzedni == nullptr) {		//w przypadku gdy pracownik (p) jest NAJMNIEJSZY czyli mniejszy od pierwszego obiektu
						kopia_p.m_pNastepny = pom;	//ten co by³ pierwszy to bedzie teraz drugi 
						m_pPoczatek = &kopia_p;		//Pocz¹tek ustawiam na tego co podalismy w funkcji. Moge tak bo kopia_p ju¿ nie jest const. 
						cout << "Poprawnie dodano pracownika!\n";
						break;						//koniec pêtli
					}
					kopia_p.m_pNastepny = pom;			//ustawiam wskaŸnik na nastêpny obiekt w pracowniku (p)
					poprzedni->m_pNastepny = &kopia_p;	//ustawiam wskaŸnik na nastêpny obiekt (czyli p) w poprzednim pracowniku na liœcie 
					cout << "Poprawnie dodano pracownika!\n";
					break;
				}
			}
		}
	}
	m_nLiczbaPracownikow++;
	system("pause");

}

void ListaPracownikow::Usun(const Pracownik & wzorzec)
{
	Pracownik *pom = m_pPoczatek;
	Pracownik *poprzedni = nullptr;
	if (m_nLiczbaPracownikow == 0) cout << "Brak pracowników na liœcie" << endl;
	else {

		while (pom != nullptr)
		{
			if (pom->Porownaj(wzorzec) == 0)
			{
				if (poprzedni == nullptr) //pocz¹tek listy
				{
					m_pPoczatek = pom->m_pNastepny; //ustawiam pocz¹tek listy na drugi element 
					m_nLiczbaPracownikow--;
					break;
				}

				if (pom->m_pNastepny == nullptr) //koniec listy
				{
					poprzedni->m_pNastepny = nullptr; //czyszczê wskaŸnik w przedostatnim elemencie
					m_nLiczbaPracownikow--;
					break;
				}
				
				poprzedni->m_pNastepny = pom->m_pNastepny; //w œrodku  
				m_nLiczbaPracownikow--;
				break;
			}
			else
			{
				poprzedni = pom;
				pom = pom->m_pNastepny;
			}	
		}
		if (pom == nullptr) cout << "Nie ma takiego pracownika na liœcie!" << endl;
	}
}

void ListaPracownikow::WypiszPracownikow() const
{
	Pracownik *pom = m_pPoczatek;
	while (pom != nullptr) 
	{
		pom->Wypisz();

		pom = pom->m_pNastepny;
	}
	if (pom == nullptr) cout << "Brak pracownikow na liscie!\n";
	system("pause");
}

const Pracownik * ListaPracownikow::Szukaj(const char * nazwisko, const char * imie) const
{
	Pracownik *pom = m_pPoczatek;
	while (pom != nullptr)
	{
		if (pom->Nazwisko() == nazwisko && pom->Imie() == imie) return pom;

		pom = pom->m_pNastepny;
	}
	return nullptr;
}
