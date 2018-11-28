#pragma once
#include <vector>
#include "Product.h"
class Inventory
{
private:
	std::vector<Product> StoreInventory;
	std::vector<Product> CustomerCart;
public:
	//Have constructor pull info from file if found and load the lists up.
	Inventory()
	{

	}

	//Accessors
	std::vector<Product> const &getStoreInventory() const { return StoreInventory; }
	std::vector<Product> const &getCustomerCart() const { return CustomerCart; }

	//Will need to add pointers and references to get to accesss the data properly
	void AddProduct(std::vector<Product> listToAddTo, Product item)
	{
		bool added = false;
		for (size_t i = 0; i < listToAddTo.size(); i++)
		{
			if (listToAddTo[i].Compare(item))
			{
				listToAddTo[i].AddQuantity(item.getQuantity());
				added = true;
			}
		}
		if (!added)
		{
			listToAddTo.push_back(item);
		}
	}

	void SubtractProduct(std::vector<Product> listToSubtractFrom, Product item)
	{
		for (size_t i = 0; i < listToSubtractFrom.size(); i++)
		{
			if (listToSubtractFrom[i].Compare(item))
			{
				listToSubtractFrom[i].SubtractQuantity(item.getQuantity());
			}
		}
	}

	void setSalePrice(Product item, double value)
	{
		for (size_t i = 0; i < StoreInventory.size(); i++)
		{
			if (StoreInventory[i].Compare(item))
			{
				if (value > 0)
				{
					StoreInventory[i].setSalePrice(value);
				}
				else
				{
				}
			}
		}
	}

	void ClearCart()
	{
		CustomerCart.empty();
	}
};

