/*

Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:

This code covers the following C++ feature -
1. CONTROL STRUCTURES
	a. IF - ELSE IF - ELSE Statements
	b. SWITCH - CASE Statements
	In C++, the code executed instructions in a sequential manner.
The control flow is from top to bottom.
Two important paths are needed to this linear flow.
These are loops and forks.

Loops indicate the repetition of a particular piece of code.
The repetition is performed till a specified condition is fulfilled.
After the condition is fulfilled, the flow of the code is linear again.

The second type of path is forks wherein, a specified condition determines which parts of the code is executed.
The body of the code for which the condition is false is not execute.
However it is complied. This implies that :-
the all branches of the forks are complied
this compilation takes time
If the fork condition is inside a loop, then the condition is checked every iteration,
This makes forks inside loops very inefficient.

There are other instances in which the control of the code divert away from the linear flow.
This occurs in the case of functions


	Start
	  |
	  |
 Body of code
	  |
	  |
	 Loop<---------------
	  |					|
	  |		Body		|
	  |Exit condition	|
	  |----------------->
	  |
	  |
  Body of code
	  |
	  |
Fork conditional -true-->   |
					Body for True condition
	 |<---------------------|
	 |
	 |			 -false-->  |
	 |			Body for False condition
	 |	 |<-----------------|
	 |   |
  Body of code
	  |
	  |
Function Call ------------->*

	  <--------------------*
	  |
	  |
	 End


------> * Function
				  |
				  |
			Body of function
				  |
				  |
		return from function ---->*
------------------------------------------------------
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
Theory:
------------------------------------------------------
Key Points:
------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include<iostream>
int main()
{
	int option{0};
	std::cout << "Enter the option :: " << std::endl;
	std::cin >> option;
	
	if (option == 0) { std::cout << "Option 0 is chosen" << std::endl; }
	else if (option == 1) { std::cout << "Option 1 is chosen" << std::endl; }
	else if (option == 2) { std::cout << "Option 2 is chosen" << std::endl; }
	else if (option == 3) { std::cout << "Option 3 is chosen" << std::endl; }
	else if (option == 4) { std::cout << "Option 4 is chosen" << std::endl; }
	else { std::cout << "Option not recognized" << std::endl; }
	
	
	switch (option)
	{
	case (0):
			std::cout << "Option 0 is chosen" << std::endl; 
			break;
	case (1):
		std::cout << "Option 1 is chosen" << std::endl;
		break;
	case (2):
		std::cout << "Option 2 is chosen" << std::endl;
		break;
	case (3):
		std::cout << "Option 3 is chosen" << std::endl;
		break;
	case (4):
		std::cout << "Option 4 is chosen" << std::endl;
		break;
	default:
		std::cout << "Option not recognized" << std::endl;
		break;
	}
	

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
	int i{ 0 };
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
	} while (i < 11);

	return 0;
}