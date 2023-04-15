#pragma once
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class KopiecBinarny
{
private:
    const int START_SPACE = 10;                                         //Stała przechowująca ilość miejsc drzewa przy utworzeniu nowego obiektu.
    const int MIN_FREE_SPACE = 5;                                       //Stała przechowująca minimalną ilość wolnego miejsca w kopcu.
    const int MAX_FREE_SPACE = 15;                                      //Stała przechowująca maksymalną ilość wolnego miejsca w kopcu.
    const string EXCEPTION_DESC = "Nieprawidlowy indeks!";              //Stałe przechowujące opisy wyjątkow.
    const string EXCEPTION_LENGTH_DESC = "Kopiec jest pusty!";
    
    string cr, cl, cp;
    int* baza;                                                          //Wskaźnik na pierwszy element tablicy (korzeń), w której znajduje się struktura kopca.
    int wierzcholki;                                                    //Zmienna przechowująca ilość wierzchołków kopca.
    int rozm;                                                           //Zmienna przechowująca ilość miejsc w tablicy.
    void naprawKopiecGora(int indeks, int ostatniWierzcholek);          //Naprawia strukturę kopca do korzenia.
    void naprawKopiecDol(int indeks, int ostatniWierzcholek);           //Naprawia strukturę kopca od korzenia.
    int znajdzIndeks(int elem);                                         //Znajduje indeks podanego elementu.
    void kopiujTablice(int* skad, int* dokad, int rozm);                //Kopiuje daną ilość elementów z tablicy źródłowej do docelowej.
    void wyswietlDrzewo(string sp, string sn, int v);
    bool znajdz(int elem, int indeks);                                              //Sprawdza czy element o podanej wartości występuje w kopcu.
   
public:
    KopiecBinarny();
    ~KopiecBinarny();
    void dodaj(int elem);                                               //Dodaje nowy element do kopca.
    void usunKorzen();                                                   //Usuwa korzeń kopca i naprawia go.
    bool usun(int elem);                                                //Usuwa pierwsze wystąpienie elementu w kopcu i naprawia go.
    bool znajdz(int elem);
    int zawartosc(int indeks);                                          //Zwraca element dla podanego miejsca w tablicy, zawierającej informację o drzewie.
    void wyswietlDrzewo();                                              //Wypisuje graficzną reprezentację drzewa.
    int ileWierzcholkow();                                              //Zwraca ilość wierzchołków kopca.
};