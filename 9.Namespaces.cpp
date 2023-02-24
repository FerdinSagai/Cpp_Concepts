/*

Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:

This code covers the following C++ feature -
1. NAMESPACES
------------------------------------------------------
Theory:
	A namespace is a named declarative region for declaring types
	The types are not visible outside the namespace
	Prevents name clashes
	Helps Modularize. Classes and functions towards one purpose can be grouped under one namespace

	* Creating namespaces
	Syntax::
		namespace <name>
		{
			(namespace, class, structure, function, variable, etc)
		}

	Namespace can be opened as
	using namespace std for standard
	Opening namespace is not desirable.

	Instead we can use declaratives such as
	using std::cout;
	or by using the full qualified name
		std::cout << "c++" << std::endl;


Two functions can have the same name if they are overloaded.

If the two function prototypes are identical but serve different functions,
they can be placed in two namespace. They can be accessed by their full qualified name.


Nesting of namespace is possible
A nested namespace can be accessed by using the declarative
	using Sort::Comparison;
or by using the full qualified name
	Sort::Comparison::Lesser();


	// Creating a Namespace without a name

Accessing a function inside a nameless namespace is done directly
InternalFunction();
------------------------------------------------------
Key Points:
------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include <iostream>

namespace Maths
{
	float Calculate(float a, float b)
	{
		return a + b;
	}
}

namespace Stats
{
	float Calculate(float a, float b)
	{
		return (0.5 * (a + b));
	}
}

namespace Sort_and_Search
{
	namespace Sort
	{
		float Insertionsort()
		{
			return 1.2f;
		}

		float Selectionsort()
		{
			return 1.2f;
		}

		float Bubblesort()
		{
			return 1.2f;
		}

		float Countingsort()
		{
			return 1.2f;
		}

		float Radixsort()
		{
			return 1.2f;
		}

		float Shellsort()
		{
			return 1.2f;
		}

		float Mergesort()
		{
			return 1.2f;
		}

		float Quicksort()
		{
			return 1.2f;
		}
	}
	// This is a nested namespace
	namespace Search
	{
		float Linear_Search()
		{
			return 1.2f;
		}

		float Binary_Search()
		{
			return 1.2f;
		}
	}
}


int main()
{
	float c{ 0.251f }, d{ 8.1850f };

	std::cout << "The result of calculate from Math  namespace is  :: " << Maths::Calculate(c, d) << std::endl;
	std::cout << "The result of calculate from Stats namespace is  :: " << Stats::Calculate(c, d) << std::endl;

	std::cout << "Calling Merge Sort     :: " << Sort_and_Search::Sort::Mergesort() << std::endl;
	std::cout << "Calling Binary Search  :: " << Sort_and_Search::Search::Binary_Search() << std::endl;
	return 0;
}