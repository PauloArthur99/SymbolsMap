#include <iostream>
#include "LinkedList.h"
using namespace std;

int  nPalavras;

class Map
{
private:
	LinkedList* LinkList;

public:
	Map();
	int getValue(string word);
	void setItem(string word, int value);
	void showItems(void);
};

Map::Map()
{
	LinkList = new LinkedList();
}

int Map::getValue(string word)
{
	Node* pivot = LinkList->Head;
	if (pivot == nullptr)
		return 0;

	while ((pivot->Element)->Key != word and (pivot->Next) != nullptr)
		pivot = pivot->Next;

	if ((pivot->Element)->Key != word)
		return 0;

	return (pivot->Element)->Value;
}

void Map::setItem(string word, int value)
{
	nPalavras++;
	if (LinkList->Size == 0)
	{
		cout << "primeira vez \n";
		Item* novoItem = new Item();
		novoItem->Key = word;
		novoItem->Value = value;
		LinkList->push(novoItem);
	}

	Node* pivot = LinkList->Head;
	while ((pivot->Element)->Key != word and (pivot->Next) != nullptr)
		pivot = pivot->Next;

	if (pivot->Element->Key == word)
	{
		pivot->Element->Value = value;
		return;
	}

	Item* novoItem = new Item();
	novoItem->Key = word;
	novoItem->Value = value;
	LinkList->push(novoItem);
}

void Map::showItems(void)
{
	Node* pivot = LinkList->Head;
 	while ((pivot->Next) != nullptr)
	{
	cout << "palavra " << pivot->Element->Key << " possui " << pivot->Element->Value << " aparições \n";
		pivot = pivot->Next;
	}
}
