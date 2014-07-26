/*
name			class number	assignment number
Cal Barkman		CST 420			Assignment #1
*/

#include "dictionary.h"

dictionary::dictionary()
{
	filename = "dictionary.txt";
	build();
}

dictionary::dictionary(string _filename):filename(_filename)
{
	build();
}

void dictionary::build()
{
	string line;
	myfile.open(filename);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//cout << line << endl;
			d.push_back(line);
		}
		myfile.close();
	}
	else
	{
		cout << "File was not opened properly" << endl;
	}
}

bool dictionary::check_dictionary(string _checkme)
{

	bool retval = false;
	bool found = false;
	
	//list<string>::iterator b = d.end();
	auto b = d.end();
	for (auto a = d.begin(); a != b && found == false; a++)
	{
		if (*a == _checkme)
		{
			found = true;
		}
	}


	return found;
}