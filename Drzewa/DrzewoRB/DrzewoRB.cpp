#include "stdafx.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "DrzewoRB.h"

using namespace std;

DrzewoRB::DrzewoRB()
{
	rozm = 0;

	cr = cl = cp = "  ";
	cr[0] = 47;
	cl[0] = 92;
	cp[0] = 124;
}


DrzewoRB::~DrzewoRB()
{
	rozm = 0;
	deleteTree(korzen); // one by one
}

void DrzewoRB::deleteTree(ElemRB* node)
{
	if (node != &sentinel)
	{
		deleteTree(node->leftSon);
		deleteTree(node->rightSon);
		delete node;
	}
}

void DrzewoRB::buildRandomly(int enteredAmount)
{
	for (int i = 0; i < enteredAmount; i++)
		addNode((rand() % 101) + 0);
}

void DrzewoRB::buildFromFile()
{
	string filename = "test.txt";
	ifstream file(filename); //opening an input stream for file test.txt
	/*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
	stream could not be opened.*/
	string helper;
	int help;
	if (file)
	{
		while (!file.eof()) // poprawka
		{
			file >> helper;
			help = stoi(helper);
			addNode(help);
		}
		file.close();
	}
	else
		cout << "\nCouldn't open " << filename << " to read\n";
}

void DrzewoRB::printTree(string text1, string text2, ElemRB* node)
{
	if (korzen == &sentinel)
		cout << "Tree is empty...\n";
	else
	{
		string text;

		if (node != &sentinel)
		{
			text = text1;
			if (text2 == topCorner)
				text[text.length() - 2] = ' ';
			printTree((text + vertical), topCorner, node->rightSon);

			text = text.substr(0, text1.length() - 2);
			cout << text << text2 << node->color << ":" << node->key << endl;

			text = text1;
			if (text2 == bottomCorner)
				text[text.length() - 2] = ' ';
			printTree((text + vertical), bottomCorner, node->leftSon);
		}
	}
}

void DrzewoRB::display()
{
	printTree("", "", korzen);
}

bool DrzewoRB::findKey(int enteredValue) // gotowe
{
	ElemRB* helper = new ElemRB();
	helper = korzen;
	bool found = false;

	if (korzen == &sentinel)
		cout << "Tree is empty...\n";
	else
	{
		while ((found == false) && (helper != &sentinel))
		{
			if (helper->key != enteredValue)
			{
				found = true;
			}
			else
			{
				if (helper->key < enteredValue)
					helper = helper->rightSon;
				else
					helper = helper->leftSon;
			}
		}
	}

	if (found == 0)
		cout << "Element not found...\n";
	else
	{
		if (helper->color == 'R')
			cout << "color: red\n";
		else cout << "color: black\n";
	}

	return found;
}

ElemRB* DrzewoRB::returnSuccesor(ElemRB* node)
{
	ElemRB* helper = NULL;

	if (node->rightSon != &sentinel)
	{
		helper = node->rightSon;
		while (helper->leftSon != &sentinel)
		{
			helper = helper->leftSon;
		}
	}
	else
	{
		helper = node->leftSon;
		while (helper->leftSon != NULL)
			helper = helper->leftSon;
	}
	return helper;
}

void DrzewoRB::addNode(int enteredValue)
{
	ElemRB* newNode = new ElemRB();
	newNode->leftSon = newNode->rightSon = &sentinel;
	newNode->parent = korzen;
	newNode->key = enteredValue;
	newNode->color = 'R';
	rozm++;
	cout << "sentinel: " << &sentinel << endl;
	cout << "korzen: " << korzen << endl;
	if (korzen == &sentinel)
	{
		korzen = newNode;
		newNode->parent = &sentinel;
		cout << "add node: " << newNode << endl;
	}
	else
	{
		while (true)
		{
			if (enteredValue < newNode->parent->key)
			{
				if (newNode->parent->leftSon == &sentinel) // if there is empty spot
				{
					newNode->parent->leftSon = newNode;
					break;
				}
				else newNode->parent = newNode->parent->leftSon; // going to the next level of the tree
			}
			else
			{
				if (newNode->parent->rightSon == &sentinel) // if there is empty spot
				{
					newNode->parent->rightSon = newNode;
					break;
				}
				else newNode->parent = newNode->parent->leftSon;
			}
		} // end of while loop

		treeAddFix(newNode); // fixing tree -> checking red-black tree conditions
	}
}

void DrzewoRB::deleteNode(int searchedKey)
{

	if (korzen == NULL)
	{
		cout << "Can't delete anything - tree is empty!\n";
	}
	else
	{
		ElemRB* helper = new ElemRB();
		ElemRB* helper1 = new ElemRB();
		helper = korzen;

		if (findKey(searchedKey))
		{
			while ((helper != &sentinel) && (helper->key != searchedKey))
			{
				helper = (searchedKey < helper->key) ? helper->leftSon : helper->rightSon;
			}

			if ((helper->leftSon == &sentinel) || (helper->rightSon == &sentinel))
			{
				if (helper->leftSon == &sentinel) // deleting node hasn't left son
				{
					if (helper->color == 'B')
					{
						if ((helper->parent->color == 'R') && (helper->rightSon->color == 'R'))
						{
							helper->rightSon->color = 'B';
						}
					}
					helper = helper->rightSon;
				}
				else // deleting node hasn't right son
				{
					if (helper->color == 'B')
					{
						if ((helper->parent->color == 'R') && (helper->leftSon->color == 'R'))
						{
							helper->leftSon->color = 'B';
						}
					}
					helper = helper->leftSon;
				}
			} // odtad ma dwoch synow 
			else
			{
				if (helper->rightSon == returnSuccesor(helper)) // 3 
				{
					helper1 = helper->rightSon;
					if (helper1->color == 'B')
						helper1->rightSon->color = 'B';
					helper1->leftSon = helper->leftSon;
					helper1->color = helper->color;
					helper = helper1;
				}
				else // 4 
				{

				}
			}
		}
		else
			cout << "Can't find the searched key!\n";
	}
}

void DrzewoRB::treeAddFix(ElemRB* newNode)
{
	ElemRB* grandpa = new ElemRB();
	ElemRB* uncle = new ElemRB();

	if (korzen == newNode)
	{
		newNode->color = 'B';
	}
	else
	{
		while ((newNode->parent != &sentinel) && (newNode->parent->color == 'R'))
		{
			grandpa = newNode->parent->parent;
			cout << "grandpa: " << grandpa;
			if (newNode->parent == grandpa->leftSon)
			{
				if (grandpa->rightSon != &sentinel) // if right uncle exists
				{
					uncle = grandpa->rightSon;
					if (uncle->color == 'R')
					{
						newNode->parent->color = 'B';
						grandpa->color = 'R';
						uncle->color = 'B';

						newNode = grandpa; // goes higher then
					}
				}
				else // no uncle so we should rotate tree
				{

					if (newNode->parent->rightSon == newNode)
					{
						newNode = newNode->parent;
						leftRotation(newNode);
					}
					newNode->parent->color = 'B';
					grandpa->color = 'R';
					rightRotation(grandpa);
				}
			}
			else // mirror situation :) parent is right son of grandpa
			{
				if (grandpa->leftSon != &sentinel)
				{
					uncle = grandpa->leftSon;
					if (uncle->color == 'R')
					{
						newNode->parent->color = 'B';
						uncle->color = 'B';
						grandpa->color = 'R';
						newNode = grandpa;
					}
				}
				else // no uncle so we should rotate tree
				{
					if (newNode->parent->leftSon == newNode)
					{
						newNode = newNode->parent;
						rightRotation(newNode);
					}
					newNode->parent->color = 'B';
					grandpa->color = 'R';
					leftRotation(grandpa);
				}
			}
			korzen->color = 'B'; // fixing korzen
		}
	}

}

void DrzewoRB::leftRotation(ElemRB* A)
{
	ElemRB* B, * p;

	B = A->rightSon;
	if (B != &sentinel)
	{
		p = A->parent;
		A->rightSon = B->leftSon;
		if (A->rightSon != &sentinel) A->rightSon->parent = A;

		B->leftSon = A;
		B->parent = p;
		A->parent = B;

		if (p != &sentinel)
		{
			if (p->leftSon == A) p->leftSon = B; else p->rightSon = B;
		}
		else korzen = B;
	}
}

void DrzewoRB::rightRotation(ElemRB* A)
{
	ElemRB* B, * p;

	B = A->leftSon;
	if (B != &sentinel)
	{
		p = A->parent;
		A->leftSon = B->rightSon;
		if (A->leftSon != &sentinel) A->leftSon->parent = A;

		B->rightSon = A;
		B->parent = p;
		A->parent = B;

		if (p != &sentinel)
		{
			if (p->rightSon == A) p->rightSon = B; else p->leftSon = B;
		}
		else korzen = B;
	}
}