#include "tablicaDynamiczna.h"

TablicaDynamiczna::TablicaDynamiczna() {
	this->rozm = 0;
}

TablicaDynamiczna::~TablicaDynamiczna() {
	if (rozm >= 1)
		delete[] baza;
}

void TablicaDynamiczna::dodaj(int elem) {
	if (rozm == 0) {
		rozm++;
		baza = new int[rozm];
		baza[rozm - 1] = elem;
	}
	else {
		int* tablicaRobocza = new int[rozm];
		kopiujTablice(baza, tablicaRobocza, rozm);
		delete[] baza;
		rozm++;

		baza = new int[rozm];
		kopiujTablice(tablicaRobocza, baza, rozm - 1);
		baza[rozm - 1] = elem;
		delete[] tablicaRobocza;
	}
}

void TablicaDynamiczna::dodaj(int indeks, int elem) {
	//dodanie element�w dla warunk�w brzegowych
	if (indeks == rozm) {
		dodaj(elem);
		return;
	}
	//jesli indeks nowego elementu nie wybiega poza rozmiar tablicy jej zawarto�� zostaje skopiowana do listy roboczej
	zakres(indeks);
	int* tablicaRobocza = new int[rozm];
	kopiujTablice(baza, tablicaRobocza, rozm);
	delete[] baza;
	rozm++;

	baza = new int[rozm];
	int przesuniecie = 0;
	for (int i = 0; i < rozm; i++) {
		if (i == indeks) {
			baza[i] = elem;
			przesuniecie++;
		}
		else
			baza[i] = tablicaRobocza[i - przesuniecie];
	}
	delete[] tablicaRobocza;
}

void TablicaDynamiczna::dodajNaPocz(int elem) {
	dodaj(0, elem);
}

int TablicaDynamiczna::zawartosc(int indeks) {
	zakres(indeks);
	return baza[indeks];
}

bool TablicaDynamiczna::znajdz(int elem) {
	for (int i = 0; i < rozm; i++) {
		if (baza[i] == elem)
			return true;
	}
	return false;
}

void TablicaDynamiczna::usun(int indeks) {
	zakres(indeks);
	if (rozm == 1) {
		delete[] baza;
		rozm--;
	}
	else {
		int* tablicaRobocza = new int[rozm];
		kopiujTablice(baza, tablicaRobocza, rozm);
		delete[] baza;
		rozm--;

		baza = new int[rozm];
		for (int i = 0; i < rozm; i++) {
			if (i < indeks)
				baza[i] = tablicaRobocza[i];
			else
				baza[i] = tablicaRobocza[i + 1];
		}
		delete[] tablicaRobocza;
	}
}

void TablicaDynamiczna::zakres(int indeks) {
	if (indeks < 0 || indeks >(rozm - 1))
		throw std::out_of_range(EXCEPTION_DESC);
}

void TablicaDynamiczna::kopiujTablice(int* skad, int* dokad, int rozm) {
	for (int i = 0; i < rozm; i++) dokad[i] = skad[i];
}
