/*
name			class number	assignment number
Cal Barkman		CST 420			Assignment #4
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "dictionary.h"
#include <algorithm>
using std::prev_permutation;
using std::cin;

class controller
{
public:
	controller(string _filename);
	void makePermutations();
	void inputLoop();
	void output();
private:
	dictionary Dictionary;
	string word;
	list<string> pList;

};

#endif