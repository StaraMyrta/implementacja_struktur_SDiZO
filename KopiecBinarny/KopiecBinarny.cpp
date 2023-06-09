﻿#include "KopiecBinarny.h"

KopiecBinarny::KopiecBinarny()
{
    cr = cl = cp = "  ";
        cr[0] = 47;
        cl[0] = 92;
        cp[0] = 124;
        rozm = 0;
    wierzcholki = 0;
}

KopiecBinarny::~KopiecBinarny()
{
    delete[] baza;                                  //Dealokacja tablicy.

}

void KopiecBinarny::dodaj(int elem)
{
    int indeks = wierzcholki;                           //Zapamiętanie indeksu dla następnego pustego miejsca w tablicy.
    wierzcholki++;
    if (rozm - wierzcholki < MIN_FREE_SPACE)            //Jeśli rozmiar tablicy przekracza minimalny, zostaje ona rozszerzona.
    {
        int* tablicaRobocza = new int[wierzcholki];    //Kopiowanie zawartości tablicy do bufora, alokacja nowego rozmiaru i przywrócenie elementów.
        kopiujTablice(baza, tablicaRobocza, wierzcholki - 1);
        delete[] baza;
        rozm += START_SPACE;
        baza = new int[rozm];
        kopiujTablice(tablicaRobocza, baza, wierzcholki - 1);
        delete[] tablicaRobocza;
    }
    naprawKopiecGora(indeks, elem);
}

void KopiecBinarny::usunKorzen()
{
    if (rozm == 1) delete[] baza;
    rozm--;
    wierzcholki--;
    if (wierzcholki == 0) throw std::length_error(EXCEPTION_LENGTH_DESC);    //Jeśli kopiec jest pusty rzucony zostaje wyjątek.
    if (rozm - wierzcholki > MAX_FREE_SPACE)            //Jeśli rozmiar tablicy jest większy niż maksymalny, zostaje zmniejszona.
    {
        int* tablicaRobocza = new int[wierzcholki];    //Zawartość tablicy zostaje skopiowana do bufora, następnie alokowany zostaje nowy rozmiar z przywróceniem elementów.
        kopiujTablice(baza, tablicaRobocza, wierzcholki);
        delete[] baza;
        rozm -= START_SPACE;
        baza = new int[rozm];
        kopiujTablice(tablicaRobocza, baza, wierzcholki);
        delete[] tablicaRobocza;
    }
    int ostatniWierzcholek = baza[wierzcholki];                 //Zapamiętany zostaje indeks ostatniego wierzchołka oraz wartość korzenia.
    int wartoscKorzenia = baza[0];
    naprawKopiecDol(0, ostatniWierzcholek);
}

bool KopiecBinarny::usun(int elem)
{
    int usunIndeks = znajdzIndeks(elem);                //Znalezienie indeksu elementu do usunięcia.

    if (usunIndeks == -1) return false;                 //Jeśli element nie został znaleziony, operacja zostaje zakończona.
    else if (usunIndeks == 0)                           //Jeśli element jest korzeniem, usuwamy korzeń.
    {
        usunKorzen();
        return true;
    }
    if (rozm - wierzcholki > MAX_FREE_SPACE)            //Jeśli rozmiar tablicy jest większy niż maksymalny, zostaje zmniejszona.
    {
        int* tablicaRobocza = new int[wierzcholki];    //Zawartość tablicy zostaje przekopiowana do bufora, następnie alokowany zostaje nowy rozmiar z przywróceniem elementów.
        kopiujTablice(baza, tablicaRobocza, wierzcholki);
        delete[] baza;
        rozm -= START_SPACE;
        baza = new int[rozm];
        kopiujTablice(tablicaRobocza, baza, wierzcholki);
        delete[] tablicaRobocza;
    }
    wierzcholki--;
    int ostatniWierzcholek = baza[wierzcholki];
    int rodzic = baza[(usunIndeks - 1) / 2];
    if (ostatniWierzcholek < rodzic) naprawKopiecDol(usunIndeks, ostatniWierzcholek);    //Jeśli wartość ostatniego liścia jest mniejsza od rodzica drzewo zostaje naprawione w dół. Jeśli nie drzewo zostaje naprawione w górę
    else naprawKopiecGora(usunIndeks, ostatniWierzcholek);
    return true;
}

bool KopiecBinarny::znajdz(int elem, int indeks)//Przeglądanie odbywa się zgodnie z własnościami kopca. Jeśli element zostanie znaleziony funkcja zwraca true.
{
    return false;
}

bool KopiecBinarny::znajdz(int elem)
{
    if (baza[0] < elem) return false;          //Jeśli poszukiwany element jest większy od korzenia wiadome jest, że nie istnieje w kopcu.
    else if (baza[0] == elem) return true;
    int i = 0;
    while (2 * i + 1 < rozm - 1)
    {
        if (baza[2 * i + 1] < elem && baza[2 * i + 2] < elem) return false;
        else if (baza[2 * i + 1] == elem || baza[2 * i + 2] == elem) return true;
        else i++;
    }
    return false;
}

int KopiecBinarny::zawartosc(int indeks)
{
    if (indeks < 0 || indeks > wierzcholki - 1) throw std::out_of_range(EXCEPTION_DESC);
    return baza[indeks];
}

void KopiecBinarny::naprawKopiecGora(int indeks, int ostatniWierzcholek)
{
    int indeksRodzica = (indeks - 1) / 2;    //Obliczenie wartości indeksu rodzica dla nowego liścia.
    while (indeks > 0 && baza[indeksRodzica] < ostatniWierzcholek)    //Dopóki nie będzie spełniony warunek kopca potomek zostaje zmieniony z jego rodzicem.
    {
        baza[indeks] = baza[indeksRodzica];
        indeks = indeksRodzica;
        indeksRodzica = (indeks - 1) / 2;
    }
    baza[indeks] = ostatniWierzcholek;
}

void KopiecBinarny::naprawKopiecDol(int indeks, int ostatniWierzcholek)
{
    int wiekszyPotomek = 2 * indeks + 1;    //Zmienna indeks przechowuje indeks rodzica dla algorytmu naprawy drzewa od góry.
    //Kopiec zostaje przejrzany w dół przez wybieranie większego potomka. Jeśli nie ma moliwości znalezienia takiego przypadku pętla zostaje przerwana (warunek kopca zachowany). 
    //W przeciwym wypadku rodzic z większym potomkiem zostają zamienieni miejscami a proces powtarza się.
    while (wiekszyPotomek < wierzcholki)
    {
        if (wiekszyPotomek + 1 < wierzcholki && baza[wiekszyPotomek] < baza[wiekszyPotomek + 1]) wiekszyPotomek++;
        if (ostatniWierzcholek >= baza[wiekszyPotomek]) break;
        baza[indeks] = baza[wiekszyPotomek];
        indeks = wiekszyPotomek;
        wiekszyPotomek = 2 * wiekszyPotomek + 1;
    }
    baza[indeks] = ostatniWierzcholek;      //Ustawienie wartości wyliczonego wierzchołka na ostatni wierzchołek kopca przed usunięciem korzenia.
}

int KopiecBinarny::znajdzIndeks(int elem)
{
    for (int i = 0; i < wierzcholki; i++)
    {
        if (baza[i] == elem) return i;
    }
    return -1;
}

void KopiecBinarny::kopiujTablice(int* skad, int* dokad, int rozm)
{
    for (int i = 0; i < rozm; i++) dokad[i] = skad[i];    //Skopiowanie 'rozm' elementów z tablicy do tablicy.
}

void KopiecBinarny::wyswietlDrzewo(string sp, string sn, int v) {
    string s;
    if (v < wierzcholki) 
    {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        wyswietlDrzewo(s + cp, cr, 2 * v + 2);

        s = s.substr(0, sp.length() - 2);

        cout << s << sn << baza[v] << endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        wyswietlDrzewo(s + cp, cl, 2 * v + 1);
    }
}

void KopiecBinarny::wyswietlDrzewo()
{
    wyswietlDrzewo("", "", 0);
}

int KopiecBinarny::ileWierzcholkow()
{
    return wierzcholki;
}