#pragma once
#include <iostream>
#include <string>
#include <random>
#include "elemListy.h"

using namespace std;

class ListaDwukierunkowa
{
private:
    const string EXCEPTION_DESC = "Nieprawidlowy indeks!";    //Sta�e przechowuj�ce opisy wyj�tku.
    const string EXCEPTION_LENGTH_DESC = "Lista jest pusta!";
    ElemListy* poczatek;                        //Wska�nik na pocz�tek listy.
    ElemListy* koniec;                          //Wska�nik na koniec listy.
    int rozm;                                   //Zmienna przechowuj�ca ilo�� element�w listy.
    ElemListy* zawartoscElem(int indeks);       //Zwraca element listy dla podanego miejsca.
public:
    ListaDwukierunkowa();                       //Konstruktor klasy listy.
    ~ListaDwukierunkowa();                      //Destruktor klasy listy.
    void dodajNaPocz(int elem);                 //Dodaje nowy element z przodu listy.
    void dodajNaKon(int elem);                  //Dodaje nowy element z ty�u listy.
    void dodajZa(int indeks, int elem);         //Dodaje nowy element za istniej�cym, znajduj�cym si� w podanym miejscu.
    void dodajLosowo(int elem);                 //Dodaje nowy element do listy w losowym miejscu.
    void usun(int indeks);                      //Usuwa element z podanego miejsca w li�cie.
    void usunZPocz();                           //Usuwa element z przodu listy.
    void usunZKon();                            //Usuwa element z ty�u listy.
    int zawartosc(int indeks);                  //Zwraca warto�� elementu listy dla podanego miejsca.
    int znajdz(int elem);                      //Sprawdza czy element o podanej warto�ci wyst�puje w li�cie.
    bool usunWartosc(int elem);                 //Usuwa pierwszy element od pocz�tku listy o podanej warto�ci.
    void usunLosowo();                          //Usuwa losowy element z tablicy.
    int rozmiar();                              //Zwraca ilo�� element�w listy.
    void zakres(int indeks);                    //Sprawdza czy dane miejsce nie wykracza poza szeroko�� listy.
};