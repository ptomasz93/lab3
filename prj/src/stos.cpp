/*
 * stos.cpp
 *
 *  Created on: 13-03-2014
 *      Author: root
 */

#include "stos.hh"

//-----------------------------------------------------------------------
//*****************************PRIVATE***********************************
//-----------------------------------------------------------------------

/**
 *\brief kopiuje zawartosc jednej tablicy do drugiej
 * @param s_tab
 */
void  stos::kopiuj(int* s_tab )
	{
		for( int i = 0; i < aktualna; i++ ) tab[ i ] = s_tab[ i ];
	}
/**
 * \brief zweikasza dwukrotnie rozmiar stosu gdy brakuje miejsca
 */
void stos::zwieksz_dwa()
{
	int* s_tab;
	if (rozmiar == 0)
	{
		tab = new int[1];
		rozmiar += 1;
	}
	else
	{
		s_tab = tab;
		tab = new int[rozmiar*2];
		kopiuj(s_tab);
		if (s_tab != NULL)
		delete[] s_tab;
		rozmiar *= 2;
	}
}
/**
 * \brief zwieksza rozmiar tablicy o 1
 */
void stos::zwieksz_o_1()
{
	int* s_tab;
	s_tab=tab;
	tab=new int[rozmiar+1];
	kopiuj(s_tab);
	if (s_tab != NULL)
	delete  s_tab;
	rozmiar+=1;
}

/**
 * \brief Zmniejsza rozmar tablicy dwukrotnie
 * \details gdy stos zajmuje 1/4 rozmiaru tablicy jest ona zmniejszana o 1/2
 */

void stos::zmniejsz()
{
	int* s_tab;
	if (rozmiar==0)return;
	if (aktualna==0)delete[] tab;
	else
	{
		s_tab = tab;
		tab = new int[rozmiar/2];
		kopiuj(s_tab);
		if (s_tab != NULL)
			delete[] s_tab;
		rozmiar /= 2;
	}
}


//----------------------------------------------------------------------
//*****************************PUBLIC***********************************
//----------------------------------------------------------------------

/**
 *\brief Konstruktor
 *\details Zeruje zmienna rozmiar i aktualna
 */
stos::stos()
:rozmiar(0), aktualna(0)
 {
 }

/**
 *\brief dodaje zmienn do stosu
 *\details funkcja sprawdza czy tablica nie jest zapelniona i dodaje zienna.
 *\details Jesli tablica pelna wywoluje funkcje zwiekszajaca jej rozmiar
 *\details ZWIEKSZ- definicja w pliku stos.hh
 * @param dana
 */
void stos::push(int dana)
{
	if(aktualna>=rozmiar)
	ZWIEKSZ
	tab[aktualna]=dana;
	aktualna+=1;
}
/**
 * \brief sciaga zmienna ze stosu
 * \details Sprawdza rowniez rozmiar tablicy. Jesli tablica zajeta w 1/4 zmniejsza jej rozmiar o polowe.
 * @return
 */
int stos::pop()
{
	int dana;
	dana=tab[aktualna-1];
	aktualna-=1;
	if(aktualna<=(rozmiar/4))zmniejsz();
	//dana=tab[rozmiar-1];
	//rozmiar-=1;
	return dana;
}
/**
 *\brief sprawdza czy jest cos na stosie;
 * @return zwraca 1 gdy pusta
 */
bool stos::isempty()
{
	if(aktualna==0)return true;
	return false;
}

/**
 * \brief sprawdza ilosc danych
 * @return ilosc zmiennych w stosie;
 */
int stos::size()
{
	return aktualna;
}
