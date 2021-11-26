#include "Typeelem.h"
Typeelem::Typeelem(string name_, int time_, int count_)
{
	if (count_ < 0)
	{
		throw "uncorrect count";
	}
	if (time_ < 0)
	{
		throw "uncorrect time";
	}
	name = name_;
	time = time_;
	count = count_;
	is = 1;       //еще не в работе
}
Typeelem& Typeelem::operator=(const Typeelem& tmp)
{
	name = tmp.name;
	time = tmp.time;
	count = tmp.count;
	is = tmp.is;
	return* this;
}
Typeelem::Typeelem(const Typeelem& tmp)
{
	name = tmp.name;
	time = tmp.time;
	count = tmp.count;
	is = tmp.is;
}