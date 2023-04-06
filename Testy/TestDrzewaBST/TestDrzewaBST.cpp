#include "TestDrzewaBST.h"

TestBST::TestBST()
{
    drzewo = new DrzewoBST();
}

TestBST::~TestBST()
{
    delete drzewo;
}

void TestBST::wypelnijDrzewo(int rozm)
{
    delete drzewo;                              //Dealokacja kopca i przydzielenie pami�ci dla nowego obiektu.
    drzewo = new DrzewoBST();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < rozm; i++) drzewo->dodaj(dist(gen));    //Wype�nienie kopca 'rozm' liczbami z przedzia�u [0, rozm - 1] 
}

void TestBST::sredniTestDodawania()
{
    double wyniki[8];                           //Testy dodawania element�w dla r�nych wielko�ci struktury.
    wyniki[0] = dodajTest(1000);
    wyniki[1] = dodajTest(5000);
    wyniki[2] = dodajTest(10000);
    wyniki[3] = dodajTest(50000);
    wyniki[4] = dodajTest(100000);
    wyniki[5] = dodajTest(500000);
    wyniki[6] = dodajTest(1000000);
    wyniki[7] = dodajTest(5000000);

    cout << "\nDodawanie dla 1000, 5000, 10000, 50000, 100000, 500000 elementow: " << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << " us" << endl;
    }
}

void TestBST::sredniTestUsuwania()
{
    double wyniki[7];                           //Testy usuwania element�w dla r�nych wielko�ci struktury.
    wyniki[0] = usunTest(1000);
    wyniki[1] = usunTest(5000);
    wyniki[2] = usunTest(10000);
    wyniki[3] = usunTest(50000);
    wyniki[4] = usunTest(100000);
    wyniki[5] = usunTest(500000);
    wyniki[6] = usunTest(1000000);
    wyniki[7] = usunTest(5000000);

    cout << "\nUsuwanie korzenia dla  1000, 5000, 10000, 50000, 100000, 500000 elementow:  " << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << " us" << endl;
    }
}

void TestBST::sredniTestSzukania()
{
    double wyniki[7];                           //Testy wyszukiwania element�w dla r�nych wielko�ci struktury.
    wyniki[0] = znajdzTest(1000);
    wyniki[1] = znajdzTest(5000);
    wyniki[2] = znajdzTest(10000);
    wyniki[3] = znajdzTest(50000);
    wyniki[4] = znajdzTest(100000);
    wyniki[5] = znajdzTest(500000);
    wyniki[6] = znajdzTest(1000000);
    wyniki[7] = znajdzTest(5000000);

    cout << "\nWyszukiwanie dla 1000, 5000, 10000, 50000, 100000, 500000 elementow: " << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << " us" << endl;
    }
}
double TestBST::dodajTest(int rozm)
{
    double srednia = 0;                         //Wynik to �rednia ze 100 doda� ze zmienionym za ka�dym razem datasetem.
    for (int i = 0; i < 10; i++)
    {
        wypelnijDrzewo(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        drzewo->dodaj(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 10;
}

double TestBST::usunTest(int rozm)
{
    double srednia = 0;                         //Wynik to �rednia ze 100 usuni�� ze zmienionym za ka�dym razem datasetem.
    for (int i = 0; i < 10; i++)
    {
        wypelnijDrzewo(rozm);
        pomiar.czasStart();
        drzewo->usunKorzen();
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 10;
}

double TestBST::znajdzTest(int rozm)
{
    //Wynik to �rednia ze 100 wyszuka� ze zmienionym za ka�dym razem datasetem.
    double srednia = 0;
    for (int i = 0; i < 10; i++)
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
    return srednia / 10;
}