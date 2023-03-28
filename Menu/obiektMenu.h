#pragma once
#include <fstream>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

/// Klasa abstrakcyjna reprezentuj¹ca menu poszczególnych struktur.
class obiektMenu
{
protected:
    bool powrot = false;                //zmienna przechowujaca wartosc true/false dla wyboru powrotu do glownego menu
    string opisMenu;                    //zmienna przechowujaca opis danego menu
    string wywolanieMenu;               //zmienna przechowuj¹ca komendê wywo³ania danego menu
    virtual void wyswietlMenu() = 0;    //wyœwietla zadane menu
public:
    virtual ~MenuItem() = default;      //dekonstruktor klasy menu
    virtual void wybor() = 0;           //Obs³uguje pêtlê komend dla danego menu.
    string pokazOpisMenu() { return opisMenu;}      // Zwraca opis danego menu.
    string pokazKomende() { return komenda; }             /// Zwraca komendê dla wywo³ania danego menu.
};