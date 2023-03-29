#pragma once
#include <iostream>
#include "../ObiektMenu.h"
#include "../../TablicaDynamiczna/TablicaDynamiczna.h"

class MenuTablicy : public ObiektMenu
{
private:
    TablicaDynamiczna* tablica;
    void wyswietlMenu() override;
    void wczytajPlik();
    void usunObiekt();
    void dodajObiekt();
    void znajdzObiekt();
    void stworzLosowo();
    void wyswietl();
    void test();
public:
    MenuTablicy();
    void wybor() override;
};