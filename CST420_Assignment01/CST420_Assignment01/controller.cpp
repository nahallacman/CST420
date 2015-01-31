/*
name			class number	assignment number
Cal Barkman		CST 420			Assignment #4
*/

#include "controller.h"

controller::controller(string _filename):Dictionary(_filename){
}

void controller::makePermutations()
{
	string  pWord(word);

	bool repeat = false;
	do
	{
		if (Dictionary.check_dictionary(pWord)) //check if there are any permuatations of the word in the dictionary
		{
			if (pWord != word) // make sure it isn't the original word when adding
			{
				pList.push_back(pWord);
			}
		}
		prev_permutation(pWord.begin(), pWord.end());
	} while (pWord != word);

	output();
	pList.clear();
}

void controller::inputLoop()
{
	bool done = false;
	while (done == false)
	{
		cout << endl;
		cout << "Enter a word: ";
		cin >> word;
		if (word == "quit") //check if the word is "quit"
		{
			done = true;
		}
		else
		{
			if (!Dictionary.check_dictionary(word)) //check if the word is in the dictionary
			{
				cout << "  " << word << " is not a valid word." << endl;
			}
			else
			{
				makePermutations();
			}
		}
	}
}

void controller::output()
{
	if (pList.size() == 0)
	{
		cout << "  " << word << " doesn't have any anagrams" << endl;
	}
	else
	{
		cout << "  " << "Anagrams: ";
		for_each(pList.begin(), pList.end(), [](string i){cout << i << " "; });
		cout << endl;
	}
}