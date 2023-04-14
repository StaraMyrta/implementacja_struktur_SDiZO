#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <chrono>

#include "ElemRB.h"
using namespace std;


class DrzewoRB
{
private:
	void wyswietlDrzewo(string sp, string sn, ElemRB* p);

public:
	DrzewoRB();
	~DrzewoRB();
	
	ElemRB straznik;
	ElemRB* korzen;

	string cr, cl, cp;
	int rozm;
	int number;

	void dodaj(int number);
	void usun(int number);
	int znajdz(int number);
	void wyswietlDrzewo();
	void rotacjaWLewo(ElemRB* wezel);
	void rotacjaWPrawo(ElemRB* wezel);
	ElemRB* nastepnik(ElemRB* p);
	ElemRB* minimum(ElemRB* p);
	void naprawDrzewo(ElemRB* wezel);
	void usunKorzen();
};