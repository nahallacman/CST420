/*
name			class number	assignment number
Cal Barkman		CST 420			Assignment #4
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <list>
#include <iostream>
#include <fstream>
#include <string>

using std::list;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

class dictionary
{
public:
	dictionary(string _filename);
	bool check_dictionary(string _checkme); //false return value means it is not in the dictionary

private:
	void build(string _filename);
	string filename;
	list<string> m_dictionary;
	//string line;
	ifstream myfile;
};

#endif