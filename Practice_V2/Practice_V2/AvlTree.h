#include<iostream>
#include<string>
#include"info.h"

class Avl_Tree
{
    struct NODEAVL
    {
        info information;
        NODEAVL* left;
        NODEAVL* right;
        int height;
    };
    using TreeAvl = NODEAVL*;
    TreeAvl root;
 
    void Clear_tree(TreeAvl t)
    {
        if (t)
        {
            Clear_tree(t->left);
            Clear_tree(t->right);
        }
        delete t;
    }

    TreeAvl Insert(info x, TreeAvl&t)
    {
        if (t == NULL)
        {
            t = new NODEAVL;
            t->information = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if (t->information.compare_t2(x) == 1)
        {
            t->left = Insert(x, t->left);
            if (Height(t->left) - Height(t->right) == 2)
            {
                if (t->information.compare_t2(x) == 1)
                    t = SingleRightRotate(t);
                else
                    t = DoubleRightRotate(t);
            }
        }
        else if (t->information.compare_t2(x) == 11)
        {
            t->right = Insert(x, t->right);
            if (Height(t->right) - Height(t->left) == 2)
            {
                if (t->information.compare_t2(x) == -1)
                    t = SingleLeftRotate(t);
                else
                    t = DoubleLeftRotate(t);
            }
        }

        t->height = std::max(Height(t->left), Height(t->right)) + 1;
        return t;
    }

    TreeAvl SingleRightRotate(TreeAvl& t)
    {
        TreeAvl u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = std::max(Height(t->left), Height(t->right)) + 1;
        u->height = std::max(Height(u->left), t->height) + 1;
        return u;
    }

    TreeAvl SingleLeftRotate(TreeAvl& t)
    {
        TreeAvl u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = std::max(Height(t->left), Height(t->right)) + 1;
        u->height = std::max(Height(t->right), t->height) + 1;
        return u;
    }

    TreeAvl DoubleLeftRotate(TreeAvl &t)
    {
        t->right = SingleRightRotate(t->right);
        return SingleLeftRotate(t);
    }

    TreeAvl DoubleRightRotate(TreeAvl& t)
    {
        t->left = SingleLeftRotate(t->left);
        return SingleRightRotate(t);
    }

    TreeAvl FindMin(TreeAvl t)
    {
        TreeAvl result = nullptr;
        if (t)
        {
            if (t->left == NULL)
                result = t;
            else
                result= FindMin(t->left);
        }
        return result;
    }

    TreeAvl FindMax(TreeAvl t)
    {
        TreeAvl result = nullptr;
        if (t)
        {
            if (t->right == NULL)
                result = t;
            else
                result = FindMax(t->right);
        }
        return result;
    }

    TreeAvl Remove(info x, TreeAvl t)
    {
        TreeAvl temp, result=nullptr;

        // Element found
        if (t)
        {
            // Searching for element
            if (t->information.compare_t2(x) == 1)
                t->left = Remove(x, t->left);
            else if (t->information.compare_t2(x) == -1)
                t->right = Remove(x, t->right);

            // Element found
            // With 2 children
            else if (t->left && t->right)
            {
                temp = FindMin(t->right);
                t->information = temp->information;
                t->right = Remove(t->information, t->right);
            }
            // With one or zero child
            else
            {
                temp = t;
                if (t->left == NULL)
                    t = t->right;
                else if (t->right == NULL)
                    t = t->left;
                delete temp;
            }
            if (t == NULL)
                result = t;
            else
            {
                t->height = std::max(Height(t->left), Height(t->right)) + 1;

                // If node is unbalanced
                // If left node is deleted, right case
                if (Height(t->left) - Height(t->right) == 2)
                {
                    // right right case
                    if (Height(t->left->left) - Height(t->left->right) == 1)
                        result= SingleLeftRotate(t);
                    // right left case
                    else
                        result= DoubleLeftRotate(t);
                }
                // If right node is deleted, left case
                else if (Height(t->right) - Height(t->left) == 2)
                {
                    // left left case
                    if (Height(t->right->right) - Height(t->right->left) == 1)
                        result= SingleRightRotate(t);
                    // left right case
                    else
                        result= DoubleRightRotate(t);
                }
            }
        
        }
        return result;
    }

    int Height(TreeAvl t)
    {
        return (t == NULL ? -1 : t->height);
    }

    int GetBalance(TreeAvl t)
    {
        if (t == NULL)
            return 0;
        else
            return Height(t->left) - Height(t->right);
    }

    void Print_tree(TreeAvl t, int level)
    {
        if (t)
        {
            Print_tree(t->right, level + 2);
            for (int i = 1; i <= level; i++) {
                std::cout << ' ';
            }
            std::cout << t->information.avg << '\n';
            Print_tree(t->left, level + 2);
        }

    }

public:
    Avl_Tree(const std::string file_name)
    {
        std::ifstream file(file_name);
        info elem;
        root = nullptr;
        while (file >> elem)
            Insert(elem, root);
        file.close();
    }
    Avl_Tree()
    {
        root = NULL;
    }

    void insert(info x)
    {
        root = Insert(x, root);
    }

    void remove(info x)
    {
        root = Remove(x, root);
    }

    void Print()
    {
        Print_tree(root, 0);
        std::cout << '\n';
    }
};

//int main()
//{
//    BST t;
//    int n;
//    std::cin >> n;
//    info x;
//    for (size_t i = 0; i < n; i++)
//    {
//        std::cin >> x;
//        t.insert(x);
//    }
//    t.Print();
//}
