// C++ implementation to read
// file word by word
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include "Hash.h"

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

	Hash* freq = new Hash();

	// extracting words from the file
	while (file >> word)
	{
    timeBefore = clock();
		int increment;
		increment = 1 + freq->getValor(word);
		freq->setItens(word, increment);
    timeAfter = clock();
    incTime = incTime + (timeAfter - timeBefore);
	}
	file.close();

	freq->showItens();
  cout << incTime << " é o tempo total de execução desse algoritmo" << "\n";

	return 0;
}
