#include "../../ListaDwukierunkowa/ListaDwukierunkowa.h"
#include "../Pomiar.h"

//Klasa s�u��ca do testowania wydajno�ci operacji na li�cie.
class TestListy
{
private:

    ListaDwukierunkowa* lista;                  //Wska�nik na obiekt klasy listy
    Pomiar pomiar;                              //Obiekt klasy s�u��cej do wykonywania jednolitych pomiar�w.
    void wypelnijListe(int rozm);               //Wype�nia list� losowymi liczbami z przedzia�u. [0, rozm - 1]
    double dodajNaPoczTest(int rozm);           //Testuje wydajno�� dodawania elementu z przodu dla listy o 'rozm' elementach.
    double dodajNaKoniecTest(int rozm);         //Testuje wydajno�� dodawania elementu z ty�u dla listy o 'rozm' elementach.
    double dodajLosowoTest(int rozm);           //Testuje wydajno�� dodawania elementu w losowym miejscu dla listy o 'rozm' elementach.
    double usunNaPoczTest(int rozm);            //Testuje wydajno�� usuwania elementu z przodu dla listy o 'rozm' elementach.
    double usunNaKonTest(int rozm);             //Testuje wydajno�� usuwania elementu z ty�u dla listy o 'rozm' elementach.
    double usunLosowoTest(int rozm);            //Testuje wydajno�� usuwania elementu z losowego miejsca listy o 'rozm' elementach.
    double znajdzTest(int rozm);                //Testuje wydajno�� wyszukiwania elementu dla listy o 'rozm' elementach.
public:
    TestListy();                                //Konstruktor klasy TestListy.
    ~TestListy();                               //Destruktor klasy TestListy.
    void sredniTestDodawania();                 //Przeprowadza testy dodania dla zdefiniowanych wielko�ci struktury.
    void sredniTestUsuwania();                  //Przeprowadza testy usuni�cia dla zdefiniowanych wielko�ci struktury.
    void sredniTestSzukania();                  //Przeprowadza testy wyszukania dla zdefiniowanych wielko�ci struktury.
};