#include <iostream>
#include <vector>
#include "obiektMenu.h"
#include "menuStruktur/menuTablicy.h"

// Klasa dla g��wnego menu programu.
class Menu
{
private:
    std::vector<ObiektMenu*> obiekty;           //Wektor przechowuj�cy kolejne menu.
    bool powrot = false;                        //Zmienna przechowuj�ca informacj� o wybraniu komendy zako�czenia programu.
    bool nieznanaKomenda = true;                //Zmienna przechowuj�ca informacj� o nierozpoznaniu komendy programu.
    void wyswietlMenu();                        //Wy�wietla zawarto�� danego menu.
public:
    Menu();                                     //Konstruktor klasy menu.
    ~Menu();                                    //Destruktor klasy menu.
    void dodajMenu(ObiektMenu* obiekt);         //Dodaje nowe menu do kontenera.
    void wybor();                             //Obs�uguje p�tl� komend.
};