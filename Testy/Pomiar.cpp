#include "Pomiar.h"

using namespace std;

Pomiar::Pomiar()
{
    czasTrwania = 0;
}

void Pomiar::czasStart()
{
    licznikWlaczony = chrono::high_resolution_clock::now();         //Ustawienie pocz�tkowego czasu wykonywania.
}

void Pomiar::czasStop()
{
    licznikWylaczony = chrono::high_resolution_clock::now();        //Ustawienie ko�cowego czasu wykonywania i zapisanie r�nicy do 'czasTrwania'.
    chrono::duration<double, micro> time = licznikWylaczony - licznikWlaczony;
    czasTrwania = time.count();
}

double Pomiar::jakiCzasTrwania()
{
    return czasTrwania;                                             //Zwr�cenie czasu trwania testowanej operacji.
}