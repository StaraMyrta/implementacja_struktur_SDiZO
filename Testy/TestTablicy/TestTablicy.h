#pragma once
#include "../../TablicaDynamiczna/TablicaDynamiczna.h"
#include "../Pomiar.h"
#include <random>

//Klasa s�u��ca do testowania wydajno�ci operacji na tablicy.
class TestTablicy
{
private:
    TablicaDynamiczna* tablica;                 //Wska�nik na obiekt klasy tablicy.
    Pomiar pomiar;                              //Obiekt klasy s�u�acej do wykonywania jednolitych pomiar�w.
    void wypelnijTablice(int rozm);             //Wype�nia tablic� losowymi liczbami.

    double dodajNaPoczTest(int rozm);           //Testuje wydajno�� dodawania elementu z przodu dla tablicy o 'rozm' elementach.
    double dodajNaKoniecTest(int rozm);         //Testuje wydajno�� dodawania elementu z ty�u dla tablicy o 'rozm' elementach.
    double dodajLosowoTest(int rozm);           //Testuje wydajno�� dodawania elementu w losowym miejscu dla tablicy o 'rozm' elementach.
    double usunNaPoczTest(int rozm);            //Testuje wydajno�� usuwania elementu z przodu dla tablicy o 'rozm' elementach.
    double usunNaKonTest(int rozm);             //Testuje wydajno�� usuwania elementu z ty�u dla tablicy o 'rozm' elementach.
    double usunLosowoTest(int rozm);            //Testuje wydajno�� usuwania elementu z losowego miejsca tablicy o 'rozm' elementach.
    double znajdzTest(int size);                //Testuje wydajno�� wyszukiwania elementu dla tablicy o 'rozm' elementach.
public:
    TestTablicy();                              //Konstruktor klasy TestTablicy.
    ~TestTablicy();                             //Destruktor klasy TestTablicy.
    void sredniTestDodawania();                 //Przeprowadza testy dodawania dla zadanych wielko�ci struktury.
    void sredniTestUsuwania();                  //Przeprowadza testy usuwania dla zadanych wielko�ci struktury.
    void sredniTestSzukania();                  //Przeprowadza testy wyszukiwania dla zadanych wielko�ci struktury.
};