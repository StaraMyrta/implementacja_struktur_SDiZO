#include "ElemRB.h"
class DrzewoRB
{
private:
    string cr, cl, cp;
	ElemRB* korzen = nullptr;
public:
	int rozm;
	DrzewoRB();
	~DrzewoRB();
	// member methods declaration
	void deleteTree(ElemRB* node);
	void buildRandomly(int enteredAmount);
	void buildFromFile();
	bool findKey(int enteredValue);
	ElemRB* returnSuccesor(ElemRB* node);
	void addNode(int enteredValue);
	void deleteNode(int searchedKey);
	void treeAddFix(ElemRB* node);
	void leftRotation(ElemRB* node);
	void rightRotation(ElemRB* node);
	void printTree(string text1, string text2, ElemRB* node);
	void display();
};