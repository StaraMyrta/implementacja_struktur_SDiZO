#pragma once
#include <chrono>

using namespace std;

class Pomiar                        //Klasa s�u��ca do jednolitego wykonywania pomiar�w czasu trwania algorytm�w.
{
private:
    double czasTrwania;             //Zmienna przechowuj�ca informacj� o d�ugo�ci wykonywania zadanej akcji w mikrosekundach.
    chrono::high_resolution_clock::time_point licznikWlaczony;          //Zmienna przechowuj�ca czas startu pomiaru.
    chrono::high_resolution_clock::time_point licznikWylaczony;         //Zmienna przechowuj�ca czas ko�ca pomiaru.
public:

    Pomiar();                       //Konstruktor klasy.
    void czasStart();               //Rozpoczyna odmierzanie czasu.
    void czasStop();                //Ko�czy odmierzanie czasu.
    double jakiCzasTrwania();       //Zwraca czas w mikrosekundach, kt�ry up�yn�� dla ostatniego pomiaru.
};