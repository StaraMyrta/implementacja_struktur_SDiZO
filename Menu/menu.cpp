#include "Menu.h"

using namespace std;

//Klasie menu wystarcza domy�lny konstruktor.
Menu::Menu() = default;

Menu::~Menu()
{
    for (auto obiekt : obiekty)
    {
        delete obiekt;
    }
}

void Menu::dodajMenu(ObiektMenu* obiekt)
{
    //Dodaje menu.
    obiekty.push_back(obiekt);
}

void Menu::wyswietlMenu()
{
    //Dla ka�dego menu wy�wietlamy jest opis.
    cout << endl;
    cout << "Menu aplikacji" << endl;
    int i = 1;
    for (ObiektMenu* obiekt : obiekty)
    {
        cout << i << ". " << obiekt -> pokazOpisMenu() << endl;
        i++;
    }
    cout << i << ". " << "Wyjdz" << endl;
    cout << "Wybierz opcje: ";
}

void Menu::wybor()
{
    //Wczytuje dane z konsoli do 'wejscie' i wykonuje funkcj� 'wybor()'
    //dla elementu menu, kt�rego komenda zgadza si� z podan�.
    string wejscie;
    powrot = false;
    while (!powrot)
    {
        wyswietlMenu();
        cin >> wejscie;
        nieznanaKomenda = true;
        //Je�li komenda to 'quit' ustawia flagi aby umo�liwi� wyj�cie z p�tli.
        if (wejscie == "quit")
        {
            powrot = true;
            nieznanaKomenda = false;
        }

        for (ObiektMenu* obiekt : obiekty)
        {
            if (wejscie == obiekt -> pokazKomende())
            {
                obiekt -> wybor();
                nieznanaKomenda = false;
            }
        }
        if (nieznanaKomenda) cout << "Nieznane polecenie!" << endl;
    }
}