/*
name			class number	assignment number
Cal Barkman		CST 420			Assignment #4		
*/

#include "controller.h"
#include "dictionary.h"
#include  <algorithm>

using std::cin;
using std::prev_permutation;

void getPermutations();

int main()
{
	string filename;

	cout << "Enter a file name for the dictionary: (usually dictionary.txt) " << endl;
	cin >> filename;

	controller Controller(filename);
	Controller.inputLoop();
}
