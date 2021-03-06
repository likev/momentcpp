# Moment.cpp
Moment.cpp is C++ DateTime library (inspired by [moment.js](https://momentjs.com/docs/#/parsing/now/) )

## Design goals

There are myriads of DateTime libraries out there, and each may even have its reason to exist. Our class had these design goals:

- **Intuitive syntax**. In languages such as Javascript, Date is a first class data type. We used all the operator magic of modern C++ to achieve the same feeling in your code. Check out the [examples below](#examples) and you'll know what I mean.

- **Trivial integration**. The whole code consists of a single header file [`moment.hpp`](https://github.com/likev/momentcpp/blob/master/include/moment.hpp). That's it. No library, no subproject, no dependencies, no complex build system. The class is written in vanilla C++11(std::chrono). All in all, everything should require no adjustment of your compiler flags or project settings.

Other aspects were not so important to us:

- **Memory efficiency**. 

- **Speed**. There are certainly [faster DateTime libraries](https://github.com/HowardHinnant/date) out there. However, if your goal is to speed up your development by adding DateTime support with a single header, then this library is the way to go. 

## Examples
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
```

## Methods

#### `moment()` 
get the current date and time

#### `moment(const long long& timestamp_milliseconds)` 
create a moment by passing an integer value representing the number of milliseconds since the Unix Epoch (Jan 1 1970 12AM UTC).

#### `moment(int year, int month, int day, int hour=0, int min=0, int sec=0, int millisec=0)` 
create a moment with year,month(0-11)...

#### `int year() const` 
get the year

#### `moment& year(int newyear)` 
set the year

#### `int month() const` 
get the month 0-11

#### `moment& month(int newmonth)` 
set the month

if a moment changed months and the new month did not have enough days to keep the current day of month, it would clamped to the end of the target month.
 ```c++
 moment([2012, 0, 31]).month(1).format("YYYY-MM-DD"); // 2012-02-29
 ```

#### `int date() const` 
get day of month

#### `moment& date(int newday)` 
set day of month

#### `int day() const`

#### `moment& day(int newday)`

Gets or sets the day of the week.

This method can be used to set the day of the week, with Sunday as 0 and Saturday as 6.

If the range is exceeded, it will bubble up to other weeks.

**Note:** `Moment#date` is for the date of the month, and `Moment#day` is for the day of the week.

#### `int dayOfYear() const`
#### `moment& dayOfYear(int newday)`

Gets or sets the day of the year.

Accepts numbers from 1 to 366. If the range is exceeded, it will bubble up to the years.

#### `int hour() const`
#### `moment& hour(int newhour)`

#### `int minute() const`
#### `moment& minute(int newminute)`

#### `int second() const`
#### `moment& second(int newsecond)`

#### `int millisecond() const`
#### `moment& millisecond(int newmillisecond)`

#### `long long unix() const` 
get Unix timestamp (seconds since the Unix Epoch)

#### `moment& unix(const long long& timestamp_seconds)` 
To create a moment from a Unix timestamp (seconds since the Unix Epoch)

#### `long long valueOf() const` 
get the number of milliseconds since the Unix Epoch (Jan 1 1970 12AM UTC).

#### `operator long long() const` 
auto convert to the number of milliseconds since the Unix Epoch (Jan 1 1970 12AM UTC).

#### `std::string toString() const`
#### `std::ostream& operator<<(std::ostream& os, const moment& m)` 
you can use `std::cout<<monment::monment()<<std::endl`

#### `moment& add(int count, const std::string& unit)`
#### `moment& subtract(int count, const std::string& unit)`

For convenience, both singular and plural method names exist. you can use `years()`,`months()` as well.

