#pragma once
#include <iostream>
#include <string>

class TablicaDynamiczna {
private:
	const std::string EXCEPTION_DESC = "Nieprawidlowy indeks!";
	int * baza;							//wskaŸnik na pocz¹tek tablicy
	int rozm;
	void zakres(int indeks);					//sprawdzenie czy tablica obejmuje podany indeks
	void kopiujTablice(int* skad, int* dokad, int rozm);	//kopiuje zadana ilosc elementow z tablicy zrodlowej do tabicy docelowej
public:
	TablicaDynamiczna();				//konstruktor klasy
	~TablicaDynamiczna();
	int zawartosc(int indeks);			//zwraca wartoœæ elementu o podanym indeksie
	bool znajdz(int elem);				//zwraca wartosc true/false dla zapytania o wystepowanie elementu o zadanej wartosci
	void dodaj(int elem);
	void dodaj(int indeks, int elem);	//dodaje zadany element w zadanym miejscu w tablicy
	void dodajNaPocz(int elem);			//dodaje zadany element na poczatku tablicy
	void dodajNaKon(int elem);			//dodaje zadany element na koncu tablicy
	void dodajLosowo(int elem);			//dodaje zadany element w losowym miejscu w tablicy
	void usun(int index);				//usuwa zadany element
	int rozmiar();						//zwraca rozmiar tablicy
};