#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"info.h"

struct NODE
{
	info information;
	NODE* next;
	NODE* prev;
	NODE(info inf, NODE* next = nullptr, NODE* prev = nullptr) : information(inf), next(next), prev(prev) {};
	~NODE() { next = nullptr; prev = nullptr; }
};

using ptrNODE = NODE*;
struct DLL
{
	ptrNODE begin, end;
	size_t size;

	void First_node(const info& information);
	bool empty();
	void add_after_node(ptrNODE pNode, const info& information);
	void add_before_node(ptrNODE pNode, const info& information);
	info& Delete(ptrNODE& pNode);
	void Print();
	void create_1(const std::string file_name);
	ptrNODE find_place(ptrNODE begin, const info& information);
	void create_2(const std::string file_name);


	DLL() { begin = nullptr; end = nullptr; }
	DLL(const std::string file_name);
	~DLL();
};

