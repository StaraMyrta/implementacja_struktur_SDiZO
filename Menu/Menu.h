#include <iostream>
#include <vector>
#include "obiektMenu.h"
#include "menuStruktur/menuTablicy.h"

// Klasa dla g³ównego menu programu.
class Menu
{
private:
    std::vector<ObiektMenu*> obiekty;           //Wektor przechowuj¹cy kolejne menu.
    bool powrot = false;                        //Zmienna przechowuj¹ca informacjê o wybraniu komendy zakoñczenia programu.
    bool nieznanaKomenda = true;                //Zmienna przechowuj¹ca informacjê o nierozpoznaniu komendy programu.
    void wyswietlMenu();                        //Wyœwietla zawartoœæ danego menu.
public:
    Menu();                                     //Konstruktor klasy menu.
    ~Menu();                                    //Destruktor klasy menu.
    void dodajMenu(ObiektMenu* obiekt);         //Dodaje nowe menu do kontenera.
    void wybor();                             //Obs³uguje pêtlê komend.
};