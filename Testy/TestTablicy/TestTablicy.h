#include "../../TablicaDynamiczna/TablicaDynamiczna.h"
//#include "../Measurement.h"

//Klasa s³u¿¹ca do testowania wydajnoœci operacji na tablicy.
class TestTablicy
{
private:
    TablicaDynamiczna* tablica;                 //WskaŸnik na obiekt klasy tablicy.
    //Measurement measurement;                  //Obiekt klasy s³u¿acej do wykonywania pomiarów.
    void wypelnijTablice(int rozm);             //Wype³nia tablicê losowymi liczbami z przedzia³u [0, rozm - 1].

    double dodajNaPoczTest(int rozm);           //Testuje wydajnoœæ dodawania elementu z przodu dla tablicy o 'rozm' elementach.
    double dodajNaKoniecTest(int rozm);         //Testuje wydajnoœæ dodawania elementu z ty³u dla tablicy o 'rozm' elementach.
    double dodajLosowoTest(int rozm);           //Testuje wydajnoœæ dodawania elementu w losowym miejscu dla tablicy o 'rozm' elementach.
    double usunNaPoczTest(int rozm);            //Testuje wydajnoœæ usuwania elementu z przodu dla tablicy o 'rozm' elementach.
    double usunNaKonTest(int rozm);             //Testuje wydajnoœæ usuwania elementu z ty³u dla tablicy o 'rozm' elementach.
    double usunLosowoTest(int rozm);            //Testuje wydajnoœæ usuwania elementu z losowego miejsca tablicy o 'rozm' elementach.
    double znajdzTest(int size);                  //Testuje wydajnoœæ wyszukiwania elementu dla tablicy o 'rozm' elementach.
public:
    TestTablicy();                              //Konstruktor klasy.
    ~TestTablicy();                             //Destruktor klasy ArrayTest.
    void sredniTestDodawania();                      //Przeprowadza testy dodania dla zadanych wielkoœci struktury.
    void sredniTestUsuwania();                   //Przeprowadza testy usuniêcia dla zadanych wielkoœci struktury.
    void sredniTestSzukania();                     //Przeprowadza testy wyszukania dla zadanych wielkoœci struktury.
};