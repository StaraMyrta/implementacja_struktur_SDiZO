#include <iostream>
#include <ctime>
#include "Menu/Menu.h"

using namespace std;

int main()
{
    //Możliwość wyświetlania polskich znaków w konsoli Windows.
    system("@chcp 65001 >nul");

    auto* menu = new Menu();
    menu->wyborStruktury();
    delete menu;
    return 0;
}