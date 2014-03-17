/*
 * kolejka.cpp
 *
 *  Created on: 15-03-2014
 *      Author: root
 */
#include "kolejka_lista.hh"
/**
 *\brief konstruktor klasy kolejka, zeruje stałą rozmiar;
 */
kolejka::kolejka()
:rozmiar(0)
{
}

/**
 * \brief dodaje na koniec kolejki zmienna
 * @param dana zmienna ktora zostanie dodana
 */
void kolejka::push(int dana)
{
if(isempty())
{
	poczatek=koniec=new element;
	koniec->dana=dana;
	rozmiar+=1;
	return;
}
koniec->nastepny=new element;
koniec=koniec->nastepny;
koniec->dana=dana;
rozmiar+=1;
}
/**
 * \brief zdejmuje pierwszy element z kolejki
 * @return zwraca element znajdujacy sie na poczatku kolejki
 */
int kolejka::pop()
{
	element* nastepny;
	int dana;
	dana=poczatek->dana;
	nastepny=poczatek->nastepny;
	delete poczatek;
	poczatek=nastepny;
	rozmiar-=1;
	return dana;

}

/**
 *
 * @return zwraca rozmiar kolejki
 */
int kolejka::size()
{
	return rozmiar;
}

/**
 *
 * @return 1 jesli pusta  jesli pelna
 */
bool kolejka::isempty()
{
	if(rozmiar==0)return true;
	return false;
}



