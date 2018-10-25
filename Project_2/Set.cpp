// Assignment: CSCI 235, Fall 2018, Project 2
// Name: Marin Pavlinov Marinov
// Date: 09/011/18
// File Name: Set.cpp
#include <iostream>

// Initialize
template <class ItemType>
Set<ItemType>::Set() {
	item_count_ = 0;
	max_items_ = DEFAULT_SET_SIZE;
}

// Find the index of the chosen entry in the array
template <class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const {
	for (int i = 0; i < item_count_; i++) {
		// returns the index if its found
		if (items_[i] == target)
			return i;
	}
	// returns blank otherwise
	return 0;
}

// Get the current size of the set
template <class ItemType>
int Set<ItemType>::getCurrentSize() const {
	return item_count_;
}

// Check if the set is empty
template <class ItemType>
bool Set<ItemType>::isEmpty() const {
	return item_count_ == 0;
}

// Add a new object to the set
template <class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry) {
	if (item_count_ < max_items_ && !(contains(newEntry))) {
		// adds new entry and increments size
		items_[item_count_] = newEntry;
		item_count_++;
		return true;
	}

	return false;
}

// Remove an object from the set
template <class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry) {
	// checks if the array contains the entry
	if (contains(anEntry)) {
		int index = getIndexOf(anEntry);
		item_count_--;
		items_[index] = items_[item_count_];
		return true;
	}

	return false;
}

// Clears the entire set
template <class ItemType>
void Set<ItemType>::clear() {
	item_count_ = 0;
}

// Checks if the set contains the chosen entry
template <class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const {
	for (int i = 0; i < item_count_; i++) {
		if (items_[i] == anEntry)
			return true;
	}

	return false;
}

// Converts the array to a vector
template <class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const {
	std::vector<ItemType> items;
	items.reserve(item_count_);


	for (int i = 0; i < item_count_; i++)
		items.emplace_back(items_[i]);

	return items;
}
