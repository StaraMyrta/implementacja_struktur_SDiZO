//Struktura dla elementu listy.
struct ElemListy
{
    int wartosc;    //Warto�� liczbowa danego elementu listy.
    /// Wska�nik na nast�pny element listy.
    ElemListy* nast;
    /// Wska�nik na poprzedni element listy.
    ElemListy* poprz;
};