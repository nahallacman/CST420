#include "word.h"

word::word(string _word, int _pagenum, int _wordnum) :m_word(_word), m_pagenum(_pagenum), m_wordnum(_wordnum)
{}


bool operator<( const word &lhs, const word &rhs)
{
	if (lhs.getword() < rhs.getword())
	{
		return true;
	}
	else
	{
		return false;
	}
}
