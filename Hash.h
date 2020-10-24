// hash example
#include <iostream>
#include <functional>
#include <string>
#include <cstdlib>
#include "LinkedMap.h"
using namespace std;

hash<string> str_hash;

class Hash
{
private:
  Map** BucketsVector;
  int NElements;

public:
  Hash();
  ~Hash();
int  getValor(string word);
void setItens(string word, int value);
void showItens(void);
};

Hash::Hash()
{
  int n_elements = 100;
  BucketsVector = new Map*[n_elements];
  NElements = n_elements;
}

Hash::~Hash()
{
  for (int i = 0; i < NElements; i++)
  {
    if (BucketsVector[i])
        delete BucketsVector[i];
  }
    delete[] BucketsVector;
}

int Hash::getValor(string word)
{
  int hashValue = abs(int(str_hash(word))) % NElements;

  if (BucketsVector[hashValue] == nullptr)
    return 0;
  else
  {
      return BucketsVector[hashValue]->getValue(word);
  }
}

void Hash::setItens(string word, int value)
{
    int hashValue = abs(int(str_hash(word))) % NElements;
    if (BucketsVector[hashValue] == nullptr)
    {
      BucketsVector[hashValue] = new Map();
      BucketsVector[hashValue]->setItem(word, value);
    }
    else
      BucketsVector[hashValue]->setItem(word, value);
}

void Hash::showItens(void)
{
  for (int i = 0; i < NElements; i++)
  {
    if (BucketsVector[i])
        BucketsVector[i]->showItems();
  }
}
