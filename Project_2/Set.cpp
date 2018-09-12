// Assignment: CSCI 235, Fall 2018, Project 2
// Name: Marin Pavlinov Marinov
// Date: 09/011/18
// File Name: Set.cpp

#include "Set.h"
#include <iostream>

template <class ItemType>
int Set<ItemType>::getCurrentSize() const
{
	return item_count_;
}

template <class ItemType>
bool Set<ItemType>::isEmpty() const
{
	if (item_count_ == 0)
		return true;

	return false;
}

template <class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry)
{
	if (items_.size() < max_items_)
	{
		std::cout << "newEntry has been stored in the set!" << '\n';
		items_[item_count_] = newEntry;
		item_count_++;
		return true;
	}

	return false;
}

template <class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry)
{
	if (items_.size() > 0)
	{
		std::cout << "anEntry has been removed from the set!" << '\n';
		for (int i = 0; i < items_.size(); i++)
		{
			if (items_[i] == anEntry)
			{
				items_[i].remove();
				item_count_--;
				return true;
			}
		}
	}
	return false;
}

template <class ItemType>
void Set<ItemType>::clear()
{
	for (int i = 0; i < items_.size(); i++)
	{
		items_[i].remove();
	}

	item_count_ = 0;
}

template <class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const
{
	for (int i = 0; i < items_.size(); i++)
	{
		if (items_[i] == anEntry)
			return true;
	}

	return false;
}

template <class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const
{
	std::vector<ItemType> items;

	for (int i = 0; i < items_.size(); i++)
	{
		items[i] = items_[i];
	}

	return items;
}
