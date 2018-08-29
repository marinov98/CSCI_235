#include "Customer.hpp"
#include "GeniusBar.hpp"
#include <iostream>
#include <string>

int main()
{
	// initialize a GeniusBar

	GeniusBar genius_bar;

	// create some customers

	Customer customer1("Lina", "iPhone");

	std::cout << customer1.getName() << " has problems with " << customer1.getDevice() << std::endl;

	Customer customer2("Clay", "iPad");

	std::cout << customer2.getName() << " has problems with " << customer2.getDevice() << std::endl;

	Customer customer3("Rory", "iMac");

	std::cout << customer3.getName() << " has problems with " << customer3.getDevice() << std::endl;

	Customer customer4("Liam", "macBookPro");

	std::cout << customer4.getName() << " has problems with " << customer4.getDevice() << std::endl;

	Customer customer5("Adri", "iPhone");

	std::cout << customer5.getName() << " has problems with " << customer5.getDevice() << std::endl;

	Customer customer6("Sky", "macBookAir");

	std::cout << customer6.getName() << " has problems with " << customer6.getDevice() << std::endl;

	std::cout << std::endl << "add customers to the geinus bar \n";

	std::cout << genius_bar.addWaitingCustomer(customer1) << std::endl; // true (1)

	std::cout << customer1.getName() << "'s wait time is now " << customer1.getWaitTime()
	          << std::endl;

	std::cout << genius_bar.addWaitingCustomer(customer2) << std::endl; // true (1)

	std::cout << customer2.getName() << "'s wait time is now " << customer2.getWaitTime()
	          << std::endl;

	std::cout << genius_bar.addWaitingCustomer(customer3) << std::endl; // true (1)

	std::cout << customer3.getName() << "'s wait time is now " << customer3.getWaitTime()
	          << std::endl;

	std::cout << genius_bar.addWaitingCustomer(customer4) << std::endl; // true (1)

	std::cout << customer4.getName() << "'s wait time is now " << customer4.getWaitTime()
	          << std::endl;

	std::cout << genius_bar.addWaitingCustomer(customer5) << std::endl; // true (1)

	std::cout << customer5.getName() << "'s wait time is now " << customer5.getWaitTime()
	          << std::endl;

	std::cout << genius_bar.addWaitingCustomer(customer6) << std::endl; // true (0)

	std::cout << customer6.getName() << "'s wait time is still " << customer6.getWaitTime()
	          << " because there is no more space at the genius bar \n";

	std::cout << "Sorry Sky please come back later!\n\n";

	std::cout << std::endl << "assigning geniuses to assist customers:" << std::endl;

	std::cout << genius_bar.assignGeniusToCustomer() << std::endl; // true (1)

	std::cout << genius_bar.assignGeniusToCustomer() << std::endl; // true (1)

	std::cout << genius_bar.assignGeniusToCustomer() << std::endl; // true (1)

	std::cout << genius_bar.assignGeniusToCustomer() << std::endl; // true (0)

	std::cout << "Oops, no more available geniuses, the remaining customers must wait \n\n";

	std::cout << std::endl
	          << "release some geniuses from helping customers and make them available again \n";

	std::cout << genius_bar.releaseGenius() << std::endl; // true (1)

	std::cout << genius_bar.releaseGenius() << std::endl; // true (1)

	std::cout << genius_bar.releaseGenius() << std::endl; // true (1)

	std::cout << genius_bar.releaseGenius() << std::endl; // true (0)

	std::cout << "no more geniuses to be released \n\n";

	std::cout << "Oops, it's lunch time, our geniuses are going on lunch break, better update the "
	             "remaining customers' wait time \n";

	std::cout << genius_bar.updateCustomersWaitTime() << std::endl; // true (1)

	std::cout << std::endl
	          << "Ok, our geniuses are back from lunch, assign more geniuses to help the remaining "
	             "customers \n";

	std::cout << genius_bar.assignGeniusToCustomer() << std::endl; // true (1)

	std::cout << genius_bar.assignGeniusToCustomer() << std::endl; // true (1)

	std::cout << genius_bar.assignGeniusToCustomer() << std::endl; // true (0)

	std::cout << "no more customers in the store, all done for today!!! \n\n";

	std::cout << "do we need to tell any remaining customers that they need to wait unitl "
	             "tomorrow? \n";

	std::cout << genius_bar.updateCustomersWaitTime() << std::endl; // true (0)

	std::cout << "no we don't, good night!!! \n\n";

	return 0;
}
