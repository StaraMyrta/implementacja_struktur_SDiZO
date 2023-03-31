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
    for (int i = 0; i < rozm; i++) lista->dodajNaKon(rand() % rozm);
}

void TestListy::sredniTestDodawania()
{

    double wyniki[3][5];                        //Testy dodawania elementów z przodu listy.
    wyniki[0][0] = dodajNaPoczTest(1000);
    wyniki[0][1] = dodajNaPoczTest(2000);
    wyniki[0][2] = dodajNaPoczTest(5000);
    wyniki[0][3] = dodajNaPoczTest(10000);
    wyniki[0][4] = dodajNaPoczTest(20000);
    
    wyniki[1][0] = dodajNaKoniecTest(1000);     //Testy dodawania elementów z ty³u listy.
    wyniki[1][1] = dodajNaKoniecTest(2000);
    wyniki[1][2] = dodajNaKoniecTest(5000);
    wyniki[1][3] = dodajNaKoniecTest(10000);
    wyniki[1][4] = dodajNaKoniecTest(20000);

    wyniki[2][0] = dodajLosowoTest(1000);       //Testy dodawania elementów w losowym miejscu listy.
    wyniki[2][1] = dodajLosowoTest(2000);
    wyniki[2][2] = dodajLosowoTest(5000);
    wyniki[2][3] = dodajLosowoTest(10000);
    wyniki[2][4] = dodajLosowoTest(20000);

    cout << "\nDodawanie front/back/random dla 1000, 2000, 5000, 10000, 20000 elementow: " << endl;
    for (auto& wynik : wyniki)
    {
        for (double j : wynik) cout << j << " us" << endl;
        cout << endl;
    }
}

void TestListy::sredniTestUsuwania()
{
    double wyniki[3][5];                        //Testy usuwania elementów z przodu listy.
    wyniki[0][0] = usunNaPoczTest(1000);
    wyniki[0][1] = usunNaPoczTest(2000);
    wyniki[0][2] = usunNaPoczTest(5000);
    wyniki[0][3] = usunNaPoczTest(10000);
    wyniki[0][4] = usunNaPoczTest(20000);

    wyniki[1][0] = usunNaKonTest(1000);         //Testy usuwania elementów z ty³u listy.
    wyniki[1][1] = usunNaKonTest(2000);
    wyniki[1][2] = usunNaKonTest(5000);
    wyniki[1][3] = usunNaKonTest(10000);
    wyniki[1][4] = usunNaKonTest(20000);

    wyniki[2][0] = usunNaKonTest(1000);         //Testy usuwania elementów z losowego miejsca listy.
    wyniki[2][1] = usunNaKonTest(2000);
    wyniki[2][2] = usunNaKonTest(5000);
    wyniki[2][3] = usunNaKonTest(10000);
    wyniki[2][4] = usunNaKonTest(20000);

    cout << "Usuwanie front/back/random dla 1000, 2000, 5000, 10000, 20000 elementow: " << endl;
    for (auto& wynik : wyniki)
    {
        for (double j : wynik) cout << j << " us" << endl;
        cout << endl;
    }
}

void TestListy::sredniTestSzukania()
{
    double wyniki[5];                           //Testy wyszukiwania elementów dla ró¿nych rozmiarów struktury.
    wyniki[0] = znajdzTest(1000);
    wyniki[1] = znajdzTest(2000);
    wyniki[2] = znajdzTest(5000);
    wyniki[3] = znajdzTest(10000);
    wyniki[4] = znajdzTest(20000);

    cout << "Wyszukiwanie dla 1000, 2000, 5000, 10000, 20000 elementow:" << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << " us" << endl;
    }
}

double TestListy::dodajNaPoczTest(int rozm)
{
    double srednia = 0;
    for (int i = 0; i < 100; i++)               //Wynik to œrednia ze 100 dodañ na pocz¹tek listy o zmienianych za ka¿dym razem danych.
    {
        wypelnijListe(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        lista->dodajNaPocz(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 100;
}

double TestListy::dodajNaKoniecTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 dodañ na koniec listy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 100; i++)
    {
        wypelnijListe(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        lista->dodajNaKon(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 100;
}

double TestListy::dodajLosowoTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 dodañ na losowym miejscu w liœcie o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 100; i++)
    {
        wypelnijListe(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        lista->dodajLosowo(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 100;
}

double TestListy::usunNaPoczTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 usuniêæ z pocz¹tku listy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 100; i++)
    {
        wypelnijListe(rozm);
        pomiar.czasStart();
        lista->usunZPocz();
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 100;
}

double TestListy::usunNaKonTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 usuniêæ z koñca listy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 100; i++)
    {
        wypelnijListe(rozm);
        pomiar.czasStart();
        lista->usunZKon();
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 100;
}

double TestListy::usunLosowoTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 usuniêæ z losowego miejsca listy o zmienianych za ka¿dym razem danych.
    for (int i = 0; i < 100; i++)
    {
        wypelnijListe(rozm);
        pomiar.czasStart();
        lista->usunLosowo();
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 100;
}

double TestListy::znajdzTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 wyszukañ w liœcie o zmienianych za ka¿dym razem danych.

    for (int i = 0; i < 100; i++)
    {
        wypelnijListe(rozm);
        int element = lista->znajdz(rand() % lista->rozmiar());
        pomiar.czasStart();
        lista->znajdz(element);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 100;
}