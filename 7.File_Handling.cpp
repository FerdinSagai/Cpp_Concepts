/*
Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:
------------------------------------------------------
Theory:
ios::out
ios::in
ios::app
ios::ate take to end of file
------------------------------------------------------
Key Points:
------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char arr[100];

	cout << "Enter data line : " << endl;
	cin.getline(arr, 100); // getline is used since cin ignores anything after spaces

	// FILE WRITE OPERATION
	ofstream myfile("Test.txt", ios::out);
	// OR fstream myfile("Test.txt", ios::out);
	//myfile.open("Test.txt"); // This command is iffy.. DO NOT USE. File is opened by ofstream
	if (myfile.is_open() ) 
	{
		myfile << arr;
		myfile.close();
	}


	// FILE READ OPERATION
	char arr_op[100];
	ifstream obj("Test.txt", ios::in);
	// OR fstream obj("Test.txt", ios::in);
	//obj.open("Test.txt");// This command is iffy.. DO NOT USE. File is opened by ifstream
	obj.getline(arr_op, 100);
	cout << "Data in File : " << arr_op << endl;
	obj.close();

	// APPENDING DATA TO AN EXISTING FILE
	cout << "Enter new data line : " << endl;
	cin.getline(arr, 100); 

	myfile.open("Test.txt", ios::app);
	// OR fstream obj("Test.txt", ios::out|ios::in); Openin output and append format
	if (myfile.is_open())
	{
		myfile << arr;
		myfile.close();
	}

	obj.open("Test.txt");
	obj.getline(arr_op, 100);
	cout << "Data in File : " << arr_op << endl;
	obj.close();

	return 0;
}