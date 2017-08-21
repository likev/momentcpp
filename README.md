# momentcpp
DateTime library Like [moment.js](https://momentjs.com/docs/#/parsing/now/), in C++

This library consist of only one header file without other dependency,your compiler must support C++11 std::chrono.

# usage
```c++
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


	//Set
	//---------------------------------------------
	std::cout << moment().year(2017).hour(12) << std::endl;
	std::cout << moment().year(2017).add(3,"years") << std::endl;
	std::cout << moment().year(2017).hour(12).subtract(2,"hours") << std::endl;
	std::cout << moment().unix(1503228936) << std::endl;

	std::cout << moment(2017, 8, 20, 16, 17, 05) - moment(2017, 8, 20, 16, 17, 15) << std::endl;

	return 0;
}
```

# methods

- **moment()**

get the current date and time
- **moment(const long long& timestamp_milliseconds)**

create a moment by passing an integer value representing the number of milliseconds since the Unix Epoch (Jan 1 1970 12AM UTC).
- **moment(int year, int month, int day, int hour=0, int min=0, int sec=0, int millisec=0)**

create a moment with year,month(0-11)...

- **int year() const** get the year
- **moment& year(int newyear)** set the year

- **int month() const** get the month 0-11
- **moment& month(int newmonth)** set the month

- **int date() const** get day of month
- **moment& date(int newday)** set day of month

- **int hour() const**
- **moment& hour(int newhour)**

- **int minute() const**
- **moment& minute(int newminute)**

- **int second() const**
- **moment& second(int newsecond)**

- **int millisecond() const**
- **moment& millisecond(int newmillisecond)**

- **long long unix() const** get Unix timestamp (seconds since the Unix Epoch)
- **moment& unix(const long long& timestamp_seconds)** To create a moment from a Unix timestamp (seconds since the Unix Epoch)

- **long long valueOf() const** get the number of milliseconds since the Unix Epoch (Jan 1 1970 12AM UTC).
- **operator long long() const** auto convert to the number of milliseconds since the Unix Epoch (Jan 1 1970 12AM UTC).

- **std::string toString() const**
- **std::ostream& operator<<(std::ostream& os, const moment& m)** you can use std::cout<<monment::monment()

- **moment& add(int count, const std::string& unit)**
- **moment& subtract(int count, const std::string& unit)**

For convenience, both singular and plural method names exist. you can use years(),months() as well.



