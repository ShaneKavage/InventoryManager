#pragma once
#include <string>

enum Department
{
	Dairy,
	Deli,
	Meat,
	Frozen,
	Produce,
	Grocery,
	Bakery,
	Alcohol,
	HBCM,
	GeneralMerchandise,
	NONE
};

class Product
{

private:
	std::string name;
	Department department;
	double price, salePrice, weight;
	int ID, quantity;

public:
	Product()
	{
		name = "";
		department = NONE;
		price = 0;
		salePrice = 0;
		weight = 0;
		ID = -1;
		quantity = -1;
	}

	Product(std::string name, Department department, double price,
		double salePricee, double weight, int ID, int quantity)
	{
		setName(name);
		setDepartment(department);
		setPrice(price);
		setSalePrice(salePrice);
		setWeight(weight);
		setID(ID);
		setQuantity(quantity);
	}
	
	//Mutators
	void setName(std::string name) { this->name = name; }
	void setDepartment(Department deptartment) { this->department = deptartment; }
	void setPrice(double price) { if (price > 0) { this->price = price; } }
	void setSalePrice(double salePrice) { if (salePrice > 0) { this->salePrice = salePrice; } }
	void setWeight(double weight) { if (weight > 0) { this->weight = weight; } }
	void setID(int ID) { this->ID = ID; }
	void setQuantity(int quantity) { if (quantity > 0) { this->quantity = quantity; } }

	//Accessors
	std::string getName() const { return name; }
	Department getDepartment()  const { return department; }
	double getPrice()  const { return price; }
	double getSalePrice()  const { return salePrice; }
	double getWeight()  const { return weight; }
	int getID()  const { return ID; }
	int getQuantity() const { return quantity; }

	//Modifiers to inventory count
	void AddQuantity(int quantity) {
		this->quantity += quantity;
		//Incase of negative input
		if (this->quantity < 0)
		{
			this->quantity = 0;
		}
	}
	void SubtractQuantity(int quantity) {
		this->quantity -= quantity;
		//Incase of over subtracting
		if (this->quantity < 0)
		{
			this->quantity = 0;
		}
	}

	bool Compare(Product item)
	{
		if (getID() == item.getID())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::string getDepartmentName() const
	{
		std::string temp;
		switch (department)
		{
		case 0: temp = "Dairy";
			break;
		case 1: temp = "Deli";
			break;
		case 2: temp = "Meat";
			break;
		case 3: temp = "Frozen";
			break;
		case 4: temp = "Produce";
			break;
		case 5: temp = "Grocery";
			break;
		case 6: temp = "Bakery";
			break;
		case 7: temp = "Alcohol";
			break;
		case 8: temp = "HBCM";
			break;
		case 9: temp = "GeneralMerchandise";
			break;
		case 10: temp = "Unassigned";
			break;

		default: temp = "ERROR - not a category";
		}
		return temp;
	}

	virtual void displayProductInformation() const;

};

