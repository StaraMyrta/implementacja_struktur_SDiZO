#pragma once
#include <iostream>
#include <string>
#include "ElemBST.h"

using namespace std;

class DrzewoBST {
private:
    string cr, cl, cp;
    ElemBST* korzen = nullptr;
    bool zawartoscElem(int wartosc, ElemBST* elemBiezacy);
    int n = 0;

    void dodajWMiejsce(ElemBST* wskaznik, int wartosc);
    void listaLiniowa();
    void rotujNRazy(int ileRotacji);
    void wyswietlDrzewo(string sp, string sn, ElemBST* v);
    void usunDrzewo(ElemBST* wskaznik);

public:
    DrzewoBST();
    ~DrzewoBST();
    void dodaj(int wartosc);      //Dodaje elementy do drzewa.
    void RotacjaWPrawo(ElemBST* wskaznik);
    void RotacjaWLewo(ElemBST* wskaznik);
    void zbalansujDrzewo();
    bool znajdz(int wartosc);
    ElemBST* zawartosc(int wartosc);
    void wyswietlDrzewo();
    void usunDrzewo();
    void usunKorzen();
};

