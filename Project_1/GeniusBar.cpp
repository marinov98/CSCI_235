// Assignment: CSCI 235, Fall 2018, Project 1
// Author: Marin P. Marinov
// Instructor: Tiziana Ligorio
// date: 08/28/18
// Purpose: Implement the GeniusBar class

#include "GeniusBar.hpp"
#include "Customer.hpp"
#include <iostream>
#include <string>

GeniusBar::GeniusBar()
{
	number_of_customers_ = 0;
	number_of_available_geniuses_ = 3;
	current_wait_time_ = 0;
}

bool GeniusBar::addWaitingCustomer(Customer& new_customer)
{
	// pre:
	if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS)
	{
		// post:
		genius_bar_[number_of_customers_] = new_customer;
		current_wait_time_ += WAIT_TIME_INCREMENT;
		new_customer.updateWaitTime(current_wait_time_);
	}

	// return statement
	if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS)
	{
		number_of_customers_++;
		return true;
	}

	return false;
}

bool GeniusBar::assignGeniusToCustomer()
{
	// pre:
	if (number_of_customers_ > 0 && number_of_available_geniuses_ > 0)
	{
		// post:
		number_of_customers_--;
		number_of_available_geniuses_--;
		// return statements
		return true;
	}

	return false;
}

bool GeniusBar::releaseGenius()
{
	// pre:
	// return statments
	if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES)
	{
		number_of_available_geniuses_++; // post
		return true;
	}

	return false;
}

bool GeniusBar::updateCustomersWaitTime()
{
	// pre:
	if (number_of_customers_ > 0)
	{
		// post:
		for (int i = 0; i < number_of_customers_; i++)
		{
			genius_bar_[i].updateWaitTime(genius_bar_[i].getWaitTime() + WAIT_TIME_INCREMENT);
		}

		// return statments
		return true;
	}

	return false;
}
