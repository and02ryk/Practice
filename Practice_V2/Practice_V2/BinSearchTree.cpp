#include "BinSearchTree.h"

void Clear_Tree(Tree& t)
{
	if (t)
	{
		Clear_Tree(t->left);
		Clear_Tree(t->right);
		delete t;
		t = nullptr;
	}
}

void Print_order(Tree t)
{
	if (t)
	{
		Print_order(t->left);
		for (int i = 1; i <= t->count; i++)
			std::cout << t->information.avg << ' ';
		Print_order(t->right);
	}
}

void find_elem(Tree& r, Tree& q)
{
	if (r->right)
		find_elem(r->right, q);
	else
	{
		q->information = r->information;
		q->count = r->count;
		q = r;
		r = r->left;
	}
}

bool Delete_element(Tree& t, info elem)
{
	bool result = true;
	if (!t)
		result = 0;
	else {
		if (t->information.compare_t2(elem) == 1)
			result = Delete_element(t->left, elem);
		else
			if (t->information.compare_t2(elem) == -1)
				result = Delete_element(t->right, elem);
			else
			{
				if (t->count > 1)
					t->count--;
				else
				{
					Tree q = t;
					if (!q->right)
						t = q->left;
					else
						if (!q->left)
							t = q->right;
						else
							find_elem(q->right, q);
					delete q;
				}
			}

	}
	return result;
}

void add(Tree& t, info elem)
{
	if (!t)
	{
		t = new NODETREE(elem, 1);
	}
	else
		if (elem.avg < t->information.avg)
			add(t->left, elem);
		else
			if (elem.avg > t->information.avg)
				add(t->right, elem);
			else
				t->count++;
}

void Print_Tree(Tree t, int level)
{
	if (t)
	{
		Print_Tree(t->right, level + 1);
		for (int i = 0; i <= level; i++)
			std::cout << ' ';
		std::cout << t->information.avg << '\n';
		Print_Tree(t->left, level + 1);
	}
}