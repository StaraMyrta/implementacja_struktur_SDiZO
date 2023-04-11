#include <iostream>
#include "DrzewoBST.h"
#include <cmath>

using namespace std;

DrzewoBST::DrzewoBST()
{
    cr = cl = cp = "  ";
    cr[0] = 47;
    cl[0] = 92;
    cp[0] = 124;
}

DrzewoBST::~DrzewoBST()
{
    usunDrzewo();
}

void DrzewoBST::dodaj(int wartosc) {

    rozm++;
    if (korzen == nullptr)
        korzen = new ElemBST(wartosc);
    else
        dodajWMiejsce(korzen, wartosc);
}

ElemBST* DrzewoBST::zawartoscElem(int wartosc,ElemBST* elemBiezacy)
{
    if (elemBiezacy != nullptr)
    {
        if (wartosc == elemBiezacy->number)
        {
            return elemBiezacy;
        }
        else if (wartosc < elemBiezacy->number)
        {
            return zawartoscElem(wartosc, elemBiezacy->lewy);
        }
        else
        {
            return zawartoscElem(wartosc, elemBiezacy->prawy);
        }
    }
    return elemBiezacy;
}

//dodawnie na glebszych poziomach elementow do drzewa
void DrzewoBST::dodajWMiejsce(ElemBST* wskaznik, int wartosc) {

    if (wartosc >= wskaznik->number) {
        if (wskaznik->prawy == nullptr) {
            wskaznik->prawy = new ElemBST(wartosc);
            wskaznik->prawy->rodzic = wskaznik;
        }
        else
            dodajWMiejsce(wskaznik->prawy, wartosc);
    }
    else {
        if (wskaznik->lewy == nullptr) {
            wskaznik->lewy = new ElemBST(wartosc);
            wskaznik->lewy->rodzic = wskaznik;
        }
        else
            dodajWMiejsce(wskaznik->lewy, wartosc);
    }
}

//obrot wezla w prawo
void DrzewoBST::RotacjaWPrawo(ElemBST* wskaznik) {

    if (wskaznik != nullptr) {
        if (wskaznik->lewy != nullptr) {
            ElemBST* secondPointer = wskaznik->lewy;

            secondPointer->rodzic = wskaznik->rodzic;
            wskaznik->lewy = secondPointer->prawy;
            if (wskaznik->lewy != nullptr)
                wskaznik->lewy->rodzic = wskaznik;
            wskaznik->rodzic = secondPointer;
            secondPointer->prawy = wskaznik;

            if (wskaznik == korzen) {
                korzen = secondPointer;
            }
            else {
                if (secondPointer->rodzic->prawy == wskaznik)
                    secondPointer->rodzic->prawy = secondPointer;
                else
                    secondPointer->rodzic->lewy = secondPointer;
            }
        }
    }
}

//obrot wezla w lewo
void DrzewoBST::RotacjaWLewo(ElemBST* wskaznik) {

    if (wskaznik != nullptr) {
        if (wskaznik->prawy != nullptr) {
            ElemBST* secondPointer = wskaznik->prawy;

            secondPointer->rodzic = wskaznik->rodzic;
            wskaznik->prawy = secondPointer->lewy;
            if (wskaznik->prawy != nullptr)
                wskaznik->prawy->rodzic = wskaznik;
            wskaznik->rodzic = secondPointer;
            secondPointer->lewy = wskaznik;

            if (wskaznik == korzen) {
                korzen = secondPointer;
            }
            else {
                if (secondPointer->rodzic->prawy == wskaznik)
                    secondPointer->rodzic->prawy = secondPointer;
                else
                    secondPointer->rodzic->lewy = secondPointer;
            }
        }
    }
}

//rownowazenie drzewa
void DrzewoBST::zbalansujDrzewo() {

    if (rozm > 0) {
        listaLiniowa();                                         //tworzymy liste liniowa

        int ileRotacji = (int)(pow(2, (int)(log2(rozm + 1))) - 1); //obliczamy ilosc rotacji
        rotujNRazy(rozm - ileRotacji);

        while (ileRotacji > 1) {                                  //obracamy okreslona ilosc wezlow
            ileRotacji = (int)(ileRotacji / 2);
            rotujNRazy(ileRotacji);
        }
    }
}

//odpowiada za odpowiednia ilosc obrotow, aby mozna bylo zrownowazyc drzewo
void DrzewoBST::rotujNRazy(int ileRotacji) {

    ElemBST* wskaznik = korzen;

    for (int i = 0; i < ileRotacji; i++) {
        RotacjaWLewo(wskaznik);
        wskaznik = wskaznik->rodzic->prawy;
    }
}

//tworzenie listy liniowej
void DrzewoBST::listaLiniowa() {

    ElemBST* wskaznik = korzen;

    while (true) {
        if (wskaznik->lewy == nullptr && wskaznik->prawy == nullptr) {
            break;
        }
        else if (wskaznik->lewy != nullptr) {
            RotacjaWPrawo(wskaznik);
            wskaznik = wskaznik->rodzic;
        }
        else {
            wskaznik = wskaznik->prawy;
        }
    }
}

bool DrzewoBST::znajdz(int wartosc)
{
    if (zawartoscElem(wartosc, korzen))
    {
        return true;
    }
    return false;
}

//wyszukiwanie wezla z podana liczba
ElemBST* DrzewoBST::zawartosc(int wartosc) {
    if (korzen != nullptr) 
    {
        ElemBST* wskaznik = korzen;
        while (true) {
            if (wskaznik->number > wartosc) {
                if (wskaznik->lewy != nullptr)
                    wskaznik = wskaznik->lewy;
                else
                    return nullptr;
            }
            else if (wskaznik->number < wartosc) {
                if (wskaznik->prawy != nullptr)
                    wskaznik = wskaznik->prawy;
                else
                    return nullptr;
            }
            else
                return wskaznik;
        }
    }
    return nullptr;
}

//wyswietlanie drzewa
void DrzewoBST::wyswietlDrzewo(string sp, string sn, ElemBST* wskaznik) {

    string s;

    if (wskaznik) {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        wyswietlDrzewo(s + cp, cr, wskaznik->prawy);

        s = s.substr(0, sp.length() - 2);
        cout << s << sn << wskaznik->number << endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        wyswietlDrzewo(s + cp, cl, wskaznik->lewy);
    }
}

//wywolanie metody do wyswietlenia drzewa z parametrami wejsciowymi
void DrzewoBST::wyswietlDrzewo() 
{
    wyswietlDrzewo("", "", korzen);
}


ElemBST* DrzewoBST::znajdzNastepnika(ElemBST* poprzednik)
{
    ElemBST* elemRoboczy = poprzednik->prawy;
    if (elemRoboczy != nullptr)
    {
        while (elemRoboczy->lewy != nullptr)
        {
            elemRoboczy = elemRoboczy->lewy;
        }
        return elemRoboczy;
    }
    elemRoboczy = poprzednik->rodzic;
    while (elemRoboczy != nullptr && elemRoboczy->lewy != poprzednik)
    {
        poprzednik = elemRoboczy;
        elemRoboczy = elemRoboczy->rodzic;
    }
    return elemRoboczy;
}


void DrzewoBST::usun(ElemBST* elemBiezacy, int number) {
    if (elemBiezacy == nullptr) {
        return;
    }

    if (number < elemBiezacy->number) {
        usun(elemBiezacy->lewy, number);
    }
    else if (number > elemBiezacy->number) {
        usun(elemBiezacy->prawy, number);
    }
    else {
        if (elemBiezacy->lewy == nullptr && elemBiezacy->prawy == nullptr) {
            // Wezel bez dzieci
            if (elemBiezacy->rodzic != nullptr) {
                if (elemBiezacy == elemBiezacy->rodzic->lewy) {
                    elemBiezacy->rodzic->lewy = nullptr;
                }
                else {
                    elemBiezacy->rodzic->prawy = nullptr;
                }
            }
            delete elemBiezacy;
            elemBiezacy = nullptr;
        }
        else if (elemBiezacy->lewy == nullptr) {
            // Wezel ma tylko prawe dziecko
            if (elemBiezacy->rodzic != nullptr) {
                if (elemBiezacy == elemBiezacy->rodzic->lewy) {
                    elemBiezacy->rodzic->lewy = elemBiezacy->prawy;
                }
                else {
                    elemBiezacy->rodzic->prawy = elemBiezacy->prawy;
                }
            }
            elemBiezacy->prawy->rodzic = elemBiezacy->rodzic;
            delete elemBiezacy;
            elemBiezacy = nullptr;
        }
        else if (elemBiezacy->prawy == nullptr) {
            // Wezel ma tylko lewe dziecko
            if (elemBiezacy->rodzic != nullptr) {
                if (elemBiezacy == elemBiezacy->rodzic->lewy) {
                    elemBiezacy->rodzic->lewy = elemBiezacy->lewy;
                }
                else {
                    elemBiezacy->rodzic->prawy = elemBiezacy->lewy;
                }
            }
            elemBiezacy->lewy->rodzic = elemBiezacy->rodzic;
            delete elemBiezacy;
            elemBiezacy = nullptr;
        }
        else {
            // Wezel ma dwoje dzieci
            ElemBST* nastepnik = elemBiezacy->prawy;
            while (nastepnik->lewy != nullptr) {
                nastepnik = nastepnik->lewy;
            }
            elemBiezacy->number = nastepnik->number;
            usun(elemBiezacy->prawy, nastepnik->number);
        }
    }
}

void DrzewoBST::usun(int wartosc)
{
    usun(korzen, wartosc);
}

void DrzewoBST::usunLosowo()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, rozm);
    usun(dist(gen));
}

//usuwanie calego drzewa
void DrzewoBST::usunDrzewo(ElemBST* wskaznik) {

    if (wskaznik) {
        usunDrzewo(wskaznik->lewy);
        usunDrzewo(wskaznik->prawy);
        delete wskaznik;
    }
    korzen = nullptr;
    rozm = 0;
}

//wywolanie metody usuwania drzewa z parametrem
void DrzewoBST::usunDrzewo() {
    usunDrzewo(korzen);
}