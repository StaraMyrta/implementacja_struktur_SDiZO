#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../TablicaDynamiczna/TablicaDynamiczna.h"
#include "../Testy/TestTablicy/TestTablicy.h"
#include "../ListaDwukierunkowa/ListaDwukierunkowa.h"
#include "../Testy/TestListy/TestListy.h"
#include "../KopiecBinarny/KopiecBinarny.h"
#include "../Testy/TestKopca/TestKopca.h"
#include "../DrzewoRB/DrzewoRB.h"
#include "../Testy/TestDrzewaRB/TestDrzewaRB.h"

// Klasa dla g³ównego menu programu.
class Menu
{
private:
    //WskaŸniki na obiekty struktur
    TablicaDynamiczna* tablica;
    ListaDwukierunkowa* lista;
    KopiecBinarny* kopiec;
    DrzewoRB* drzewoRB;
    int wejscie, wejscie2;
    bool powrot = false;                        //Zmienna przechowuj¹ca informacjê o wybraniu komendy zakoñczenia programu.
    bool nieznanaKomenda = true;                //Zmienna przechowuj¹ca informacjê o nierozpoznaniu komendy programu.
    
    //Funkcje powi¹zane z tablic¹ dynamiczn¹
    void menuTablicy();                         //Wyœwietla menu wyboru operacji na tablicy dynamicznej.
    void wczytajPlikDoTablicy();                //Wczytuje dane z pliku do tablicy dynamicznej.
    void usunTablica(int wybor);                         //Wywo³anie funkcji usuniêcia wybranego elementu z tablicy dynamicznej.
    void dodajTablica(int wybor);                        //Wywo³anie funkcji dodania wybranego elementu do tablicy dynamicznej.
    void znajdzTablica();                       //Wywo³anie funkcji znalezienia wybranego elementu w tablicy dynamicznej.
    void stworzLosowoTablica();                 //Wywo³anie funkcji tworzacej tablicê dynamiczn¹ wype³nion¹ losowymi wartoœciami o zadanym rozmiarze.
    void wyswietlTablica();                     //Wyœwietlenie zawartoœci tablicy.
    void testTablica();                         //Wywo³anie testów dla tablicy dynamicznej.

    //Funkcje powi¹zane z list¹ dwukierunkow¹
    void menuListy();                           //Wyœwietla menu wyboru operacji na liœcie dwukierunkowej.
    void wczytajPlikDoListy();                  //Wczytuje dane z pliku do listy dwukierunkowej.
    void usunLista(int wybor);                           //Wywo³anie funkcji usuniêcia wybranego elementu z listy dwukierunkowej.
    void dodajLista(int wybor);                          //Wywo³anie funkcji dodania wybranego elementu do listy dwukierunkowej.
    void znajdzLista();                         //Wywo³anie funkcji znalezienia wybranego elementu w liœcie dwukierunkowej.
    void stworzLosowoLista();                   //Wywo³anie funkcji tworzacej listê dwukierunkow¹ wype³nion¹ losowymi wartoœciami o zadanym rozmiarze.
    void wyswietlLista();                       //Wyœwietlenie zawartoœci listy.
    void testLista();                           //Wywo³anie testów dla listy dwukierunkowej.

    //Funkcje powi¹zane z kopcem binarnym
    void menuKopca();                           //Wyœwietla menu wyboru operacji na kopcu binarnym.
    void wczytajPlikDoKopca();                  //Wczytuje dane z pliku do kopca binarnego.
    void usunKopiec();                          //Wywo³anie funkcji usuniêcia wybranego elementu z kopca binarnego.
    void dodajKopiec();                         //Wywo³anie funkcji dodania wybranego elementu do kopca binarnego.
    void znajdzKopiec();                        //Wywo³anie funkcji znalezienia wybranego elementu w kopcu binarnym.
    void stworzLosowoKopiec();                  //Wywo³anie funkcji tworzacej kopiec binarny wype³niony losowymi wartoœciami o zadanym rozmiarze.
    void wyswietlKopiec();                      //Wyœwietlenie zawartoœci kopca binarnego.
    void testKopiec();                          //Wywo³anie testów dla kopca binarnego.

    //Funkcje powi¹zane z drzewem RB
    void menuRB();                           //Wyœwietla menu wyboru operacji na drzewie RB.
    void wczytajPlikDoRB();                  //Wczytuje dane z pliku do drzewa RB.
    void usunRB();                          //Wywo³anie funkcji usuniêcia wybranego elementu z drzewa RB.
    void dodajRB();                         //Wywo³anie funkcji dodania wybranego elementu do drzewa RB.
    void znajdzRB();                        //Wywo³anie funkcji znalezienia wybranego elementu w drzewie RB.
    void stworzLosowoRB();                  //Wywo³anie funkcji tworzacej drzewo RB wype³niony losowymi wartoœciami o zadanym rozmiarze.
    void wyswietlRB();                      //Wyœwietlenie zawartoœci drzewa RB.
    void testRB();

public:
    Menu();                                     //Konstruktor klasy menu.
    void wyborStruktury();                      //Wyœwietla menu wyboru struktury.
};