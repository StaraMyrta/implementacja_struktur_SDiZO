#include "TestListy.h"

using namespace std;

TestListy::TestListy()
{
    lista = new ListaDwukierunkowa();
}

TestListy::~TestListy()
{
    delete lista;
}

void TestListy::wypelnijListe(int rozm)         //Dealokacja listy i przydzielenie pamiêci dla nowego obiektu.
{
    delete lista;
    lista = new ListaDwukierunkowa();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < rozm; i++) lista->dodajNaKon(dist(gen));
}

void TestListy::sredniTestDodawania()
{

    double wyniki[3][10];                        //Testy dodawania elementów z przodu listy.
    wyniki[0][0] = dodajNaPoczTest(1000);
    wyniki[0][1] = dodajNaPoczTest(5000);
    wyniki[0][2] = dodajNaPoczTest(10000);
    wyniki[0][3] = dodajNaPoczTest(50000);
    wyniki[0][4] = dodajNaPoczTest(100000);
    wyniki[0][5] = dodajNaPoczTest(500000);
    wyniki[0][6] = dodajNaPoczTest(1000000);
    wyniki[0][7] = dodajNaPoczTest(2500000);
    //wyniki[0][8] = dodajNaPoczTest(5000000);
    //wyniki[0][9] = dodajNaPoczTest(10000000);
    
    wyniki[1][0] = dodajNaKoniecTest(1000);     //Testy dodawania elementów z ty³u listy.
    wyniki[1][1] = dodajNaKoniecTest(5000);
    wyniki[1][2] = dodajNaKoniecTest(10000);
    wyniki[1][3] = dodajNaKoniecTest(50000);
    wyniki[1][4] = dodajNaKoniecTest(100000);
    wyniki[1][5] = dodajNaKoniecTest(500000);
    wyniki[1][6] = dodajNaKoniecTest(1000000);
    wyniki[1][7] = dodajNaKoniecTest(2500000);
    //wyniki[1][8] = dodajNaKoniecTest(5000000);
    //wyniki[1][9] = dodajNaKoniecTest(10000000);

    wyniki[2][0] = dodajLosowoTest(1000);       //Testy dodawania elementów w losowym miejscu listy.
    wyniki[2][1] = dodajLosowoTest(5000);
    wyniki[2][2] = dodajLosowoTest(10000);
    wyniki[2][3] = dodajLosowoTest(50000);
    wyniki[2][4] = dodajLosowoTest(100000);
    wyniki[2][5] = dodajLosowoTest(500000);
    wyniki[2][6] = dodajLosowoTest(1000000);
    wyniki[2][7] = dodajLosowoTest(2500000);
    //wyniki[2][8] = dodajLosowoTest(5000000);
    //wyniki[2][9] = dodajLosowoTest(10000000);

    cout << "\nDodawanie na pocz¹tek/koniec/losowo dla 1000, 5000, 10000, 50000, 100000, 500000, 1000000 elementow: " << endl;
    for (auto& wynik : wyniki)
    {
        for (double j : wynik) cout << j << " us" << endl;
        cout << endl;
    }
}

void TestListy::sredniTestUsuwania()
{
    double wyniki[3][10];                        //Testy usuwania elementów z przodu listy.
    wyniki[0][0] = usunNaPoczTest(1000);
    wyniki[0][1] = usunNaPoczTest(5000);
    wyniki[0][2] = usunNaPoczTest(10000);
    wyniki[0][3] = usunNaPoczTest(50000);
    wyniki[0][4] = usunNaPoczTest(100000);
    wyniki[0][5] = usunNaPoczTest(500000);
    wyniki[0][6] = usunNaPoczTest(1000000);
    wyniki[0][7] = usunNaPoczTest(2500000);
    //wyniki[0][8] = usunNaPoczTest(5000000);
    //wyniki[0][9] = usunNaPoczTest(10000000);

    wyniki[1][0] = usunNaKonTest(1000);         //Testy usuwania elementów z ty³u listy.
    wyniki[1][1] = usunNaKonTest(5000);
    wyniki[1][2] = usunNaKonTest(10000);
    wyniki[1][3] = usunNaKonTest(50000);
    wyniki[1][4] = usunNaKonTest(100000);
    wyniki[1][5] = usunNaKonTest(500000);
    wyniki[1][6] = usunNaKonTest(1000000);
    wyniki[1][7] = usunNaKonTest(2500000);
    //wyniki[1][8] = usunNaKonTest(5000000);
    //wyniki[1][9] = usunNaKonTest(10000000);

    wyniki[2][0] = usunNaKonTest(1000);         //Testy usuwania elementów z losowego miejsca listy.
    wyniki[2][1] = usunLosowoTest(5000);
    wyniki[2][2] = usunLosowoTest(10000);
    wyniki[2][3] = usunLosowoTest(50000);
    wyniki[2][4] = usunLosowoTest(100000);
    wyniki[2][5] = usunLosowoTest(500000);
    wyniki[2][6] = usunLosowoTest(1000000);
    wyniki[2][7] = usunLosowoTest(2500000);
    //wyniki[2][8] = usunLosowoTest(5000000);
    //wyniki[2][9] = usunLosowoTest(10000000);

    cout << "Usuwanie z pocz¹tku/koñca/losowo dla 1000, 5000, 10000, 50000, 100000, 500000, 1000000 elementow: " << endl;
    for (auto& wynik : wyniki)
    {
        for (double j : wynik) cout << j << " us" << endl;
        cout << endl;
    }
}

void TestListy::sredniTestSzukania()
{
    double wyniki[10];                           //Testy wyszukiwania elementów dla ró¿nych rozmiarów struktury.
    wyniki[0] = znajdzTest(1000);
    wyniki[1] = znajdzTest(5000);
    wyniki[2] = znajdzTest(10000);
    wyniki[3] = znajdzTest(50000);
    wyniki[4] = znajdzTest(100000);
    wyniki[5] = znajdzTest(500000);
    wyniki[6] = znajdzTest(1000000);
    wyniki[7] = znajdzTest(2500000);
    //wyniki[8] = znajdzTest(5000000);
    //wyniki[9] = znajdzTest(10000000);

    cout << "Wyszukiwanie dla  1000, 5000, 10000, 50000, 100000, 250000, 500000, 750000, 1000000, 5000000 elementow: " << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << " us" << endl;
    }
}

double TestListy::dodajNaPoczTest(int rozm)
{
    double srednia = 0;
    for (int i = 0; i < 10; i++)               //Wynik to œrednia ze 100 dodañ na pocz¹tek listy o zmienianych za ka¿dym razem danych.
    {
        wypelnijListe(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        lista->dodajNaPocz(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 10;
}

double TestListy::dodajNaKoniecTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 dodañ na koniec listy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 10; i++)
    {
        wypelnijListe(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        lista->dodajNaKon(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 10;
}

double TestListy::dodajLosowoTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 dodañ na losowym miejscu w liœcie o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 10; i++)
    {
        wypelnijListe(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        lista->dodajLosowo(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 10;
}

double TestListy::usunNaPoczTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 usuniêæ z pocz¹tku listy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 10; i++)
    {
        wypelnijListe(rozm);
        pomiar.czasStart();
        lista->usunZPocz();
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 10;
}

double TestListy::usunNaKonTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 usuniêæ z koñca listy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 10; i++)
    {
        wypelnijListe(rozm);
        pomiar.czasStart();
        lista->usunZKon();
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 10;
}

double TestListy::usunLosowoTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 usuniêæ z losowego miejsca listy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 10; i++)
    {
        wypelnijListe(rozm);
        pomiar.czasStart();
        lista->usunLosowo();
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 10;
}

double TestListy::znajdzTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 wyszukañ w liœcie o zmienianych za ka¿dym razem danych.

    for (int i = 0; i < 10; i++)
    {
        wypelnijListe(rozm);
        int element = lista->znajdz(rand() % lista->rozmiar());
        pomiar.czasStart();
        lista->znajdz(element);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 10;
}