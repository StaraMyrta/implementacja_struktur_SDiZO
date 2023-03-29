#include "../../TablicaDynamiczna/TablicaDynamiczna.h"
//#include "../Measurement.h"

//Klasa s�u��ca do testowania wydajno�ci operacji na tablicy.
class TestTablicy
{
private:
    TablicaDynamiczna* tablica;                 //Wska�nik na obiekt klasy tablicy.
    //Measurement measurement;                  //Obiekt klasy s�u�acej do wykonywania pomiar�w.
    void wypelnijTablice(int rozm);             //Wype�nia tablic� losowymi liczbami z przedzia�u [0, rozm - 1].

    double dodajNaPoczTest(int rozm);           //Testuje wydajno�� dodawania elementu z przodu dla tablicy o 'rozm' elementach.
    double dodajNaKoniecTest(int rozm);         //Testuje wydajno�� dodawania elementu z ty�u dla tablicy o 'rozm' elementach.
    double dodajLosowoTest(int rozm);           //Testuje wydajno�� dodawania elementu w losowym miejscu dla tablicy o 'rozm' elementach.
    double usunNaPoczTest(int rozm);            //Testuje wydajno�� usuwania elementu z przodu dla tablicy o 'rozm' elementach.
    double usunNaKonTest(int rozm);             //Testuje wydajno�� usuwania elementu z ty�u dla tablicy o 'rozm' elementach.
    double usunLosowoTest(int rozm);            //Testuje wydajno�� usuwania elementu z losowego miejsca tablicy o 'rozm' elementach.
    double znajdzTest(int size);                  //Testuje wydajno�� wyszukiwania elementu dla tablicy o 'rozm' elementach.
public:
    TestTablicy();                              //Konstruktor klasy.
    ~TestTablicy();                             //Destruktor klasy ArrayTest.
    void sredniTestDodawania();                      //Przeprowadza testy dodania dla zadanych wielko�ci struktury.
    void sredniTestUsuwania();                   //Przeprowadza testy usuni�cia dla zadanych wielko�ci struktury.
    void sredniTestSzukania();                     //Przeprowadza testy wyszukania dla zadanych wielko�ci struktury.
};