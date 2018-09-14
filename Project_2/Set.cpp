// Assignment: CSCI 235, Fall 2018, Project 2
// Name: Marin Pavlinov Marinov
// Date: 09/011/18
// File Name: Set.cpp
#include <iostream>

// Initialize
template <class ItemType>
Set<ItemType>::Set()
{
	item_count_ = 0;
	max_items_ = DEFAULT_SET_SIZE;
}

// Find the index of the chosen entry in the array
template <class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const
{
	for (int i = 0; i < item_count_; i++)
	{
		// returns the index if its found
		if (items_[i] == target)
		{
			return i;
		}
	}
	// returns blank otherwise
	return 0;
}

// Get the current size of the set
template <class ItemType>
int Set<ItemType>::getCurrentSize() const
{
	return item_count_;
}

// Check if the set is empty
template <class ItemType>
bool Set<ItemType>::isEmpty() const
{
	return item_count_ == 0;
}

// Add a new object to the set
template <class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry)
{
	if (item_count_ < max_items_)
	{
		// adds new entry and increments size
		items_[item_count_] = newEntry;
		item_count_++;
		return true;
	}

	return false;
}

// Remove an object from the set
template <class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry)
{
	// checks if the array contains the entry
	if (this->contains(anEntry))
	{
		int index = this->getIndexOf(anEntry);
		// removes the index by replacing the entry with the index of
		// the one after it
		for (int i = index; i < item_count_ - 1; i++)
		{
			items_[i] = items_[i + 1];
		}
		item_count_--;
		return true;
	}

	return false;
}

// Clears the entire set
template <class ItemType>
void Set<ItemType>::clear()
{
	// removes all items from the array
	// for (int i = 0; i < item_count_; i++)
	// {
	// 	this->remove(items_[i]);
	// }

	item_count_ = 0;
}

// Checks if the set contains the chosen entry
template <class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const
{
	for (int i = 0; i < item_count_; i++)
	{
		if (items_[i] == anEntry)
			return true;
	}

	return false;
}

// Converts the array to a vector
template <class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const
{
	std::vector<ItemType> items;

	for (int i = 0; i < item_count_; i++)
	{
		items.push_back(items_[i]);
	}

	return items;
}
