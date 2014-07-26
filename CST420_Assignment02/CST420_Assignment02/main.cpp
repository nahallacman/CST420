/*
programmer:
Cal Barkman
Class:
CST 420
Assignment:
Assignment 2
Due date:
7/20/14
*/


#include "book.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void main()
{
	string filename_book;
	string filename_skip;
	cout << "Enter document file name: ";
	cin >> filename_book;
	cout << "Enter the skip-words file name: ";
	cin >> filename_skip;
	cout << endl;


	book c(filename_book, filename_skip);
	c.print();

	return;
}