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
        cout << "0 - wezel czerwony, 1- wezel czarny\n";
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
    // inicjujemy straznika
    if (rozm == 0)
    {
        straznik.kolor = true;
        straznik.rodzic = &straznik;
        straznik.lewy = &straznik;
        straznik.prawy = &straznik;
        korzen = &straznik;
    }

    ElemRB* wezel, * stryj;
    // Tworzymy nowy wezel
    wezel = new ElemRB;

    // Inicjujemy pola
    wezel->lewy = &straznik;
    wezel->prawy = &straznik;
    wezel->rodzic = korzen;
    wezel->number = number;

    // jezeli rodzic jest ustawiony na sentinel wezel wezel staje sie korzeniem
    if (wezel->rodzic == &straznik)
    {
        korzen = wezel;
    }
    else
    {
        while (true) // Szukamy liscia do zastspienia przez wezel
        {
            if (number < wezel->rodzic->number)
            {
                // jezeli jest lisciem
                if (wezel->rodzic->lewy == &straznik)
                {
                    // wezel zastepuje lewy lisc
                    wezel->rodzic->lewy = wezel;
                    break;
                }
                // lewy syn staje sie ojcem
                wezel->rodzic = wezel->rodzic->lewy;
            }
            else
            {
                // jezeli jest lisciem
                if (wezel->rodzic->prawy == &straznik)
                {
                    // wezel zastepuje prawy lisc
                    wezel->rodzic->prawy = wezel;
                    break;
                }
                // prawy syn staje sie ojcem
                wezel->rodzic = wezel->rodzic->prawy;
            }
        }

        // ustawiamy kolor wezla na czerwony
        wezel->kolor = false;

        // ustawianie kolorow w drzewie
        while ((wezel != korzen) && (wezel->rodzic->kolor == false))
        {
            // sprawdzamy czy ojciec jest lewym synem
            if (wezel->rodzic == wezel->rodzic->rodzic->lewy)
            {
                // stryj jest prawym bratem ojca wezel
                stryj = wezel->rodzic->rodzic->prawy;

                // przypadek 1
                //ojciec i wujek sa czerwoni
                if (stryj->kolor == false)
                {
                    wezel->rodzic->kolor = true;
                    stryj->kolor = true;
                    wezel->rodzic->rodzic->kolor = false;
                    wezel = wezel->rodzic->rodzic;
                    continue;
                }

                // przypadek 2
                //ojciec czerwony wujek czarny
                // sprawdzamy czy wezel jest prawym synem
                if (wezel == wezel->rodzic->prawy)
                {
                    wezel = wezel->rodzic;
                    rotacjaWLewo(wezel);
                    continue;
                }

                // przypadek 3
                //wujek czarny 
                //sprawdzamy czy wezel jest po lewej stronie
                wezel->rodzic->kolor = true;
                wezel->rodzic->rodzic->kolor = false;
                rotacjaWPrawo(wezel->rodzic->rodzic);
                break;
            }
            else
            {
                // przypadek analogiczny tylko z drugiej strony

                // stryj jest lewym bratem ojca
                stryj = wezel->rodzic->rodzic->lewy;

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

// analogicznie do rotacji w lewo
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
    // tworzymy pomocnicze zmienne do usuwania elementow
    ElemRB* X, * Y, * Z, * W;

    X = korzen;

    // znajdujemy odpowiedni wezel
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

    // jezeli ojciec jest straznikiem to oznacza to ze Y jest glowa
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

    // Naprawiamy strukture jesli wezel jest czarny
    if (Y->kolor == true)
    {

        while ((Z != korzen) && (Z->kolor == true))
        {
            //jezeli Z jest po lewej
            if (Z == Z->rodzic->lewy)
            {
                //ustawiamy W jako brata Z 
                W = Z->rodzic->prawy;

                //Rozpoatrzamy cztery rozne przypadki
                //kazdy przypadek to inne ustawienie wezlow

                //przypadek 1
                //brat wezla jest czerwony
                if (W->kolor == false)
                {
                    W->kolor = true;
                    Z->rodzic->kolor = false;
                    rotacjaWLewo(Z->rodzic);
                    W = Z->rodzic->prawy;
                }

                //przypadek 2
                //brat jest czarny i posiada dwojke czarnych synow
                if ((W->lewy->kolor == true) && (W->prawy->kolor == true))
                {

                    W->kolor = false;
                    Z = Z->rodzic;
                    continue;
                }

                //przypadek 3
                //brat jest czarny
                //lewy syn jest czerwony
                //prawy syn jest czarny
                if (W->prawy->kolor == true)
                {

                    W->lewy->kolor = true;
                    W->kolor = false;
                    rotacjaWPrawo(W);
                    W = Z->rodzic->prawy;
                }
                //przypadek 4
                //brat jest czarny
                //prawy syn jest czerwony
                W->kolor = Z->rodzic->kolor;
                Z->rodzic->kolor = true;
                W->prawy->kolor = true;
                rotacjaWLewo(Z->rodzic);
                Z = korzen; // To spowoduje zakoñczenie pêtli
            }
            else
            {
                // Przypadki lustrzane dla wezla po prawej stronie

                W = Z->rodzic->lewy;

                //przypadek 1
                //brat wezla jest czerwony
                if (W->kolor == false)
                {
                    W->kolor = true;
                    Z->rodzic->kolor = false;
                    rotacjaWPrawo(Z->rodzic);
                    W = Z->rodzic->lewy;
                }

                //przypadek 2
                //brat jest czarny i posiada dwojke czarnych synow
                if ((W->lewy->kolor == true) && (W->prawy->kolor == true))
                {
                    W->kolor = false;
                    Z = Z->rodzic;
                    continue;
                }

                //przypadek 3
                //brat jest czarny
                //lewy syn jest czerwony
                //prawy syn jest czarny
                if (W->lewy->kolor == true)
                {
                    W->prawy->kolor = true;
                    W->kolor = false;
                    rotacjaWLewo(W);
                    W = Z->rodzic->lewy;
                }

                //przypadek 4
                //brat jest czarny
                //prawy syn jest czerwony
                W->kolor = Z->rodzic->kolor;
                Z->rodzic->kolor = true;
                W->lewy->kolor = true;
                rotacjaWPrawo(Z->rodzic);

                // To spowoduje zakoñczenie pêtli
                Z = korzen;
            }
        }
    }

    Z->kolor = true;
    rozm--;
    delete Y;
}
void DrzewoRB::usunKorzen()
{
    usun(korzen->number);
}
void DrzewoRB::naprawDrzewo(ElemRB* X)
{
    ElemRB* wezel;

    while ((X != korzen) && (X->kolor == true))
    {

        if (X == X->rodzic->lewy)
        {
            wezel = X->rodzic->prawy;

            // przypadek 1
            if (wezel->kolor == false)
            {
                wezel->kolor = true;
                X->rodzic->kolor = false;
                rotacjaWLewo(X->rodzic);
                wezel = X->rodzic->prawy;
            }

            // przypadek 2
            if ((wezel->lewy->kolor == true) && (wezel->prawy->kolor == true))
            {
                wezel->kolor = false;
                X = X->rodzic;
                continue;
            }

            // przypadek 3
            if (wezel->prawy->kolor == true)
            {
                wezel->lewy->kolor = true;
                wezel->kolor = false;
                rotacjaWPrawo(wezel);
                wezel = X->rodzic->prawy;
            }

            // przypadek 4
            wezel->kolor = X->rodzic->kolor;
            X->rodzic->kolor = true;
            wezel->prawy->kolor = true;
            rotacjaWLewo(X->rodzic);
        }
        else
        {
            wezel = X->rodzic->lewy;

            // przypadek 1
            if (wezel->kolor == false)
            {
                wezel->kolor = true;
                X->rodzic->kolor = false;
                rotacjaWPrawo(X->rodzic);
                wezel = X->rodzic->lewy;
            }

            // przypadek 2
            if ((wezel->lewy->kolor == true) && (wezel->prawy->kolor == true))
            {
                wezel->kolor = false;
                X = X->rodzic;
                continue;
            }

            // przypadek 3
            if (wezel->lewy->kolor == true)
            {
                wezel->prawy->kolor = true;
                wezel->kolor = false;
                rotacjaWLewo(wezel);
                wezel = X->rodzic->lewy;
            }

            // przypadek 4
            wezel->kolor = X->rodzic->kolor;
            X->rodzic->kolor = true;
            wezel->lewy->kolor = true;
            rotacjaWPrawo(X->rodzic);
        }
        // warunek konczacy petle
        X = korzen;
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
    // tworzymy pomocnicz¹ zmienn¹
    ElemRB* r;

    // jezeli p nie jest straznikiem
    if (p != &straznik)
    {
        // jezeli prawy syn p nie jest straznikiem
        if (p->prawy == &straznik)
        {
            // r ustawiamy na ojca p
            r = p->rodzic;

            // dopoki r jest rozne od straznika i p == prawemu synowi r
            // przypisujemy r do p
            // przypisujemy do r ojca r
            // jezeli p jest lewym synem to konczymy
            while ((r != &straznik) && (p == r->prawy))
            {
                p = r;
                r = r->rodzic;
            }
            return r;
        }
        // zwracamy minimum
        return minimum(p->prawy);
    }
    // zwracamy puste
    return &straznik;
}
int DrzewoRB::znajdz(int number)
{
    // tworzymy pomocniczy element
    ElemRB* p;

    p = korzen;
    // iterujemy po kazdym elemencie
    // szukajac poprawnej wartosci
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
        return -1;
    }

    else
    {
        return 1;
    }
}