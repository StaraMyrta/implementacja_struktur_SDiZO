#include "MenuTablicy.h"
#include "../../Testy/TestTablicy/TestTablicy.h"

using namespace std;

MenuTablicy::MenuTablicy()
{
    //Ustawia zmienne definiuj¹ce opis menu.
    opisMenu = "Tablica";
    wywolanieMenu = "tablica";
}

void MenuTablicy::wyswietlMenu()
{
    //Wypisanie menu dla tablicy.
    cout << endl;
    cout << "Menu dla tablicy" << endl;
    cout << "1. Wczytaj z pliku (load)" << endl;
    cout << "2. Usun (delete)" << endl;
    cout << "3. Dodaj (add)" << endl;
    cout << "4. Znajdz (find)" << endl;
    cout << "5. Utworz losowo (rand)" << endl;
    cout << "6. Wyswietl (disp)" << endl;
    cout << "7. Testuj (test)" << endl;
    cout << "8. Wroc (back)" << endl;
    cout << "Wybierz opcje: ";
}

void MenuTablicy::wybor()
{
    tablica = new TablicaDynamiczna();    //Tworzy nowy obiekt klasy TablicaDynamiczna i wchodzi do pêtli obs³ugi opcji.
    string wejscie;
    powrot = false;
    while (!powrot)
    {
        wyswietlMenu();
        cin >> wejscie;
        if (wejscie == "load") wczytajPlik();
        else if (wejscie == "delete") usunObiekt();
        else if (wejscie == "add") dodajObiekt();
        else if (wejscie == "find") znajdzObiekt();
        else if (wejscie == "rand") stworzLosowo();
        else if (wejscie == "disp") wyswietl();
        else if (wejscie == "test") test();
        else if (wejscie == "back") powrot = true;
        else cout << "Nieznane polecenie!" << endl;
    }
    delete tablica;    //Po wyjœciu z pêtli tablica zostaje zdealokowana.
}

void MenuTablicy::wczytajPlik()
{
    string nazwaPliku;
    int licznik, elem;
    cout << "\nPodaj nazwe pliku: ";
    cin >> nazwaPliku;
    ifstream plik;
    plik.open(nazwaPliku);
    if (plik.is_open())
    {
        delete tablica;
        tablica = new TablicaDynamiczna();
        plik >> licznik;
        for (int i = 0; i < licznik; i++)
        {
            plik >> elem;
            tablica->dodaj(elem);
        }
        wyswietl();
    }
    else cout << "Podana nazwa pliku jest nieprawidlowa!" << endl;
    plik.close();
}

void MenuTablicy::usunObiekt()
{
    int indeks;
    cout << "\nPodaj indeks elementu do usuniecia: ";
    cin >> indeks;
    try
    {
        tablica->usun(indeks);
        wyswietl();
    }
    catch (out_of_range& e)
    {
        cout << e.what() << endl;
    }
}

void MenuTablicy::dodajObiekt()
{
    int indeks;
    int elem;
    cout << "\nPodaj indeks elementu do dodania: ";
    cin >> indeks;
    cout << "Podaj wartosc elementu: ";
    cin >> elem;
    try
    {
        tablica->dodaj(indeks, elem);
        wyswietl();
    }
    catch (out_of_range& e)
    {
        cout << e.what() << endl;
    }
}

void MenuTablicy::znajdzObiekt()
{
    int elem;
    cout << "\nPodaj wartosc elementu: ";
    cin >> elem;
    if (tablica->znajdz(elem)) cout << "Znaleziono element o takiej wartosci!" <<endl;
    else cout << "Nie znaleziono elementu o takiej wartosci!" << endl;
    wyswietl();
}

void MenuTablicy::stworzLosowo()
{
    //Dealokujemy tablicê i alokujemy pamiêæ na nowy obiekt.
    delete tablica;
    tablica = new TablicaDynamiczna();
    int rozm;
    cout << "\nPodaj wielkosc tablicy: ";
    cin >> rozm;
    for (int i = 0; i < rozm; i++) tablica->dodaj(rand() % 50 + 1);
    wyswietl();
}

void MenuTablicy::wyswietl()
{
    cout << "\nZawartosc tablicy: ";
    for (int i = 0; i < tablica->rozmiar(); i++) cout << tablica->zawartosc(i) << endl;
}

void MenuTablicy::test()
{
    auto* test = new TestTablicy();
    test->sredniTestDodawania();
    test->sredniTestUsuwania();
    test->sredniTestSzukania();
    delete test;
}