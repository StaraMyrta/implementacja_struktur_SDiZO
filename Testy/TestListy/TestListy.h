#include "../../ListaDwukierunkowa/ListaDwukierunkowa.h"
#include "../Pomiar.h"

//Klasa s³u¿¹ca do testowania wydajnoœci operacji na liœcie.
class TestListy
{
private:

    ListaDwukierunkowa* lista;                  //WskaŸnik na obiekt klasy listy
    Pomiar pomiar;                              //Obiekt klasy s³u¿¹cej do wykonywania jednolitych pomiarów.
    void wypelnijListe(int rozm);               //Wype³nia listê losowymi liczbami z przedzia³u. [0, rozm - 1]
    double dodajNaPoczTest(int rozm);           //Testuje wydajnoœæ dodawania elementu z przodu dla listy o 'rozm' elementach.
    double dodajNaKoniecTest(int rozm);         //Testuje wydajnoœæ dodawania elementu z ty³u dla listy o 'rozm' elementach.
    double dodajLosowoTest(int rozm);           //Testuje wydajnoœæ dodawania elementu w losowym miejscu dla listy o 'rozm' elementach.
    double usunNaPoczTest(int rozm);            //Testuje wydajnoœæ usuwania elementu z przodu dla listy o 'rozm' elementach.
    double usunNaKonTest(int rozm);             //Testuje wydajnoœæ usuwania elementu z ty³u dla listy o 'rozm' elementach.
    double usunLosowoTest(int rozm);            //Testuje wydajnoœæ usuwania elementu z losowego miejsca listy o 'rozm' elementach.
    double znajdzTest(int rozm);                //Testuje wydajnoœæ wyszukiwania elementu dla listy o 'rozm' elementach.
public:
    TestListy();                                //Konstruktor klasy TestListy.
    ~TestListy();                               //Destruktor klasy TestListy.
    void sredniTestDodawania();                 //Przeprowadza testy dodania dla zdefiniowanych wielkoœci struktury.
    void sredniTestUsuwania();                  //Przeprowadza testy usuniêcia dla zdefiniowanych wielkoœci struktury.
    void sredniTestSzukania();                  //Przeprowadza testy wyszukania dla zdefiniowanych wielkoœci struktury.
};