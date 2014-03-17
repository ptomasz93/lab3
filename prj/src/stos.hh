/*
 * stos.hh
 *
 *  Created on: 13-03-2014
 *      Author: root
 */

#ifndef STOS_HH_
#define STOS_HH_

/**
 * \brief wybor sposobu zwiekszania talicy
 * \zwieksz_dwa()-zwieksza dwukrotnie rozmiar tablicy
 * \zwieksz_o_1()-zwieksza o 1 rozmiar tablicy;
 */
#define ZWIEKSZ zwieksz_o_1();

#include <iostream>
#include <cstring>

/**
 * \class
 * \brief zawiera zmienne oraz funkcje do obslugi stosu opartego na tablicy
 */
class stos
{
private:
	int* tab;
	int rozmiar;
	int aktualna;
	void zwieksz_dwa();
	void zwieksz_o_1();
	void zwieksz();
	void kopiuj(int* s_tab );
	void zmniejsz();
public:
	stos();
	void push(int dana);
	int pop();
	bool isempty();
	int size();
};


#endif /* STOS_HH_ */
