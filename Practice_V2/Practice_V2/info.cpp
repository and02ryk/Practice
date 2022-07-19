#include "info.h"

std::ostream& operator<<(std::ostream& out, info& p)
{
	out << p.firstName << ' ' << p.lastName << ' ' << p.avg << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, info& p)
{
	in >> p.firstName >> p.lastName;
	int x; p.avg = 0;
	for (size_t i = 0; i < 5; i++)
	{
		in >> x;
		p.avg += x;
	}
	p.avg /= 5;
	return in;
}

void info::print()
{
	std::cout << firstName << ' ' << lastName << ' ' << avg << ' ' << '\n';
}

info::info(std::ifstream& file, bool& check)
{
	avg = 0;
	file >> firstName >> lastName;
	short mark;
	for (size_t i = 0; i < 5; i++)
	{
		file >> mark;
		if (mark != 4 && mark != 5)
			check = false;
		avg += mark;
	}
	avg /= 5;
}

info::info(std::ifstream& file)
{
	file >> firstName >> lastName;
	short mark;
	for (size_t i = 0; i < 5; i++)
	{
		file >> mark;
		avg += mark;
	}
	sum_marks = avg;
	avg /= 5;
}

short info::compare_t2(info inform)
{
	short check = 0;
	if (avg < inform.avg)
		check = -1;
	else if (avg > inform.avg)
		check = 1;
	return check;
}

short info::compare_t3(info inform)
{
	short check = 0;
	if (sum_marks < inform.sum_marks)
		check = -1;
	else if (sum_marks > inform.sum_marks)
		check = 1;
	return check;
}