//Struktura dla elementu drzewa RB.
struct ElemRB {
    ElemRB(int wartosc) { number = wartosc; }

    int number;
    ElemRB* lewy = nullptr;
    ElemRB* prawy = nullptr;
    ElemRB* rodzic = nullptr;
    bool color;                     //false = czerwony, true = czarny
};