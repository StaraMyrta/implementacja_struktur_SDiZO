#pragma once
#include "../../TablicaDynamiczna/TablicaDynamiczna.h"
#include "../Pomiar.h"
#include <random>

//Klasa s³u¿¹ca do testowania wydajnoœci operacji na tablicy.
class TestTablicy
{
private:
    TablicaDynamiczna* tablica;                 //WskaŸnik na obiekt klasy tablicy.
    Pomiar pomiar;                              //Obiekt klasy s³u¿acej do wykonywania jednolitych pomiarów.
    void wypelnijTablice(int rozm);             //Wype³nia tablicê losowymi liczbami.

    double dodajNaPoczTest(int rozm);           //Testuje wydajnoœæ dodawania elementu z przodu dla tablicy o 'rozm' elementach.
    double dodajNaKoniecTest(int rozm);         //Testuje wydajnoœæ dodawania elementu z ty³u dla tablicy o 'rozm' elementach.
    double dodajLosowoTest(int rozm);           //Testuje wydajnoœæ dodawania elementu w losowym miejscu dla tablicy o 'rozm' elementach.
    double usunNaPoczTest(int rozm);            //Testuje wydajnoœæ usuwania elementu z przodu dla tablicy o 'rozm' elementach.
    double usunNaKonTest(int rozm);             //Testuje wydajnoœæ usuwania elementu z ty³u dla tablicy o 'rozm' elementach.
    double usunLosowoTest(int rozm);            //Testuje wydajnoœæ usuwania elementu z losowego miejsca tablicy o 'rozm' elementach.
    double znajdzTest(int size);                //Testuje wydajnoœæ wyszukiwania elementu dla tablicy o 'rozm' elementach.
public:
    TestTablicy();                              //Konstruktor klasy TestTablicy.
    ~TestTablicy();                             //Destruktor klasy TestTablicy.
    void sredniTestDodawania();                 //Przeprowadza testy dodawania dla zadanych wielkoœci struktury.
    void sredniTestUsuwania();                  //Przeprowadza testy usuwania dla zadanych wielkoœci struktury.
    void sredniTestSzukania();                  //Przeprowadza testy wyszukiwania dla zadanych wielkoœci struktury.
};