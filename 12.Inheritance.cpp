/*
Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:

This code covers the following C++ feature -
1. INHERITANCE
------------------------------------------------------
Theory:

Defines a class in terms of another class

Reusability and Maintainability

Implements a IS-A relationship

Types of inheritance
------------------------
Single level Inheritance :
One Base class with One Child class

Multi Level Inheritance
One Base class with One Child class and one Grandchild Class

Hierarchial Inheritance
One Base class with Multiple Child classes

Multiple Inheritance
Multiple Base classes with One Child class



Hybrid Inheritance
Combination of the above


Types of Access
------------------------
public and protected used. Private is not used

------------------------------------------------------
Key Points:
Syntax
class derived-class:access-specifier base-class

------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================
#include <iostream>
#include <string>

// Single Inheritance :: One Base class with One Child class
class Single_Inheritance_Parent
{
public:
	int x, y, z;
	Single_Inheritance_Parent()
	{
		x = 1;
		y = 2;
		z = 3;
	}
};

class Single_Inheritance_Child :public Single_Inheritance_Parent
{
};

// Multi Level Inheritance :: One Base class with One Child class and one Grandchild Class
class Multi_Level_Inheritance_Parent
{
public:
	int x, y, z;
	Multi_Level_Inheritance_Parent()
	{
		x = 1;
		y = 2;
		z = 3;
	}
};

class Multi_Level_Inheritance_Child :public Multi_Level_Inheritance_Parent
{
};

class Multi_Level_Inheritance_Grandchild :public Multi_Level_Inheritance_Child
{
};

// Hierarchial Inheritance :: One Base class with Multiple Child classes
class Hierarchial_Inheritance_Parent
{
public:
	int x, y, z;
	Hierarchial_Inheritance_Parent()
	{
		x = 1;
		y = 2;
		z = 3;
	}
};
class Hierarchial_Inheritance_Child1 :public Hierarchial_Inheritance_Parent
{
};

class Hierarchial_Inheritance_Child2 :public Hierarchial_Inheritance_Parent
{
};

class Hierarchial_Inheritance_Child3 :public Hierarchial_Inheritance_Parent
{
};
// Multiple Inheritance :: Multiple Base classes with One Child class
class Multiple_Inheritance_Parent_Father
{
public:
	int x, y, z;
	Multiple_Inheritance_Parent_Father()
	{
		x = 1;
		y = 2;
		z = 3;
	}

	void Print()
	{
		std::cout << "Father " << std::endl;
	}
};

class Multiple_Inheritance_Parent_Mother
{
public:
	float a, b, c;
	Multiple_Inheritance_Parent_Mother()
	{
		a = 1.281;
		b = 2.751;
		c = 3.252;
	}
	void Print()
	{
		std::cout << "Mother " << std::endl;
	}
};

class Multiple_Child_public :public Multiple_Inheritance_Parent_Mother, public Multiple_Inheritance_Parent_Father
{
public:
	// Two versions of the void Print() function is inherited by the Child. 
	// Only one version can be active.  OR The child has to have its own version
	// Both the Parent versions can be accessed by using the scope resolution operator as shown below.
	// This is Function Over-riding. 
	// The issue of many versions of a function being inherited is called Ambiguity and its resolution
	void Print()
	{
		Multiple_Inheritance_Parent_Mother::Print();
		Multiple_Inheritance_Parent_Father::Print();
	}

};

// Hybrid Inheritance :: Combination of the above (Diamond Inheritance)
class Hybrid_Inheritance_Parent
{
public:
	int x, y, z;
	Hybrid_Inheritance_Parent()
	{
		x = 1;
		y = 2;
		z = 3;
	}
};
class Hybrid_Inheritance_Child_Mother :virtual public Hybrid_Inheritance_Parent
{
public:
	Hybrid_Inheritance_Child_Mother()
	{
		x = 10;
		y = 20;
		z = 30;
	}
};

class Hybrid_Inheritance_Child_Father :virtual public Hybrid_Inheritance_Parent
{
public:
	Hybrid_Inheritance_Child_Father()
	{
		x = 100;
		y = 200;
		z = 300;
	}
};

class Hybrid_Inheritance_Grandchild :public Hybrid_Inheritance_Child_Father, public Hybrid_Inheritance_Child_Mother
{
public:
	// This class inherits x, y, z from TWO Classes, which themselves inherit them from a single parent class.
	// This Grandchild class now receives two values for x, y, z.
	// This is the Diamond problem. The 2nd order class inherits 2 values for a variable.
	// Solution is Virtual Inheritance.
	// The Child Mother and Child Father inherit the Parent class Virtually.
	// This ensures that only one value of the variables of the Parent is sent to the grandchild. 
	// This value is the ones corresponding to the last class that the Grandchild inherits from. 
	// In this case Child_Mother
};
//===============================================================================
//===============================================================================
//===============================================================================
int main()
{
	// Function overriding

	Multiple_Child_public AB;
	AB.Print();

	Hybrid_Inheritance_Grandchild IGC;

	std::cout << "x :: " << IGC.x << std::endl;
	std::cout << "y :: " << IGC.y << std::endl;
	std::cout << "z :: " << IGC.z << std::endl;

	return 0;
}

//	This portion showcases access. It will not run, since it is erroneous
//================================================================================
//================================================================================
//================================================================================
//================================================================================
//================================================================================
/*
class Parent
{
private:
	int x;
protected:
	int y;
public:
	int z;
	Parent()
	{
		x = 1;
		y = 2;
		z = 3;
	}
	void InsideFunction();
};

void OutsideFunction(Parent obj)
{
	std::cout << " Private Access Variable Value ::" << obj.x << std::endl; // Generates an error. Access is Private. OutsideFunciton can't access
	std::cout << " Protected Access Variable Value ::" << obj.y << std::endl; // Generates an error. Access is Protected. OutsideFunciton can't access
	std::cout << " Public Access Variable Value ::" << obj.z << std::endl; // Generates No error. Access is Public
}

void Parent::InsideFunction()
{
	std::cout << " Private Access Variable Value ::" << this->x << std::endl; // Generates no error. InsideFunciton is a member
	std::cout << " Protected Access Variable Value ::" << this->y << std::endl; // Generates no error. InsideFunciton is a member
	std::cout << " Public Access Variable Value ::" << this->z << std::endl; // Generates no error. InsideFunciton is a member
}


// Inheriting

class Child_public :public Parent
{
	// Inherits 
	// 
	// protected int y
	// public int z
};
class Grandchild_public :public Child_public
{
	// Inherits  
	// 
	// protected int y
	// public int z
};

class Child_protected :protected Parent
{
	// Inherits 
	// 
	// protected int y
	// protected int z
};
class Grandchild_protected :protected Child_protected
{
	// Inherits 
	// 
	// protected int y
	// protected int z
};


class Child_private :private Parent
{
	// Inherits 
	// 
	// private int y
	// private int z
};

class Grandchild_private :private Child_private
{
	// Inherits 
	// 
	// Nothing. Since the Base class has everyting in private
};

int main()
{
	Parent test_parent;
	OutsideFunction(test_parent);
	test_parent.InsideFunction();

	std::cout << " Private Access Variable Value ::" << test_parent.x << std::endl;					// Cannot access this from outside as it is Private
	std::cout << " Protected Access Variable Value ::" << test_parent.y << std::endl;				// Cannot access this from outside as it is Protected
	std::cout << " Public Access Variable Value ::" << test_parent.z << std::endl;					// Can access this from outside as it is Public


	Child_public test_child_public;
	std::cout << " Private Access Variable Value ::" << test_child_public.x << std::endl;			// Cannot access this from outside as it is inhereted from test_parent as Private
	std::cout << " Protected Access Variable Value ::" << test_child_public.y << std::endl;			// Cannot access this from outside as it is inhereted from test_parent as Protected
	std::cout << " Public Access Variable Value ::" << test_child_public.z << std::endl;			// Can access this from outside as it is inhereted from test_parent as Public

	Grandchild_public test_grandchild_public;
	std::cout << " Private Access Variable Value ::" << test_grandchild_public.x << std::endl;		// Cannot access this from outside as it is inhereted from test_child as Private
	std::cout << " Protected Access Variable Value ::" << test_grandchild_public.y << std::endl;	// Cannot access this from outside as it is inhereted from test_child as Protected
	std::cout << " Public Access Variable Value ::" << test_child_public.z << std::endl;			// Can access this from outside as it is inhereted from test_child as Public



	Child_private test_child_private;
	std::cout << " Private Access Variable Value ::" << test_child_private.x << std::endl;			// Cannot access this from outside as it is inhereted from test_parent as Private
	std::cout << " Protected Access Variable Value ::" << test_child_private.y << std::endl;		// Cannot access this from outside as it is inhereted from test_parent as Protected
	std::cout << " Public Access Variable Value ::" << test_child_private.z << std::endl;			// Cannot access this from outside as it is inhereted from test_parent as Public

	Grandchild_private test_grandchild_private;
	std::cout << " Private Access Variable Value ::" << test_grandchild_private.x << std::endl;		// Cannot access this from outside as it is inhereted from test_child as Private
	std::cout << " Protected Access Variable Value ::" << test_grandchild_private.y << std::endl;	// Cannot access this from outside as it is inhereted from test_child as Protected
	std::cout << " Public Access Variable Value ::" << test_grandchild_private.z << std::endl;		// Cannot access this from outside as it is inhereted from test_child as Public



	Child_protected test_child_protected;
	std::cout << " Private Access Variable Value ::" << test_child_protected.x << std::endl;		// Cannot access this from outside as it is inhereted from test_parent as Private
	std::cout << " Protected Access Variable Value ::" << test_child_protected.y << std::endl;		// Cannot access this from outside as it is inhereted from test_parent as Protected
	std::cout << " Public Access Variable Value ::" << test_child_protected.z << std::endl;			// Cannot access this from outside as it is inhereted from test_parent as Public

	Grandchild_protected test_grandchild_protected;
	std::cout << " Private Access Variable Value ::" << test_grandchild_protected.x << std::endl;	// Cannot access this from outside as it is inhereted from test_child as Private
	std::cout << " Protected Access Variable Value ::" << test_grandchild_protected.y << std::endl;	// Cannot access this from outside as it is inhereted from test_child as Protected
	std::cout << " Public Access Variable Value ::" << test_grandchild_protected.z << std::endl;	// Cannot access this from outside as it is inhereted from test_child as Public

	return 0;
}
*/