// Assignment: CSCI 235, Fall 2018, Project 1
// Author: Marin P. Marinov
// Instructor: Tiziana Ligorio
// date: 08/28/18
// Purpose: Implement the Customer class

#include "Customer.hpp"
#include <iostream>
#include <string>

Customer::Customer()
{
	name_ = "";
	defective_device_ = "unknown";
	wait_time_ = 0;
}

// Initialize the name, device, and time
Customer::Customer(std::string name, std::string device, int wait_time)
{
	name_ = name;
	defective_device_ = device;
	int wait_time_ = wait_time;
}

// return name_
std::string Customer::getName()
{
	return name_;
}

// return defective_device_
std::string Customer::getDevice()
{
	return defective_device_;
}

// return wait_time_
int Customer::getWaitTime()
{
	return wait_time_;
}

// updates wait time based on amount put into the argument
void Customer::updateWaitTime(int new_wait_time)
{
	wait_time_ = new_wait_time;
}
