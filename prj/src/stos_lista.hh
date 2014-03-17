/*
 * stos_lista.hh
 *
 *  Created on: 15-03-2014
 *      Author: root
 */

#ifndef STOS_LISTA_HH_
#define STOS_LISTA_HH_

#include <iostream>
#include <cstring>
/**
 * \struct
 * \brief przechowuje zmienne ktore zawiera element stosu
 *
 */
struct element
{
	int dana;
	element* poprzedni;
};
/**
 * \class
 * \brief klasa zawiera zmienne oraz funkcje do obslugi stosu zbudowanego na liscie
 */
class stos_l
{
private:
element* aktualny;
int rozmiar;
public:
stos_l();
void push(int dana);
int pop();
bool isempty();
int size();
};




#endif /* STOS_LISTA_HH_ */
