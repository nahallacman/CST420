//
// CST 407 - assignment #3
//
// Cal Barkman
//
// File: raceAnalyzer.h
//
// Definitions for RaceAnalyzer class.
//

#include "raceAnalyzer.h"
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

string extract_rider(pair<string, Rider> ret) { string retval = ret.second.getName(); return retval; }
string extract_team(pair<string, Rider> ret) { string retval = ret.second.getTeamName(); return retval; }
string extract_country(pair<string, Rider> ret) { string retval = ret.second.getHomeCountry(); return retval; }

struct counter {
	int tot;
	int get_tot()
	{
		return tot;
	}
	void operator() (int i)
	{
		tot += i;
	}
} counterobj;

//RaceAnalyzer::Results extract_rider_results(pair<string, Rider> rider) {  // function:
RaceAnalyzer::PairResults extract_rider_results(pair<string, Rider> rider) {  // function:
	//these two lines total up the time for a rider in for each race, it may not be useful though
	vector<int> temp = rider.second.getRaceTimes();
	counter time1 = for_each(temp.begin(), temp.end(), counterobj);
	/*
	typedef  pair<Seconds, string>  PairResults;
	typedef  list<PairResults>      Results;
	*/
	Seconds sec;
	sec = time1.get_tot();
	string str;
	str = rider.second.getName();
	RaceAnalyzer::PairResults ins(sec, str);
	//RaceAnalyzer::Results structure;
	//structure.push_back(ins);
	
	//return structure;
	return ins;
}


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
	Rider retval = m_riders.at(riderName);
	return retval.getTeamName();
}
//
// Returns the team name for a specified rider.
//


string  RaceAnalyzer::getCountry(const string  &riderName)  const
{
	Rider retval = m_riders.at(riderName);
	return retval.getHomeCountry();
}
//
// Returns the country name for a specified rider.
//


RaceAnalyzer::StrSet  RaceAnalyzer::riders()  const
{
	StrSet retval;
	std::transform(m_riders.begin(), m_riders.end(), inserter(retval, retval.begin()), extract_rider);
	return retval;
}
//
// Returns the names of all the riders in the race.
//


RaceAnalyzer::StrSet RaceAnalyzer::teams()  const
{
	StrSet retval;
	std::transform(m_riders.begin(), m_riders.end(), inserter(retval, retval.begin()), extract_team);
	return retval;
}
//
// Returns the names of all the teams in the race.
//


RaceAnalyzer::StrSet  RaceAnalyzer::countries()  const
{
	StrSet retval;
	std::transform(m_riders.begin(), m_riders.end(), inserter(retval, retval.begin()), extract_country);
	return retval;
}
//
// Returns the names of all the countries represented
// in the race.
//


RaceAnalyzer::Results  RaceAnalyzer::riderResults(unsigned       stage,
	const string  &team,
	const string  &country)  const
{
	Results retval;

	//  typedef  pair<Seconds, string>  PairResults;
	//	typedef  list<PairResults>      Results;
	//start by building a structure where the only riders left are the ones that are in _team_ and _country_

	//then go through that structure and extract the times for those riders when they were at _stage_	
	

	std::transform(m_riders.begin(), m_riders.end(), inserter(retval, retval.begin()), 
		[stage](pair<string, Rider> rider){
		string str;
		str = rider.second.getName();
		Seconds sec;
		sec = rider.second.getRaceTimes()[stage];
		RaceAnalyzer::PairResults ret(sec, str);
		cout << "Testing riderResults" << rider.second.getRaceTimes()[stage] << endl; return ret;
		}
	);
	
	return retval;
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
	Stage temp = m_stages.at(stage);
	double distance = temp.getLength();
	//now you have the values seconds and retval, calculate miles per hour
	double time = seconds;
	time = time / 3600; // convert to hours
	double mph = distance / time; //miles div by hours to get MPH
	return MPH(mph);
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
		cout << "Riders File open" << endl;
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
			m_riders.insert(pair<string, Rider>(name, Rider(name, country, team, raceTimes)));
		}
	}
	else
	{
		cout << "Riders File not open." << endl;
	}
}