#include "ListaDwukierunkowa.h"

using namespace std;

ListaDwukierunkowa::ListaDwukierunkowa()
{
    rozm = 0;                                                       //Ustawienie pocz¹tkowej iloœci elementów listy. WskaŸniki na poczatek oraz koniec pokazuj¹ NULL.
    poczatek = nullptr;
    koniec = nullptr;
}

ListaDwukierunkowa::~ListaDwukierunkowa()
{
    ElemListy* nast;                                                //Dealokacja pamiêci dla kolejnych elementów listy przechodz¹c po niej od pocz¹tku do koñca.
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

    nowyElem->poprz = nullptr;                                      //Nowy element staje siê pocz¹tkiem listy.
    nowyElem->nast = poczatek;
    poczatek = nowyElem;
    
    if (poczatek->nast != nullptr) poczatek->nast->poprz = nowyElem;    //Jeœli w liœcie znajdowa³ siê kolejny element to jego wskaŸnik 'poprz' zostaje ustawiony na nowy pocz¹tek.
    else koniec = nowyElem;                                         //W przeciwnym wypadku koniec listy równie¿ wskazuje na nowy element (tablica jednoelementowa).
    rozm++;
}

void ListaDwukierunkowa::dodajNaKon(int elem)
{
    auto* nowyElem = new ElemListy();                               //Ustawienie danych nowego elementu.
    nowyElem->wartosc = elem;

    nowyElem->nast = nullptr;                                       //Nowy element staje siê teraz koñcem.
    nowyElem->poprz = koniec;
    koniec = nowyElem;
    if (koniec->poprz != nullptr) koniec->poprz->nast = nowyElem;   //Jeœli w liœcie znajdowa³ siê poprzedni element to jego wskaŸnik 'nast' zostaje zmieniony na nowy koniec listy.
    else poczatek = nowyElem;                                       //W przeciwnym wypadku pocz¹tek listy równie¿ wskazuje na nowy element (lista jednoelementowa).
    rozm++;
}

void ListaDwukierunkowa::dodajZa(int indeks, int elem)
{
    zakres(indeks);                                                 //Sprawdzenie poprawnoœci indeksu dla dodawanego elementu i ustawienie danych nowego elementu.
    auto* nowyElem = new ElemListy();
    nowyElem->wartosc = elem;


    ElemListy* poprzElem = zawartoscElem(indeks);                   //Znalezienie elementu, który poprzedza nowy.
    ElemListy* nastElem = nullptr;

    if (poprzElem == koniec || poprzElem == nullptr) dodajNaKon(elem);  //Jeœli wybrany indeks jest koñcem listy lub lista jest pusta, nastêpuje wrzucenie go na koniec listy.
    else
    {
        nastElem = poprzElem->nast;                                 //Znalezienie elementu, który bêdzie nastêpnikiem nowego.
        poprzElem->nast = nowyElem;
        nastElem->poprz = nowyElem;

        nowyElem->nast = nastElem;                                  //Ustawienie odpowiednich wskaŸników nowego elementu i zwiêkszenie rozmiaru listy.
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
    ElemListy* elemPorownawczy = poczatek;                          //Przeszukanie listy przechodz¹c od pocz¹tku do koñca w celu znalezienia zadanego elementu. Zwraca true - jeœli element zostanie znaleziony.
    while (elemPorownawczy != nullptr)
    {
        if (elemPorownawczy->wartosc == elem) return true;
        elemPorownawczy = elemPorownawczy->nast;
    }
    return false;
}

bool ListaDwukierunkowa::usunWartosc(int elem)
{
    ElemListy* elemPorownawczy = poczatek;                          //Przeszukanie listy przechodz¹c od pocz¹tku do koñca w celu znalezienia, a nastêpnie usuniêcia zadanego elementu.
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

    zakres(indeks);                                             //Sprawdzenie czy indeks nie wybiega poza listê i znalezienie danego elementu.
    ElemListy* usunElem = zawartoscElem(indeks);
    if (usunElem->nast == nullptr) koniec = usunElem->poprz;    //Jeœli element do usuniêcia jest koñcem, ustawienie koñca na jego poprzednika.
    else usunElem->nast->poprz = usunElem->poprz;               //W przeciwnym wypadku ustawienie wskaŸnika 'poprz' nastêpnika usuwanego elementu na poprzednika usuwanego elementu.
    if (usunElem->poprz == nullptr) poczatek = usunElem->nast;  //Jeœli element do usuniêcia jest pocz¹tkiem, ustawienie pocz¹tku na jego nastêpnika.
    else usunElem->poprz->nast = usunElem->nast;                //W przeciwnym wypadku ustawienie wskaŸnika 'nast' poprzednika usuwanego elementu na nastêpnika usuwanego elementu.
    rozm--;
    delete usunElem;                                            //Dealokacja pamiêci dla usuwanego elementu.
}

void ListaDwukierunkowa::usunLosowo()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, rozm);
    if (rozm > 0) usun(dist(gen));                          //Usuniêcie losowego elementu tablicy, jeœli nie jest pusta.
}

void ListaDwukierunkowa::zakres(int indeks)
{

    if (indeks < 0 || indeks >(rozm - 1))                       //Jeœli podany indeks jest mniejszy od zera lub wiêkszy od wielkoœci listy, rzucenie wyj¹tku.
    throw out_of_range(EXCEPTION_RANGE_DESC);
}

ElemListy* ListaDwukierunkowa::zawartoscElem(int indeks)
{
    
    ElemListy* poczElem;                                        //Wyszukiwane elementu rozpoczyna siê od ustalenia czy znajduje siê on bli¿ej pocz¹tku lub koñca.
    int indeksRoboczy = 0;
    if ((rozm - 1) - indeks >= indeks)
    {
        poczElem = poczatek;                                    //Jeœli element znajduje siê bli¿ej pocz¹tku, lista bêdzie przejrzana od pocz¹tku do podanego indeksu.
        while (indeksRoboczy != indeks)
        {
            poczElem = poczElem->nast;
            indeksRoboczy++;
        }
    }
    else
    {
        poczElem = koniec;                                        //Jeœli element znajduje siê bli¿ej koñca, lista bêdzie przejrzana od koñca do podanego indeksu.
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