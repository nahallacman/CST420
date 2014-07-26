#include "book.h"
#include <iostream>
#include <sstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::for_each;
using std::istringstream;

#define DEBUGGING 0
/*
book::book()
{
	m_filename_book = "doc.txt";
	m_filename_skiplist = "skip.txt";
	init();
}
*/

book::book(string _filename_book, string _filename_skiplist):m_filename_book(_filename_book), m_filename_skiplist(_filename_skiplist)
{
	init();
}

void book::init()
{

#if DEBUGGING
	cout << "Running in debug mode." << endl;
	cout << "m_filename_book = " << m_filename_book;
	cout << "m_filename_skiplist = " << m_filename_skiplist;
	string test = "TeSt";
	cout << "Testing 1: " << test << endl;
	normalize_word(test);
	cout << "Testing 2: " << test << endl;
	test = "test.";
	normalize_word(test);
	cout << "Testing 3: " << test << endl;
#else
	cout << "Not running in debug mode." << endl;
#endif

	ifstream inSkip(m_filename_skiplist); // initalize skip list

	if (inSkip.is_open())
	{
#if DEBUGGING
		cout << "Skip File open" << endl;
#endif
		StringInIter SkipIter(inSkip);
		for (; SkipIter != StringInIter(); ++SkipIter)
		{
			string insert = *SkipIter;
			normalize_word(insert);
			m_skiplist.push_back(insert);
		}
	}
	else
	{
#if DEBUGGING
		cout << "Skip File not open" << endl;
#endif
	}

	std::vector<string> file;
	std::ifstream input(m_filename_book);
	int linecount = 0;
	for (std::string line; getline(input, line);)
	{
		file.push_back(line);
		linecount++;
	}

	if (input.is_open())  //open file and check it
	{
#if DEBUGGING
		cout << "File open" << endl;
#endif
		//StringInIter InIter(inFile);
		typedef std::vector<string>::iterator VecStrIter;
		VecStrIter InIter;
		int current_page = 1;
		int current_line = 0;
		int file_line_index = 0;
		while (file_line_index != linecount)
		{

			if (file[file_line_index] == "<newpage>")
			{
#if DEBUGGING
				cout << "found <newpage>" << endl;
#endif
				current_page++;
				current_line = 1;
				file_line_index++;
			}
			else
			{
				string line = file[file_line_index];
				file_line_index++;
				if (line != "")
				{
					current_line++;
					//break up line into strings.
					istringstream iss(line);
					while (iss)
					{
						string sub;
						iss >> sub;
						if (sub != "")
						{
							sub = normalize_word(sub);
							if (!check_skip_list(sub))
							{
#if DEBUGGING
								cout << "Inserting: " << sub << " into the mutliset." << endl;
#endif
								word a(sub, current_page, current_line);
								m_storage.insert(a);
							}
#if DEBUGGING
							cout << "Substring: " << sub << endl;
#endif
						}
					}
				}
				else
				{
#if DEBUGGING
					cout << "Blank line found" << endl;
#endif
				}
			}
		}
	}
	else
	{
#if DEBUGGING
		cout << "File not open" << endl;
#endif
	}
}

void normalize_char(char &i) {  // function:
	i = tolower(i);
}

bool myispunct(char i)
{
	if (ispunct(i) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string book::normalize_word(string _normalize)
{
#if DEBUGGING
	cout << "begin lower case modification: " << _normalize << endl;
#endif
	//change the whole string to lower case
	for_each(_normalize.begin(), _normalize.end(), normalize_char);
	//then remove anything that isn't a character
#if DEBUGGING
	cout << "end lower case modification: " << _normalize << endl;
	cout << "Begin punctuation removal: " << _normalize << endl;
#endif
	string result;
	std::remove_copy_if(_normalize.begin(), _normalize.end(),
		std::back_inserter(result),         
		ispunct
		);
#if DEBUGGING
	cout << "End punctuation removal: " << result << endl;
#endif
	return result;
}

void book::print()
{
	string last;
	cout << "Index" << endl << "-----";
	for (std::multiset<word>::iterator it = m_storage.begin(); it != m_storage.end(); ++it)
	{
		if (last != it->getword())
		{
			
			cout << endl << it->getword() << endl
				<< "  " << it->getpagenum() << "." << it->getwordnum();
		}
		else
		{
			cout << ", " << it->getpagenum() << "." << it->getwordnum();
		}
		last = it->getword();
	}
}

bool book::check_skip_list(string _check)
{
	//bool in_list = false;
	for (auto iter = m_skiplist.begin(); iter != m_skiplist.end(); iter++) //iterate through skip list to see if the word is in the skip list
	{
		if (*iter == _check)
		{
			//word is in skip list
			//in_list = true;
			return true;
		}
		//else
		//{
			//word in not in skip list
			//in_list = false;
		//}
	}
	return false;
}




/*
I built this without looking at the requirements. It isn't used for anything, but it was well built so I decided it would be a shame to delete it.
*/
/*
void book::print_word(string _search)
{
#if DEBUGGING
cout << "Beginning print" << endl
<< "looking for the word: " << _search << endl;
#endif
word test(_search, 1, 1);
std::pair <std::multiset<word>::iterator, std::multiset<word>::iterator> ret;
ret = m_storage.equal_range(test);
if (ret.first->getword() == ret.second->getword())
{
#if DEBUGGING
cout << "Word not found." << endl;
#endif
}
else
{
#if DEBUGGING
cout << "Word found." << endl;
#endif
cout << _search << endl;
}
for (std::multiset<word>::iterator it = ret.first; it != ret.second; ++it)
{
cout << "  " << it->getpagenum() << '.' << it->getwordnum() << endl;
}
#if DEBUGGING
cout << "Ending print" << endl;
#endif
}
*/