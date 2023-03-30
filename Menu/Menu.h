#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../TablicaDynamiczna/TablicaDynamiczna.h"
#include "../Testy/TestTablicy/TestTablicy.h"

// Klasa dla g³ównego menu programu.
class Menu
{
private:
    TablicaDynamiczna* tablica;
    string wejscie;
    bool powrot = false;                        //Zmienna przechowuj¹ca informacjê o wybraniu komendy zakoñczenia programu.
    bool nieznanaKomenda = true;                //Zmienna przechowuj¹ca informacjê o nierozpoznaniu komendy programu.
    void menuTablicy();                         //Wyœwietla menu wyboru operacji na tablicy dynamicznej.
    void wczytajPlikDoTablicy();                //Wczytuje dane z pliku do tablicy dynamicznej.
    void usunTablica();                         //Wywo³anie funkcji usuniêcia wybranego elementu z tablicy dynamicznej.
    void dodajTablica();                        //Wywo³anie funkcji dodania wybranego elementu do tablicy dynamicznej.
    void znajdzTablica();                       //Wywo³anie funkcji znalezienia wybranego elementu w tablicy dynamicznej.
    void stworzLosowoTablica();                 //Wywo³anie funkcji tworzacej tablicê dynamiczn¹ wype³nion¹ losowymi wartoœciami o zadanym rozmiarze.
    void wyswietlTablica();                     //Wyœwietlenie zawartoœci tablicy.
    void testTablica();                         //Wywo³anie testów dla tablicy dynamicznej.
public:
    Menu();                                     //Konstruktor klasy menu.
    void wyborStruktury();                      //Wyœwietla menu wyboru struktury.
};