#pragma once
#include <iostream>
#include <string>
#include <random>
#include "elemListy.h"

using namespace std;

class ListaDwukierunkowa
{
private:
    const string EXCEPTION_DESC = "Nieprawidlowy indeks!";    //Sta³e przechowuj¹ce opisy wyj¹tku.
    const string EXCEPTION_LENGTH_DESC = "Lista jest pusta!";
    ElemListy* poczatek;                        //WskaŸnik na pocz¹tek listy.
    ElemListy* koniec;                          //WskaŸnik na koniec listy.
    int rozm;                                   //Zmienna przechowuj¹ca iloœæ elementów listy.
    ElemListy* zawartoscElem(int indeks);       //Zwraca element listy dla podanego miejsca.
public:
    ListaDwukierunkowa();                       //Konstruktor klasy listy.
    ~ListaDwukierunkowa();                      //Destruktor klasy listy.
    void dodajNaPocz(int elem);                 //Dodaje nowy element z przodu listy.
    void dodajNaKon(int elem);                  //Dodaje nowy element z ty³u listy.
    void dodajZa(int indeks, int elem);         //Dodaje nowy element za istniej¹cym, znajduj¹cym siê w podanym miejscu.
    void dodajLosowo(int elem);                 //Dodaje nowy element do listy w losowym miejscu.
    void usun(int indeks);                      //Usuwa element z podanego miejsca w liœcie.
    void usunZPocz();                           //Usuwa element z przodu listy.
    void usunZKon();                            //Usuwa element z ty³u listy.
    int zawartosc(int indeks);                  //Zwraca wartoœæ elementu listy dla podanego miejsca.
    int znajdz(int elem);                      //Sprawdza czy element o podanej wartoœci wystêpuje w liœcie.
    bool usunWartosc(int elem);                 //Usuwa pierwszy element od pocz¹tku listy o podanej wartoœci.
    void usunLosowo();                          //Usuwa losowy element z tablicy.
    int rozmiar();                              //Zwraca iloœæ elementów listy.
    void zakres(int indeks);                    //Sprawdza czy dane miejsce nie wykracza poza szerokoœæ listy.
};