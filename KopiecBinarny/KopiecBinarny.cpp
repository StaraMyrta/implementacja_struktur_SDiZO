#include "KopiecBinarny.h"

KopiecBinarny::KopiecBinarny()
{
    rozm = START_SPACE;                                 //Ustawienie rozmiaru tablicy na rozmiar początkowy.
    wierzcholki = 0;
    baza = new int[START_SPACE];
}

KopiecBinarny::~KopiecBinarny()
{
    delete[] baza;                                  //Dealokacja tablicy.

}

void KopiecBinarny::dodaj(int elem)
{
    int indeks = wierzcholki;                           //Zapamiętanie indeksu dla następnego pustego miejsca w tablicy.
    wierzcholki++;
    if (rozm - wierzcholki < MIN_FREE_SPACE)            //Jeśli rozmiar tablicy przekracza minimalny, zostaje ona rozszerzona.
    {
        int* tablicaRobocza = new int[wierzcholki];    //Kopiowanie zawartości tablicy do bufora, alokacja nowego rozmiaru i przywrócenie elementów.
        kopiujTablice(baza, tablicaRobocza, wierzcholki - 1);
        delete[] baza;
        rozm += START_SPACE;
        baza = new int[rozm];
        kopiujTablice(tablicaRobocza, baza, wierzcholki - 1);
        delete[] tablicaRobocza;
    }
    naprawKopiecGora(indeks, elem);
}

int KopiecBinarny::usunKorzen()
{
    if (wierzcholki == 0) throw std::length_error(EXCEPTION_LENGTH_DESC);    //Jeśli kopiec jest pusty rzucony zostaje wyjątek.
    if (rozm - wierzcholki > MAX_FREE_SPACE)            //Jeśli rozmiar tablicy jest większy niż maksymalny, zostaje zmniejszona.
    {
        int* tablicaRobocza = new int[wierzcholki];    //Zawartość tablicy zostaje skopiowana do bufora, następnie alokowany zostaje nowy rozmiar z przywróceniem elementów.
        kopiujTablice(baza, tablicaRobocza, wierzcholki);
        delete[] baza;
        rozm -= START_SPACE;
        baza = new int[rozm];
        kopiujTablice(tablicaRobocza, baza, wierzcholki);
        delete[] tablicaRobocza;
    }
    wierzcholki--;
    int ostatniWierzcholek = baza[wierzcholki];                 //Zapamiętany zostaje indeks ostatniego wierzchołka oraz wartość korzenia.
    int wartoscKorzenia = baza[0];
    naprawKopiecDol(0, ostatniWierzcholek);
    return wartoscKorzenia;
}

bool KopiecBinarny::usun(int elem)
{
    int usunIndeks = znajdzIndeks(elem);                //Znalezienie indeksu elementu do usunięcia.

    if (usunIndeks == -1) return false;                 //Jeśli element nie został znaleziony, operacja zostaje zakończona.
    else if (usunIndeks == 0)                           //Jeśli element jest korzeniem, usuwamy korzeń.
    {
        usunKorzen();
        return true;
    }
    if (rozm - wierzcholki > MAX_FREE_SPACE)            //Jeśli rozmiar tablicy jest większy niż maksymalny, zostaje zmniejszona.
    {
        int* tablicaRobocza = new int[wierzcholki];    //Zawartość tablicy zostaje przekopiowana do bufora, następnie alokowany zostaje nowy rozmiar z przywróceniem elementów.
        kopiujTablice(baza, tablicaRobocza, wierzcholki);
        delete[] baza;
        rozm -= START_SPACE;
        baza = new int[rozm];
        kopiujTablice(tablicaRobocza, baza, wierzcholki);
        delete[] tablicaRobocza;
    }
    wierzcholki--;
    int ostatniWierzcholek = baza[wierzcholki];
    int rodzic = baza[(usunIndeks - 1) / 2];
    if (ostatniWierzcholek < rodzic) naprawKopiecDol(usunIndeks, ostatniWierzcholek);    //Jeśli wartość ostatniego liścia jest mniejsza od rodzica drzewo zostaje naprawione w dół. Jeśli nie drzewo zostaje naprawione w górę
    else naprawKopiecGora(usunIndeks, ostatniWierzcholek);
    return true;
}

bool KopiecBinarny::znajdz(int elem)
{
    for (int i = 0; i < wierzcholki; i++)    //Cała tablica zostaje przejrzana. Jeśli element zostanie znaleziony funkcja zwraca true.
    {
        if (baza[i] == elem) return true;
    }
    return false;
}

int KopiecBinarny::zawartosc(int indeks)
{
    if (indeks < 0 || indeks > wierzcholki - 1) throw std::out_of_range(EXCEPTION_DESC);
    return baza[indeks];
}

void KopiecBinarny::naprawKopiecGora(int indeks, int ostatniWierzcholek)
{
    int indeksRodzica = (indeks - 1) / 2;    //Obliczenie wartości indeksu rodzica dla nowego liścia.
    while (indeks > 0 && baza[indeksRodzica] < ostatniWierzcholek)    //Dopóki nie będzie spełniony warunek kopca potomek zostaje zmieniony z jego rodzicem.
    {
        baza[indeks] = baza[indeksRodzica];
        indeks = indeksRodzica;
        indeksRodzica = (indeks - 1) / 2;
    }
    baza[indeks] = ostatniWierzcholek;
}

void KopiecBinarny::naprawKopiecDol(int indeks, int ostatniWierzcholek)
{
    int wiekszyPotomek = 2 * indeks + 1;    //Zmienna indeks przechowuje indeks rodzica dla algorytmu naprawy drzewa od góry.
    //Kopiec zostaje przejrzany w dół przez wybieranie większego potomka. Jeśli nie ma moliwości znalezienia takiego przypadku pętla zostaje przerwana (warunek kopca zachowany). 
    //W przeciwym wypadku rodzic z większym potomkiem zostają zamienieni miejscami a proces powtarza się.
    while (wiekszyPotomek < wierzcholki)
    {
        if (wiekszyPotomek + 1 < wierzcholki && baza[wiekszyPotomek] < baza[wiekszyPotomek + 1]) wiekszyPotomek++;
        if (ostatniWierzcholek >= baza[wiekszyPotomek]) break;
        baza[indeks] = baza[wiekszyPotomek];
        indeks = wiekszyPotomek;
        wiekszyPotomek = 2 * wiekszyPotomek + 1;
    }
    baza[indeks] = ostatniWierzcholek;      //Ustawienie wartości wyliczonego wierzchołka na ostatni wierzchołek kopca przed usunięciem korzenia.
}

int KopiecBinarny::znajdzIndeks(int elem)
{
    for (int i = 0; i < wierzcholki; i++)
    {
        if (baza[i] == elem) return i;
    }
    return -1;
}

void KopiecBinarny::kopiujTablice(int* skad, int* dokad, int rozm)
{
    for (int i = 0; i < rozm; i++) dokad[i] = skad[i];    //Skopiowanie 'rozm' elementów z tablicy do tablicy.
}

void KopiecBinarny::wyswietlDrzewo(string sp, string sn, int wierzcholek)
{
    string cr, cl, cp;                                    //Stałe przechowujące specjalne zanki ascii potrzebne do wyświetlania kopca.
    //218 = ┌   192 = └     196 = ─    179 = | 

    cl[0] = 192;    cl[1] = 196;
    cr[0] = 218;    cr[1] = 196;
    cp[0] = 179;

    string s;

    if (wierzcholek < n)
    {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        wyswietlDrzewo(s + cp, cr, 2 * wierzcholek + 2);

        s = s.substr(0, sp.length() - 2);

        cout << s << sn << baza[wierzcholek] << endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        wyswietlDrzewo(s + cp, cl, 2 * wierzcholek + 1);
    }
}

int KopiecBinarny::ileWierzcholkow()
{
    return wierzcholki;
}