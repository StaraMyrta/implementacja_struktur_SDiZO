#pragma once
#include "../../Drzewa/DrzewoBST/DrzewoBST.h"
#include "../Pomiar.h"
#include <random>

class TestBST                                 //Klasa s�u��ca do testowania wydajno�ci operacji na drzewie BST.
{
private:
    DrzewoBST* drzewo;                      //Wska�nik na obiekt klasy kopca binarnego.
    Pomiar pomiar;                              //Obiekt klasy s�u�acej do wykonywania pomiar�w.
    void wypelnijDrzewo(int rozm);              //Wype�nia drzewo 'rozm' losowymi liczbami z przedzia�u [0, rozm - 1].
    double dodajTest(int rozm);                 //Testuje wydajno�� dodawania elementu dla kopca o 'rozm' elementach.
    double usunTest(int rozm);                  //Testuje wydajno�� usuwania elementu dla kopca o 'rozm' elementach.
    double znajdzTest(int rozm);                //Testuje wydajno�� wyszukiwania elementu dla kopca o 'rozm' elementach.
public:
    TestBST();
    ~TestBST();
    void sredniTestDodawania();                 //Przeprowadza testy dodania dla zdefiniowanych wielko�ci struktury.
    void sredniTestUsuwania();                  //Przeprowadza testy usuni�cia dla zdefiniowanych wielko�ci struktury.
    void sredniTestSzukania();                  //Przeprowadza testy wyszukania dla zdefiniowanych wielko�ci struktury.

};