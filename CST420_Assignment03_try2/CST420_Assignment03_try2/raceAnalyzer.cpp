//
// CST 407 - assignment #3
//
// Cal Barkman
//
// File: raceAnalyzer.h
//
// Definitions for RaceAnalyzer class.
//

#include  "raceAnalyzer.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::for_each;
using std::istringstream;

typedef  istream_iterator<string>  StringInIter;

#define DEBUGGING 1

RaceAnalyzer::RaceAnalyzer(const string  &stageFilename,
	const string  &riderFilename) :m_stageFilename(stageFilename), m_riderFilename(riderFilename)
{
	init();
}

size_t RaceAnalyzer::numStages()  const
{
	size_t ret_val = m_numstages;
	return ret_val;
}

string  RaceAnalyzer::getTeam(const  string  &riderName)  const
{
	return string();
}
//
// Returns the team name for a specified rider.
//


string  RaceAnalyzer::getCountry(const string  &riderName)  const
{
	return string();
}
//
// Returns the country name for a specified rider.
//


RaceAnalyzer::StrSet  RaceAnalyzer::riders()  const
{
	return StrSet();
}
//
// Returns the names of all the riders in the race.
//


RaceAnalyzer::StrSet RaceAnalyzer::teams()  const
{
	return StrSet();
}
//
// Returns the names of all the teams in the race.
//


RaceAnalyzer::StrSet  RaceAnalyzer::countries()  const
{
	return StrSet();
}
//
// Returns the names of all the countries represented
// in the race.
//


RaceAnalyzer::Results  RaceAnalyzer::riderResults(unsigned       stage,
	const string  &team,
	const string  &country)  const
{
	return Results();
}
//
// Returns riders and stage/race times based on the
// criteria specified by the parameters.
//


Seconds  RaceAnalyzer::teamTime(const string  &teamName,
	unsigned       stage,
	unsigned       numRiders)  const
{
	return Seconds();
}
//
// Returns stange/race time for the specified team/stage. A
// team time for a stage is sum of the numRiders fastest
// times for the team.
//


RaceAnalyzer::MPH  RaceAnalyzer::calcMPH(Seconds  seconds, unsigned  stage)  const
{
	return MPH();
}

void RaceAnalyzer::init()
{
	
	/*
#if DEBUGGING
	cout << "Running in debug mode." << endl;
	cout << "m_stageFilename = " << m_stageFilename;
	cout << "m_riderFilename = " << m_riderFilename;
#else
	cout << "Not running in debug mode." << endl;
#endif
	*/
	//start by reading in the stage file line by line
	//one value per line, ++m_numstages per value


	ifstream inSkip(m_stageFilename); // initalize skip list

	if (inSkip.is_open()) // how to replace this statement?
	{
#if DEBUGGING
		cout << "Skip File open" << endl;
#endif
		StringInIter StageIter(inSkip);
		for (; StageIter != StringInIter(); ++StageIter)
		{
			string insert = *StageIter;
			//normalize_word(insert);
			//m_stages.push_back()
		}
	}
	else
	{
#if DEBUGGING
		cout << "Skip File not open" << endl;
#endif
	}
}