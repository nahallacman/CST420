/*
name			class number	assignment number
Cal Barkman		CST 420			Assignment #1		
*/

#include "dictionary.h"
#include  <algorithm>

using std::cin;
using std::prev_permutation;

int main()
{
	bool done = false;
	string word;
	string filename;

	cout << "Enter a file name for the dictionary: (usually dictionary.txt) " << endl;
	cin >> filename;

	dictionary d(filename);

	while (done == false)
	{
		cout << endl;
		cout << "Enter a word: ";
		cin >> word;
		//check if the word is "quit"
		if (word == "quit")
		{
			done = true;
		}
		else
		{
			//check if the word is in the dictionary
			if (!d.check_dictionary(word))
			{
				cout << "  " << word << " is not a valid word." << endl;
			}
			else
			{
				string  pWord(word);
				list<string> pList;
				bool repeat = false;
				do
				{
					//check if there are any permuatations of the word in the dictionary

					if (d.check_dictionary(pWord))
					{
						if (pWord != word) // make sure it isn't the original word when adding
						{
							pList.push_back(pWord);
						}
					}
					prev_permutation(pWord.begin(), pWord.end());
				} while (pWord != word);

				if (pList.size() == 0)
				{
					cout << "  " << word << " doesn't have any anagrams" << endl;
				}
				else
				{

					cout << "  " << "Anagrams: ";
					for (auto iter = pList.begin(); iter != pList.end(); iter++)
					{
						cout << *iter << " ";
					}
					cout << endl;
				}
			}
		}
	}
}