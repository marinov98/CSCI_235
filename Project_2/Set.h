// Assignment: CSCI 235, Fall 2018, Project 2
// Name: Marin Pavlinov Marinov
// Date: 09/011/18
// File Name: Set.h

#ifndef SET_H
#define SET_H
#include "SetInterface.h"
template <class ItemType>

class Set : public SetInterface<ItemType>
{
  public:
	int getCurrentSize() const;

	bool isEmpty() const;

	bool add(const ItemType& newEntry);

	bool remove(const ItemType& anEntry);

	void clear();

	bool contains(const ItemType& anEntry) const;

	std::vector<ItemType> toVector() const;

  private:
	static const int DEFAULT_SET_SIZE = 4; // for testing purposes we will keep the set small

	ItemType items_[DEFAULT_SET_SIZE]; // array of set items

	int item_count_; // current count of set items

	int max_items_; // max capacity of the set
};

#endif
