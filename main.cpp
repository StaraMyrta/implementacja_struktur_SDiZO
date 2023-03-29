#include <iostream>
#include <ctime>
#include "Menu/Menu.h"

using namespace std;

int main()
{
    //Możliwość wyświetlania polskich znaków w konsoli Windows.
    system("@chcp 65001 >nul");

    auto* menu = new Menu();
    auto* tablica = new MenuTablicy();
    //auto* list = new ListItem();
    //auto* heap = new BinaryHeapItem();
    //auto* tree = new TreeItem();
    menu->dodajMenu(tablica);
    //menu->addMenuItem(list);
    //menu->addMenuItem(heap);
    //menu->addMenuItem(tree);
    menu->wybor();
    delete menu;
    return 0;
}