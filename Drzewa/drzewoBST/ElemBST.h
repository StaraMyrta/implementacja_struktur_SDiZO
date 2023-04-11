//Struktura dla elementu drzewa BST.
struct ElemBST {
    ElemBST(int wartosc) { number = wartosc; }

    int number;
    ElemBST* lewy = nullptr;
    ElemBST* prawy = nullptr;
    ElemBST* rodzic = nullptr;
};