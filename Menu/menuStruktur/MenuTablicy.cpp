#include "MenuTablicy.h"
#include "../../Test/TestTablicy/TestTablicy.h"

using namespace std;

MenuTablicy::MenuTablicy()
{
    //Ustawiamy zmienne definiuj¹ce opis menu.
    opisMenu = "Tablica";
    menuCommand = "tablica";
}

void MenuTablicy::wyswietlMenu()
{
    //Wypisane menu dla tablicy.
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
    //Tworzy nowy obiekt klasy Array i wchodzi do pêtli obs³ugi opcji.
    tablica = new TablicaDynamiczna();
    string wejscie;
    powrot = false;
    while (!powrot)
    {
        wyswietlMenu();
        cin >> wejscie;
        if (wejscie == "load") loadFile();
        else if (wejscie == "delete") deleteItem();
        else if (wejscie == "add") addItem();
        else if (wejscie == "find") findItem();
        else if (wejscie == "rand") createRandom();
        else if (wejscie == "disp") display();
        else if (wejscie == "test") test();
        else if (wejscie == "back") backTyped = true;
        else cout << "Nieznane polecenie!" << endl;
    }
    //Po wyjœciu z pêtli dealokujemy tablicê.
    delete array;
}

void MenuTablicy::loadFile()
{
    //Standardowe wczytywanie z pliku.
    std::string fileName;
    int count, element;
    std::cout << "\nPodaj nazwe pliku: ";
    std::cin >> fileName;
    std::ifstream file;
    file.open(fileName);
    if (file.is_open())
    {
        delete array;
        array = new Array();
        file >> count;
        for (int i = 0; i < count; i++)
        {
            file >> element;
            array->add(element);
        }
        display();
    }
    else std::cout << "Podana nazwa pliku jest nieprawidlowa!" << std::endl;
    file.close();
}

void MenuTablicy::deleteItem()
{
    //Usuwanie elementu dla danego indexu.
    int index;
    std::cout << "\nPodaj index elementu do usuniecia: ";
    std::cin >> index;
    try
    {
        array->remove(index);
        display();
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void MenuTablicy::addItem()
{
    //Dodawanie elementu dla danego indexu.
    int index;
    int element;
    std::cout << "\nPodaj index elementu do dodania: ";
    std::cin >> index;
    std::cout << "Podaj wartosc elementu: ";
    std::cin >> element;
    try
    {
        array->add(index, element);
        display();
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void MenuTablicy::findItem()
{
    //Wyszukiwanie elementu.
    int element;
    std::cout << "\nPodaj wartosc elementu: ";
    std::cin >> element;
    if (array->find(element)) std::cout << "Znaleziono element o takiej wartosci!" << std::endl;
    else std::cout << "Nie znaleziono elementu o takiej wartosci!" << std::endl;
    display();
}

void MenuTablicy::createRandom()
{
    //Dealokujemy tablicê i alokujemy pamiêæ na nowy obiekt.
    delete array;
    array = new Array();
    int size;
    std::cout << "\nPodaj wielkosc tablicy: ";
    std::cin >> size;
    for (int i = 0; i < size; i++) array->add(rand() % 50 + 1);
    display();
}

void MenuTablicy::display()
{
    //Wyœwietlamy zawartoœæ tablicy.
    std::cout << "\nZawartosc tablicy: ";
    for (int i = 0; i < array->getSize(); i++) std::cout << array->get(i) << " ";
    std::cout << std::endl;
}

void MenuTablicy::test()
{
    //Tworzymy obiekt klasy testu tablicy i uruchamiamy metody.
    auto* test = new ArrayTest();
    test->addTestAverage();
    test->removeTestAverage();
    test->findTestAverage();
    //Usuwamy obiekt z zaalokowan¹, osobn¹ tablic¹.
    delete test;
}