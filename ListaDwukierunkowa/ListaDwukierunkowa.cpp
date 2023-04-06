#include "ListaDwukierunkowa.h"

using namespace std;

ListaDwukierunkowa::ListaDwukierunkowa()
{
    rozm = 0;                                                       //Ustawienie pocz�tkowej ilo�ci element�w listy. Wska�niki na poczatek oraz koniec pokazuj� NULL.
    poczatek = nullptr;
    koniec = nullptr;
}

ListaDwukierunkowa::~ListaDwukierunkowa()
{
    ElemListy* nast;                                                //Dealokacja pami�ci dla kolejnych element�w listy przechodz�c po niej od pocz�tku do ko�ca.
    while (poczatek != nullptr)
    {
        nast = poczatek->nast;
        delete poczatek;
        poczatek = nast;
    }
}

void ListaDwukierunkowa::dodajNaPocz(int elem)
{
    auto* nowyElem = new ElemListy();                               //Ustawienie danch nowego elementu.
    nowyElem->wartosc = elem;

    nowyElem->poprz = nullptr;                                      //Nowy element staje si� pocz�tkiem listy.
    nowyElem->nast = poczatek;
    poczatek = nowyElem;
    
    if (poczatek->nast != nullptr) poczatek->nast->poprz = nowyElem;    //Je�li w li�cie znajdowa� si� kolejny element to jego wska�nik 'poprz' zostaje ustawiony na nowy pocz�tek.
    else koniec = nowyElem;                                         //W przeciwnym wypadku koniec listy r�wnie� wskazuje na nowy element (tablica jednoelementowa).
    rozm++;
}

void ListaDwukierunkowa::dodajNaKon(int elem)
{
    auto* nowyElem = new ElemListy();                               //Ustawienie danych nowego elementu.
    nowyElem->wartosc = elem;

    nowyElem->nast = nullptr;                                       //Nowy element staje si� teraz ko�cem.
    nowyElem->poprz = koniec;
    koniec = nowyElem;
    if (koniec->poprz != nullptr) koniec->poprz->nast = nowyElem;   //Je�li w li�cie znajdowa� si� poprzedni element to jego wska�nik 'nast' zostaje zmieniony na nowy koniec listy.
    else poczatek = nowyElem;                                       //W przeciwnym wypadku pocz�tek listy r�wnie� wskazuje na nowy element (lista jednoelementowa).
    rozm++;
}

void ListaDwukierunkowa::dodajZa(int indeks, int elem)
{
    zakres(indeks);                                                 //Sprawdzenie poprawno�ci indeksu dla dodawanego elementu i ustawienie danych nowego elementu.
    auto* nowyElem = new ElemListy();
    nowyElem->wartosc = elem;


    ElemListy* poprzElem = zawartoscElem(indeks);                   //Znalezienie elementu, kt�ry poprzedza nowy.
    ElemListy* nastElem = nullptr;

    if (poprzElem == koniec || poprzElem == nullptr) dodajNaKon(elem);  //Je�li wybrany indeks jest ko�cem listy lub lista jest pusta, nast�puje wrzucenie go na koniec listy.
    else
    {
        nastElem = poprzElem->nast;                                 //Znalezienie elementu, kt�ry b�dzie nast�pnikiem nowego.
        poprzElem->nast = nowyElem;
        nastElem->poprz = nowyElem;

        nowyElem->nast = nastElem;                                  //Ustawienie odpowiednich wska�nik�w nowego elementu i zwi�kszenie rozmiaru listy.
        nowyElem->poprz = poprzElem;
        rozm++;
    }
}

void ListaDwukierunkowa::dodajLosowo(int elem)
{
    int indeks = rand() % (rozm + 1);
    if (indeks == 0) dodajNaPocz(elem);
    else dodajZa(indeks - 1, elem);
}

void ListaDwukierunkowa::usunZPocz()
{
    if (rozm != 0) usun(0);
    else throw length_error(EXCEPTION_LENGTH_DESC);
}

void ListaDwukierunkowa::usunZKon()
{
    if (rozm != 0) usun(rozm - 1);
    else throw length_error(EXCEPTION_LENGTH_DESC);
}

int ListaDwukierunkowa::zawartosc(int indeks)
{
    zakres(indeks);
    ElemListy* szukajElem = zawartoscElem(indeks);
    return szukajElem->wartosc;
}

bool ListaDwukierunkowa::znajdz(int elem)
{
    ElemListy* elemPorownawczy = poczatek;                          //Przeszukanie listy przechodz�c od pocz�tku do ko�ca w celu znalezienia zadanego elementu. Zwraca true - je�li element zostanie znaleziony.
    while (elemPorownawczy != nullptr)
    {
        if (elemPorownawczy->wartosc == elem) return true;
        elemPorownawczy = elemPorownawczy->nast;
    }
    return false;
}

bool ListaDwukierunkowa::usunWartosc(int elem)
{
    ElemListy* elemPorownawczy = poczatek;                          //Przeszukanie listy przechodz�c od pocz�tku do ko�ca w celu znalezienia, a nast�pnie usuni�cia zadanego elementu.
    int indeks = 0;
    while (elemPorownawczy != nullptr)
    {
        if (elemPorownawczy->wartosc == elem)
        {
            usun(indeks);
            return true;
        }
        elemPorownawczy = elemPorownawczy->nast;
        indeks++;
    }
    return false;
}

void ListaDwukierunkowa::usun(int indeks)
{

    zakres(indeks);                                             //Sprawdzenie czy indeks nie wybiega poza list� i znalezienie danego elementu.
    ElemListy* usunElem = zawartoscElem(indeks);
    if (usunElem->nast == nullptr) koniec = usunElem->poprz;    //Je�li element do usuni�cia jest ko�cem, ustawienie ko�ca na jego poprzednika.
    else usunElem->nast->poprz = usunElem->poprz;               //W przeciwnym wypadku ustawienie wska�nika 'poprz' nast�pnika usuwanego elementu na poprzednika usuwanego elementu.
    if (usunElem->poprz == nullptr) poczatek = usunElem->nast;  //Je�li element do usuni�cia jest pocz�tkiem, ustawienie pocz�tku na jego nast�pnika.
    else usunElem->poprz->nast = usunElem->nast;                //W przeciwnym wypadku ustawienie wska�nika 'nast' poprzednika usuwanego elementu na nast�pnika usuwanego elementu.
    rozm--;
    delete usunElem;                                            //Dealokacja pami�ci dla usuwanego elementu.
}

void ListaDwukierunkowa::usunLosowo()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, rozm);
    if (rozm > 0) usun(dist(gen));                          //Usuni�cie losowego elementu tablicy, je�li nie jest pusta.
}

void ListaDwukierunkowa::zakres(int indeks)
{

    if (indeks < 0 || indeks >(rozm - 1))                       //Je�li podany indeks jest mniejszy od zera lub wi�kszy od wielko�ci listy, rzucenie wyj�tku.
    throw out_of_range(EXCEPTION_RANGE_DESC);
}

ElemListy* ListaDwukierunkowa::zawartoscElem(int indeks)
{
    
    ElemListy* poczElem;                                        //Wyszukiwane elementu rozpoczyna si� od ustalenia czy znajduje si� on bli�ej pocz�tku lub ko�ca.
    int indeksRoboczy = 0;
    if ((rozm - 1) - indeks >= indeks)
    {
        poczElem = poczatek;                                    //Je�li element znajduje si� bli�ej pocz�tku, lista b�dzie przejrzana od pocz�tku do podanego indeksu.
        while (indeksRoboczy != indeks)
        {
            poczElem = poczElem->nast;
            indeksRoboczy++;
        }
    }
    else
    {
        poczElem = koniec;                                        //Je�li element znajduje si� bli�ej ko�ca, lista b�dzie przejrzana od ko�ca do podanego indeksu.
        indeksRoboczy = rozm - 1;
        while (indeksRoboczy != indeks)
        {
            poczElem = poczElem->poprz;
            indeksRoboczy--;
        }
    }
    return poczElem;
}

int ListaDwukierunkowa::rozmiar()
{
    return rozm;
}