#include <iostream>
#include <ctime>
#include "Menu/Menu.h"

using namespace std;

int main()
{
    system("@chcp 65001 >nul");         //Możliwość wyświetlania polskich znaków w konsoli Windows.

    auto* menu = new Menu();            //Wywołanie Menu, umożliwiającego użytkownikowi wybór struktur i operacji poprzez konsolę
    menu->wyborStruktury();
    delete menu;
    return 0;
}