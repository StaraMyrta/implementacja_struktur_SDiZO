#include <iostream>
#include "../obiektMenu.h"
#include "../../tablicaDynamiczna/tablicaDynamiczna.h"

//menu tablicy
class Tablica : public MenuItem
{
private:
    Tablica* tablica;
    void wyswietlMenu() override;
    void wczytajPlik();
    void usun();
    void dodaj();
    void znajdz();
    void wyswietl();
public:
    Tablica();
    void wybor() override;
};