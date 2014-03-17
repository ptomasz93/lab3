/*
 * stos_lista.cpp
 *
 *  Created on: 15-03-2014
 *      Author: root
 */
#include "stos_lista.hh"


/**
 * \brief konstruktor zeruje zmienna rozmiar
 */

stos_l::stos_l()
:rozmiar(0)
{
}

/**
 * dodaje zmienna na szczty stosu
 * @param dana zmienna do dodania
 */
void stos_l::push(int dana)
{
	element* nowy;
	if(rozmiar==0)
	{
		aktualny=new element;
		aktualny->poprzedni=NULL;
		aktualny->dana=dana;
		rozmiar+=1;
		return;
	}
	nowy=new element;
	nowy->dana=dana;
	nowy->poprzedni=aktualny;
	aktualny=nowy;
	rozmiar+=1;
}

/**
 * \brief sciaga zmienna ze stosu
 * @return zmienna zdjeta ze stosu
 */
int stos_l::pop()
{
	int dana;
	element* szczyt;
	szczyt=aktualny->poprzedni;
	dana=aktualny->dana;
	delete aktualny;
	rozmiar-=1;
	aktualny=szczyt;
	return dana;
}

/**
 * \brief sprawdza rozmiar stosu
 * @return rozmiar stosu
 */
int stos_l::size()
{
	return rozmiar;
}

/**
 * \brief sprawdza czy stos jest pusty
 * @return 1 pusty 0 pelny
 */
bool stos_l::isempty()
{
	if(rozmiar==0)return true;
	return false;
}
