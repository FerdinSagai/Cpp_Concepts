/*

Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:
------------------------------------------------------
Theory:
------------------------------------------------------
Key Points:
& - accesses address of the variable
*p -  used to declare a pointer
* is also termed as the de-referenceing operator. 
*p gives the value at address stored in p.

A Pointer can be assigned to an array.
Pointer to an array will point to the 0th element.
Arrays are contiguous in memory. 
Incrementing the pointer will make it point ot the 1st element.
------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include<iostream>
int main()
{
	using namespace std;
	//===============================================================================
	cout << "---------------BEGIN CONCEPT 1--------------"<< endl;
	int x = 50;
	int* ptr = nullptr; // int pointer can only point to a integer. void 
	ptr = &x;
	cout << "Address of variable x using &x:: " << &x << endl;
	cout << "Address of variable x using ptr:: " << ptr << endl;
	cout << "Value of variable x using dereferencing *:: " << *ptr << endl;
	ptr = nullptr;
	cout << "--------------END OF CONCEPT 1--------------" << endl<< endl;
//===============================================================================
	cout << "---------------BEGIN CONCEPT 2--------------" << endl;
	int numbers[] = { 1,2,3,4,5 };
	ptr = &numbers[0];
	cout << "Address pointed to  :: " << ptr << endl;
	cout << "Address of element 0   :: " << &numbers[0] << endl;
	cout << "0th Value from pointer  :: " << *ptr << endl;
	ptr++;
	cout << "1st Value from pointer  :: " << *ptr << endl;
	ptr++;
	cout << "2nd Value from pointer  :: " << *ptr << endl;
	ptr = nullptr;
	cout << "--------------END OF CONCEPT 2--------------" << endl << endl;
	//===============================================================================
	cout << "---------------BEGIN CONCEPT 3--------------" << endl;
	const int CHUNK_SIZE = 512;
	// int* ptr_const = &CHUNK_SIZE; // This is not allowed. 
	/*	
	If it is, then the value can be changed with *ptr_const = 10;
	The pointer to a constant should also be a constant. i.e.
	*/
	
	/*
	The address that the ptr_const is pointing to is NOT constant,
	but the value in that address is constant.
	*/
	const int* ptr_const = &CHUNK_SIZE;
	x = 10;
	ptr_const = &x;		// Allowed. 
	//*ptr_const = 10;	// Not Allowed. ptr_const is a pointer to a const integer. 

	int* const ptr_const2 = &x;
	x = 100;
	//ptr_const2 = &x; // Not Allowed. 
	*ptr_const2 = 10;  // Allowed. 

	/*
	This makes the pointer itself as a constant.
	The ptr_const will always point to a single address.
	The value in that address can change
	*/
	cout << "--------------END OF CONCEPT 3--------------" << endl << endl;
	//===============================================================================
	cout << "---------------BEGIN CONCEPT 4--------------" << endl;
	/*In C++
	C++ provides operators to allocate memory.
	new		:- allocates memory on the heap and returns a pointer to that location
	delete	:- deallocates memory
	memory allocated with new must be released using delete

	Syntax:-
	<type>*<variable> = new<type>(optional arguments);
	delete <variable>;
	*/
	int* p_cpp = new int(4);		// Initialized with 4
	*p_cpp = 6;						// Changed to 6
	std::cout << *p_cpp << std::endl;
	delete p_cpp;
	p_cpp = nullptr;


	// New for 1D arrays: 
	/*
	Syntax:
		<type> *<variable>=new <type>[size of array];
		delete[] <variable>;
	*/

	int* p_cpparr = new int[5];
	for (int i = 0; i < 5; i++)
	{
		p_cpparr[i] = i;
		std::cout << p_cpparr[i] << std::endl;
	}
	delete[]p_cpparr;
	p_cpparr = nullptr;

	char* c = new char[5];
	strcpy_s(c, 4, "C++");
	std::cout << c << std::endl;
	delete[]c;
	c = nullptr;

	// New for 2D arrays: 
	/*
	2D arrays are stored as 1D contiguous arrays in the memory heap
	*/
	int data[2][3] = {
		1,2,3,
		4,5,6
	};
	std::cout << data[0][1] << std::endl;

	/*
	To create the same on a heap, we have to create 2 1D arrays.
	We create 2 pointerd for each 1D array and then create a pointer to pointer that points to the two 1D pointer

	*/

	int* p1 = new int[2];
	int* p2 = new int[3];
	int** pdata = new int* [2]; // Allocates 1D array for integer pointers

	pdata[0] = p1;
	pdata[1] = p2;

	pdata[0][0] = 7;
	pdata[0][1] = 7;

	pdata[1][0] = 7;
	pdata[1][1] = 7;
	pdata[1][2] = 7;

	std::cout << pdata[0][1] << std::endl;
	/*Free memory in the same order in which they were allocated*/

	delete[]p1;
	delete[]p2;
	delete[]pdata;
	p1 = nullptr;
	p2 = nullptr;
	pdata = nullptr;

	//int *p = malloc(sizeof(int));		
/* This works in C
malloc is a function that returns a pointer of type void.
In C the pointer is automatically type-cast into the type of the pointer
This does not happen in C++. Here the malloc return void pointer must be forcibly typecast.
i.e. :: int* p = (int*) malloc(sizeof(int));

*/

	/*

	new vs malloc

	malloc
		Function
		Requires size during allocation
		cannot initialize memory
		cannot call constructors
		returns void pointer that needs to be typecast
		cannot be customized
		malloc, calloc and realloc
		returns null pointer when memory allocation fails

	new
		operator
		size is ascertained from the type
		can initialize memory
		can call constructors
		returns correct type of pointer
		can be customized through overloading
		new has different forms
		throws exception on failure

		new is superior to malloc
	*/

	cout << "--------------END OF CONCEPT 4--------------" << endl << endl;
	//===============================================================================
	return 0;
}