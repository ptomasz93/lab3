/*
 * main.cpp
 *
 *  Created on: 13-03-2014
 *      Author: root
 */
//#define R 1000 //rozmiar

#include <iostream>
//#include "stos.hh"
//#include "stos_lista.hh"
//#include "kolejka_lista.hh"
#include "generator.hh"
#include "stoper.hh"
#include "kolejka_tablica.hh"
using namespace std;

#define SREDNIA_Z 20 ///z ilu powtirzen liczyc srednia

int main()
{
//	kolejka danych;
//	stos danych;
//	stos_l danych;
	czas stoper;
	kolejka_t danych;
	double suma;
	fstream wejsciowe, wyniki;
	wyniki.open("czas_kolejka_t.txt",ios::out);
	int rozmiar;
	int sr;
	int il=0;
	for(int b=0;b<20;b++)
	{
		il+=50000;

		generuj("wejsciowe",il);
		for(sr=0;sr<SREDNIA_Z;sr++)
		{
			wejsciowe.open("wejsciowe");
			wejsciowe>>rozmiar;
						stoper.start();
				for(int i=0;i<rozmiar;i++)
				{
					int a;
					wejsciowe>>a;
					danych.push(a);
				}
				stoper.stop();
					for(int i=0;i<rozmiar;i++)
					{
					danych.pop();
					}
			wejsciowe.close();
			suma+=stoper.wynik();
		}
		cout<<rozmiar<<"  "<<suma/sr<<"\n";
		wyniki<<rozmiar<<"  "<<suma/sr<<"\n";
		suma=0;
	//	cout<<"teraz stos ma rozmiar: "<<danych.size()<<"\n"<<"jest pusty? "<<danych.isempty()<<"\n";
	//	cout<<"sciagamy i wyswietlamy;\n";

	}
//	cout<<"teraz stos ma rozmiar: "<<danych.size()<<"\n"<<"jest pusty? "<<danych.isempty()<<"\n";
//	wyniki.close();
}


