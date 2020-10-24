// C++ implementation to read
// file word by word
#include <fstream>
#include <string>
#include <iostream>
#include "LinkedMap.h"

using namespace std;

int main()
{
	clock_t timeBefore, timeAfter;
  clock_t incTime = 0;

	// filestream variable file
	fstream file;
	string word, t, q, filename;

	// filename of the file
	filename = "arquivoPalavras.txt";

	// opening file
	file.open(filename.c_str());

	Map* freq = new Map();

	// extracting words from the file
	while (file >> word)
	{
		int increment;
		increment = 1 + freq->getValue(word);
		freq->setItem(word, increment);
		timeAfter = clock();
    incTime = incTime + (timeAfter - timeBefore);
	}
	file.close();

	freq->showItems();
	cout << incTime << " é o tempo total de execução desse algoritmo" << "\n";

	return 0;
}
