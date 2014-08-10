//
// CST 407 - assignment #3
//
// Cal Barkman
//
// File: book.h
//
//
//

#ifndef BOOK_H
#define BOOK_H
#include "word.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <list>
#include <algorithm>
#include <vector>

using std::istream_iterator;
using std::multiset;
using std::list;

typedef  istream_iterator<string>  StringInIter;

class book
{
public:
	//book();
	book(string _filename_book, string _filename_skiplist);
	void print();
	//void print_word(string _search);

private:
	void book::init();
	string book::normalize_word(string _normalize);
	bool book::check_skip_list(string _check);
	string m_filename_book;
	string m_filename_skiplist;
	list<string> m_skiplist;
	multiset<word> m_storage;


};

#endif