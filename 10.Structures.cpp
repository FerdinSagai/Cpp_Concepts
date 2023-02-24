/*

Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:

This code covers the following C++ feature -
1. STRUCTURES
2. ARRAY OF STRUCTURES
3. POINTERS TO STRUCTURES

------------------------------------------------------
Theory:
------------------------------------------------------
Key Points:
------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include<iostream>

struct School
{
	std::string name;
	int No_of_Science_students{ 0 };
	int No_of_Commerce_students{ 0 };
	int No_of_Teaching_Staff{ 0 };
};

struct Student
{
	std::string name;
	int roll_no{0};
	char grade = 'U';
};

struct Staff
{
	std::string name;
	int emp_id{ 0 };
	double salary{0.00};
};

int main()
{
	School Test;

	Test.name = "QWERTY College of Science and Technology";
	Test.No_of_Science_students = 3;
	Test.No_of_Commerce_students = 3;
	Test.No_of_Teaching_Staff = 3;

	Student Science_Stream[3];
	Student Commerce_Stream[3];

	std::cout << "Enter Details for Science Stream" << std::endl;
	for (int i = 0; i < Test.No_of_Science_students; i++)
	{
		std::cout << "Enter Name : " << std::endl;
		std::cin >> Science_Stream[i].name;
		std::cout << "Enter Roll number : " << std::endl;
		std::cin >> Science_Stream[i].roll_no;
		std::cout << "Enter Grade : " << std::endl;
		std::cin >> Science_Stream[i].grade;
	}

	std::cout << "Enter Details for Commerce Stream" << std::endl;
	for (int i = 0; i < Test.No_of_Commerce_students; i++)
	{
		std::cout << "Enter Name : " << std::endl;
		std::cin >> Commerce_Stream[i].name;
		std::cout << "Enter Roll number : " << std::endl;
		std::cin >> Commerce_Stream[i].roll_no;
		std::cout << "Enter Grade : " << std::endl;
		std::cin >> Commerce_Stream[i].grade;
	}
//========================================================================
	Staff* Tearching_Staff = new Staff[Test.No_of_Teaching_Staff];
	std::cout << "Enter Details for Teaching Staff" << std::endl;
	for (int i = 0; i < Test.No_of_Teaching_Staff; i++)
	{
		std::cout << "Enter Name : " << std::endl;
		std::cin >> Tearching_Staff[i].name;
		std::cout << "Enter Employee id : " << std::endl;
		std::cin >> Tearching_Staff[i].emp_id;
		std::cout << "Enter Salary : " << std::endl;
		std::cin >> Tearching_Staff[i].salary;
	}

	return 0;
}