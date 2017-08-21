
#include <iostream>
#include "./include/moment.hpp"

int main()
{
	using moment::moment;

	//Create
	std::cout << moment() << std::endl;
	std::cout << +moment() << std::endl;
	std::cout << moment(2017, 8, 20) << std::endl;
	std::cout << moment(1503228936974) << std::endl;
	std::cout << moment(2017, 8, 20, 16, 17, 05) << std::endl;

	//Get
	//---------------------------------------------
	std::cout <<" year: "<< moment().year()
		<< " month: " << moment().month()
		<< " date: " << moment().date()
		<< " hour: " << moment().hour()
		<< " minute: " << moment().minute()
		<< " second: " << moment().second()
		<< " millisecond: " << moment().millisecond()
		<< std::endl;
	std::cout << moment().unix() << std::endl;

	std::cout << " dayOfWeek: " << moment().day() << std::endl;
	std::cout << " dayOfYear: " << moment().month(0).date(1).dayOfYear() << std::endl;


	//Set
	//---------------------------------------------
	std::cout << moment().year(2017).hour(12) << std::endl;
	std::cout << moment().year(2017).add(3,"years") << std::endl;
	std::cout << moment().year(2017).hour(12).subtract(2,"hours") << std::endl;
	std::cout << moment().unix(1503228936) << std::endl;

	std::cout << "moment(2012,0,31).month(1): " << moment(2012,0,31).month(1) << std::endl;
	
	std::cout << " dayOfWeek: " << moment().day(2) << std::endl;
	std::cout << " dayOfYear: " << moment().dayOfYear(2) << std::endl;

	std::cout << moment(2017, 8, 20, 16, 17, 05) - moment(2017, 8, 20, 16, 17, 15) << std::endl;

	return 0;
}

