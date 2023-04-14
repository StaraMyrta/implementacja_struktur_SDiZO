#include "TestDrzewaRB.h"

using namespace std;

TestRB::TestRB()
{
    drzewo = new DrzewoRB();
}

TestRB::~TestRB()
{
    delete drzewo;
}

void TestRB::wypelnijDrzewo(int rozm)
{
    delete drzewo;                              //Dealokacja kopca i przydzielenie pamiêci dla nowego obiektu.
    drzewo = new DrzewoRB();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < rozm; i++) drzewo->dodaj(dist(gen));    //Wype³nienie kopca 'rozm' liczbami z przedzia³u [0, rozm - 1] 
}

void TestRB::sredniTestDodawania()
{
    double wyniki[8];                           //Testy dodawania elementów dla ró¿nych wielkoœci struktury.
    wyniki[0] = dodajTest(100);
    wyniki[1] = dodajTest(200);
    wyniki[2] = dodajTest(400);
    wyniki[3] = dodajTest(800);
    wyniki[4] = dodajTest(1600);
    wyniki[5] = dodajTest(3200);
    wyniki[6] = dodajTest(6400);
    wyniki[7] = dodajTest(12800);

    cout << "\nDodawanie dla 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000 elementow: " << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << endl;
    }
}

void TestRB::sredniTestUsuwania()
{
    double wyniki[8];                           //Testy usuwania elementów dla ró¿nych wielkoœci struktury.
    //wyniki[0] = usunTest(1000);
    //wyniki[1] = usunTest(5000);
    //wyniki[2] = usunTest(10000);
    //wyniki[3] = usunTest(50000);
    //wyniki[4] = usunTest(100000);
    //wyniki[5] = usunTest(500000);
    //wyniki[6] = usunTest(1000000);
    //wyniki[7] = usunTest(5000000);

    cout << "\nUsuwanie korzenia dla  1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000 elementow:  " << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << endl;
    }
}

void TestRB::sredniTestSzukania()
{
    double wyniki[8];                           //Testy wyszukiwania elementów dla ró¿nych wielkoœci struktury.
    //wyniki[0] = znajdzTest(1000);
    //wyniki[1] = znajdzTest(5000);
    //wyniki[2] = znajdzTest(10000);
    //wyniki[3] = znajdzTest(50000);
    //wyniki[4] = znajdzTest(100000);
    //wyniki[5] = znajdzTest(500000);
    //wyniki[6] = znajdzTest(1000000);
    //wyniki[7] = znajdzTest(5000000);

    cout << "\nWyszukiwanie dla 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000 elementow: " << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << endl;
    }
}
double TestRB::dodajTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 20 dodañ ze zmienionym za ka¿dym razem datasetem.
    for (int i = 0; i < 30; i++)
    {
        wypelnijDrzewo(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        drzewo->dodaj(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 30;
}

double TestRB::usunTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 20 usuniêæ ze zmienionym za ka¿dym razem datasetem.
    for (int i = 0; i < 30; i++)
    {
        wypelnijDrzewo(rozm);
        pomiar.czasStart();
        drzewo->usun(rand()%rozm);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 30;
}

double TestRB::znajdzTest(int rozm)
{
    //Wynik to œrednia ze 20 wyszukañ ze zmienionym za ka¿dym razem datasetem.
    double srednia = 0;
    for (int i = 0; i < 30; i++)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1, 1000000);
        wypelnijDrzewo(rozm);
        int elem = dist(gen);
        pomiar.czasStart();
        drzewo->znajdz(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 30;
}