#pragma once
#include <iostream>
#include <string>
#include <random>
#include "ElemBST.h"

using namespace std;

class DrzewoBST {
private:
    string cr, cl, cp;
    ElemBST* korzen = nullptr;
    ElemBST* zawartoscElem(int wartosc, ElemBST* elemBiezacy);
    ElemBST* znajdzNastepnika(ElemBST* poprzednik);
    void usun(ElemBST* elemBiezacy, int wartosc);
    int rozm = 0;

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
    void usun(int wartosc);
    void usunLosowo();
};

