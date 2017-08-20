# momentcpp
Like [moment.js](https://momentjs.com/docs/#/parsing/now/), in C++
This library consist of only one header file without other dependency,your compiler must support C++11 std::chrono.

# usage
```c++
#include <iostream>
#include "./include/moment.hpp"

int main(){
  std::cout << moment::moment() << std::endl;
}
```

# methods

- **moment()** 
get the current date and time
- **moment(const long long& timestamp_milliseconds)**
create a moment by passing an integer value representing the number of milliseconds since the Unix Epoch (Jan 1 1970 12AM UTC).
- **moment(int year, int month, int day, int hour=0, int min=0, int sec=0, int millisec=0)**
create a moment with year,month...

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
- **operator long long() const** convert to the number of milliseconds since the Unix Epoch (Jan 1 1970 12AM UTC).

- **std::string toString() const**
- **std::ostream& operator<<(std::ostream& os, const moment& m)** you can use std::cout<<monment::monment()

For convenience, both singular and plural method names exist. you can use years(),months() as well.



