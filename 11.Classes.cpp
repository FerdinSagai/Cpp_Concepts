/*

Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:
This code covers the following C++ feature -
1. CLASSES
a. Defining a Class
b. Access Specifiers
c. Constructors 
d. this pointer
e. Pointer to an object
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
#include<string>
class Cars
{
private:
	std::string Company_name;
	std::string Model_name;
	std::string Fuel_type;
	double Mileage{ 0.00 };
	double price{ 0.00 };
public:
	void setData(std::string _Company_name, std::string _Model_name, std::string _Fuel_type, double _Mileage, double _price)
	{
		Company_name = _Company_name;
		Model_name = _Model_name;
		Fuel_type = _Fuel_type;
		Mileage = _Mileage;
		price = _price;
	}

	void displayData()
	{
		std::cout << "Company name is : " << Company_name << std::endl;
		std::cout << "Model name is : " << Model_name << std::endl;
		std::cout << "Fuel Type is : " << Fuel_type << std::endl;
		std::cout << "Mileage is : " << Mileage << std::endl;
		std::cout << "Price is : " << price << std::endl;
	}
};

class Motorbikes
{
private:
	std::string Company_name;
	std::string Model_name;
	std::string Fuel_type;
	double Mileage{ 0.00 };
	double Top_Speed{ 0.00 };
	double price{ 0.00 };
public:
	// Constructors 
	//		Default Constructor
	Motorbikes() 
	{
		Company_name = "Default";
		Model_name = "Default";
		Fuel_type = "Default";
		Mileage = 0.00;
		Top_Speed = 0.00;
		price = 0.00;
	}
	//		Parameterized Constructor 1
	Motorbikes(std::string _Company_name, std::string _Model_name, std::string _Fuel_type, double _Mileage, double _Top_Speed, double _price)
	{
		Company_name = _Company_name;
		Model_name = _Model_name;
		Fuel_type = _Fuel_type;
		Mileage = _Mileage;
		Top_Speed = _Top_Speed;
		price = _price;
	}

	// Member Functions
	void setData(std::string _Company_name, std::string _Model_name, std::string _Fuel_type, double _Mileage, double _Top_Speed, double _price)
	{
		Company_name = _Company_name;
		Model_name = _Model_name;
		Fuel_type = _Fuel_type;
		Mileage = _Mileage;
		Top_Speed = _Top_Speed;
		price = _price;
	}

	void displayData()
	{
		std::cout << "Company name is : " << Company_name << std::endl;	
		std::cout << "Model name is : " << Model_name << std::endl;
		std::cout << "Fuel Type is : " << Fuel_type << std::endl;
		std::cout << "Mileage is : " << Mileage << std::endl;
		std::cout << "Top Speed is : " << Top_Speed << std::endl;
		std::cout << "Price is : " << price << std::endl;
	}

	// Compare two Bikes
	Motorbikes determineFastest(Motorbikes Bike1, Motorbikes Bike2)
	{
		if (Bike1.Top_Speed > Bike2.Top_Speed)
			return Bike1;
		else
			return Bike2;
	}

	Motorbikes determineEfficient(Motorbikes Bike2)
	{
		Motorbikes Bike1(this->Company_name, this->Model_name, this->Fuel_type, this->Mileage, this->Top_Speed, this->price);
		if (Bike1.Mileage > Bike2.Mileage)
			return Bike1;
		else
			return Bike2;
	}
};

class Cycles
{
private:
	std::string Company_name;
	std::string Model_name;
	double price{ 0.00 };
public:
	// Constructors 
//		Default Constructor
	Cycles()
	{
		Company_name = "Default";
		Model_name = "Default";
		price = 0.00;
	}
	//		Parameterized Constructor 1
	Cycles(std::string _Company_name, std::string _Model_name, double _price)
	{
		Company_name = _Company_name;
		Model_name = _Model_name;
		price = _price;
	}
	// Member Functions
	//	Getters and Setters
	void setData(std::string _Company_name, std::string _Model_name, double _price)
	{
		Company_name = _Company_name;
		Model_name = _Model_name;
		price = _price;
	}

	void displayData()
	{
		std::cout << "Company name is : " << Company_name << std::endl;
		std::cout << "Model name is : " << Model_name << std::endl;
		std::cout << "Price is : " << price << std::endl;
	}

};


// ====================================================================================
int main()
{
	Cars Car1;
	Car1.setData("Porshce", "Camaro", "Petrol", 10, 5502.34);
	Car1.displayData();

	Motorbikes MBike1; // Default constructor is called at the time of creation
	MBike1.displayData();		// Proof that default constructor is called.
	MBike1.setData("Yamaha", "R1", "Petrol", 8, 320, 1502.34);
	MBike1.displayData();		// Proof that default constructor is called.

	Motorbikes MBike2("Suzuki", "Hayabusa", "Petrol", 4, 360, 3502.34);; // Parameterized constructor is called at the time of creation
	MBike2.displayData();
	std::cout << "===============================" << std::endl;
	Motorbikes Fastest; 
	std::cout << "Fastest Bike is :: " << std::endl;
	Fastest = Fastest.determineFastest(MBike1, MBike2);
	Fastest.displayData();
	std::cout << "===============================" << std::endl;

	Motorbikes Efficient;
	std::cout << "Efficient Bike is :: " << std::endl;
	Efficient = MBike1.determineEfficient(MBike2);
	Efficient.displayData();
	std::cout << "===============================" << std::endl;

	Cycles* CycleList = new Cycles[3];
	CycleList[0].setData("Hero", "Model-100", 1002);
	CycleList[1].setData("Mountain Fox", "MF-850", 10002.32);
	CycleList[2].setData("BMX", "BMX-10k", 20251.85);

	return 0;
}