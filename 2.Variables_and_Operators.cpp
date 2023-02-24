/*

Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:

This code covers the following C++ feature -
1. VARIABLES
	a. Arithmetic
		i.		bool
		ii.		char
		iii.	int
		iv.		float
		v.		double
		vi.		string
		vii.	auto

	b. Modifiers
		i.		signed
		ii.		unsigned
		iii.	short
		iv.		long

	c. Qualifiers
		i.		const
		ii.		volatile
		iii.	static
2. ARRAYS
	
3. OPERATORS
	a. Normal Operators
	b. Binary Operators
	c. Urnary Operators
------------------------------------------------------
Theory:
------------------------------------------------------
Key Points:
------------------------------------------------------
VARIABLES
Declared variables have a scope where they are active
They go out of scope once the } is encountered
Variables declared with the keyword static have global scope
They stored in a different part of the memory from the other variables
	
Strings are special objects inside namespace std.
The strings are initialized inside the namespace and so there is no need to initialize them
Literals are used to initialize characters and strings.
Character literals are 'a'
String literals are ""
In auto, variable will take the datatype of the intializer. 
The initializer can be a value, function etc.

An variable is signed by default. 
Signed can represent both positive and negative values. 
An unsigned is an integer that can never be negative.

Short indicates a smaller size is required
Short int takes 2 bytes instead of 4
Range is from -32768 to 32767

Long indicates a larger size is required
Long int takes 4+ bytes instead of 4
Range is from -2147483647 to 2147483647

Const Qualifier are used to store constant values that cannot be changed
Volatile is a qualifier that is applied to a variable when it is declared. 
It tells the compiler that the value of the variable may change any time.
Static variable extend the scope of the variable outside a function

Initialize Variables when you declare them
Uniform Initialization is preferred in modern standards
Advantages of Uniform Initialization
	* 1. It forces Initialization
	* 2. You can use direct initialization for arrays
	* 3. It prevents Narrowing Conversions, i.e.
	float f{} ;
	int i{f};		//a float is being stored in int. Error will occur
	* 4. Uniform syntax for all types

ARRAYS
Arrays are a container that holds the same data type.
The arrays are stored in a contiguous memory block
Accessing any element of an array takes constant time.
This is called random access since the memory is contiguous
The size of the array must be know at declaration. (for static memory allocation)

OPERATORS
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include<iostream>
int main()
{
//1. VARIABLES===================================================================
	std::cout << "Void and Arithmetic :: bool, char, int, float, double" << std::endl;
	// Scalar types
	char ch = 'a';
	bool flag = true;
	float f = 1.283f;
	double d = 521.342;
	std::string word = "Test Word";
	auto term{1.32};

	std::cout << "Modifiers :: signed, unsigned, short, long" << std::endl;
	std::cout << "Qualifiers :: const, volatile, static" << std::endl;
//Const Qualifier are used to store constant values that cannot be changed
	std::cout << "The syntax is" << std::endl;
	const float PI{ 3.142f };
	std::cout << "The value of Pi is" << PI << std::endl;
// Static variable extend the scope of the variable outside a block
	for (int i = 0; i < 10; i++)
	{
		{
			int update = 0;
			static int count = 0;
			count++;
			std::cout << "Variable updated by static :: " << count << std::endl;
			std::cout << "Variable updated by static :: " << update << std::endl;
		}
	}
//2. ARRAYS======================================================================
//3. OPERATORS===================================================================
	int i{ 1 };
	// Normal Operators
	i = i + 10;
	i = i - 1;
	i = i * 2;
	i = i / 2;
	i = i % 3;
	std::cout << "Result of normal operators  :: " << i << std::endl;

	// Binary form Operators
	i += 10;
	i -= 1;
	i *= 2;
	i /= 2;
	i %= 3;
	std::cout << "Result of binary operators :: " << i << std::endl;

	// Urnary form Operators
	i++;
	std::cout << "Result of post increment urnary operator  :: " << i << std::endl;
	i--;
	std::cout << "Result of post decrement urnary operator  :: " << i << std::endl;
	++i;
	std::cout << "Result of pre increment urnary operator  :: " << i << std::endl;
	--i;
	std::cout << "Result of pre decrement urnary operator  :: " << i << std::endl;
	//For instance
	// i++ returns value of i and then performs increment. ++i performs increment and then returns i.
	// The difference is not immediately obvious since the importance of return is only on the same line.
	std::cout << "i is :: " << i << " on line 1" << std::endl;
	std::cout << "Result i++ :: " << i++ << " Result ++i :: " << ++i << std::endl;
	return 0;
}

