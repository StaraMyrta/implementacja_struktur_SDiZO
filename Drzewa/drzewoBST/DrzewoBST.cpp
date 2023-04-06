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

    n++;
    if (korzen == nullptr)
        korzen = new ElemBST(wartosc);
    else
        dodajWMiejsce(korzen, wartosc);
}

bool DrzewoBST::zawartoscElem(int wartosc,ElemBST* elemBiezacy)
{
    if (elemBiezacy != nullptr)
    {
        if (wartosc == elemBiezacy->number)
        {
            return true;
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
    return false;
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

    if (n > 0) {
        listaLiniowa();                                         //tworzymy liste liniowa

        int ileRotacji = (int)(pow(2, (int)(log2(n + 1))) - 1); //obliczamy ilosc rotacji
        rotujNRazy(n - ileRotacji);

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

//usuwanie wezla z drzewa
void DrzewoBST::usunKorzen() 
{

    if (korzen != nullptr) 
    {
        n--;
        //usuwanie korzenia, który jest jedynym elementem drzewa
        if (korzen->lewy == nullptr && korzen->prawy == nullptr) 
        {
            korzen = nullptr;
        }
        //usuwanie korzenia, który ma tylko prawego syna
        else if (korzen->lewy == nullptr) 
        {
            korzen->prawy->rodzic = nullptr;
            korzen = korzen->prawy;
            //usuwanie korzen, który ma tylko lewego syna
        }
        else if (korzen->prawy == nullptr) 
        {
            korzen->lewy->rodzic = nullptr;
            korzen = korzen->lewy;
        }

            //usuwanie korzen, który ma dwóch synów
        else {
            ElemBST* secondPointer = korzen->prawy;
            while (secondPointer->lewy != nullptr) 
            {
                secondPointer = secondPointer->lewy;
            }
            if (korzen->prawy == secondPointer) 
            {
                korzen->prawy = secondPointer->prawy;
                if (secondPointer->prawy != nullptr)     secondPointer->prawy->rodzic = korzen;
            }
            else {
                if (secondPointer->prawy == nullptr) 
                {
                    secondPointer->rodzic->lewy = nullptr;
                }
                else 
                {
                    secondPointer->prawy->rodzic = secondPointer->rodzic;
                    secondPointer->rodzic->lewy = secondPointer->prawy;
                }
            }
            korzen->number = secondPointer->number;

            delete secondPointer;
        }
    }
    else cout << "Brak elementu do usuniecia" << endl;
}

//usuwanie calego drzewa
void DrzewoBST::usunDrzewo(ElemBST* wskaznik) {

    if (wskaznik) {
        usunDrzewo(wskaznik->lewy);
        usunDrzewo(wskaznik->prawy);
        delete wskaznik;
    }
    korzen = nullptr;
    n = 0;
}

//wywolanie metody usuwania drzewa z parametrem
void DrzewoBST::usunDrzewo() {
    usunDrzewo(korzen);
}