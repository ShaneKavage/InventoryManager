#pragma once
#include "Product.h"
#include <string>

enum PerishType
{
	NonPerishable,
	Freezer,
	Fridge,
	NonRefridgerated
};

class Perishable : public Product
{

private:
	PerishType perishType;
	int shelfLife;

public:
	Perishable() : Product()
	{

	}
	Perishable(PerishType perishType, int shelfLife)
	{
		setPerishType(perishType);
		setShelfLife(shelfLife);
	}

	//Mutators
	void setPerishType(PerishType perishType) { this->perishType = perishType; }
	void setShelfLife(int shelfLife) { if (shelfLife > 0) { this->shelfLife = shelfLife; } }

	//Accessors
	PerishType getPerisghType() const { return perishType; }
	int getShelfLife() const { return shelfLife; }
};

