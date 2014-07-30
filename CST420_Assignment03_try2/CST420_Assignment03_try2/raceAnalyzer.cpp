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

RaceAnalyzer::RaceAnalyzer(const string  &stageFilename, const string  &riderFilename) :m_stageFilename(stageFilename), m_riderFilename(riderFilename)
{
	init();
}

size_t RaceAnalyzer::numStages()  const
{
	size_t ret_val = m_stages.size();
	return ret_val;
}

string  RaceAnalyzer::getTeam(const  string  &riderName)  const
{
	string a = m_riders.;
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
	typedef  istream_iterator<Stage>     StageInIter;
	
#if DEBUGGING
	cout << "Running in debug mode."
		<< " m_stageFilename = " << m_stageFilename
		<< " m_riderFilename = " << m_riderFilename << endl;
#else
	cout << "Not running in debug mode." << endl;
#endif
	
	ifstream fInStage(m_stageFilename); // initalize stage file

	if (fInStage.is_open()) 
	{
		cout << "Stage file open" << endl;
		StageInIter sIter(fInStage);

		std::copy(std::istream_iterator<Stage>(sIter), std::istream_iterator<Stage>(),  //start by reading the stage file
			std::back_inserter(m_stages)); // and putting it into the m_stages vector

		cout << "End Stage file copy" << endl;
	}
	else
	{
		cout << "Stage File not open" << endl;
	}

	ifstream fInRiders(m_riderFilename); // initalize riders file

	if (fInRiders.is_open())
	{
		cout << "Stage file open" << endl;
		for (std::string line; getline(fInRiders, line);)
		{
			string name, country, team;
			int time;
			istringstream test(line);
			test >> name >> country >> team;
			vector<int> raceTimes;
			for (int i = 0; i < m_stages.size(); i++)
			{
				test >> time;
				raceTimes.push_back(time);
			}
			m_riders.insert(Rider(name, country, team, raceTimes));
		}
	}
}