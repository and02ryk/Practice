#include<iostream>
#include<string>
#include<fstream>
#include"DLL.h"
#include"BinSearchTree.h"
#include"AvlTree.h"

struct Full_info
{
	std::string firstName;
	std::string lastName;
	short mark[5];

	Full_info() { for (size_t i = 0; i < 5; i++) mark[i] = 0; };
	void Read(std::ifstream& file)
	{
		file >> firstName >> lastName;
		for (size_t i = 0; i < 5; i++)
		{
			file >> mark[i];
		}
	}

	double to_avg()
	{
		double avg = 0;
		for (size_t i = 0; i < 5; i++)
		{
			avg += mark[i];
		}
		avg /= 5;
		return avg;
	}

	std::string to_string_marks()
	{
		std::string result;
		for (size_t i = 0; i < 5; i++)
		{
			result += std::to_string(mark[i]) + ' ';
		}
		return result;
	}
};

int main()
{
	std::string file_name = "data.txt";
	std::ofstream offile(file_name);
	Full_info information;
	size_t n;
	std::cout << "Enter count students\n";
	std::cin >> n;

	//считывание с клавиатуры и запись в файл data.txt
	std::cout << "Enter Firstname, Lastname, five marks\n";
	for (size_t i = 0; i < n; i++)
	{
		std::getline(std::cin, information.firstName, ' ');
		std::getline(std::cin, information.lastName, ' ');
		for (size_t i = 0; i < 5; i++)
		{
			std::cin >> information.mark[i];
			while (information.mark[i] < 2 || information.mark[i]>5)
			{
				std::cout << "\nEntered wrong numder.  ";
				std::cin >> information.mark[i];
			}
		}
		std::cin.ignore();

		offile << information.firstName << ' ' << information.lastName;
		for (size_t i = 0; i < 5; i++)
			offile << ' ' << information.mark[i];
	}
	offile.close();

	DLL dll_first_task, dll_second_task;
	std::cout << "-------------\n";

	dll_first_task.create_1(file_name); //create_1 задание 2
	dll_first_task.Print();
	std::cout << "-------------\n";

	dll_second_task.create_2(file_name);  //create_2 задание 3
	dll_second_task.Print();
	std::cout << "-------------\n";

	Binary_tree t(file_name); //задание 4
	t.print();
	std::cout << "--------------\n";

	Avl_Tree avlt(file_name); // задание 5
	avlt.Print();
	std::cout << "--------------\n";

	//задание 6
	std::string result;
	Full_info* arr_info=new Full_info[n];
	double max_avg = 0;
	std::ifstream file(file_name);
	for (size_t i = 0; i < n; i++)
	{
		arr_info[i].Read(file);
		if (arr_info[i].to_avg() == max_avg)
			result += arr_info[i].lastName + ' ' + arr_info[i].to_string_marks() + '\n';
		else if (arr_info[i].to_avg() > max_avg)
		{
			max_avg = arr_info[i].to_avg();
			result = arr_info[i].lastName + ' ' + arr_info[i].to_string_marks() + '\n';
		}
	}
	std::cout << result;
	system("pause");
}


//4
//p p 4 4 4 4 4
//t u 3 3 3 2 2
//e e 3 3 3 3 3
//o p 5 4 5 4 5

//3
//o p 5 4 5 4 5
//p p 4 4 4 4 4
//t u 3 3 3 3 3