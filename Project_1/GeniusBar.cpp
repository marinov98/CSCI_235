// Assignment: CSCI 235, Fall 2018, Project 1
// Author: Marin P. Marinov
// Instructor: Tiziana Ligorio
// date: 08/28/18
// Purpose: Implement the GeniusBar class

#include "GeniusBar.hpp"
#include "Customer.hpp"
#include <iostream>
#include <string>

// initialize values
GeniusBar::GeniusBar() {
	number_of_customers_ = 0;
	number_of_available_geniuses_ = 3;
	current_wait_time_ = 0;
}

// Adds a waiting customer, as long as they do not go above the max
bool GeniusBar::addWaitingCustomer(Customer& new_customer) {
	if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS) {
		// adds customer to genius bar and increments wait time
		genius_bar_[number_of_customers_] = new_customer;
		current_wait_time_ += WAIT_TIME_INCREMENT;
		new_customer.updateWaitTime(current_wait_time_);
		// return true if a customer can be assigned, false otherwise
		number_of_customers_++;
		return true;
	}

	return false;
}

/*
Assigns genius to a customer and decreases the amount of customers
that require help as well as the number of available geniuses until
there are none remaining
*/
bool GeniusBar::assignGeniusToCustomer() {
	if (number_of_customers_ > 0 && number_of_available_geniuses_ > 0) {
		number_of_customers_--;
		number_of_available_geniuses_--;
		// return true if a genius can be released, false otherwise
		return true;
	}

	return false;
}

// releases geniuses from their break
bool GeniusBar::releaseGenius() {
	// pre:
	if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES) {
		number_of_available_geniuses_++;
		// return true if a genius can be made avaliable, false otherwise
		return true;
	}

	return false;
}

// Updates customer's wait time until there are no available customers left
bool GeniusBar::updateCustomersWaitTime() {
	// pre:
	if (number_of_customers_ > 0) {
		// post:
		for (int i = 0; i < number_of_customers_; i++) {
			genius_bar_[i].updateWaitTime(genius_bar_[i].getWaitTime() + WAIT_TIME_INCREMENT);
		}

		// return statments
		return true;
	}

	return false;
}
