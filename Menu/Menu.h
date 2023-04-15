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

// Klasa dla g��wnego menu programu.
class Menu
{
private:
    //Wska�niki na obiekty struktur
    TablicaDynamiczna* tablica;
    ListaDwukierunkowa* lista;
    KopiecBinarny* kopiec;
    DrzewoRB* drzewoRB;
    int wejscie, wejscie2;
    bool powrot = false;                        //Zmienna przechowuj�ca informacj� o wybraniu komendy zako�czenia programu.
    bool nieznanaKomenda = true;                //Zmienna przechowuj�ca informacj� o nierozpoznaniu komendy programu.
    
    //Funkcje powi�zane z tablic� dynamiczn�
    void menuTablicy();                         //Wy�wietla menu wyboru operacji na tablicy dynamicznej.
    void wczytajPlikDoTablicy();                //Wczytuje dane z pliku do tablicy dynamicznej.
    void usunTablica(int wybor);                         //Wywo�anie funkcji usuni�cia wybranego elementu z tablicy dynamicznej.
    void dodajTablica(int wybor);                        //Wywo�anie funkcji dodania wybranego elementu do tablicy dynamicznej.
    void znajdzTablica();                       //Wywo�anie funkcji znalezienia wybranego elementu w tablicy dynamicznej.
    void stworzLosowoTablica();                 //Wywo�anie funkcji tworzacej tablic� dynamiczn� wype�nion� losowymi warto�ciami o zadanym rozmiarze.
    void wyswietlTablica();                     //Wy�wietlenie zawarto�ci tablicy.
    void testTablica();                         //Wywo�anie test�w dla tablicy dynamicznej.

    //Funkcje powi�zane z list� dwukierunkow�
    void menuListy();                           //Wy�wietla menu wyboru operacji na li�cie dwukierunkowej.
    void wczytajPlikDoListy();                  //Wczytuje dane z pliku do listy dwukierunkowej.
    void usunLista(int wybor);                           //Wywo�anie funkcji usuni�cia wybranego elementu z listy dwukierunkowej.
    void dodajLista(int wybor);                          //Wywo�anie funkcji dodania wybranego elementu do listy dwukierunkowej.
    void znajdzLista();                         //Wywo�anie funkcji znalezienia wybranego elementu w li�cie dwukierunkowej.
    void stworzLosowoLista();                   //Wywo�anie funkcji tworzacej list� dwukierunkow� wype�nion� losowymi warto�ciami o zadanym rozmiarze.
    void wyswietlLista();                       //Wy�wietlenie zawarto�ci listy.
    void testLista();                           //Wywo�anie test�w dla listy dwukierunkowej.

    //Funkcje powi�zane z kopcem binarnym
    void menuKopca();                           //Wy�wietla menu wyboru operacji na kopcu binarnym.
    void wczytajPlikDoKopca();                  //Wczytuje dane z pliku do kopca binarnego.
    void usunKopiec();                          //Wywo�anie funkcji usuni�cia wybranego elementu z kopca binarnego.
    void dodajKopiec();                         //Wywo�anie funkcji dodania wybranego elementu do kopca binarnego.
    void znajdzKopiec();                        //Wywo�anie funkcji znalezienia wybranego elementu w kopcu binarnym.
    void stworzLosowoKopiec();                  //Wywo�anie funkcji tworzacej kopiec binarny wype�niony losowymi warto�ciami o zadanym rozmiarze.
    void wyswietlKopiec();                      //Wy�wietlenie zawarto�ci kopca binarnego.
    void testKopiec();                          //Wywo�anie test�w dla kopca binarnego.

    //Funkcje powi�zane z drzewem RB
    void menuRB();                           //Wy�wietla menu wyboru operacji na drzewie RB.
    void wczytajPlikDoRB();                  //Wczytuje dane z pliku do drzewa RB.
    void usunRB();                          //Wywo�anie funkcji usuni�cia wybranego elementu z drzewa RB.
    void dodajRB();                         //Wywo�anie funkcji dodania wybranego elementu do drzewa RB.
    void znajdzRB();                        //Wywo�anie funkcji znalezienia wybranego elementu w drzewie RB.
    void stworzLosowoRB();                  //Wywo�anie funkcji tworzacej drzewo RB wype�niony losowymi warto�ciami o zadanym rozmiarze.
    void wyswietlRB();                      //Wy�wietlenie zawarto�ci drzewa RB.
    void testRB();

public:
    Menu();                                     //Konstruktor klasy menu.
    void wyborStruktury();                      //Wy�wietla menu wyboru struktury.
};