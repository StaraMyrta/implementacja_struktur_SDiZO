#include "../../KopiecBinarny/KopiecBinarny.h"
#include "../Pomiar.h"

class TestKopca                                 //Klasa s�u��ca do testowania wydajno�ci operacji na kopcu binarnym.
{
private:
    KopiecBinarny* kopiec;                      //Wska�nik na obiekt klasy kopca binarnego.
    Pomiar pomiar;                              //Obiekt klasy s�u�acej do wykonywania pomiar�w.
    void wypelnijKopiec(int rozm);              //Wype�nia kopiec 'rozm' losowymi liczbami z przedzia�u [0, rozm - 1].
    double dodajTest(int rozm);                 //Testuje wydajno�� dodawania elementu dla kopca o 'rozm' elementach.
    double usunTest(int rozm);                  //Testuje wydajno�� usuwania elementu dla kopca o 'rozm' elementach.
    double znajdzTest(int rozm);                //Testuje wydajno�� wyszukiwania elementu dla kopca o 'rozm' elementach.
public:
    TestKopca();
    ~TestKopca();
    void sredniTestDodawania();                 //Przeprowadza testy dodania dla zdefiniowanych wielko�ci struktury.
    void sredniTestUsuwania();                  //Przeprowadza testy usuni�cia dla zdefiniowanych wielko�ci struktury.
    void sredniTestSzukania();                  //Przeprowadza testy wyszukania dla zdefiniowanych wielko�ci struktury.

};