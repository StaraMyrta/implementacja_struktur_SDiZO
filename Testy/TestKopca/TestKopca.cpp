#include "TestKopca.h"

TestKopca::TestKopca()
{
    kopiec = new KopiecBinarny();
}

TestKopca::~TestKopca()
{
    delete kopiec;
}

void TestKopca::wypelnijKopiec(int rozm)
{
    delete kopiec;                              //Dealokacja kopca i przydzielenie pamiêci dla nowego obiektu.
    kopiec = new KopiecBinarny();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < rozm; i++) kopiec->dodaj(dist(gen));    //Wype³nienie kopca 'rozm' liczbami z przedzia³u [0, rozm - 1] 
}

void TestKopca::sredniTestDodawania()
{
    double wyniki[5];                           //Testy dodawania elementów dla ró¿nych wielkoœci struktury.
    wyniki[0] = dodajTest(1000);
    wyniki[1] = dodajTest(2000);
    wyniki[2] = dodajTest(5000);
    wyniki[3] = dodajTest(10000);
    wyniki[4] = dodajTest(20000);

    cout << "\nDodawanie dla 1000, 2000, 5000, 10000, 20000 elementow: " << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << " us" << endl;
    }
}

void TestKopca::sredniTestUsuwania()
{
    double wyniki[5];                           //Testy usuwania elementów dla ró¿nych wielkoœci struktury.
    wyniki[0] = usunTest(1000);
    wyniki[1] = usunTest(2000);
    wyniki[2] = usunTest(5000);
    wyniki[3] = usunTest(10000);
    wyniki[4] = usunTest(20000);

    cout << "\nUsuwanie korzenia dla 1000, 2000, 5000, 10000, 20000 elementow: " << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << " us" << endl;
    }
}

void TestKopca::sredniTestSzukania()
{
    double wyniki[5];                           //Testy wyszukiwania elementów dla ró¿nych wielkoœci struktury.
    wyniki[0] = znajdzTest(1000);
    wyniki[1] = znajdzTest(2000);
    wyniki[2] = znajdzTest(5000);
    wyniki[3] = znajdzTest(10000);
    wyniki[4] = znajdzTest(20000);

    cout << "\nWyszukiwanie dla 1000, 2000, 5000, 10000, 20000 elementow:" << endl;
    for (double wynik : wyniki)
    {
        cout << wynik << " us" << endl;
    }
}
double TestKopca::dodajTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 dodañ ze zmienionym za ka¿dym razem datasetem.
    for (int i = 0; i < 100; i++)
    {
        wypelnijKopiec(rozm);
        int elem = rand() % rozm;
        pomiar.czasStart();
        kopiec->dodaj(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 100;
}

double TestKopca::usunTest(int rozm)
{
    double srednia = 0;                         //Wynik to œrednia ze 100 usuniêæ ze zmienionym za ka¿dym razem datasetem.
    for (int i = 0; i < 100; i++)
    {
        wypelnijKopiec(rozm);
        pomiar.czasStart();
        kopiec->usunKorzen();
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 100;
}

double TestKopca::znajdzTest(int rozm)
{
    //Wynik to œrednia ze 100 wyszukañ ze zmienionym za ka¿dym razem datasetem.
    double srednia = 0;
    for (int i = 0; i < 100; i++)
    {
        wypelnijKopiec(rozm);
        int elem = kopiec->zawartosc(rand() % kopiec->ileWierzcholkow());
        pomiar.czasStart();
        kopiec->znajdz(elem);
        pomiar.czasStop();
        srednia += pomiar.jakiCzasTrwania();
    }
    return srednia / 100;
}