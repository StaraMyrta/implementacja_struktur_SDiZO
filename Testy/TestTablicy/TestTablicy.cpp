#include "TestTablicy.h"

using namespace std;

TestTablicy::TestTablicy()
{
    tablica = new TablicaDynamiczna();
}

TestTablicy::~TestTablicy()
{
    delete tablica;
}

void TestTablicy::wypelnijTablice(int rozm)     //Dealokacja tablicy i przydzielenie pamiêci dla nowego obiektu.
{
    delete tablica;
    tablica = new TablicaDynamiczna();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < rozm; i++)
    {
        int random_num = dist(gen);
        tablica->dodaj(random_num);
    }
}

void TestTablicy::sredniTestDodawania()
{
    double wyniki[3][7];                        //Testy dodawania elementów z przodu tablicy.
    wyniki[0][0] = dodajNaPoczTest(1000);
    wyniki[0][1] = dodajNaPoczTest(5000);
    wyniki[0][2] = dodajNaPoczTest(10000);
    wyniki[0][3] = dodajNaPoczTest(50000);
    wyniki[0][4] = dodajNaPoczTest(100000);
    wyniki[0][5] = dodajNaPoczTest(500000);

    wyniki[1][0] = dodajNaKoniecTest(1000);     //Testy dodawania elementów z ty³u tablicy.
    wyniki[1][1] = dodajNaKoniecTest(5000);
    wyniki[1][2] = dodajNaKoniecTest(10000);
    wyniki[1][3] = dodajNaKoniecTest(50000);
    wyniki[1][4] = dodajNaKoniecTest(100000);
    wyniki[1][5] = dodajNaKoniecTest(500000);

    wyniki[2][0] = dodajLosowoTest(1000);       //Testy dodawania elementów w losowym miejscu tablicy.
    wyniki[2][1] = dodajLosowoTest(5000);
    wyniki[2][2] = dodajLosowoTest(10000);
    wyniki[2][3] = dodajLosowoTest(50000);
    wyniki[2][4] = dodajLosowoTest(100000);
    wyniki[2][5] = dodajLosowoTest(500000);

    cout << "\nDodawanie na pocz¹tek/koniec/losowo dla 1000, 5000, 10000, 50000, 100000, 500000 elementow: " << endl;
    for (auto& wynik : wyniki)
    {
        for (double j : wynik) cout << j <<endl;
        cout << endl;
    }
}

void TestTablicy::sredniTestUsuwania()
{
    double wyniki[3][10];                        //Testy usuwania elementów z przodu tablicy.
    wyniki[0][0] = usunNaPoczTest(1000);       //Testy dodawania elementów w losowym miejscu tablicy.
    wyniki[0][1] = usunNaPoczTest(5000);
    wyniki[0][2] = usunNaPoczTest(10000);
    wyniki[0][3] = usunNaPoczTest(50000);
    //wyniki[0][4] = usunNaPoczTest(100000);
    //wyniki[0][5] = usunNaPoczTest(500000);

    wyniki[1][0] = usunNaKonTest(1000);         //Testy usuwania elementów z ty³u tablicy.
    wyniki[1][1] = usunNaKonTest(5000);
    wyniki[1][2] = usunNaKonTest(10000);
    wyniki[1][3] = usunNaKonTest(50000);
    //wyniki[1][4] = usunNaKonTest(100000);
    //wyniki[1][5] = usunNaKonTest(500000);

    wyniki[2][0] = usunLosowoTest(1000);         //Testy usuwania elementów z losowego miejsca tablicy.
    wyniki[2][1] = usunLosowoTest(5000);
    wyniki[2][2] = usunLosowoTest(10000);
    wyniki[2][3] = usunLosowoTest(50000);
    //wyniki[2][4] = usunLosowoTest(100000);
    //wyniki[2][5] = usunLosowoTest(500000);

    cout << "Usuwanie z pocz¹tku/koñca/losowo dla 1000, 5000, 10000, 50000, 100000, 500000 elementow: " << endl;
    for (auto& wynik : wyniki)
    {
        for (double j : wynik) cout << j << endl;
        cout << endl;
    }
}

void TestTablicy::sredniTestSzukania()
{

    double wyniki[7];                           //Testy wyszukiwania elementów dla ró¿nych rozmiarów struktury.
    wyniki[0] = znajdzTest(1000);
    wyniki[1] = znajdzTest(5000);
    wyniki[2] = znajdzTest(10000);
    wyniki[3] = znajdzTest(50000);
    //wyniki[4] = znajdzTest(100000);
    //wyniki[5] = znajdzTest(500000);
    //wyniki[6] = znajdzTest(1000000);

    cout << "Wyszukiwanie dla  1000, 5000, 10000, 50000, 100000, 500000, 1000000 elementow: " << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << endl;
    }
}

double TestTablicy::dodajNaPoczTest(int rozm)
{

    double srednia = 0;                         //Wynik to œrednia ze 100 dodañ na pocz¹tek tablicy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 20; i++)
    {
        wypelnijTablice(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        tablica->dodajNaPocz(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 20;
}

double TestTablicy::dodajNaKoniecTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 dodañ na koniec tablicy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 20; i++)
    {
        wypelnijTablice(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        tablica->dodaj(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 20;
}

double TestTablicy::dodajLosowoTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 dodañ na losowym miejscu w tablicy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 20; i++)
    {
        wypelnijTablice(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        tablica->dodajLosowo(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 20;
}

double TestTablicy::usunNaPoczTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 usuniêæ z pocz¹tku tablicy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 20; i++)
    {
        wypelnijTablice(rozm);
        pomiar.czasStart();
        tablica->usun(0);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 20;
}

double TestTablicy::usunNaKonTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 usuniêæ z koñca tablicy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 20; i++)
    {
        wypelnijTablice(rozm);
        int indeks = rozm - 1;
        pomiar.czasStart();
        tablica->usun(indeks);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 20;
}

double TestTablicy::usunLosowoTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 usuniêæ z losowego miejsca w tablicy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 20; i++)
    {
        wypelnijTablice(rozm);
        pomiar.czasStart();
        tablica->usunLosowo();
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 20;
}

double TestTablicy::znajdzTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 wyszukiwañ w tablicy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 20; i++)
    {
        wypelnijTablice(rozm);
        int elem = tablica->zawartosc(rand() % tablica->rozmiar());
        pomiar.czasStart();
        tablica->znajdz(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 20;
}