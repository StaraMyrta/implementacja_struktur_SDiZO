#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../TablicaDynamiczna/TablicaDynamiczna.h"
#include "../Testy/TestTablicy/TestTablicy.h"

// Klasa dla g��wnego menu programu.
class Menu
{
private:
    TablicaDynamiczna* tablica;
    string wejscie;
    bool powrot = false;                        //Zmienna przechowuj�ca informacj� o wybraniu komendy zako�czenia programu.
    bool nieznanaKomenda = true;                //Zmienna przechowuj�ca informacj� o nierozpoznaniu komendy programu.
    void menuTablicy();                         //Wy�wietla menu wyboru operacji na tablicy dynamicznej.
    void wczytajPlikDoTablicy();                //Wczytuje dane z pliku do tablicy dynamicznej.
    void usunTablica();                         //Wywo�anie funkcji usuni�cia wybranego elementu z tablicy dynamicznej.
    void dodajTablica();                        //Wywo�anie funkcji dodania wybranego elementu do tablicy dynamicznej.
    void znajdzTablica();                       //Wywo�anie funkcji znalezienia wybranego elementu w tablicy dynamicznej.
    void stworzLosowoTablica();                 //Wywo�anie funkcji tworzacej tablic� dynamiczn� wype�nion� losowymi warto�ciami o zadanym rozmiarze.
    void wyswietlTablica();                     //Wy�wietlenie zawarto�ci tablicy.
    void testTablica();                         //Wywo�anie test�w dla tablicy dynamicznej.
public:
    Menu();                                     //Konstruktor klasy menu.
    void wyborStruktury();                      //Wy�wietla menu wyboru struktury.
};