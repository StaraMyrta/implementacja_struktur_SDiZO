#pragma once
#include <fstream>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

//Klasa abstrakcyjna reprezentuj�ca menu poszczeg�lnych struktur.
class ObiektMenu
{
protected:      
    bool powrot = false;                            //zmienna przechowujaca wartosc true/false dla wyboru powrotu do glownego menu
    string opisMenu;                                //zmienna przechowujaca opis danego menu
    string wywolanieMenu;                           //zmienna przechowuj�ca komend� wywo�ania danego menu
    virtual void wyswietlMenu() = 0;                //wy�wietla zadane menu
public:
    virtual ~ObiektMenu() = default;                  //dekonstruktor klasy menu
    virtual void wybor() = 0;                       //Obs�uguje p�tl� komend dla danego menu.
    string pokazOpisMenu() { return opisMenu;}      //Zwraca opis danego menu.
    string pokazKomende() { return wywolanieMenu; }       //Zwraca komend� dla wywo�ania danego menu.
};