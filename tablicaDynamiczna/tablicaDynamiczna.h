#pragma once
#include <random>
#include <iostream>
#include <string>

using namespace std;

class TablicaDynamiczna {
private:
	const std::string EXCEPTION_DESC = "Nieprawidlowy indeks!";		//Sta³a przechowuj¹ca opis wyj¹tku.
	int * baza;							//WskaŸnik na pocz¹tek tablicy.
	int rozm;
	void zakres(int indeks);			//Sprawdzenie czy tablica obejmuje podany indeks.
	void kopiujTablice(int* skad, int* dokad, int rozm);		//Kopiuje zadana ilosc elementow z tablicy zrodlowej do tabicy docelowej.
public:
	TablicaDynamiczna();				//Konstruktor klasy.
	~TablicaDynamiczna();
	int zawartosc(int indeks);			//Zwraca wartoœæ elementu o podanym indeksie.
	bool znajdz(int elem);				//Zwraca wartosc true/false dla zapytania o wystepowanie elementu o zadanej wartosci.
	void dodaj(int elem);				//Dodaje zadany element na koñcu tablicy.
	void dodaj(int indeks, int elem);	//Dodaje zadany element w zadanym miejscu w tablicy.
	void dodajNaPocz(int elem);			//Dodaje zadany element na poczatku tablicy.
	void dodajNaKon(int elem);			//Dodaje zadany element na koncu tablicy.
	void dodajLosowo(int elem);			//Dodaje zadany element w losowym miejscu w tablicy.
	void usun(int index);				//Usuwa zadany element.
	void usunLosowo();
	int rozmiar();						//Zwraca rozmiar tablicy.
};