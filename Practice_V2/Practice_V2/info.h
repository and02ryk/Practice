#pragma once
#include<string>
#include<iostream>
#include<fstream>
struct info
{
	std::string firstName;
	std::string lastName;
	double avg;
	int sum_marks;

	void print();
	info(std::ifstream& file, bool& check);
	info(std::ifstream& file);
	info() { avg = 0; };
	short compare_t2(info inform);
	short compare_t3(info inform);

	friend std::ostream& operator <<(std::ostream& out, info& p);
	friend std::istream& operator >>(std::istream& in, info& p);

};