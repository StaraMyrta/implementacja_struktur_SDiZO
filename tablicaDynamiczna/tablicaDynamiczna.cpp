#include "TablicaDynamiczna.h"

TablicaDynamiczna::TablicaDynamiczna()
{
    this->rozm = 0;                         //Ustawienie wielkoœci tablicy na 0.
}

TablicaDynamiczna::~TablicaDynamiczna()
{
    if (rozm > 0) delete[] baza;                                    //Usuniêcie zalokowanej pamiêci, jeœli jest zalokowana.
}

void TablicaDynamiczna::dodaj(int elem)
{
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

void TablicaDynamiczna::dodaj(int indeks, int elem)
{
    //dodanie elementów dla warunków brzegowych
    if (indeks == rozm) {
        dodaj(elem);
        return;
    }
    //jesli indeks nowego elementu nie wybiega poza rozmiar tablicy jej zawartoœæ zostaje skopiowana do listy roboczej
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

void TablicaDynamiczna::dodajNaKon(int elem) {
    dodaj(rozm, elem);
}

void TablicaDynamiczna::dodajLosowo(int elem)
{
    dodaj(rand() % (rozm + 1), elem);
}

int TablicaDynamiczna::zawartosc(int indeks) {
    zakres(indeks);
    return baza[indeks];
}

int TablicaDynamiczna::znajdz(int elem) {
    for (int i = 0; i < rozm; i++) {
        if (baza[i] == elem)
            return i;
    }
    return -1;
}

void TablicaDynamiczna::usun(int indeks) {
    zakres(indeks);
    if (rozm == 1) {
        delete[] baza;
        rozm--;
    }
    else if (indeks == rozm) {
        rozm--;
        int* tablicaRobocza = new int[rozm];
        kopiujTablice(baza, tablicaRobocza, rozm);
        delete[] baza;
        baza = new int[rozm];
        kopiujTablice(tablicaRobocza, baza, rozm);
        delete[] tablicaRobocza;
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

void TablicaDynamiczna::usunKoniec()
{
    usun(rozm - 1);
}

void TablicaDynamiczna::usunLosowo()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, rozm);
    if (rozm > 0) usun(dist(gen));
}

int TablicaDynamiczna::rozmiar()
{
    return rozm;
}

void TablicaDynamiczna::zakres(int indeks) {
    if (indeks < 0 || indeks >(rozm - 1))
        throw std::out_of_range(EXCEPTION_DESC);
}

void TablicaDynamiczna::kopiujTablice(int* skad, int* dokad, int rozm) {
    for (int i = 0; i < rozm; i++) dokad[i] = skad[i];
}
