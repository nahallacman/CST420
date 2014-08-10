//
// CST 407 - assignment #3
//
// Cal Barkman
//
// File: word.h
//
//
//

#ifndef WORD_H
#define WORD_H
#include <string>
using std::string;


class word{
public:
	word(string _word, int _pagenum, int _wordnum);
	string getword() const   { return  m_word; }
	int getpagenum() const   { return  m_pagenum; }
	int getwordnum() const   { return  m_wordnum; }

private:
	string m_word;
	int m_pagenum;
	int m_wordnum;
};

bool operator<( const word &lhs, const word &rhs); //had an issue making this const correct

#endif