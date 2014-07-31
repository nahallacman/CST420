#ifndef STAGE_H
#define STAGE_H
#include <iostream>
#include <fstream>
using std::istream;

class Stage
{
public:
	Stage();
	Stage(double m_length);
	friend  istream  &operator>>(istream  &in, Stage &rhs);
	double getLength(){ return m_length; }

private:
	double m_length;
};

#endif
