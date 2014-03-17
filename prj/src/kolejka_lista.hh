/*
 * kolejka_lista.hh
 *
 *  Created on: 15-03-2014
 *      Author: root
 */

#ifndef KOLEJKA_LISTA_HH_
#define KOLEJKA_LISTA_HH_
/**
 * \struct
 * \brief zawiera zmienne jednego elementu kolejki
 */
struct element
{
element* nastepny;
int dana;
};

/**
 * \class
 * \brief zawiera funkcje i zmienne obslugujace kolejke
 * \details przechowuje wskaznik na koniec oraz poczatek kolejki
 * \details oraz funkcje dodawania, sicagania elementu sprawdzania rozmiaru
 */
class kolejka
{
private:
	element* poczatek;
	element* koniec;
	int rozmiar;
public:
	kolejka();
	void push(int dana);
	int pop();
	bool isempty();
	int size();

};

#endif /* KOLEJKA_LISTA_HH_ */
