#pragma once
#include"info.h"

struct NODETREE
{
	info information;
	int count;
	NODETREE* left, * right;
	NODETREE(info elem, int count, NODETREE* left = nullptr, NODETREE* right = nullptr) : information(elem), count(count), left(left), right(right) {};
	~NODETREE()
	{
		left = nullptr;
		right = nullptr;
	}
};

using Tree = NODETREE*;

void Clear_Tree(Tree& t);
void Print_order(Tree t);
void find_elem(Tree& r, Tree& q);
bool Delete_element(Tree& t, info elem);
void add(Tree& t, info elem);
void Print_Tree(Tree t, int level);

struct Binary_tree
{
private:
	Tree root;
public:
	Binary_tree(std::string file_name)
	{
		std::ifstream file(file_name);
		info elem;
		root = nullptr;
		while (file >> elem)
			add(root, elem);
		file.close();
	}

	~Binary_tree()
	{
		Clear_Tree(root);
	}
	void print()
	{
		Print_Tree(root, 0);
	}
	Tree get_tree()
	{
		return root;
	}
	void print_elements()
	{
		Print_order(root);
		std::cout << '\n';
	}

	bool search(info elem)
	{
		Tree ptr = root;
		bool result = 0;
		while (ptr && !result)
		{
			if (elem.avg < ptr->information.avg)
				ptr = ptr->left;
			else
				if (elem.avg > ptr->information.avg)
					ptr = ptr->right;
				else
					result = 1;
		}
		return result;
	}

	bool Delete(info elem)
	{
		return Delete_element(root, elem);
	}
};


