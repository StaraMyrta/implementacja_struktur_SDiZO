#include "Pomiar.h"

using namespace std;

Pomiar::Pomiar()
{
    czasTrwania = 0;
}

void Pomiar::czasStart()
{
    licznikWlaczony = chrono::high_resolution_clock::now();    //Ustawia pocz�tkowy czas wykonywania.
}

void Pomiar::czasStop()
{
    //Ustawiamy ko�cowy czas wykonywania i zapisujemy r�nic� do 'duration'.
    licznikWylaczony = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> time = licznikWylaczony - licznikWlaczony;
    czasTrwania = time.count();
}

double Pomiar::jakiCzasTrwania()
{
    return czasTrwania;
}