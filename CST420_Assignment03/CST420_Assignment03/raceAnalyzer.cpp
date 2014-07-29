#include  "raceAnalyzer.h"

RaceAnalyzer::RaceAnalyzer(const string  &stageFilename,
	const string  &riderFilename)
{


}

size_t RaceAnalyzer::numStages()  const
{
	return size_t();
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