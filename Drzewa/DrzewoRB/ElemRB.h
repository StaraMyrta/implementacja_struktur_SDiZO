
struct ElemRB
{
	ElemRB* rodzic;
	ElemRB* lewy;
	ElemRB* prawy;
	int number;
	bool kolor;		//false = czerwony, true = czarny
};