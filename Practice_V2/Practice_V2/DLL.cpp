#include "DLL.h"

void DLL::First_node(const info& information)
{
	begin = new NODE(information);
	end = begin;
}

bool DLL::empty()
{
	return begin == nullptr;
}

void DLL::add_after_node(ptrNODE pNode, const info& information)
{
	ptrNODE p = new NODE(information, pNode->next, pNode);
	if (pNode == end)
		end = p;
	else
		pNode->next->prev = p;
	pNode->next = p;
}

void DLL::add_before_node(ptrNODE pNode, const info& information)
{
	ptrNODE p = new NODE(information, pNode, pNode->prev);
	if (pNode == begin)
		begin = p;
	else
		pNode->prev->next = p;
	pNode->prev = p;
}

info& DLL::Delete(ptrNODE& pNode)
{
	ptrNODE p = pNode;
	if (pNode == begin)
	{
		begin = p->next;
		pNode = begin;
		if (p->next)
			p->next->prev = nullptr;
	}
	else if (pNode == end)
	{
		end = p->prev;
		pNode = end;
		if (p->prev)
			p->prev->next = nullptr;
		else
		{
			pNode = pNode->next;
			p->next->prev = p->prev;
			p->prev->next = p->next;
		}
	}
	static info information; information = p->information;
	delete p;
	return information;
}

void DLL::Print()
{
	ptrNODE p = begin;
	while (p)
	{
		p->information.print();
		p = p->next;
	}
}

void DLL::create_1(const std::string file_name)
{
	std::ifstream file(file_name);
	bool check = true;
	info information(file, check);
	First_node(information);
	ptrNODE pbegin = begin;
	while (!file.eof())
	{
		check = true;
		info information(file, check);
		if (check)
			add_before_node(begin, information);
		else
			add_after_node(pbegin, information);
	}
	file.close();
}

ptrNODE DLL::find_place(ptrNODE begin, const info& information)
{
	ptrNODE p = begin;
	while (p && p->information.compare_t3(information) < 0)
		p = p->next;
	return p;
}

void DLL::create_2(const std::string file_name)
{
	int sum = 0;
	std::ifstream file(file_name);
	info information(file);
	First_node(information);
	ptrNODE place;
	while (!file.eof())
	{
		info information(file);
		place = find_place(begin, information);
		if (place)
			add_before_node(place, information);
		else
			add_after_node(end, information);
	}
	file.close();
}

DLL::DLL(const std::string file_name)
{
	std::ifstream file(file_name);
	info information(file);
	First_node(information);
	while (!file.eof())
	{
		info information(file);
		add_after_node(begin, information);
	}
	file.close();
}

DLL::~DLL()
{
	while (!empty())
		Delete(begin);
}
