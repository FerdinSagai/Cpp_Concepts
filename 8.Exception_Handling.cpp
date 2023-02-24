/*
Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:

Exception is an unexpected problem that arises during the execution of a program
Exception handling is a mechanism to transfer control from the main operation to an error handling part.
Complied correctly but runtime error can occur.

Better than print statements.
The code does not crash. Instead correction can be implemented.

try, throw catch
try block: the condition that can cause an error.
it is followed by multiple catch blocks

throw block:
Throws the exception when problem surfaces

catch block:
it catches the exception thrown from the try block

a single try block can have multiple catch blocks
Every throw block must have corresponding catch blocks

------------------------------------------------------
Theory:

try
throw
catch
------------------------------------------------------
Key Points:
------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include<iostream>
/*
int main()
{
	int a{ 0 }, b{ 0 };
	int result{ 0 };
	std::cout << "Enter Numerator and Denominator" << std::endl;
	std::cin >> a >> b;
	// The program will usually hang if b is given as zero.
	// Now the program will end and print out a message
	try
	{
		if (b == 0)
		{
			throw b;
		}
	}
	catch (int ex)
	{

		std::cout << " Exception:: Division by 0 not allowed. Correcting b to 1" << std::endl;

		b = 1;
	}
	result = a / b;
	std::cout << result << std::endl;

	return 0;
}

*/

// Example 2 
// The purpose of this function is to allocate an array using the size provided.
// In this case the size provided is the largest integer possible and this allocation is impossible.
// The allocation will fail. Malloc will crash. If new was used, then an exception would be thrown. 
// For a demo of exception handling, malloc is used instead of new. 
// READ NOTE A:: WARNING. THIS HANGS THE CODE

// Every throw needs a corresponding catch statement. 
// All exceptions are stored in the std namespace
// exception is an abstract class that has bad_alloc, runtime_error,out_of_range as children
// the what() in exception is pure virtual. So calling any of the children will replace the parent function. 
// This allows us to use catch (std::exception& ex) as a generic.
// We pass the parent but get the what() implementation of the children.
// catch(...) stands for catch all. The disadvantage is that it is not clear which throw triggered this catch.
int Allocate_Memory(int count)
{
	int* pArray = (int*)malloc(count * sizeof(int));
	if (pArray == nullptr)
	{
		throw std::runtime_error("ERROR :: Failed to allocate memory");
	}

	if (count<=10)
	{
		
		throw std::out_of_range("ERROR :: Need to be greater than 10");
	}

	for (int i = 0; i < count; i++)
	{
		pArray[i] = i;
	}

	free(pArray);
	return 0;
}

int main()
{
	try
	{
		
		 //Allocate_Memory(std::numeric_limits<int>::max());  READ NOTE A
		Allocate_Memory(10);
		
	}

	catch (std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (std::out_of_range& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (std::bad_alloc& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	// Alternatively
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	// Alternatively
	catch (...)
	{
		std::cout << "Exception" << std::endl;
	}
	return 0;
}

