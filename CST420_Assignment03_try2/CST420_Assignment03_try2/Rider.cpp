//
// CST 407 - assignment #3
//
// Cal Barkman
//
// File: Rider.cpp
//
//
//

#include "Rider.h"
Rider::Rider()
{}
Rider::Rider(string _name, string _homeCountry, string _teamname, vector<int> _raceTimes) :m_name(_name), m_homeCountry(_homeCountry), m_teamname(_teamname), m_raceTimes(_raceTimes)
{}


bool Rider::operator<( const Rider &rhs)
{
	if (this->m_name < rhs.m_name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<(const Rider &lhs, const Rider &rhs)
{
	if (lhs.m_name < rhs.m_name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
istream  &operator>>(istream  &in, Rider  &rhs)
{
	in >> rhs.m_name >> rhs.m_homeCountry >> rhs.m_teamname;
	
	return in;
}
*/