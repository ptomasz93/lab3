/*
 * main.cpp
 *
 *  Created on: 13-03-2014
 *      Author: root
 */
//#define R 1000 //rozmiar

#include <iostream>
#include "stos.hh"
#include "stos_lista.hh"
//#include "kolejka_lista.hh"
#include "generator.hh"
#include "stoper.hh"
using namespace std;

int main()
{
	stos danych;
//	stos_l danych;
	czas stoper;
//	kolejka danych;
	fstream wejsciowe, wyniki;
	wyniki.open("czas_stos_t+1.txt",ios::out);
	int rozmiar;
	int il=0;
	for(int b=0;b<20;b++)
	{
		il+=50000;
		generuj("wejsciowe",il);
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
		cout<<"czas tworzenia stosu: "<<stoper.wynik()<<"s\n";
		stoper.zapisz(wyniki,rozmiar);
		wejsciowe.close();
	//	cout<<"teraz stos ma rozmiar: "<<danych.size()<<"\n"<<"jest pusty? "<<danych.isempty()<<"\n";
	//	cout<<"sciagamy i wyswietlamy;\n";

	}
	cout<<"teraz stos ma rozmiar: "<<danych.size()<<"\n"<<"jest pusty? "<<danych.isempty()<<"\n";
	wyniki.close();
}


