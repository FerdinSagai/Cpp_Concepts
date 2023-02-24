/*
Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:
------------------------------------------------------
Theory:
------------------------------------------------------
Key Points:
Variables are sent ot the function. They are received in the function as local variables
These variables received by the function are local to the function.

Function call  
Test_function (a , b)

Function definition
void Test_function(int a, int b)
{
	a = 2100;
	b = -2100;
}
The changes made to a nad b inside the function are not reflected in the main
This is because the a and b variables in main are different from a and b in the function.
 
 Common practice to avoid confusion is to use differnt variables
 Function call
Test_function (a , b)

Function definition
void Test_function(int x, int y)
{
	x = 2100;
	y = -2100;
}
Sometimes it is desirable to use the the same variable name in the function as passed by the main function.
This avoids a lot of confusion in large programs but is subject to the previous confusion.
The best practice in such situations is the use of _
 Function call
Test_function (a , b)

Function definition
void Test_function(int _a, int _b)
{
	_a = 2100;
	_b = -2100;
}
The underscore (_) means nothing in execution or operational perspective.
It just conveys that the variable's scope is local to the function.

------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include <iostream>
int add(int, int);
void Print(char);
void Swap_by_value(int, int);
void Swap_by_address(int*, int*);
void Swap_by_reference(int&, int&);
void Print_through_Recursion(char);
int main()
{
	int x{ -1 }, y{5};
	std::cout << "Result of addition using a function :: " << add(x, y) << std::endl;
	int a{};
	int b{};

	int* ptr_a{ &a };
	int* ptr_b{ &b };

	int& ref_a{ a };
	int& ref_b{ b };

	std::cout << "Enter the two values to swap ::" << std::endl;
	std::cin >> a >> b;

	Print('X');

	std::cout << "Main function Pre-swap :: Value 1 :: " << a << "\tValue 2 :: " << b << std::endl;
	Swap_by_value(a, b);
	std::cout << "Main function Post-swap :: Value 1 :: " << a << "\tValue 2 :: " << b << std::endl;

	Print('X');

	std::cout << "Main function Pre-swap :: Value 1 :: " << a << "\tValue 2 :: " << b << std::endl;
	std::cout << "Address Pre-swap :: Value 1 :: " << &a << "\tValue 2 :: " << &b << std::endl;
	Swap_by_address(ptr_a, ptr_b);
	std::cout << "Main function Post-swap :: Value 1 :: " << a << "\tValue 2 :: " << b << std::endl;
	std::cout << "Address Post-swap :: Value 1 :: " << &a << "\tValue 2 :: " << &b << std::endl;
	Print('X');

	std::cout << "Main function Pre-swap :: Value 1 :: " << a << "\tValue 2 :: " << b << std::endl;
	Swap_by_reference(ref_a, ref_b);
	std::cout << "Main function Post-swap :: Value 1 :: " << a << "\tValue 2 :: " << b << std::endl;
	std::cout << "Address Post-swap :: Value 1 :: " << &a << "\tValue 2 :: " << &b << std::endl;

	Print_through_Recursion('X');

	return 0;
}
static int iter = 0;
void Print_through_Recursion(char ch)
{
	if (iter == 50) 
	{
		std::cout << std::endl;
		return;
	}
	iter++;
	std::cout << ch;
	Print_through_Recursion('X');
}

void Print(char ch)
{
	for (int i = 0; i <= 20; i++)
	{
		std::cout << ch;
	}
	std::cout << std::endl;
}

int add(int _x, int _y)
{
	return (_x + _y);
}

/*
Swap by value only swaps the values locally wthin the scope of the function.
The change is not reflected in the main function unless the values are returned somehow.
*/

void Swap_by_value(int x, int y)
{
	int temp{};

	temp = x;
	x = y;
	y = temp;

	std::cout << "Swap by value :: Value 1 :: " << x << "\tValue 2 :: " << y << std::endl;
}
/*
Swap by address swaps the values globally and the changes are reflected in main too.
*/
void Swap_by_address(int* x, int* y)
{
	int temp{};

	temp = *x;
	*x = *y;
	*y = temp;

	std::cout << "Swap by address :: Value 1 :: " << *x << "\tValue 2 :: " << *y << std::endl;
}

/*
Swap by reference swaps the values globally and the changes are reflected in main too. Addresses are not changed
*/
void Swap_by_reference(int& x, int& y)
{
	int temp{};

	temp = x;
	x = y;
	y = temp;

	std::cout << "Swap by reference :: Value 1 :: " << x << "\tValue 2 :: " << y << std::endl;
}