/*
name			class number	assignment number
Cal Barkman		CST 420			Assignment #4
*/

#include "dictionary.h"


dictionary::dictionary(string _filename)
{
	build(_filename);
}

void dictionary::build(string _filename)
{
	string line;
	myfile.open(_filename);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			m_dictionary.push_back(line);
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
	bool found = false;
	
	//list<string>::iterator b = d.end();
	auto b = m_dictionary.end();
	for (auto a = m_dictionary.begin(); a != b && found == false; a++)
	{
		if (*a == _checkme)
		{
			found = true;
		}
	}


	return found;
}