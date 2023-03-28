#include <iostream>
#include "../obiektMenu.h"
#include "../../tablicaDynamiczna/tablicaDynamiczna.h"

class MenuTablicy : public ObiektMenu
{
private:
    MenuTablicy* tablica;
    void wyswietlMenu() override;
    void wczytajPlik();
    void usun();
    void dodaj();
    void znajdz();
    void wyswietl();
public:
    MenuTablicy();
    void wybor() override;
};