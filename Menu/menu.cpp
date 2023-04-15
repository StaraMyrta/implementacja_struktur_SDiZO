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
    cout << "4. Drzewo Czerwono-Czarne (4)" << endl;
    cout << "5. Zamknij program (powrot)" << endl;
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
            drzewoRB = new DrzewoRB();

            menuRB();
        }
    }
}

void Menu::menuTablicy()
{

    cout << endl;                                               //Wybór operacji.
    cout << "Menu dla tablicy:" << endl;
    cout << "1. Wczytaj z pliku (1)" << endl;
    cout << "2. Usun (do wyboru poczatek, koniec, wybrane inne miejsce) (2)" << endl;
    cout << "3. Dodaj (do wyboru poczatek, koniec, wybrane inne miejsce) (3)" << endl;
    cout << "4. Znajdz (4)" << endl;
    cout << "5. Utworz losowo (5)" << endl;
    cout << "6. Wyswietl (6)" << endl;
    cout << "7. Testuj (7)" << endl;
    cout << "8. Wroc (powrot)" << endl;
    cout << "Wybierz opcje: ";

    while (!powrot)
    {
        cin >> wejscie;
        if (wejscie == "1") wczytajPlikDoTablicy();
        else 
            if (wejscie == "2")
            {
                cout << "Opcje usuwania:" << endl;
                cout << "Usuwanie z poczatku (1)" << endl;
                cout << "Usuwanie z konca (2)" << endl;
                cout << "Usuwanie z dowolnego wybranego miejsca (3)" << endl;

                cin >> wejscie2;
                if (wejscie2 == "1") usunTablica(1);
                else if (wejscie2 == "2") usunTablica(2);
                else if (wejscie2 == "3") usunTablica(3);
            }
        else 
            if (wejscie == "3")
            {
                cout << "Opcje dodawania:" << endl;
                cout << "Dodawanie na poczatek (1)" << endl;
                cout << "Dodawanie na koniec (2)" << endl;
                cout << "Dodawanie w inne dowolnie wybrane miejsce (3)" << endl;

                cin >> wejscie2;
                if (wejscie2 == "1") dodajTablica(1);
                else if (wejscie2 == "2") dodajTablica(2);
                else if (wejscie2 == "3") dodajTablica(3);

            }
        else if (wejscie == "4") znajdzTablica();
        else if (wejscie == "5") stworzLosowoTablica();
        else if (wejscie == "6") wyswietlTablica();
        else if (wejscie == "7") testTablica();
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

void Menu::usunTablica(int wybor)
{
    if (wybor == 1) tablica->usun(0);
    else if (wybor == 2) tablica->usunKoniec();
    else
    {
        int indeks;
        cout << "\nPodaj indeks elementu do usuniecia: ";
        cin >> indeks;
        try
        {
            tablica->usun(indeks);
        }
        catch (out_of_range& e)
        {
            cout << e.what() << endl;
        }
    }
    wyswietlTablica();
    menuTablicy();
}

void Menu::dodajTablica(int wybor)
{
    int elem;
    cout << "Podaj wartosc elementu: ";
    cin >> elem;

    if (wybor == 1) tablica->dodajNaPocz(elem);
    else if (wybor == 2) tablica->dodajNaKon(elem);
    else
    {
        int indeks;
        cout << "\nPodaj indeks elementu do dodania: ";
        cin >> indeks;
        try
        {
            tablica->dodaj(indeks, elem);
        }
        catch (out_of_range& e)
        {
            cout << e.what() << endl;
        }
    }
    wyswietlTablica();
    menuTablicy();
}

void Menu::znajdzTablica()
{
    int elem;
    cout << "\nPodaj wartosc elementu: ";
    cin >> elem;
    int indeks = tablica->znajdz(elem);
    if(indeks == -1) cout << "Nie znaleziono elementu o takiej wartosci!" << endl;
    else cout << "Znaleziono element o takiej wartosci! Jego indeks to:" << indeks << endl;
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
    cout << "1. Wczytaj z pliku (1)" << endl;
    cout << "2. Usun (do wyboru poczatek, koniec, wybrane inne miejsce) (2)" << endl;
    cout << "3. Dodaj (do wyboru poczatek, koniec, wybrane inne miejsce) (3)" << endl;
    cout << "4. Znajdz (4)" << endl;
    cout << "5. Utworz losowo (5)" << endl;
    cout << "6. Wyswietl (6)" << endl;
    cout << "7. Testuj (7)" << endl;
    cout << "8. Wroc (powrot)" << endl;
    cout << "Wybierz opcje: ";

    while (!powrot)
    {
        cin >> wejscie;
        if (wejscie == "1") wczytajPlikDoListy();
        else
            if (wejscie == "2")
            {
                cout << "Opcje usuwania:" << endl;
                cout << "Usuwanie z poczatku (1)" << endl;
                cout << "Usuwanie z konca (2)" << endl;
                cout << "Usuwanie z dowolnego wybranego miejsca (3)" << endl;

                cin >> wejscie2;
                if (wejscie2 == "1") usunLista(1);
                else if (wejscie2 == "2") usunLista(2);
                else if (wejscie2 == "3") usunLista(3);
            }
            else
                if (wejscie == "3")
                {
                    cout << "Opcje dodawania:" << endl;
                    cout << "Dodawanie na poczatek (1)" << endl;
                    cout << "Dodawanie na koniec (2)" << endl;
                    cout << "Dodawanie w inne dowolnie wybrane miejsce (3)" << endl;

                    cin >> wejscie2;
                    if (wejscie2 == "1") dodajLista(1);
                    else if (wejscie2 == "2") dodajLista(2);
                    else if (wejscie2 == "3") dodajLista(3);

                }
        else if (wejscie == "4") znajdzLista();
        else if (wejscie == "5") stworzLosowoLista();
        else if (wejscie == "6") wyswietlLista();
        else if (wejscie == "7") testLista();
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

void Menu::usunLista(int wybor)
{
    if (wybor == 1) lista->usunZPocz();
    else if (wybor == 2) lista->usunZKon();
    else
    {
        int indeks;
        cout << "\nPodaj indeks elementu do usuniecia: ";
        cin >> indeks;
        lista->zakres(indeks);
        lista->usun(indeks); 
    }
    wyswietlLista();
    menuListy();
}

void Menu::dodajLista(int wybor)
{
    int elem;
    cout << "Podaj wartosc elementu: ";
    cin >> elem;

    if (wybor == 1) lista->dodajNaPocz(elem);
    else if (wybor == 2) lista->dodajNaKon(elem);
    else
    {
        int indeks;
        cout << "\nPodaj indeks elementu do dodania: ";
        cin >> indeks;
        try
        {
            if (indeks == 0) lista->dodajNaPocz(elem);
            else lista->dodajZa(indeks - 1, elem);
        }
        catch (out_of_range& e)
        {
            cout << e.what() << endl;
        }
    }
    wyswietlLista();
    menuListy();
}

void Menu::znajdzLista()
{
    int elem;
    cout << "\nPodaj wartosc elementu: ";
    cin >> elem;
    int indeks = lista->znajdz(elem);
    if (indeks == -1) cout << "Nie znaleziono elementu o takiej wartosci!" << endl;
    else cout << "Znaleziono element o takiej wartosci! Jego indeks to:" << indeks << endl;
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
    cout << "1. Wczytaj z pliku (1)" << endl;
    cout << "2. Usun (2)" << endl;
    cout << "3. Dodaj (3)" << endl;
    cout << "4. Znajdz (4)" << endl;
    cout << "5. Utworz losowo (5)" << endl;
    cout << "6. Wyswietl (6)" << endl;
    cout << "7. Testuj (7)" << endl;
    cout << "8. Wroc (powrot)" << endl;
    cout << "Wybierz opcje: ";

    while (!powrot)
    {
        cin >> wejscie;
        if (wejscie == "1") wczytajPlikDoKopca();
        else if (wejscie == "2") usunKopiec();
        else if (wejscie == "3") dodajKopiec();
        else if (wejscie == "4") znajdzKopiec();
        else if (wejscie == "5") stworzLosowoKopiec();
        else if (wejscie == "6") wyswietlKopiec();
        else if (wejscie == "7") testKopiec();
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
    kopiec->usunKorzen();
    wyswietlKopiec();
    menuKopca();
}

void Menu::dodajKopiec()
{
    int elem;
    cout << "Podaj wartosc elementu: ";
    cin >> elem;
    kopiec->dodaj(elem);
    
    wyswietlKopiec();
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
    menuKopca();
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

void Menu::menuRB()
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
    menuRB();
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