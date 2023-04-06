#pragma once
#include "../../Drzewa/DrzewoBST/DrzewoBST.h"
#include "../Pomiar.h"
#include <random>

class TestBST                                 //Klasa s³u¿¹ca do testowania wydajnoœci operacji na drzewie BST.
{
private:
    DrzewoBST* drzewo;                      //WskaŸnik na obiekt klasy kopca binarnego.
    Pomiar pomiar;                              //Obiekt klasy s³u¿acej do wykonywania pomiarów.
    void wypelnijDrzewo(int rozm);              //Wype³nia drzewo 'rozm' losowymi liczbami z przedzia³u [0, rozm - 1].
    double dodajTest(int rozm);                 //Testuje wydajnoœæ dodawania elementu dla kopca o 'rozm' elementach.
    double usunTest(int rozm);                  //Testuje wydajnoœæ usuwania elementu dla kopca o 'rozm' elementach.
    double znajdzTest(int rozm);                //Testuje wydajnoœæ wyszukiwania elementu dla kopca o 'rozm' elementach.
public:
    TestBST();
    ~TestBST();
    void sredniTestDodawania();                 //Przeprowadza testy dodania dla zdefiniowanych wielkoœci struktury.
    void sredniTestUsuwania();                  //Przeprowadza testy usuniêcia dla zdefiniowanych wielkoœci struktury.
    void sredniTestSzukania();                  //Przeprowadza testy wyszukania dla zdefiniowanych wielkoœci struktury.

};