#include "Stage.h"

Stage::Stage() :m_length(0)
{}

Stage::Stage(double _length) :m_length(_length)
{}
/*
istream  &operator>>(istream  &in, Stage  &rhs)
{
	return  in >> rhs.m_length;
}
*/

istream  &operator>>(istream  &in, Stage  &rhs)
{
	in >> rhs.m_length;
	return in;
}