/*

Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:

This code covers the following C++ feature -
1. LOOP STRUCTURES
These include
	a. For Loop
	b. While Loop
	c. Do While loop
------------------------------------------------------
Theory:
loop body is not executed if the condition is false. This is true for entry controlled loop
The exit controlled loop execute the body of the loop at least once.
------------------------------------------------------
Key Points:
1. WHILE LOOP is an entry controlled loop.
2. DO-WHILE LOOP is an exit controlled loop
3. FOR LOOP also behaves as a entry controlled loop.
------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include<iostream>
int main()
{
	for (int i = 0; i <= 10; i++)
	{
		std::cout << "The number printed by FOR LOOP is :: " << i << std::endl;
	}

	std::cout << std::endl;

	for (int i = 11; i <= 10; ++i)
	{
		std::cout << "The number printed by FOR LOOP is :: " << i << std::endl;
	}

	std::cout << std::endl;
	int i{0};
	while (i < 11)
	{
		std::cout << "The number printed by WHILE LOOP is :: " << i << std::endl;
		i++;
	}


	std::cout << std::endl;
	i = 0;
	do
	{
		std::cout << "The number printed by DO-WHILE LOOP is :: " << i << std::endl;
		i++;
	}while (i < 11);

	return 0;
}