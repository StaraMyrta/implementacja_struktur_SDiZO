#include "Menu.h"

using namespace std;

//Klasie menu wystarcza domyœlny konstruktor.
Menu::Menu() = default;

void Menu::wyborStruktury()
{
    cout << endl;                                               //Wybór struktury.
    cout << "Wybierz strukture:" << endl;
    cout << "1. Tablica Dynamiczna (1)" << endl;
    cout << "2. Lista Dwukierunkowa (2)" << endl;
    cout << "3. Kopiec Binarny (3)" << endl;
    cout << "4. Drzewo BST (4)" << endl;
    cout << "5. Drzewo Czerwono-Czarne (5)" << endl;
    cout << "6. Wroc (powrot)" << endl;
    cout << "Wybierz opcje: ";
    powrot = false;                                             //Wczytanie danych z konsoli do 'wejscie' i wywo³anie menu wybranej struktury.
    while (!powrot)
    {
        cin >> wejscie;
        nieznanaKomenda = true;                                 //Jeœli komenda to 'powrot' ustawione zostaj¹ flagi umo¿liwiaj¹ce wyjœcie z pêtli.
        if (wejscie == "powrot")
        {
            powrot = true;
            nieznanaKomenda = false;
        }
        else if (wejscie == "1") menuTablicy();
        else if (wejscie == "2") menuListy();
        //else if (wejscie == "3") menuKopca();
        //else if (wejscie == "4") menuBST();
        //else if (wejscie == "5") menuCC();

    }
}

void Menu::menuTablicy()
{
    cout << endl;                                               //Wybór operacji.
    cout << "Menu dla tablicy:" << endl;
    cout << "1. Wczytaj z pliku (T1)" << endl;
    cout << "2. Usun (T2)" << endl;
    cout << "3. Dodaj (T3)" << endl;
    cout << "4. Znajdz (T4)" << endl;
    cout << "5. Utworz losowo (T5)" << endl;
    cout << "6. Wyswietl (T6)" << endl;
    cout << "7. Testuj (T7)" << endl;
    cout << "8. Wroc (powrot)" << endl;
    cout << "Wybierz opcje: ";

    powrot = false;
    while (!powrot)
    {
        cin >> wejscie;
        if (wejscie == "T1") wczytajPlikDoTablicy();
        else if (wejscie == "T2") usunTablica();
        else if (wejscie == "T3") dodajTablica();
        else if (wejscie == "T4") znajdzTablica();
        else if (wejscie == "T5") stworzLosowoTablica();
        else if (wejscie == "T6") wyswietlTablica();
        else if (wejscie == "T7") testTablica();
        else if (wejscie == "powrot") powrot = true;
        else cout << "Nieznane polecenie!" << endl;
    }
    delete tablica;                                             //Po wyjœciu z pêtli tablica zostaje zdealokowana.
}

void Menu::wczytajPlikDoTablicy()
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
        wyswietlTablica();
    }
    else cout << "Podana nazwa pliku jest nieprawidlowa!" << endl;
    plik.close();
    menuTablicy();
}

void Menu::usunTablica()
{
    int indeks;
    cout << "\nPodaj indeks elementu do usuniecia: ";
    cin >> indeks;
    try
    {
        tablica->usun(indeks);
        wyswietlTablica();
    }
    catch (out_of_range& e)
    {
        cout << e.what() << endl;
    }
    menuTablicy();
}

void Menu::dodajTablica()
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
        wyswietlTablica();
    }
    catch (out_of_range& e)
    {
        cout << e.what() << endl;
    }
    menuTablicy();
}

void Menu::znajdzTablica()
{
    int elem;
    cout << "\nPodaj wartosc elementu: ";
    cin >> elem;
    if (tablica->znajdz(elem)) cout << "Znaleziono element o takiej wartosci!" << endl;
    else cout << "Nie znaleziono elementu o takiej wartosci!" << endl;
    wyswietlTablica();
    menuTablicy();
}

void Menu::stworzLosowoTablica()
{
    delete tablica;                                                 //Dealokacja tablicy i rezerwacja pamiêci na nowy obiekt.
    tablica = new TablicaDynamiczna();
    int rozm;
    cout << "\nPodaj wielkosc tablicy: ";
    cin >> rozm;
    for (int i = 0; i < rozm; i++) tablica->dodaj(rand() % 50 + 1);
    wyswietlTablica();
    menuTablicy();
}

void Menu::wyswietlTablica()
{
    cout << "\nZawartosc tablicy:\n";
    for (int i = 0; i < tablica->rozmiar(); i++) cout << tablica->zawartosc(i) << endl;
    menuTablicy();
}

void Menu::testTablica()                                            //Stworzenie obiektu klasy testu tablicy i uruchomienie metody.
{
    auto* test = new TestTablicy();
    test->sredniTestDodawania();
    test->sredniTestUsuwania();
    test->sredniTestSzukania();
    delete test;
    menuTablicy();
}

void Menu::menuListy()
{
    cout << endl;                                                   //Wybór operacji.
    cout << "Menu dla listy:" << endl;
    cout << "1. Wczytaj z pliku (L1)" << endl;
    cout << "2. Usun (L2)" << endl;
    cout << "3. Dodaj (L3)" << endl;
    cout << "4. Znajdz (L4)" << endl;
    cout << "5. Utworz losowo (L5)" << endl;
    cout << "6. Wyswietl (L6)" << endl;
    cout << "7. Testuj (L7)" << endl;
    cout << "8. Wroc (powrot)" << endl;
    cout << "Wybierz opcje: ";

    powrot = false;
    while (!powrot)
    {
        cin >> wejscie;
        if (wejscie == "L1") wczytajPlikDoListy();
        else if (wejscie == "L2") usunLista();
        else if (wejscie == "L3") dodajLista();
        else if (wejscie == "L4") znajdzLista();
        else if (wejscie == "L5") stworzLosowoLista();
        else if (wejscie == "L6") wyswietlLista();
        else if (wejscie == "L7") testLista();
        else if (wejscie == "powrot") powrot = true;
        else cout << "Nieznane polecenie!" << endl;
    }

    delete lista;                                                   //Po wyjœciu z pêtli lista zostaje zdealokowana.
}

void Menu::wczytajPlikDoListy()
{
    string nazwaPliku;
    int licznik, elem;
    cout << "\nPodaj nazwe pliku: ";
    cin >> nazwaPliku;
    ifstream plik;
    plik.open(nazwaPliku);
    if (plik.is_open())
    {
        delete lista;
        lista = new ListaDwukierunkowa();
        plik >> licznik;
        for (int i = 0; i < licznik; i++)
        {
            plik >> elem;
            lista->dodajNaKon(elem);
        }
        wyswietlLista();
    }
    else cout << "Podana nazwa pliku jest nieprawidlowa!" << endl;
    plik.close();
    menuListy();
}

void Menu::usunLista()
{
    int elem;
    cout << "\nPodaj wartosc elementu do usuniecia: ";
    cin >> elem;
    if (!lista->usunWartosc(elem))
        cout << "Nie znaleziono takiego elementu!" << endl;
    wyswietlLista();
    menuListy();
}

void Menu::dodajLista()
{
    int indeks;
    int elem;
    cout << "\nPodaj index elementu do dodania: ";
    cin >> indeks;
    cout << "Podaj wartosc elementu: ";
    cin >> elem;
    try
    {
        if (indeks == 0) lista->dodajNaPocz(elem);
        else lista->dodajZa(indeks - 1, elem);
        wyswietlLista();
    }
    catch (out_of_range& e)
    {
        cout << e.what() << endl;
    }
    menuListy();
}

void Menu::znajdzLista()
{
    int elem;
    cout << "\nPodaj wartosc elementu: ";
    cin >> elem;
    if (lista->znajdz(elem)) cout << "Znaleziono element o takiej wartosci!" << endl;
    else cout << "Nie znaleziono elementu o takiej wartosci!" << endl;
    wyswietlLista();
    menuListy();
}

void Menu::stworzLosowoLista()
{
    delete lista;                                               //Dealokacja listy i rezerwacja pamiêci na nowy obiekt.
    lista = new ListaDwukierunkowa();
    int rozm;
    cout << "\nPodaj wielkosc listy: ";
    cin >> rozm;
    for (int i = 0; i < rozm; i++) lista->dodajNaKon(rand() % 50 + 1);
    wyswietlLista();
    menuListy();
}

void Menu::wyswietlLista()
{
    cout << "\nZawartosc listy (od poczatku do konca): ";
    for (int i = 0; i < lista->rozmiar(); i++) cout << lista->zawartosc(i) << endl;
    menuListy();
}

void Menu::testLista()
{
    auto* test = new TestListy();                               //Stworzenie obiektu klasy testu listy i uruchomienie metody.
    test->sredniTestDodawania();
    test->sredniTestUsuwania();
    test->sredniTestSzukania();

    delete test;
    menuListy();
}