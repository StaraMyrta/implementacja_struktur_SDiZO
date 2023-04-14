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
        else if (wejscie == "1")
        {
            tablica = new TablicaDynamiczna();
            menuTablicy();
        }
        else if (wejscie == "2")
        {
            lista = new ListaDwukierunkowa(); 
            menuListy();
        }
        else if (wejscie == "3")
        {
            kopiec = new KopiecBinarny();
            menuKopca();
        }
        else if (wejscie == "4") 
        {
            drzewoBST = new DrzewoBST();

            cout << endl;                                               //Wybór operacji.
            cout << "Menu dla drzewa BST:" << endl;
            cout << "1. Wczytaj z pliku (1)" << endl;
            cout << "2. Usun (2)" << endl;
            cout << "3. Dodaj (3)" << endl;
            cout << "4. Znajdz (4)" << endl;
            cout << "5. Utworz losowo (5)" << endl;
            cout << "6. Wyswietl (6)" << endl;
            cout << "7. Testuj (7)" << endl;
            cout << "8. Wroc (powrot)" << endl;
            cout << "Wybierz opcje: ";

            menuBST();
        }

        else if (wejscie == "5")
        {
            cout << endl;                                               //Wybór operacji.
            cout << "Menu dla drzewa BST:" << endl;
            cout << "1. Wczytaj z pliku (1)" << endl;
            cout << "2. Usun (2)" << endl;
            cout << "3. Dodaj (3)" << endl;
            cout << "4. Znajdz (4)" << endl;
            cout << "5. Utworz losowo (5)" << endl;
            cout << "6. Wyswietl (6)" << endl;
            cout << "7. Testuj (7)" << endl;
            cout << "8. Wroc (powrot)" << endl;
            cout << "Wybierz opcje: ";

            menuRB();
        }
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
    wyborStruktury();
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
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < rozm; i++) tablica->dodaj(dist(gen));
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
    wyborStruktury();
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
    cout << "\nPodaj indeks elementu do dodania: ";
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
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < rozm; i++) lista->dodajNaKon(dist(gen));
    wyswietlLista();
    menuListy();
}

void Menu::wyswietlLista()
{
    cout << "\nZawartosc listy (od poczatku do konca): ";
    for (int i = 0; i < lista->rozmiar(); i++) cout << lista->zawartosc(i) << ", ";
    cout << "\nZawartosc listy (od konca do poczatku): ";
    for (int i = lista->rozmiar() - 1; i >= 0; i--) cout << lista->zawartosc(i) << ", ";
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

void Menu::menuKopca()
{
    cout << endl;                                                   //Wybór operacji.
    cout << "Menu dla kopca:" << endl;
    cout << "1. Wczytaj z pliku (K1)" << endl;
    cout << "2. Usun (K2)" << endl;
    cout << "3. Dodaj (K3)" << endl;
    cout << "4. Znajdz (K4)" << endl;
    cout << "5. Utworz losowo (K5)" << endl;
    cout << "6. Wyswietl (K6)" << endl;
    cout << "7. Testuj (K7)" << endl;
    cout << "8. Wroc (powrot)" << endl;
    cout << "Wybierz opcje: ";

    powrot = false;
    while (!powrot)
    {
        cin >> wejscie;
        if (wejscie == "K1") wczytajPlikDoKopca();
        else if (wejscie == "K2") usunKopiec();
        else if (wejscie == "K3") dodajKopiec();
        else if (wejscie == "K4") znajdzKopiec();
        else if (wejscie == "K5") stworzLosowoKopiec();
        else if (wejscie == "K6") wyswietlKopiec();
        else if (wejscie == "K7") testKopiec();
        else if (wejscie == "powrot") powrot = true;
        else cout << "Nieznane polecenie!" << endl;
    }

    delete kopiec;                                                   //Po wyjœciu z pêtli kopiec zostaje zdealokowany.
    wyborStruktury();
}


void Menu::wczytajPlikDoKopca()
{
    string nazwaPliku;
    int licznik, elem;
    cout << "\nPodaj nazwe pliku: ";
    cin >> nazwaPliku;
    ifstream plik;
    plik.open(nazwaPliku);
    if (plik.is_open())
    {
        delete kopiec;
        kopiec = new KopiecBinarny();
        plik >> licznik;
        for (int i = 0; i < licznik; i++)
        {
            plik >> elem;
            kopiec->dodaj(elem);
        }
        wyswietlKopiec();
    }
    else cout << "Podana nazwa pliku jest nieprawidlowa!" << endl;
    plik.close();
    menuKopca();
}

void Menu::usunKopiec()
{
    int elem;
    cout << "\nPodaj wartosc elementu do usuniecia: ";
    cin >> elem;
    if (!kopiec->usun(elem))
        cout << "Nie znaleziono takiego elementu!" << endl;
    wyswietlKopiec();
    menuKopca();
}

void Menu::dodajKopiec()
{
    int elem;
    cout << "Podaj wartosc elementu: ";
    cin >> elem;
    kopiec->dodaj(elem);
    
    menuKopca();
}

void Menu::znajdzKopiec()
{
    int elem;
    cout << "\nPodaj wartosc elementu: ";
    cin >> elem;
    if (kopiec->znajdz(elem)) cout << "Znaleziono element o takiej wartosci!" << endl;
    else cout << "Nie znaleziono elementu o takiej wartosci!" << endl;
    wyswietlKopiec();
    menuKopca();
}

void Menu::stworzLosowoKopiec()
{
    delete kopiec;                                               //Dealokacja listy i rezerwacja pamiêci na nowy obiekt.
    kopiec = new KopiecBinarny();
    int rozm;
    cout << "\nPodaj wielkosc kopca: ";
    cin >> rozm;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < rozm; i++) kopiec->dodaj(dist(gen));
    wyswietlKopiec();
    menuKopca();
}

void Menu::wyswietlKopiec()
{
    cout << endl;
    kopiec->wyswietlDrzewo();
}

void Menu::testKopiec()
{
    auto* test = new TestKopca();                               //Stworzenie obiektu klasy testu listy i uruchomienie metody.
    test->sredniTestDodawania();
    test->sredniTestUsuwania();
    test->sredniTestSzukania();

    delete test;
    menuKopca();
}

void Menu::menuBST()
{
    powrot = false;
    while (!powrot)
    {
        cin >> wejscie;
        if (wejscie == "1") wczytajPlikDoBST();
        else if (wejscie == "2") usunBST();
        else if (wejscie == "3") dodajBST();
        else if (wejscie == "4") znajdzBST();
        else if (wejscie == "5") stworzLosowoBST();
        else if (wejscie == "6") wyswietlBST();
        else if (wejscie == "7") testBST();
        else if (wejscie == "powrot") powrot = true;
        else cout << "Nieznane polecenie!" << endl;
    }
    delete drzewoBST;                                             //Po wyjœciu z pêtli tablica zostaje zdealokowana.
    wyborStruktury();
}

void Menu::wczytajPlikDoBST() {

    usunBST();
    string nazwaPliku;
    int licznik, elem;
    cout << "\nPodaj nazwe pliku: ";
    cin >> nazwaPliku;
    ifstream plik;
    plik.open(nazwaPliku);
    if (plik.is_open())
    {
        drzewoBST = new DrzewoBST();
        plik >> licznik;
        for (int i = 0; i < licznik; i++)
        {
            plik >> elem;
            drzewoBST->dodaj(elem);
        }
        wyswietlBST();
    }
    else cout << "Podana nazwa pliku jest nieprawidlowa!" << endl;
    plik.close();
    menuKopca();
}

void Menu::usunBST()
{
    int elem;
    cout << "\nPodaj wartosc elementu do usuniecia: ";
    cin >> elem; 
    drzewoBST->usun(elem);
    wyswietlBST();
    menuBST();
}

void Menu::dodajBST()
{
    int elem;
    cout << "Podaj wartosc elementu: ";
    cin >> elem;
    drzewoBST->dodaj(elem);
    wyswietlBST();
    menuBST();
}

void Menu::znajdzBST()
{
    int elem;
    cout << "\nPodaj wartosc elementu: ";
    cin >> elem;
    if (drzewoBST->znajdz(elem)) cout << "Znaleziono element o takiej wartosci!" << endl;
    else cout << "Nie znaleziono elementu o takiej wartosci!" << endl;
    menuBST();
}

void Menu::stworzLosowoBST()
{
    delete drzewoBST;                                               //Dealokacja listy i rezerwacja pamiêci na nowy obiekt.
    drzewoBST = new DrzewoBST();
    int rozm;
    cout << "\nPodaj ilosc elementow: ";
    cin >> rozm;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < rozm; i++) drzewoBST->dodaj(dist(gen));
    wyswietlBST();
    menuBST();
}

void Menu::wyswietlBST()
{
    cout << endl;
    drzewoBST->wyswietlDrzewo();
}

void Menu::testBST()
{
    auto* test = new TestBST();                               //Stworzenie obiektu klasy testu listy i uruchomienie metody.
    test->sredniTestDodawania();
    test->sredniTestUsuwania();
    test->sredniTestSzukania();

    delete test;
    menuBST();
}

void Menu::menuRB()
{
    powrot = false;
    while (!powrot)
    {
        cin >> wejscie;
        if (wejscie == "1") wczytajPlikDoRB();
        else if (wejscie == "2") usunRB();
        else if (wejscie == "3") dodajRB();
        else if (wejscie == "4") znajdzRB();
        else if (wejscie == "5") stworzLosowoRB();
        else if (wejscie == "6") wyswietlRB();
        else if (wejscie == "7") testRB();
        else if (wejscie == "powrot") powrot = true;
        else cout << "Nieznane polecenie!" << endl;
    }
    delete drzewoRB;                                             //Po wyjœciu z pêtli tablica zostaje zdealokowana.
    wyborStruktury();
}

void Menu::wczytajPlikDoRB() {

    usunRB();
    string nazwaPliku;
    int licznik, elem;
    cout << "\nPodaj nazwe pliku: ";
    cin >> nazwaPliku;
    ifstream plik;
    plik.open(nazwaPliku);
    if (plik.is_open())
    {
        drzewoRB = new DrzewoRB();
        plik >> licznik;
        for (int i = 0; i < licznik; i++)
        {
            plik >> elem;
            drzewoRB->dodaj(elem);
        }
        wyswietlRB();
    }
    else cout << "Podana nazwa pliku jest nieprawidlowa!" << endl;
    plik.close();
    menuKopca();
}

void Menu::usunRB()
{
    int elem;
    cout << "\nPodaj wartosc elementu do usuniecia: ";
    cin >> elem;
    drzewoRB->usun(elem);
    wyswietlRB();
    menuRB();
}

void Menu::dodajRB()
{
    int elem;
    cout << "Podaj wartosc elementu: ";
    cin >> elem;
    drzewoRB->dodaj(elem);
    wyswietlRB();
    menuRB();
}

void Menu::znajdzRB()
{
    int elem;
    cout << "\nPodaj wartosc elementu: ";
    cin >> elem;
    if (drzewoRB->znajdz(elem)) cout << "Znaleziono element o takiej wartosci!" << endl;
    else cout << "Nie znaleziono elementu o takiej wartosci!" << endl;
    menuRB();
}

void Menu::stworzLosowoRB()
{
    delete drzewoRB;                                               //Dealokacja listy i rezerwacja pamiêci na nowy obiekt.
    drzewoRB = new DrzewoRB();
    int rozm;
    cout << "\nPodaj ilosc elementow: ";
    cin >> rozm;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < rozm; i++) drzewoRB->dodaj(dist(gen));
    wyswietlRB();
    menuRB();
}

void Menu::wyswietlRB()
{
    cout << "\n0 - wezel czerwony, 1- wezel czarny\n\n";;
    drzewoRB->wyswietlDrzewo();
}

void Menu::testRB()
{
    auto* test = new TestRB();                               //Stworzenie obiektu klasy testu listy i uruchomienie metody.
    test->sredniTestDodawania();
    test->sredniTestUsuwania();
    test->sredniTestSzukania();

    delete test;
    menuRB();
}