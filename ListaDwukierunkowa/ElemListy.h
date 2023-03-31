//Struktura dla elementu listy.
struct ElemListy
{
    int wartosc;    //Wartoœæ liczbowa danego elementu listy.
    /// WskaŸnik na nastêpny element listy.
    ElemListy* nast;
    /// WskaŸnik na poprzedni element listy.
    ElemListy* poprz;
};