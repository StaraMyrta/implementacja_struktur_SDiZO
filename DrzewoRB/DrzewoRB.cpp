#include "DrzewoRB.h"
using namespace std;

DrzewoRB::DrzewoRB() {
    rozm = 0;
    cr = cl = cp = "  ";
    cr[0] = 47;
    cl[0] = 92;
    cp[0] = 124;
}

DrzewoRB::~DrzewoRB() {

}

void DrzewoRB::wyswietlDrzewo(string sp, string sn, ElemRB* p)
{

    if (rozm == 0) {
        cout << ("DrzewoRB is empty");
    }
    else
    {
        string t;

        if (p != &straznik)
        {
            t = sp;
            if (sn == cr)
                t[t.length() - 2] = ' ';
            wyswietlDrzewo(t + cp, cr, p->prawy);
            t = t.substr(0, sp.length() - 2);
            cout << t << sn << p->kolor << ":" << p->number << endl;

            t = sp;
            if (sn == cl)
                t[t.length() - 2] = ' ';
            wyswietlDrzewo(t + cp, cl, p->lewy);
        }
    }
}
void DrzewoRB::wyswietlDrzewo()
{
    wyswietlDrzewo("", "", korzen);
}
void DrzewoRB::dodaj(int number)
{
    if (rozm == 0)                              //Inicjacia stra¿nika.
    {
        straznik.kolor = true;
        straznik.rodzic = &straznik;
        straznik.lewy = &straznik;
        straznik.prawy = &straznik;
        korzen = &straznik;
    }

    ElemRB* wezel, * stryj;
    wezel = new ElemRB;

    wezel->lewy = &straznik;                    //Inicjacja pól.
    wezel->prawy = &straznik;
    wezel->rodzic = korzen;
    wezel->number = number;

    if (wezel->rodzic == &straznik)             //Je¿eli rodzic jest ustawiony na stra¿nika wêze³ staje siê korzeniem.
    {
        korzen = wezel;
    }
    else
    {
        while (true)                            //Poszukiwanie liœcia do zast¹pienia przez wêze³.
        {
            if (number < wezel->rodzic->number)
            {
                if (wezel->rodzic->lewy == &straznik)                //Je¿eli jest lewym potomkiem wêze³ zastêpuje lewy liœæ.
                {
                    wezel->rodzic->lewy = wezel;
                    break;
                }

                wezel->rodzic = wezel->rodzic->lewy;                //Jeœli rodzic ma ju¿ lewego potomka wêze³ dodawany schodzi o poziom ni¿ej.
            }
            else
            {
                if (wezel->rodzic->prawy == &straznik)              //Analogicznie rozpatrywana jest opcja z prawym potomkiem.
                {
                    wezel->rodzic->prawy = wezel;
                    break;
                }
                wezel->rodzic = wezel->rodzic->prawy;
            }
        }
        wezel->kolor = false;

        naprawDrzewo(wezel);
        
    }
    korzen->kolor = true;
    rozm++;
}
void DrzewoRB::rotacjaWLewo(ElemRB* A)
{
    // tworzymy pomocnicze wezly
    ElemRB* B, * p;

    // ustawiamy wezel na prawego syna A
    B = A->prawy;
    if (B != &straznik)
    {
        // p ustawiamy na ojca
        p = A->rodzic;

        // ustawiamy wartosc prawego syna a
        A->prawy = B->lewy;

        // ustawiamy dziecku wskaznik na ojca
        if (A->prawy != &straznik)
        {
            A->prawy->rodzic = A;
        }

        // ustawiamy pozostale wartosci
        B->lewy = A;
        B->rodzic = p;
        A->rodzic = B;

        // jezeli p nie jest lisciem
        if (p != &straznik)
        {
            // ustawiamy wartosci
            if (p->lewy == A)
            {
                p->lewy = B;
            }

            else
            {
                p->prawy = B;
            }
        }
        else {
            korzen = B;
        }

    }
}
//Analogicznie do rotacji w lewo.
void DrzewoRB::rotacjaWPrawo(ElemRB* A)
{
    ElemRB* B, * p;
    B = A->lewy;
    if (B != &straznik)
    {
        p = A->rodzic;
        A->lewy = B->prawy;

        if (A->lewy != &straznik)
        {
            A->lewy->rodzic = A;
        }

        B->prawy = A;
        B->rodzic = p;
        A->rodzic = B;

        if (p != &straznik)
        {
            if (p->lewy == A)
            {
                p->lewy = B;
            }

            else
            {
                p->prawy = B;
            }
        }
        else
            korzen = B;
    }
}
void DrzewoRB::usun(int number)
{
    if (rozm == 0) {
        return;
    }
    ElemRB* X, * Y, * Z, * W;

    X = korzen;

    //Znalezienie wêz³a
    while ((X != &straznik) && (X->number != number))
    {
        if (number < X->number)
        {
            X = X->lewy;
        }

        else
        {
            X = X->prawy;
        }
    }

    // jezeli nie udalo sie znalezc wezla to wychodzimy
    if (X == &straznik)
    {
        return;
    }
    // jezeli korzen nie ma zadnych synow to przypisujemy Y X
    if ((X->lewy == &straznik) || (X->prawy == &straznik))
    {
        Y = X;
    }
    // w innym wypadku ustawiamy Y jako nastepnika dla X
    else
    {
        Y = nastepnik(X);
    }

    // jezeli Y ma lewego syna to przypisujemy do Z ten adres
    if (Y->lewy != &straznik)
    {
        Z = Y->lewy;
    }
    // w innym wypadku przypisujemy prawego syna do Z
    else
    {
        Z = Y->prawy;
    }
    // ustawiamy Z tego samego ojca co Y
    Z->rodzic = Y->rodzic;

    // jezeli rodzic jest straznikiem to oznacza to ze Y jest glowa
    // przypisujemy do korzenia Z
    if (Y->rodzic == &straznik)
    {
        korzen = Z;
    }
    // ustawiamy lewego syna jako Z
    else if (Y == Y->rodzic->lewy)
    {
        Y->rodzic->lewy = Z;
    }
    // ustawiamy prawego syna jako Z
    else
    {
        Y->rodzic->prawy = Z;
    }

    // przypisujemy wartosci
    if (Y != X)
    {
        X->number = Y->number;
    }

    naprawDrzewo(Y);

    Z->kolor = true;
    rozm--;
    delete Y;
}
void DrzewoRB::usunKorzen()
{
    usun(korzen->number);
}
void DrzewoRB::naprawDrzewo(ElemRB* wezel)
{
    ElemRB* stryj;

    while ((wezel != korzen) && (wezel->rodzic->kolor == false))        //Ustawianie kolorow w drzewie, kiedy rodzic jest czerwony.
    {
        //Jeœli rodzic jest lewym synem
        if (wezel->rodzic == wezel->rodzic->rodzic->lewy)
        {
            stryj = wezel->rodzic->rodzic->prawy;

            //przypadek 1
            //Rodzic i stryj s¹ czerwoni.
            if (stryj->kolor == false)
            {
                wezel->rodzic->kolor = true;
                stryj->kolor = true;
                wezel->rodzic->rodzic->kolor = false;
                wezel = wezel->rodzic->rodzic;
                continue;
            }

            //przypadek 2
            //Rodzic czerwony, a stryj czarny.
            //Sprawdzenie po³o¿enia wêz³a (opca prawy syn).
            if (wezel == wezel->rodzic->prawy)
            {
                wezel = wezel->rodzic;
                rotacjaWLewo(wezel);
                continue;
            }

            // przypadek 3
            //Rodzic czerwony, a stryj czarny.
            //Sprawdzenie po³o¿enia wêz³a (opca lewy syn).
            wezel->rodzic->kolor = true;
            wezel->rodzic->rodzic->kolor = false;
            rotacjaWPrawo(wezel->rodzic->rodzic);
            break;
        }
        else
        {
            stryj = wezel->rodzic->rodzic->lewy;            //Analogicznie, gdzy rodzic jest czarny.

            // przypadek 1
            if (stryj->kolor == false)
            {
                wezel->rodzic->kolor = true;
                stryj->kolor = true;
                wezel->rodzic->rodzic->kolor = false;
                wezel = wezel->rodzic->rodzic;
                continue;
            }

            // przypadek 2
            if (wezel == wezel->rodzic->lewy)
            {
                wezel = wezel->rodzic;
                rotacjaWPrawo(wezel);
            }

            // przypadek 3
            wezel->rodzic->kolor = true;
            wezel->rodzic->rodzic->kolor = false;
            rotacjaWLewo(wezel->rodzic->rodzic);
            break;
        }
    }
}
ElemRB* DrzewoRB::minimum(ElemRB* p)
{
    if (p != &straznik)
        while (p->lewy != &straznik) {
            p = p->lewy;
        }

    return p;
}
ElemRB* DrzewoRB::nastepnik(ElemRB* p)
{
    ElemRB* r;

    if (p != &straznik)
    {
        if (p->prawy == &straznik)
        {
            r = p->rodzic;

            while ((r != &straznik) && (p == r->prawy))
            {
                p = r;
                r = r->rodzic;
            }
            return r;
        }
        return minimum(p->prawy);
    }
    return &straznik;
}
bool DrzewoRB::znajdz(int number)
{
    ElemRB* p;

    p = korzen;

    while ((p != &straznik) && (p->number != number))
        if (number < p->number)
        {
            p = p->lewy;
        }

        else
        {
            p = p->prawy;
        }

    if (p == &straznik)
    {
        return false;
    }

    else
    {
        return true;
    }
}