//
// CST 407 - assignment #3
//
// Cal Barkman
//
// File: Rider.h
//
//
//

#ifndef RIDER_H
#define RIDER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::istream;
using std::string;
using std::vector;

class Rider
{
public:
	Rider();
	Rider(string _name, string _homeCountry, string _teamname, vector<int> _ractimes);
	friend  istream  &operator>>(istream  &in, Rider &rhs);

	bool operator<( const Rider &rhs);

	string getName() { return m_name; }
	vector<int> getRaceTimes() { return m_raceTimes; }
	string getHomeCountry() { return m_homeCountry; }
	string getTeamName() { return m_teamname; }

//private:
	string m_name;
	string m_homeCountry;
	string m_teamname;
	vector<int> m_raceTimes;
};

bool operator<(const Rider &lhs, const Rider &rhs);

#endif
