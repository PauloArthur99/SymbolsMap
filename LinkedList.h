#include <iostream>
using namespace std;

class Item
{
public:
	string Key;
	int Value;

	Item()
	{
		this->Key = "";
		this->Value = 0;
	}
};

class Node
{
public:
	Item* Element;
	Node* Next;

	Node(Item* element, Node* next)
	{
		this->Element = element;
		this->Next = next;
	}
};

class LinkedList
{
public:
	Node* Head;
	int Size;

public:
	LinkedList();
	~LinkedList();
	int len();
	bool isEmpty();
	void push(Item* element);
	void remove(int pos);
	void clear();
};

LinkedList::LinkedList()
{
	this->Head = nullptr;
	this->Size = 0;
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::clear()
{
	Node* t, *p = this->Head;
	while (p)
	{
		t = p;
		p = p->Next;
		delete t;
	}
	this->Size = 0;
	this->Head = nullptr;
}

int LinkedList::len()
{
	return this->Size;
}

bool LinkedList::isEmpty()
{
	return this->Size == 0;
}

void LinkedList::push(Item* element)
{
	Node* new_node;
	new_node = new Node(element, nullptr);

	if (this->isEmpty())
	{
		this->Head = new_node;
		(this->Head)->Next = nullptr;
	}
	else
	{
		new_node->Next = (this->Head)->Next;
		(this->Head)->Next = new_node;
	}
	this->Size++;
}

void LinkedList::remove(int pos)
{
	if (pos == 0)
		this->Head = (this->Head)->Next;
	else
	{
		Node* pivot = this->Head;
		int idx = 1;

		while (idx < pos)
		{
			pivot = pivot->Next;
			idx++;
		}
		pivot->Next = (pivot->Next)->Next;
	}
	(this->Size)--;
}
