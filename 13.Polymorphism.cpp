/*

Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:

This code covers the following C++ feature -
1. POLYMORPHISM
	a. Static polymorphism/ early binding : Occurs at Complile time
		i. Function Overloading
		ii. Operator Overloading
		iii. Templates
	b. Dynamic polymorphism/ late binding : Occurs at Run time
		i. Function Overriding
------------------------------------------------------
Theory:

Polymorphism means having many forms.


Virtual Function 
A Virtual function is a member function which is declared within base class and is redefined by the derived class.
This is called overriding. It is a feature that enables runtime polymorphism
// Dynamic dispatch V tables
 // Runtime costs. Performace costs
 Allows the definition of a single function capable of working on all the objects and their children
 Non Virtual function that are common to parent and child will use the parent version.
 Virtual function in the parent will be overridden by child's functions.





Abstract Classes
Sometimes implementation of all functions cannot be provided in a base class, because the implementation is not known.
Such a class is called an abstract class.

A Pure virtual function is a virtual function for which we don't have an implementation. 
The implementation will be provided by derived classes which will override the pure virtual function. 
A Pure Virtual Function is declared by assigning 0 in declaration. 

A class is abstract if it has at least one pure virtual function.
We can have pointers and references of abstract class type.
If we do not override a pure virtual function in a derived class, then the derived class is also an abstract class.
Abstract classes cannot be instantiated


------------------------------------------------------
Key Points:
Templates are expanded at compiler time, wery much like macros.
The difference is, that the compiler does type checking before template expansion.
The idea is simple, source code contains only function/class.
But compiled code may contain multiple copies of the same function/class.

------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include<iostream>
class Animal
{
public:
	void Eat() { std::cout << "Eating Generic Food " << std::endl; }
	virtual void EatMore() { std::cout << "Eating More Generic Food " << std::endl; }
};

class Cat :public Animal
{
public:
	void Eat() { std::cout << "Eating Cat Food " << std::endl; }
	void EatMore() { std::cout << "Eating More Cat Food " << std::endl; }
};

class Dog :public Animal
{
public:
	void Eat() { std::cout << "Eating Dog Food " << std::endl; }
	void EatMore() { std::cout << "Eating More Dog Food " << std::endl; }
};

// Abstract Class Example
class Shape 
{
public:
	virtual void getArea()= 0; // Abstract Function
};

class Circle :public Shape
{
public:

	void getArea()
	{
		std::cout << "Area of Circle" << std::endl;
	}
};

class Rectangle :public Shape
{
public:

	void getArea()
	{
		std::cout << "Area of Rectangle" << std::endl;
	}
};



void Eat_Call(Animal* x)
{
	// This is a function that essentially works for the entire animal object and its children. 
	std::cout << std::endl;
	std::cout <<" Inside Function"<<std::endl;
	std::cout << " Result of Non virtual function " << std::endl;
	std::cout << " -------------------------------------" << std::endl;
	x->Eat(); // Prints statement from Base Class Animal
	std::cout << " Result of virtual function " << std::endl;
	std::cout << " -------------------------------------" << std::endl;
	x->EatMore(); // Prints statement from Child class Cat. Because EatMore is Virtual in Animal. Is overridden
}

int main()
{
	Animal* Anim = new Animal();
	Cat* Meow1 = new Cat();
	Dog* Woof1 = new Dog();

	Anim->Eat(); // Prints statement from Base Class Animal
	Meow1->Eat(); // Prints statement from Base Class Animal 
	Woof1->Eat(); // Prints statement from Base Class Animal 

	Eat_Call(Anim);

	Eat_Call(Meow1);
	Eat_Call(Woof1);

	//Shape S; // Cannot perform this. It is an abstract class. It cannot be instantiated
	Circle C;
	Rectangle R;

	C.getArea();
	R.getArea();

	return 0;
}